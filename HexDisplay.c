#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 65536  // 64 Kbytes = 65536 bytes

// Hex Format Record
typedef struct {
    uint8_t byteCount;
    uint8_t address[2];
    uint8_t recordType;
    uint8_t data[16];
    uint8_t checkSum;
} HexData;

uint8_t *getFilename(uint8_t *cmd);
uint8_t checkCmd(uint8_t *cmd);
uint8_t *removeSpaces(uint8_t *str);
uint8_t readFile(HexData *data, uint8_t *filename);
uint8_t checkSum(HexData data);
uint8_t strToInt(uint8_t *str);
uint8_t hexToChar(uint8_t hex);
uint8_t isContinue(void);
uint8_t totalBytes(HexData data);
void makeBuffer(HexData *data, uint8_t *buffer);
void show(uint8_t *buffer);
void clearStdin(void);

uint8_t main() {
    uint8_t buffer[MAX_BUFFER];
    memset(buffer, 0xff, MAX_BUFFER);
    uint8_t cmd[100];
    HexData data[MAX_BUFFER / 16];

    system("cls");
    printf(">> ");
    scanf("%[^\n]s", cmd);
    clearStdin();

    removeSpaces(cmd);
    if (!checkCmd(cmd))
        return 1;

    uint8_t *filename = getFilename(cmd);
    readFile(data, filename);
    makeBuffer(data, buffer);
    show(buffer);
    free(filename);
    return 0;
}

/**
 * Get name of hex file from command line
 * @param cmd command
 * @return name of file
 */
uint8_t *getFilename(uint8_t *cmd) {
    uint8_t *filename = (uint8_t *) malloc(100);
    int len = strlen(cmd);
    while ((len > 0) && (cmd[len - 1] != ' ')) len--;
    strcpy(filename, &cmd[len]);
    return filename;
}

/**
 * Check command user input from keyboard
 * @param cmd command user input from keyboard
 * @return True or False
 */
uint8_t checkCmd(uint8_t *cmd) {
    uint8_t extension[100] = "";
    uint8_t temp[100] = "";
    uint32_t i = 0, len = strlen(cmd);
    while ((i < len) && (cmd[i] != ' ')) i++;
    strncpy(temp, cmd, i);
    if (strcmp(temp, "HexDisplay") != 0) {
        printf("\nUsage: HexDisplay <filename>\n\n");
        return 0;
    }
    while ((len > 0) && (cmd[len - 1] != '.')) len--;
    strcpy(extension, &cmd[len]);
    if (strcmp(extension, "hex") != 0) {
        printf("\n[ERROR] File extension must be \"hex\"\n\n");
        return 0;
    } else
        return 1;
}

/**
 * Remove the extra spaces in string
 * @param str string you want to remove extra whitespace
 * @return string with extra whitespace removed
 */
uint8_t *removeSpaces(uint8_t *str) {
    uint32_t len = strlen(str);
    uint32_t i = len;
    while ((i > 0) && (str[i - 1] == ' ')) i--;
    if (i != len) {
        len = i;
        str[i] = '\0';
    }
    i = 0;
    while ((i < len) && (str[i] == ' ')) i++;
    if (i != 0)
        strcpy(str, &str[i]);
    len = strlen(str), i = 0;
    while (i < len) {
        if ((str[i] == ' ') && (str[i + 1] == ' ')) {
            strcpy(&str[i], &str[i + 1]);
            len--;
            i--;
        }
        i++;
    }
    return str;
}

/**
 * Read data from input file
 * @param data array of all record get from input file
 * @param filename name of input file
 * @return True or False
 */
uint8_t readFile(HexData *data, uint8_t *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("\n[ERROR]: %s could not be opened\n\n", filename);
        exit(1);
    }
    uint8_t record[50]; // one line in hex file
    uint8_t recordLen;
    uint32_t line = 0; // count line
    uint8_t bytes = 0;
    uint8_t tempHex[3] = "";
    while (!feof(fp)) {
        line++;
        fscanf(fp, "%[^\n]s", record);
        recordLen = strlen(record);
        if (record[0] != ':') {
            printf("\n[ERROR]: line %d of file %s: syntax error\n\n", line, filename);
            fclose(fp);
            exit(1);
        }
        // get byte count
        strncpy(tempHex, &record[1], 2);
        data[line - 1].byteCount = strToInt(tempHex);
        memset(tempHex, '\0', sizeof(tempHex));

        // get address
        strncpy(tempHex, &record[3], 2);
        data[line - 1].address[0] = strToInt(tempHex);
        memset(tempHex, '\0', sizeof(tempHex));
        strncpy(tempHex, &record[5], 2);
        data[line - 1].address[1] = strToInt(tempHex);
        memset(tempHex, '\0', sizeof(tempHex));

        // get record type
        strncpy(tempHex, &record[7], 2);
        data[line - 1].recordType = strToInt(tempHex);
        if ((data[line - 1].recordType < 0) || (data[line - 1].recordType > 5)) {
            fclose(fp);
            printf("\n[ERROR]: line %d of file %s: syntax error\n\n", line, filename);
            return 0;
        }
        memset(tempHex, '\0', sizeof(tempHex));

        // get data
        if (data[line - 1].recordType != 0x01) {
            memset(data[line - 1].data, 0xff, 16);
            for (int i = 0; i < data[line - 1].byteCount; i++) {
                strncpy(tempHex, &record[9 + i * 2], 2);
                data[line - 1].data[i] = strToInt(tempHex);
                memset(tempHex, '\0', sizeof(tempHex));
            }
        }

        // get check sum
        strcpy(tempHex, &record[recordLen - 2]);
        data[line - 1].checkSum = strToInt(tempHex);
        memset(tempHex, '\0', sizeof(tempHex));

        if (!checkSum(data[line - 1])) {
            fclose(fp);
            printf("\n[ERROR]: line %d of file %s: syntax error\n\n", line, filename);
            return 0;
        }
        if (data[line - 1].recordType == 0x01) break;
        fgetc(fp);  // get '\n'
    }
    fclose(fp);
    return 1;
}

/**
 * Check sum
 * @param data record to check
 * @return True or False
 */
uint8_t checkSum(HexData data) {
    uint8_t sum = totalBytes(data);
    sum += data.checkSum;
    return sum == 0x00;
}

/**
 * Convert string hex number to integer
 * @param str string hex to convert
 * @return integer number
 */
uint8_t strToInt(uint8_t *str) {
    uint32_t res = 0;
    uint8_t len = strlen(str);
    uint8_t temp;
    for (uint8_t i = 0; i < len; i++) {
        temp = str[i];
        if (isdigit(temp))
            temp -= '0';
        else if (isalpha(temp)) {
            temp = toupper(temp);
            temp = temp - 'A' + 10;
        } else
            return 0xff;
        res = res * 16 + temp;
    }
    return res;
}

/**
 * Convert hex value to ascii
 * @param hex hex value
 * @return ascii code
 */
uint8_t hexToChar(uint8_t hex) {
    if (hex == 0xff)
        return ' ';
    else if (hex >= 0x20)
        return hex;
    else
        return '.';
}

/**
 * Ask user if he wants to continue the program
 * @return True or False
 */
uint8_t isContinue(void) {
    uint8_t c;
    do {
        printf("Do you want to continue print hex file [y/n]? ");
        scanf("%c", &c);
        clearStdin();
        c = tolower(c);
    } while (c != 'y' && c != 'n');
    if (c == 'y') return 1;
    return 0;
}

/**
 * Get sum of total bytes in a record
 * @param data one record
 * @return sum of total bytes in a record
 */
uint8_t totalBytes(HexData data) {
    uint8_t total = 0;
    total += data.byteCount;
    total += data.address[0];
    total += data.address[1];
    total += data.recordType;
    for (uint8_t i = 0; i < data.byteCount; i++)
        total += data.data[i];
    return total;
}

/**
 * Print hex file to screen
 * @param buffer string of hex file
 */
void show(uint8_t *buffer) {
    uint8_t line = 0;
    uint32_t address = 0;
    do {
        system("cls");
        for (uint8_t i = 0; i < 25; i++) {
            printf("%08x  ", address);
            for (uint8_t j = 0; j < 16; j++)
                printf("%02x ", buffer[address + j]);
            printf(" ");
            for (uint8_t j = 0; j < 16; j++)
                printf("%c", hexToChar(buffer[address + j]));
            printf("\n");
            address += 16;
            if (address == MAX_BUFFER)
                return;
        }
    } while (isContinue());
}
/**
 * Make memory buffer
 * @param data all data get from input file
 * @param buffer result
 */
void makeBuffer(HexData *data, uint8_t *buffer) {
    uint32_t address = 0;
    uint32_t linearAdd = 0;
    uint32_t segmentAdd = 0;
    uint8_t ls = 'l';  // l: linearAdd, s: segmentAdd
    for (uint32_t i = 0; i < MAX_BUFFER / 16; i++) {
        switch (data[i].recordType) {
            case 0x00:
                if (ls == 'l') {
                    address = (linearAdd << 16) + (data[i].address[0] << 8) + data[i].address[1];
                    if (address < MAX_BUFFER) {
                        for (uint32_t j = 0; j < data[i].byteCount; j++) {
                            buffer[address + j] = data[i].data[j];
                        }
                    }
                } else if (ls == 's') {
                    address = (segmentAdd << 4) + (data[i].address[0] << 8) + data[i].address[1];
                    for (uint32_t j = 0; j < data[i].byteCount; j++) {
                        buffer[address + j] = data[i].data[j];
                    }
                }
                break;
            case 0x04:
                ls = 'l';
                linearAdd = (data[i].data[0] << 8) + data[i].data[1];
                break;
            case 0x02:
                ls = 's';
                segmentAdd = (data[i].data[0] << 8) + data[i].data[1];
                break;
            case 0x01:
                return;
            case 0x03:
            case 0x05:
                break;
            default:
                return;
        }
    }
}

/**
 * Discards unwanted uint8_tacters from stdin so that the next input function has a clean stream
 */
void clearStdin(void) {
    while (getchar() != '\n');
}
// HexDisplay Uart.X.production.hex
