#ifndef _PARSE_H_
#define _PARSE_H_


/******************************************************************************
*                                   Includes
******************************************************************************/
#include <stdint.h>


/******************************************************************************
*                                   Definitions
******************************************************************************/
#define MAX_LENG_LINE 80U


/******************************************************************************
*                                   Variables
******************************************************************************/
extern uint8_t termination_record;
extern uint32_t lineCount;
extern uint32_t actual_lineCount;


/******************************************************************************
*                                   Typedef
******************************************************************************/
typedef enum returnError
{
    RETURN_OK = 0,

    RETURN_HEXA_FAIL,

    RETURN_S_FAIL,

    RETURN_TYPE_FAIL,

    RETURN_CHECKSUM_FAIL,

    RETURN_BYTE_COUNT_FAIL,

    RETURN_TERMINATE,

} Error;


/******************************************************************************
*                                   API
******************************************************************************/
/* Function to check the first character is a letter "S" */
Error check_S(uint8_t *lineChar);

/* Function to check Type is single numeric digit "0" to "9" */
Error check_Type(uint8_t *lineChar);

/* Function to check the character in file text is hexa */
Error check_Hexa(uint8_t *lineChar);

/* Function to check Byte Count */
Error check_ByteCount(uint8_t *lineChar);

/* Function to check Checksum */
Error check_checkSum(uint8_t *lineChar);

/* Function to printf Data & Address */
void printAddressData(uint8_t *lineChar, FILE *output);

#endif /* _PARSE_H_ */

/******************************************************************************
*                                   End
******************************************************************************/
