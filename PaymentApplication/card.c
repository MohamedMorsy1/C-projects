
#include "card.h"


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    printf("Please enter card holder name:\n");
    gets(cardData->cardHolderName);
    int strlength = strlen(cardData->cardHolderName);
    EN_cardError_t result = WRONG_NAME;

    if ((strlength < 20) || (strlength > 24))
    {
          
        printf("Error: invalid holder name (must be 20-24 characters)\n");
        return result;
    }
    else
    {

        for (int i = 0; i < strlength; i++)
        {
            if (!isalpha(cardData->cardHolderName[i]) )  //check if character is not alphabetic
            {
                if (cardData->cardHolderName[i] != ' ')  //check if it is not 'space'
                {
                    printf("Error: invalid holder name (only letters and spaces!)\n");
                    result = WRONG_NAME;
                    break;
                }

            }
            else                                          //the character is alpha or space
            {
                result = OK;
            }

        }
        if(result == OK)printf("\nOK, holder name is: %s \n\n\n", cardData->cardHolderName);
        return result;
    }
}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    printf("Please enter card expiry date in the format [MM/YY]:\n");
    gets(cardData->cardExpirationDate);
    // check if month > 12  or  wrong length  or  3rd digit is not '/'
    //atoi will take only the first group of integers (2 digits, month)
    if ((atoi(cardData->cardExpirationDate)>12 || strlen(cardData->cardExpirationDate) != 5) || (cardData->cardExpirationDate[2] != '/'))
    {
        printf("Error: invalid expiration date\n");
        return WRONG_EXP_DATE;
    }
    else
    {
        printf("\nOK, expiration date is: %s \n\n\n", cardData->cardExpirationDate);
        return OK;
    }
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    printf("Please enter the card's Primary Account Number:\n");
    gets(cardData->primaryAccountNumber);
    if ((strlen(cardData->primaryAccountNumber) > 19) || (strlen(cardData->primaryAccountNumber) < 16))
    {
        printf("Error: invalid PAN (must be 16-19 digits)\n");
        return WRONG_PAN;
    }
    else
    {
        int i = 0;
        while ( i < strlen(cardData->primaryAccountNumber))
        {
            if (cardData->primaryAccountNumber[i] < 48 || cardData->primaryAccountNumber[i] > 57)
            {
                printf("Error: invalid PAN (must be digits only)\n");
                return WRONG_PAN;
                break;
            }
            i++;

        }
        printf("\nOK, your PAN is: %s \n\n", cardData->primaryAccountNumber);
        return OK;
    }
}