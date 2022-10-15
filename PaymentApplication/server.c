#include"server.h"
#include"card.h"

struct ST_accountsDB_t accountsDB[255] = {  {5000, "12345678901234567" ,BLOCKED},
										    {1000,"123456789012345678" , RUNNING},
										    {1000,"123456789012345679", RUNNING},
											{2000,"11111111111111111", RUNNING},
											{2000,"22222222222222222", BLOCKED},
										  };

struct ST_transaction_t transaction[255] = { 0 };  


	
extern struct ST_cardData_t NewCard;
extern struct ST_terminalData_t NewTermData;

EN_transState_t state;

int targetAccountIndex = 0;



EN_transState_t  recieveTransactionData(ST_transaction_t* transData)
{
	

	if (isValidAccount(&NewCard) != OK)
	{
		printf("\nError: DECLINED_STOLEN_CARD\n");
		state= DECLINED_STOLEN_CARD;
	}
		
	 else if (isAmountAvailable(&NewTermData) != OK)
	{
		printf("\nError: DECLINED_INSUFFECIENT_FUND\n");
		state= DECLINED_INSUFFECIENT_FUND;
	}
	else
	{
		printf("\nOK, APPROVED\n");
		printf("\nbalance: %f", accountsDB[targetAccountIndex].balance);
		accountsDB[targetAccountIndex].balance -= NewTermData.transAmount;      // updating balance
		printf("\nnew balance: %f\n", accountsDB[targetAccountIndex].balance);
		state = APPROVED;
	}
	
	saveTransaction(&transData[targetAccountIndex]);
	return state;
}

 

EN_serverError_t isValidAccount(ST_cardData_t *cardData)
{
	
	EN_transState_t result;

	for (int i=0;i < 255;i++)
	{

		if (strlen(accountsDB[i].primaryAccountNumber) > 0 && strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber) == 0)
		{
			
			targetAccountIndex = i;
			
			if (accountsDB[i].accountState == BLOCKED) result = DECLINED_STOLEN_CARD;
			else result = OK;
			break;
		}
		else result = DECLINED_STOLEN_CARD;
	
	}
 

	return result;


}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData)
{
	if (termData->transAmount > accountsDB[targetAccountIndex].balance)
	{
		//printf("\nError: DECLINED_INSUFFECIENT_FUND\n");
		return LOW_BALANCE;
	}
	else 
	{
		printf("\nOK, SUFFECIENT_FUND\n");
		return OK;
	}
}


EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
	transData->cardHolderData = NewCard;
	transData->terminalData = NewTermData; 
	transData->transState = state;
	transData->transactionSequenceNumber++;

//test printing saved data
	printf("\nholde name: %s\n\n", transData->cardHolderData.cardHolderName);
	printf("expiry date: %s\n", transData->cardHolderData.cardExpirationDate);
	printf("PAN: %s\n", transData->cardHolderData.primaryAccountNumber);
	printf("amount: %f\n", transData->terminalData.transAmount);
	printf("state: %d\n", transData->transState);
	printf("sequence number: %u\n\n\n", transData->transactionSequenceNumber);
	return OK;
}