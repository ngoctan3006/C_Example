/******************************************************************************
*                                   Includes
******************************************************************************/
#include <stdio.h>
#include <string.h>

#include "parse.h"

/******************************************************************************
*                                   Variables
******************************************************************************/
uint8_t termination_record = 0;
uint32_t lineCount = 0;
uint32_t actual_lineCount = 0;


/******************************************************************************
*                                   Prototype
******************************************************************************/
/* Function to convert number from hexa to decimal */
static uint8_t convertHex(uint8_t first, uint8_t second);


/******************************************************************************
*                                   Code
******************************************************************************/
/* Function to convert number from hexa to decimal */
static uint8_t convertHex(uint8_t first, uint8_t second)
{
    if ((first >= '0') && (first <= '9'))
    {
        first = first - '0';
    }
    else
    {
        first = first - 'A' + 10;
    }

    if ((second >= '0') && (second <= '9'))
    {
        second = second - '0';
    }
    else
    {
        second = second - 'A' + 10;
    }

    return ((first << 4) | second);
}

/* Function to check the first character is a letter "S" */
Error check_S(uint8_t *lineChar)
{
    Error ret_val = RETURN_OK;

    if (lineChar[0] != 'S')
    {
        ret_val = RETURN_S_FAIL;
    }
    else
    {
        /* Do nothing */
    }

    return ret_val;
}

/* Function to check Type is single numeric digit "0" to "9" */
Error check_Type(uint8_t *lineChar)
{
    Error ret_val = RETURN_OK;

    if ((lineChar[1] < '0') || (lineChar[1] > '9'))
    {
        ret_val = RETURN_TYPE_FAIL;
    }
    else
    {
        /* If it is S1/S2/S3 then increase the number of lines counter variable */
        if ((lineChar[1] == '1') || (lineChar[1] == '2') || (lineChar[1] == '3'))
        {
            actual_lineCount++;
        }
        /* If it is S7/S8/S9 means termination record */
        else if ((lineChar[1] == '7') || (lineChar[1] == '8') || (lineChar[1] == '9'))
        {
            termination_record = 1;
        }
        /* If it's S5 or S6 read lineCount */
        else if ((lineChar[1] == '5'))
        {

            lineCount = (convertHex(lineChar[4], lineChar[5]) << 8) |\
                        (convertHex(lineChar[6], lineChar[7]));
        }
        else if ((lineChar[1] == 6))
        {
            lineCount = (convertHex(lineChar[4], lineChar[5]) << 16) |\
                        (convertHex(lineChar[6], lineChar[7]) << 8) |\
                        (convertHex(lineChar[8], lineChar[9]));
        }
        else
        {

            /* Do nothing */
        }
    }
    
    return ret_val;
}

/* Function to check the character in file text is hexa */
Error check_Hexa(uint8_t *lineChar)
{
    Error ret_val = RETURN_OK;
    
    uint8_t for_cnt = 0;

    /* Check from the 2nd character to the last character in the row */
    /* Minus 1 because the input line includes \0 at the same time */
    /* Except for the condition: (0 <= Char <= 9 || A <= Char <= F), return FAIL */
    
    for (for_cnt = 2; for_cnt < strlen(lineChar) - 1; for_cnt++)
    {
        if (((lineChar[for_cnt] >= '0') && (lineChar[for_cnt] <= '9')) ||\
            ((lineChar[for_cnt] >= 'A') && (lineChar[for_cnt] <= 'F')))
        {
            /* Do nothing */
        }
        else
        {
            ret_val = RETURN_HEXA_FAIL;
            for_cnt = strlen(lineChar);
        }
    }

    return ret_val;
}

/* Function to check Byte Count */
Error check_ByteCount(uint8_t *lineChar)
{
    Error ret_val = RETURN_OK;

    uint8_t byteCount = 0;
    uint8_t actual_byteCount = 0;

    /* Read & convert bytecount */
    byteCount = convertHex(lineChar[2], lineChar[3]);

    /* (-5) is strlen of ((-1)S, (-1)Type,(-2)Checksum, (-1)'\0') */
    /* (/2) because 2 characters is 1 byte */
    actual_byteCount = (strlen(lineChar) - 5) / 2;

    if (actual_byteCount != byteCount)
    {
        ret_val = RETURN_BYTE_COUNT_FAIL;
    }
    else
    {
        /* Do nothing */
    }

    return ret_val;
}

/* Function to check Checksum */
Error check_checkSum(uint8_t *lineChar)
{
    Error ret_Val = RETURN_OK;

    uint8_t line_length = 0;
    uint8_t checkSum = 0;
    uint8_t cnt = 0;
    uint32_t sum = 0;

    line_length = strlen(lineChar) - 1;

    /* Read checkSum from record by converting the last 2 characters */
    checkSum = convertHex(lineChar[line_length - 2], lineChar[line_length - 1]);

    /* Convert every 2 characters to 1 byte and add them together */
    /* Starting from ByteCount so (cnt = 2) */
    /* Do not count Checksum so (< line length -2) */
    for (cnt = 2; cnt < line_length - 2; cnt += 2)
    {
        sum += convertHex(lineChar[cnt], lineChar[cnt + 1]);
    }

    /* Reverse the bit and get the least signed byte as the formula */
    sum = ~sum;
    sum &= 0x00FF;

    if (sum != checkSum)
    {
        ret_Val = RETURN_CHECKSUM_FAIL;
    }
    else
    {
        /* Do nothing */
    }

    return ret_Val;
}

/* Function to printf Data & Address */
void printAddressData(uint8_t *lineChar, FILE *output)
{
    uint8_t cnt = 0;

    /* If it is S0 S1 S5 S9, the address has 4 characters, the rest is data */
    /* If it's S2 S6 S9 then the address has 6 characters */
    /* If it's S3 S7 then the address has 8 characters */

    /* Print each character from a string */
    
    if ((lineChar[1] = '0') || (lineChar[1] = '1') ||\
        (lineChar[1] = '5') || (lineChar[1] = '9'))
    {

        for (cnt = 4; cnt < 8; cnt++)
        {
            fprintf(output, "%c", lineChar[cnt]);
        }
        /* Printf space between address and data */
        fprintf(output, " ");
        for (cnt = 8; cnt < strlen(lineChar) - 3; cnt++)
        {
            fprintf(output, "%c", lineChar[cnt]);
        }
        fprintf(output, "\n");
    }
    else if ((lineChar[1] = '2') || (lineChar[1] = '6') || (lineChar[1] = '8'))
    {
        for (cnt = 4; cnt < 10; cnt++)
        {
            fprintf(output, "%c", lineChar[cnt]);
        }
        fprintf(output, " ");

        for (cnt = 10; cnt < strlen(lineChar) - 3; cnt++)
        {
            fprintf(output, "%c", lineChar[cnt]);
        }
        fprintf(output, "\n");
    }
    else if ((lineChar[1] = '3') || (lineChar[1] = '7'))
    {
        for (cnt = 4; cnt < 12; cnt++)
        {
            fprintf(output, "%c", lineChar[cnt]);
        }
        fprintf(output, " ");

        for (cnt = 12; cnt < strlen(lineChar) - 3; cnt++)
        {
            fprintf(output, "%c", lineChar[cnt]);
        }
        fprintf(output, "\n");
    }
    else
    {
        /* Do nothing */
    }
}

/******************************************************************************
*                                   End
******************************************************************************/
