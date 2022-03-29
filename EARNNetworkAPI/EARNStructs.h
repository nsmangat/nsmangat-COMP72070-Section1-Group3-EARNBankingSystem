#pragma once

namespace EarnStructs  {
	//Macros for EarnDB objects (length of strings...
	
	//Length of varchars, so we don't overwrite in database
	const int VARCHARLEN = 45;
	
	//Length of zip codes, since they are always the same
	const int ZIPLEN = 6;

	//Enummeration for different types of Objects
	//CREATEACCOUNT is to know we sending 2 structs
	//STARTUPACCOUNTINFO = server response after login so client has their savings and chequings account   *we not using this anymore, this is not ACCOUNT
	enum ObjectType { OBJECTNULL, CLIENT, CREDENTIALS, ACCOUNT, TRANSACTION, CREATEACCOUNT, STARTUPACCOUNTINFO, FORGETPASSWORD, LOGOFF, BIGFILETRANSFER, SHUTDOWN };

	//Structure for Client object's info, to ease serialization
	struct ClientInfo {
		char firstName[VARCHARLEN];
		char lastName[VARCHARLEN];
		char email[VARCHARLEN];
		char phoneNumber[VARCHARLEN];
		char street[VARCHARLEN];
		char city[VARCHARLEN];
		char province[VARCHARLEN];
		char zipcode[ZIPLEN];
	};

	//Structure for Credential object's info, to ease validation
	struct CredentialInfo {
		int clientID;
		char username[VARCHARLEN];
		int usernumber;
		char userPasswordHash[VARCHARLEN];
	};

	//Enummeration for Account types
	enum AccountType { ACCOUNTNULL, CHEQUINGS, SAVINGS };

	//Structure for Account object's info, to ease serialization
	struct AccountInfo {
		int clientID;
		AccountType accountType;
		double accountBalance;
	};

	//Enummeration for transaction types
	enum TransactionType { TRANSACTIONNULL, ETRANSFER, CHEQUE, ACCOUNTTRANSFER };

	//Structure for Transaction object's info, to ease serialization
	struct TransactionInfo {
		int accountID;
		TransactionType transactionType;
		char transactionTime[VARCHARLEN];
		double previousBalance;
		double newBalance;
		int secondaryAccount;
	};
}