/******************************************************************************
*                                   Includes
******************************************************************************/
#include <stdio.h>

#include "parse.h"


/******************************************************************************
*                                   Definitions
******************************************************************************/
#define FILE_SREC "Srec.txt"
#define FILE_OUT "Output.txt"


/******************************************************************************
*                                   Code
******************************************************************************/
uint8_t main()
{
    uint32_t line_number = 0;
    int8_t lineChar[MAX_LENG_LINE] = {0};
    
    FILE *input = fopen(FILE_SREC, "r");
    if (input == NULL)
    {
        printf("Can't open file, please check again.");
    }
    else
    {
        /* Do nothing */
    }

    FILE *output = fopen(FILE_OUT, "w+");
    if (output == NULL)
    {
        printf("Can't open file, please check again.");
    }
    else
    {
        /* Do nothing */
    }

    while (fgets(lineChar, MAX_LENG_LINE, input))
    {
        line_number++;

        fprintf(output, "%u ", line_number);

        if (check_S(lineChar) == RETURN_OK)
        {
            if (check_Type(lineChar) == RETURN_OK)
            {
                if (check_Hexa(lineChar) == RETURN_OK)
                {
                    if (check_ByteCount(lineChar) == RETURN_OK)
                    {
                        if (check_checkSum(lineChar) == RETURN_OK)
                        {
                            printAddressData(lineChar, output);
                        }
                        else
                        {
                            fprintf(output, "Check checkSum fail\n");
                        }
                    }
                    else
                    {
                        fprintf(output, "Check Bytecount fail\n");
                    }
                }
                else
                {
                    fprintf(output, "Check Hexa fail\n");
                }
            }
            else
            {
                fprintf(output, "Check Type fail\n");
            }
        }
        else
        {
            fprintf(output, "Check S fail\n");
        }
    }

    /* Check Terminate */
    if (!termination_record)
    {
        fprintf(output, "Not found Termination record\n");
    }
    else
    {
        /* Do nothing */
    }

    /* Check Line_Count */
    if (actual_lineCount != lineCount)
    {
        fprintf(output, "Line Count fail\n");
    }
    else
    {
        /* Do nothing */
    }
    
    fclose(input);
    fclose(output);
    
    return 0;
}

/******************************************************************************
*                                   End
******************************************************************************/
