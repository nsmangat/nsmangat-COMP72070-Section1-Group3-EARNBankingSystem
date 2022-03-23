#pragma once

namespace EarnStructs  {
	//Macros for EarnDB objects (length of strings...
	
	//Length of varchars, so we don't overwrite in database
	const int VARCHARLEN = 45;
	
	//Length of zip codes, since they are always the same
	const int ZIPLEN = 6;

	//Enummeration for different types of Objects
	enum ObjectType { OBJECTNULL, CLIENT, CREDENTIALS, ACCOUNT, TRANSACTION };

	//Converts enum to string depending on type to assist logging
	inline const std::string EnumToString(ObjectType inputType)
	{
		switch (inputType)
		{
		case OBJECTNULL:	return "OBJECTNULL";
		case CLIENT:		return "CLIENT";
		case CREDENTIALS:	return "CREDENTIALS";
		case ACCOUNT:		return "ACCOUNT";
		case TRANSACTION:	return "TRANSACTION";
		default:			return "[Unknown Type]";
		}
	};

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

	//Converts enum to string depending on type
	inline const std::string EnumToString(AccountType inputType)
	{
		switch (inputType)
		{
		case ACCOUNTNULL:	return "ACCOUNTNULL";
		case CHEQUINGS:		return "CHEQUINGS";
		case SAVINGS:		return "SAVINGS";
		default:			return "[Unknown Type]";
		}
	};

	//Structure for Account object's info, to ease serialization
	struct AccountInfo {
		int clientID;
		AccountType accountType;
		double accountBalance;
	};

	//Enummeration for transaction types
	enum TransactionType { TRANSACTIONNULL, ETRANSFER, CHEQUE, WITHDRAW, ACCOUNTTRANSFER };

	//Converts enum to string depending on type
	inline const std::string EnumToString(TransactionType inputType)
	{
		switch (inputType)
		{
		case TRANSACTIONNULL:	return "TRANSACTIONNULL";
		case ETRANSFER:			return "ETRANSFER";
		case CHEQUE:			return "CHEQUE";
		case WITHDRAW:			return "WITHDRAW";
		case ACCOUNTTRANSFER:	return "ACCOUNTTRANSFER";
		default:				return "[Unknown Type]";
		}
	};

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