#pragma once
#include <string>
#include <time.h>

#include "DBAccess.h"

namespace EarnDB {
	using namespace std;
	
	//macros for EarnDB...

	//length of varchars, so we don't overwrite in database
	const int VARCHARLEN = 45;
	//length of zip codes, since they are always the same
	const int ZIPLEN = 6;		

	//enummeration for different types of DBObjects
	enum DBOType {DBONULL, CLIENT, ACCOUNT, TRANSACTION };

	//DBObject Interface / abstract class, used by client, account, etc...
	class DBObject : public DBAccessInterface {
		DBOType objectType;

	public:
		//Constructors...

		//default constructor
		DBObject();

		//copy constructor
		DBObject(const DBObject& copyObject);

		//parametrized constructor
		DBObject(DBOType initalizeType, int objectID);

		//get function for DBOType
		DBOType getDBOType();

		//set function for DBType
		void setDBOType(DBOType inputType);

		//display Info about Object to terminal (debugging purposes).
		virtual string displayInfo() = 0;
	};

	//struct for the DBClient so it can be easier to serialize & deserialize using networkAPI
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

	//class for client in the database, with all the overloaded abstract functions for DBAccess & Logging
	class DBClient :DBObject {
		DBClientInfo clientInfo;

	public:
		//Constructors

		//default constructor
		DBClient();

		//struct constructor, for use after deserializing
		DBClient(const DBClientInfo copyInfo);

		//copy constructor
		DBClient(const DBClient& copyClient);

		//parametrized constructor
		DBClient(int inputobjectID, char inputFirst[VARCHARLEN], char inputLast[VARCHARLEN], char inputEmail[VARCHARLEN], char inputPhone[VARCHARLEN], char inputStreet[VARCHARLEN], char inputCity[VARCHARLEN], char inputProvince[VARCHARLEN], char inputZip[ZIPLEN]);

		//Get functions

		//get first name as C string
		const char* getFirstName(int& lenOfArray);
		//get first name as Cpp string
		string getFirstName();
		
		//get last name as C string
		const char* getLastName(int& lenOfArray);
		//get last name as Cpp string
		string getLastName();

		//get email as C string
		const char* getEmail(int& lenOfArray);
		//get email as Cpp string
		string getEmail();

		//get phone number as C string
		const char* getPhoneNum(int& lenOfArray);
		//get phone number as Cpp string
		string getPhoneNum();
		
		//get street as C string
		const char* getStreet(int& lenOfArray);
		//get street as Cpp string
		string getStreet();

		//get city as C string
		const char* getCity(int& lenOfArray);
		//get city as Cpp string
		string getCity();

		//get Province as C string
		const char* getProvince(int& lenOfArray);
		//get province as Cpp string
		string getProvince();

		//get zip code as C string
		const char* getZip(int& lenOfArray);
		//get zip code as Cpp string
		string getZip();

		//Set functions

		//set first name from C string
		void setFirstName(char newFirst[VARCHARLEN]);
		//set first name from Cpp string
		void setFirstName(string newFirst);

		//set last name from C string
		void setLastName(char newLast[VARCHARLEN]);
		//set last name from Cpp string
		void setLastName(string newLast);

		//set email from C string
		void setEmail(char newEmail[VARCHARLEN]);
		//set email from Cpp string
		void setEmail(string newEmail);

		//set phone number from C string
		void setPhoneNum(char newPhone[VARCHARLEN]);
		//set phone number from Cpp string
		void setPhoneNum(string newPhone);

		//set street from C string
		void setStreet(char newStreet[VARCHARLEN]);
		//set street from Cpp string
		void setStreet(string newStreet);

		//set city from C string
		void setCity(char newCity[VARCHARLEN]);
		//set city from Cpp string
		void setCity(string newCity);

		//set province from C string
		void setProvince(char newProvince[VARCHARLEN]);
		//set province from Cpp string
		void setProvince(string newProvince);

		//set zip code from C string
		void setZip(char newZip[ZIPLEN]);
		//set zip code from Cpp string
		void setZip(string newZip);

		//Inherited functions

		string displayInfo();
		//string getLogData();
		string addInfoToDB();
		string modifyInfoInDB();
		string deleteInfoInDB();
	};

	//enummeration for Account types
	enum DBAType{DBANULL, CHEQUINGS, SAVINGS};

	struct DBAccountInfo {
		int clientID;
		DBAType accountType;
		double accountBalance;
	};

	class DBAccount : public DBObject {
		DBAccountInfo accountInfo;

	public:
		//Constructors
		
		//default constructor
		DBAccount();

		//struct constructor, for use after deserializing
		DBAccount(const DBAccountInfo copyInfo);

		//copy constructor
		DBAccount(const DBAccount& copyAccount);

		//parametrized constructor
		DBAccount(int inputObjectID, int inputClientID, DBAType inputAccountType, double inputBalance);

		//Get functions

		//get account type...
		DBAType getAccountType();

		//get client ID for connected client
		int getAccountClientID();

		//get balance for this account
		double getAccountBalance();

		//get accountInfo struct, used in serializing...
		DBAccountInfo getAccountInfo();

		//Set functions
		
		//set account type, in case user changes account to a different one...
		void setAccountType(DBAType newType);

		//set client ID, in case account is transferred for some reason?
		void setAccountClientID(int newClientID);

		//set account balance, due to a transaction etc...
		void setBalance(double newBalance);

		//set account info, used in case everything is changed at once
		void setAccountInfo(DBAccountInfo newAccountInfo);

		//Inherited functions

		string displayInfo();
		//string getLogData();
		string addInfoToDB();
		string modifyInfoInDB();
		string deleteInfoInDB();
	};

	//enummeration for transaction types
	enum DBTType{DBTNULL, ETRANSFER, CHEQUE, WITHDRAW, ACCOUNTTRANSFER};

	struct DBTransactionInfo {
			int accountID;
			DBTType transactionType;
			char* transactionTime;
			double previousBalance;
			double newBalance;
			int secondaryAccount;
		};

	class DBTransaction : public DBObject {
		DBTransactionInfo transactionInfo;

	public:
		//Constructors

		//default constructor
		DBTransaction();

		//struct constructor, for use after deserializing
		DBTransaction(const DBTransactionInfo copyInfo);

		//copy constructor
		DBTransaction(DBTransaction& copyTransaction);

		//parametrized constructor
		DBTransaction(int inputObjectID, int inputAccountID, DBTType inputTransactionType, char* transactionTime, double inputPreviousBalance, double inputNewBalance, int inputSecondaryAccount);

		//Get functions

		//get account ID for connected account
		int getTransactionAccountID();

		//get transaction type...
		DBTType getTransactionType();

		//get time of transaction
		char* getTransactionTime();

		//get balance before transaction
		double getTransactionPreviousBal();

		//get balance after transaction
		double getTransactionNewBal();

		//get other account connected (relationship is implied through transaction type...)
		int getTransactionSecondaryAcc();

		//Set functions
		
		//set account ID for connected account
		void setTransactionAccountID(int newAccountID);

		//set transaction type...
		void setTransactionType(DBTType newTransactionType);

		//set time of transaction
		void setTransactionTime(char* newTransactionTime);

		//set balance before transaction
		void setTransactionPreviousBal(double newTransactionPB);

		//set balance after transaction
		void setTransactionNewBal(double newTransactionNB);

		//set other account connected (relationship is implied through transaction type...)
		void setTransactionSecondaryAcc(int newTransactionSA);

		//Inherited functions

		string displayInfo();
		//string getLogData();
		string addInfoToDB();
		string modifyInfoInDB();
		string deleteInfoInDB();
	};
}