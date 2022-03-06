#pragma once
#include <string>
#include <time.h>

#include "DBAccess.h"

namespace EarnDB {
	using namespace std;
	
	const int VARCHARLEN = 45;	//length of varchars, so we don't overwrite in database
	const int ZIPLEN = 6;		//length of zip codes, since they are always the same

	//enummeration for different types of DBObjects
	enum DBOType {CLIENT, ACCOUNT, TRANSACTION };

	class DBObject : public DBAccessInterface {
		DBOType objectType;

	public:
		DBObject();	//empty constructor
		DBObject(const DBObject& copyObject) : DBAccessInterface((const DBAccessInterface&) copyObject);	//constructor casts input to parent type to send up to it's constructor
		DBObject(DBOType initalizeType, int objectID) :DBAccessInterface((const int) objectID);	//parametrized constructor also passes objectID up

		DBOType getDBType();
		virtual string displayInfo() = 0;
	};

	struct DBClientInfo {
			char firstName[VARCHARLEN];
			char lastName[VARCHARLEN];
			char email[VARCHARLEN];
			char phoneNumber[VARCHARLEN];
			char street[VARCHARLEN];
			char city[VARCHARLEN];
			char province[VARCHARLEN];
			char zipcode[ZIPLEN];
		};

	class DBClient :DBObject {
		DBClientInfo clientInfo;

	public:
		DBClient();
		DBClient(const DBClient& copyClient): DBObject((const DBObject&)copyClient);
		DBClient(int inputobjectID, char inputFirst[VARCHARLEN], char inputLast[VARCHARLEN], char inputEmail[VARCHARLEN], char inputPhone[VARCHARLEN], char inputStreet[VARCHARLEN], char inputCity[VARCHARLEN], char inputProvince[VARCHARLEN], char inputZip[ZIPLEN]) :DBObject(CLIENT, inputobjectID);
		
		/*
		Inherited functions from DBObject & Above
		*/

		string displayInfo();
		string getLogData();
		string addInfoToDB();
		string modifyInfoInDB();
		string deleteInfoInDB();
	};

	//enummeration for Account types
	enum DBAType{CHEQUINGS, SAVINGS};

	struct DBAccountInfo {
		int clientID;
		DBAType accountType;
		double accountBalance;
	};

	class DBAccount : public DBObject {
		DBAccountInfo accountInfo;

	public:
		DBAccount();
		DBAccount(const DBAccount& copyAccount): DBObject((DBObject&) copyAccount);
		DBAccount(int inputObjectID, int inputClientID, DBAType inputAccountType, double inputBalance) : DBObject(ACCOUNT, inputObjectID);

		DBAType getAccountType();

		/*
		Inherited functions from DBObject & Above
		*/

		string displayInfo();
		string getLogData();
		string addInfoToDB();
		string modifyInfoInDB();
		string deleteInfoInDB();
	};

	//enummeration for transaction types
	enum DBTType{ETRANSFER, CHEQUE, WITHDRAW, ACCOUNTTRANSFER};

	struct DBTransactionInfo {
			int accountID;
			DBTType transactionType;
			char* timeOfTransaction;
			double previousBalance;
			double newBalance;
			int secondaryAccount;
		};

	class DBTransaction : public DBObject {
		DBTransactionInfo transactionInfo;

	public:
		DBTransaction();
		DBTransaction(DBTransaction& copyTransaction) :DBObject((DBObject&)copyTransaction);
		DBTransaction(int inputObjectID, int inputAccountID, DBTType inputTransactionType, char* timeOfTransaction, double inputPreviousBalance, double inputNewBalance, int inputSecondaryAccount) :DBObject(TRANSACTION, inputObjectID);

		DBTType getTransactionType();

		/*
		Inherited functions from DBObject & Above
		*/

		string displayInfo();
		string getLogData();
		string addInfoToDB();
		string modifyInfoInDB();
		string deleteInfoInDB();
	};
}