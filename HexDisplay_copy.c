#include <stdio.h>   //Khai báo thư viện
#include <stdlib.h>  //Khai báo thư viện
#include <string.h>  //Khai báo thư viện

#define LINE_SCREEN 25
#define MAX_MEMORY 0xFFFF  //  or 0xFFFFFFFF

const char *CMD = "HexDisplay";

typedef enum {
    ERROR = -1,
    OK = 0,
    OK_END_OF_FILE = 1,
    ERROR_OPEND_FILE = 2,
    ERROR_FORMAT_HEX = 3,
    ERROR_FORMAT_HEX_NOT_SUPPORT = 4
} ErrorCode_t;

typedef unsigned char uByte_t;
typedef unsigned int uInt_t;

ErrorCode_t errCode = 0;  // -1: error, 0 : Ok, ...
char gp_cmd[100];
uByte_t g_mem[MAX_MEMORY];  // 0000 0000 -> FFFF FFFF
char gp_hFileName[30];
FILE *g_fp;

ErrorCode_t check_cmd(char *p_cmd, char *p_fileName) {
    int getBool = 0;  // 0: false, 1: true
    int num = 0;
    int ret = strncmp(p_cmd, CMD, strlen(CMD));
    if (ret != 0) {
        printf("Error: command line incorrect\n");
        return -1;
    }
    for (int i = 0; i < 100; i++) {
        if (p_cmd[i] == ' ') {
            getBool = 1;
            continue;
        } else if (p_cmd[i] == '\0') {
            p_fileName[num] = '\0';
            // printf("|%c|, |%c|, |%c|, |%c|",  p_fileName[num-4], p_fileName[num-3], p_fileName[num-2], p_fileName[num-1]);
            if ((p_fileName[num - 1] != 'x') || (p_fileName[num - 2] != 'e' || p_fileName[num - 3] != 'h' || p_fileName[num - 4] != '.')) {
                printf("Error: syntax file name incoorect, ex:fileName.hex\n");
                p_fileName[0] = '\0';
                return ERROR;
            }
            return OK;
        }

        if (getBool == 1) {
            p_fileName[num] = p_cmd[i];
            num++;
            if (num >= 30) {
                printf("Error: name file over 30 characters\n");
                return ERROR;
            }
        }
    }
}

ErrorCode_t _check_sum(uByte_t *p_checkLine, uByte_t numCheck) {
    uByte_t temp = 0x00;

    // checkSum = Byte count + Address + Record type + Data + Checksum = 0xXX00; -> LSB = 00 OK

    for (int i = 0; i < numCheck; i++) {
        // printf("%2x|", p_checkLine[i]);
        temp += p_checkLine[i];
    }
    if (temp == 0x00) {
        return OK;
    } else {
        return ERROR;
    }
}

ErrorCode_t _write_memory(uByte_t *p_mem, uByte_t *p_hexLine, int numHexline) {
    int numMem = 0;  // 0000 0000 -> FFFF FFFF
    static int linAddr = 0;
    static int segAddr = 0;
    static int switAddr = 0;  // 0: linAddr, 1: segAddr

    if (numHexline < 5) {
        return ERROR_FORMAT_HEX;
    }
    switch (p_hexLine[3]) {
        case 0x00:
            if (p_hexLine[0] != (numHexline - 5)) {
                return ERROR_FORMAT_HEX;
            }
            if (switAddr == 0) {
                numMem = (linAddr << 16) + (p_hexLine[1] << 8) + p_hexLine[2];
                if (numMem <= MAX_MEMORY) {
                    for (int i = 0; i < p_hexLine[0]; i++) {
                        p_mem[numMem + i] = p_hexLine[4 + i];
                    }
                }
            } else if (switAddr == 1) {
                numMem = (segAddr << 4) + (p_hexLine[1] << 8) + p_hexLine[2];
                for (int i = 0; i < p_hexLine[0]; i++) {
                    p_mem[numMem + i] = p_hexLine[4 + i];
                }
            }
            break;
        case 0x01:
            return OK_END_OF_FILE;
            break;
        case 0x02:
            if ((p_hexLine[0] != 0x02) && (numHexline != 7)) {
                return ERROR_FORMAT_HEX;
            }
            segAddr = (p_hexLine[4] << 8) + p_hexLine[5];
            switAddr = 1;
            break;
        case 0x04:
            if ((p_hexLine[0] != 0x02) && (numHexline != 7)) {
                return ERROR_FORMAT_HEX;
            }
            linAddr = (p_hexLine[4] << 8) + p_hexLine[5];
            switAddr = 0;
            break;
        case 0x03:
        case 0x05:
            return ERROR_FORMAT_HEX_NOT_SUPPORT;
            break;
        default:
            return ERROR_FORMAT_HEX;
            break;
    }

    return OK;
}

ErrorCode_t check_file_hex(char *p_fileName, uByte_t *p_mem) {
    char c;
    int numLine = 0;
    uByte_t temp[300];  // max len data 1byte
    int numTemp = 0;
    char byteTemp[2];
    int numByte = 0;   // 0 4bits High, 1 4bits Low
    int stepTemp = 0;  // 0 init, 1: (:), 2: stop and new line
    ErrorCode_t errWrite;

    g_fp = fopen(p_fileName, "r");
    if (g_fp == NULL) {
        printf("Error: %s could not be opened\n", p_fileName);
        return ERROR_OPEND_FILE;
    }
    while ((c = getc(g_fp)) != EOF) {
        // :10001300AC12AD13AE10AF1112002F8E0E8F0F2244  => 1 -> 0x31, 0 -> 0x30 --> 0x01, 0x00 -->  0x10 + 0x00 = 0x10
        if (c == ':') {
            numLine++;
            stepTemp++;
            if (stepTemp == 1) {
                continue;
            }
        }

        if (stepTemp == 1) {
            if ((c >= '0') && (c <= '9')) {
                byteTemp[numByte] = c - 0x30;
                numByte++;
            } else if ((c >= 'A') && (c <= 'F')) {
                byteTemp[numByte] = c - 'A' + 0x0A;
                numByte++;
            } else if ((c >= 'a') && (c <= 'f')) {
                byteTemp[numByte] = c - 'a' + 0x0A;
                numByte++;
            } else if ((c == '\r') || (c == '\n')) {
                continue;
            } else {
                printf("Error: line %d of %s file hex error syntax\n", numLine, p_fileName);
                return ERROR_FORMAT_HEX;
            }
            if (numByte == 2) {
                numByte = 0;
                temp[numTemp] = (byteTemp[0] << 4) + byteTemp[1];
                // printf("%2x, %2x, %2x\n", temp[numTemp], byteTemp[0], byteTemp[1]);
                numTemp++;
            }
            continue;
        } else if (stepTemp == 2) {
            stepTemp = 1;
            // cộng tổng các byte lại , byte low = 0x00 ok
            if (_check_sum(temp, numTemp) == OK) {
                errWrite = _write_memory(p_mem, temp, numTemp);
                numTemp = 0;
                if (errWrite == OK_END_OF_FILE) {
                    // printf("END OF FILE \n");
                    return OK;
                } else if (errWrite != OK) {
                    printf("Error: line %d of %s file hex error syntax\n", numLine, p_fileName);
                    return ERROR_FORMAT_HEX;
                }
            } else {
                printf("Error: line %d of %s file hex error syntax\n", numLine, p_fileName);
                return ERROR_FORMAT_HEX;
            }
        }
    }
    if (_write_memory(p_mem, temp, 5) == OK_END_OF_FILE) {
        // printf("END OF FILE \n");
        return OK;
    } else {
        return ERROR_FORMAT_HEX;
    }
}

char _ascii_char(uByte_t c) {
    // printf("%c\n", c);
    if (c == 0xFF) {
        return ' ';
    } else if (c >= 0x20)  //&& (c <= 0x7E))
    {
        return c;
    } else {
        return '.';
    }
}

ErrorCode_t printf_hex_file(uByte_t *p_mem) {
    // LINE_SCREEN
    int numScreen = 0;
    int memStart = 0;
    uInt_t numMem = 0;
    char yesNo;

    while (1) {
        printf("%08x  %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
               numMem, p_mem[numMem], p_mem[numMem + 1], p_mem[numMem + 2], p_mem[numMem + 3], p_mem[numMem + 4], p_mem[numMem + 5], p_mem[numMem + 6], p_mem[numMem + 7],
               p_mem[numMem + 8], p_mem[numMem + 9], p_mem[numMem + 10], p_mem[numMem + 11], p_mem[numMem + 12], p_mem[numMem + 13], p_mem[numMem + 14], p_mem[numMem + 15],
               _ascii_char(p_mem[numMem]), _ascii_char(p_mem[numMem + 1]), _ascii_char(p_mem[numMem + 2]), _ascii_char(p_mem[numMem + 3]), _ascii_char(p_mem[numMem + 4]), _ascii_char(p_mem[numMem + 5]), _ascii_char(p_mem[numMem + 6]), _ascii_char(p_mem[numMem + 7]),
               _ascii_char(p_mem[numMem + 8]), _ascii_char(p_mem[numMem + 9]), _ascii_char(p_mem[numMem + 10]), _ascii_char(p_mem[numMem + 11]), _ascii_char(p_mem[numMem + 12]), _ascii_char(p_mem[numMem + 13]), _ascii_char(p_mem[numMem + 14]), _ascii_char(p_mem[numMem + 15]));
        if (numMem >= (MAX_MEMORY - 16)) {
            return OK_END_OF_FILE;
        }
        numMem += 16;
        numScreen++;
        if (numScreen == LINE_SCREEN) {
            printf("Do you want to continue printing file hex (Y/N) ");
            scanf(" %c", &yesNo);
            if ((yesNo == 'Y') || (yesNo == 'y')) {
                system("cls");
                numScreen = 0;
            } else {
                return OK;
            }
        }
    }
}

int main() {
    memset(g_mem, 0xFF, sizeof(g_mem));
    memset(gp_cmd, 0, sizeof(gp_cmd));

    system("cls");
    printf(">>");
    fgets(gp_cmd, 100, stdin);
    gp_cmd[strlen(gp_cmd) - 1] = '\0';
    // Check cmd
    errCode = check_cmd(gp_cmd, gp_hFileName);
    if (errCode != OK) {
        return ERROR;
    }
    // Check file error (checksum of each line, check format hexLine of each line, write memory buffer)
    errCode = check_file_hex(gp_hFileName, g_mem);
    if (errCode != OK) {
        return ERROR;
    }
    // Printf hex file
    errCode = printf_hex_file(g_mem);
    return OK;
}

// HexDisplay Uart.X.production.hex
// HexDisplay avr_uart.hex
