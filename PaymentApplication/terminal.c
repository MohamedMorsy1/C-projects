#define _CRT_SECURE_NO_WARNINGS
#include "terminal.h"
#include "app.h"
#include<stdio.h>
#include<string.h>
#include<time.h>

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{/*
    printf("Please enter transaction date in the format DD/MM/YYYY:\n");
    gets(termData->transactionDate);
    
    if ((strlen(termData->transactionDate) != 10) )
    {
        printf("Error: invalid transaction date\n");
        return WRONG_DATE;
    }
    else
    {
        printf("\nOK, transaction date is: %s \n\n", termData->transactionDate);
        return OK;
    }
    /**/
    //try to read computer time
    	time_t t = time(NULL);
		struct tm tm = *localtime(&t);
        sprintf(termData->transactionDate, "%02d/%02d/%02d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("\ntransaction date is: %s \n\n\n", termData->transactionDate);
        return OK;

}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
      //extracting substrings months and years
    uint8_t expMonth[2] , expYear[2], transMonth[2], transYear[2];
    expMonth[0] = cardData->cardExpirationDate[0]; expMonth[1] = cardData->cardExpirationDate[1];
    expYear[0] = cardData->cardExpirationDate[3];  expYear[1] = cardData->cardExpirationDate[4];
    
    transMonth[0] = termData->transactionDate[3]; transMonth[1] = termData->transactionDate[4];
    transYear[0] = termData->transactionDate[8];  transYear[1] = termData->transactionDate[9];
    //expiration year < transaction year
    if (atoi(expYear) < atoi(transYear))
    {
        printf("Error: EXPIRED_CARD\n\n");
        return EXPIRED_CARD;
    }
         //exp. year = trans. year && exp. month < trans. month
    else if (atoi(expYear) == atoi(transYear) && atoi(expMonth) < atoi(transMonth))
    {
        printf("Error: EXPIRED_CARD\n\n");
        return EXPIRED_CARD;
    }
    else
    {
         printf("OK, valid card \n\n");
         return OK;
    }
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{
    //apply luhn check
    
    return OK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("Please enter transaction amount:\n");
    scanf("%f", &termData->transAmount);

    if (termData->transAmount <= 0)
    {
        printf("Error: invalid transaction amount\n");
        return INVALID_AMOUNT;
    }
    else
    {
        printf("\ntransaction amount is: %f \n\n", termData->transAmount);
        return OK;
    }

}


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
    if (termData->transAmount > termData->maxTransAmount)
    {
        printf("error: the requested transction amount exceeds tha maximum amount!\n\n");
        return EXCEED_MAX_AMOUNT;
    }
        
    else
    {
        printf("OK: allowed amount\n\n");
        return OK;
    }
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
    printf("Please enter max allowed amount:\n");
    scanf("%f", &termData->maxTransAmount);
    
   // termData->maxTransAmount = maxAmount;

    if (termData->maxTransAmount <= 0)
    {
        printf("Error: invalid max amount\n");
        return INVALID_MAX_AMOUNT;
    }
    else
    {
        printf("\OK, max amount is: %f \n\n", termData->maxTransAmount);
        return OK;
    }
}


