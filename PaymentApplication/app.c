#include"app.h" 
#include"server.h"
extern struct ST_transaction_t transaction[255];
extern struct ST_cardData_t NewCard;
extern struct ST_terminalData_t NewTermData;



void appStart(void)
{

	enum EN_cardError_t result;	
	//card module
						result = getCardHolderName(&NewCard);
	if (result == OK)	result = getCardExpiryDate(&NewCard);
	if (result == OK)	result = getCardPAN(&NewCard);
	//terminal
	if (result == OK)	result = getTransactionDate(&NewTermData);
	if (result == OK)	result = isCardExpired(&NewCard, &NewTermData);
	if (result == OK)	result = isValidCardPAN(&NewCard);
	if (result == OK)	result = getTransactionAmount(&NewTermData);
	if (result == OK)	result = setMaxAmount(&NewTermData);
	if (result == OK)	result = isBelowMaxAmount(&NewTermData);
	//server

	if (result == OK)   result = recieveTransactionData(&transaction);
	

}