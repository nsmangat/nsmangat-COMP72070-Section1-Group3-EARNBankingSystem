#pragma once
#include "DBAccess.h"

#include <string>
#include <time.h>

namespace EarnDB  {
	//Macros for EarnDB objects (length of strings...
	
	//Length of varchars, so we don't overwrite in database
	const int VARCHARLEN = 45;
	
	//Length of zip codes, since they are always the same
	const int ZIPLEN = 6;

	//Enummeration for different types of DBObjects
	enum DBOType { DBONULL, CLIENT, CREDENTIALS, ACCOUNT, TRANSACTION };

	//DBObject Interface / abstract class, used by client, account, etc...
	class DBObject :public DBAccessInterface {
		DBOType objectType;

	public:
		//Constructors...

		//Default constructor
		DBObject();

		//Copy constructor
		DBObject(const DBObject& copyObject);

		//Parametrized constructor
		DBObject(DBOType initalizeType, int objectID);

		//Get function for DBOType
		DBOType getDBOType();

		//Set function for DBType
		void setDBOType(DBOType inputType);

		//Display Info about Object to terminal (debugging purposes).
		virtual std::string displayInfo() = 0;
	};

	//Structure for DBClient object's info, to ease serialization
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

	//DBClient object class
	class DBClient :public DBObject {
		DBClientInfo clientInfo;

	public:
		//Constructors

		//Default constructor
		DBClient();

		//Struct constructor, for use after deserializing
		DBClient(const DBClientInfo copyInfo);

		//Copy constructor
		DBClient(const DBClient& copyClient);

		//Parametrized constructor
		DBClient(int inputObjectID, char inputFirst[VARCHARLEN], char inputLast[VARCHARLEN], char inputEmail[VARCHARLEN], char inputPhone[VARCHARLEN], char inputStreet[VARCHARLEN], char inputCity[VARCHARLEN], char inputProvince[VARCHARLEN], char inputZip[ZIPLEN]);

		//Get functions

		//Get first name as C string
		const char* getFirstName(int& lenOfArray);
		//Get first name as Cpp string
		std::string getFirstName();

		//Get last name as C string
		const char* getLastName(int& lenOfArray);
		//Get last name as Cpp string
		std::string getLastName();

		//Get email as C string
		const char* getEmail(int& lenOfArray);
		//Get email as Cpp string
		std::string getEmail();

		//Get phone number as C string
		const char* getPhoneNum(int& lenOfArray);
		//Get phone number as Cpp string
		std::string getPhoneNum();

		//Get street as C string
		const char* getStreet(int& lenOfArray);
		//Get street as Cpp string
		std::string getStreet();

		//Get city as C string
		const char* getCity(int& lenOfArray);
		//Get city as Cpp string
		std::string getCity();

		//Get Province as C string
		const char* getProvince(int& lenOfArray);
		//Get province as Cpp string
		std::string getProvince();

		//Get zip code as C string
		const char* getZip(int& lenOfArray);
		//Get zip code as Cpp string
		std::string getZip();

		//Get Client info as a struct
		DBClientInfo getClientInfo();

		//Set functions

		//Set first name from C string
		void setFirstName(char newFirst[VARCHARLEN]);
		//Set first name from Cpp string
		void setFirstName(std::string newFirst);

		//Set last name from C string
		void setLastName(char newLast[VARCHARLEN]);
		//Set last name from Cpp string
		void setLastName(std::string newLast);

		//Set email from C string
		void setEmail(char newEmail[VARCHARLEN]);
		//Set email from Cpp string
		void setEmail(std::string newEmail);

		//Set phone number from C string
		void setPhoneNum(char newPhone[VARCHARLEN]);
		//Set phone number from Cpp string
		void setPhoneNum(std::string newPhone);

		//Set street from C string
		void setStreet(char newStreet[VARCHARLEN]);
		//Set street from Cpp string
		void setStreet(std::string newStreet);

		//Set city from C string
		void setCity(char newCity[VARCHARLEN]);
		//Set city from Cpp string
		void setCity(std::string newCity);

		//Set province from C string
		void setProvince(char newProvince[VARCHARLEN]);
		//Set province from Cpp string
		void setProvince(std::string newProvince);

		//Set zip code from C string
		void setZip(char newZip[ZIPLEN]);
		//Set zip code from Cpp string
		void setZip(std::string newZip);

		//Inherited functions

		//Display info of client as a string for terminal debugging
		std::string displayInfo();

		//Get log data format for client to be used in DBLogger
		//std::string getLogData();

		//Add Client info query for database
		std::string addInfoToDB();

		//Modify Client info query for client of the same client ID
		std::string modifyInfoInDB();

		//Delete Client info query for client of the same client ID
		std::string deleteInfoInDB();

		//Check if client id is in database
		std::string checkObjectExists();
	};

	//Structure for DBCredential object's info, to ease validation
	struct DBCredentialInfo {
		int clientID;
		char username[VARCHARLEN];
		int usernumber;
		char userPasswordHash[VARCHARLEN];
	};

	//DBCredential / validation object class
	class DBCredentials :public DBObject {
		DBCredentialInfo credentialInfo;

	public:
		//Constructors

		//Default constructor
		DBCredentials();

		//Struct constructor, for use after deserializing
		DBCredentials(const DBCredentialInfo copyInfo);

		//Copy constructor
		DBCredentials(const DBCredentials& copyCredentials);

		//Parametrized constructor
		DBCredentials(int inputObjectID, int inputClientID, char inputUserName[VARCHARLEN], int inputUserNumber, char inputPasswordHash[VARCHARLEN]);

		//Get functions

		//Get clientID as int
		int getClientID();

		//Get Username as C string
		const char* getUsername(int& lenOfArray);
		//Get Username as Cpp string
		std::string getUsername();

		//Get Usernumber as int
		int getUsernumber();

		//Get PasswordHash as C string
		const char* getPasswordHash(int& lenOfArray);
		//Get PasswordHash as Cpp string
		std::string getPasswordHash();

		//Get Credential info as a struct
		DBCredentialInfo getCredentialInfo();

		//Set functions

		//Set ClientID as int
		void setClientID(int newClientID);

		//Set Username or Usernumber from C string
		void setUsername(char newUsername[VARCHARLEN]);
		//Set Username or Usernumber from Cpp string
		void setUsername(std::string newUsernameOrNum);

		//Set Usernumber as int
		void setUsernumber(int newUsernumber);

		//Set PasswordHash from C string
		void setPasswordHash(char newPasswordHash[VARCHARLEN]);
		//Set PasswordHash from Cpp string
		void setPasswordHash(std::string newPasswordHash);

		//Inherited functions

		//Display info of credentials as a string for terminal debugging
		std::string displayInfo();

		//Get log data format for credentials to be used in DBLogger
		//std::string getLogData();

		//Add Credential info query for database
		std::string addInfoToDB();

		//Modify Credential info query for credential of the same credential ID
		std::string modifyInfoInDB();

		//Delete Credential info query for credential of the same credential ID
		std::string deleteInfoInDB();

		//Check if Credential id is in database
		std::string checkObjectExists();
	};

	//Enummeration for Account types
	enum DBAType { DBANULL, CHEQUINGS, SAVINGS };

	//Structure for DBAccount object's info, to ease serialization
	struct DBAccountInfo {
		int clientID;
		DBAType accountType;
		double accountBalance;
	};

	//DBAccount object class
	class DBAccount :public DBObject {
		DBAccountInfo accountInfo;

	public:
		//Constructors

		//Default constructor
		DBAccount();

		//Struct constructor, for use after deserializing
		DBAccount(const DBAccountInfo copyInfo);

		//Copy constructor
		DBAccount(const DBAccount& copyAccount);

		//Parametrized constructor
		DBAccount(int inputObjectID, int inputClientID, DBAType inputAccountType, double inputBalance);

		//Get functions

		//Get account type...
		DBAType getAccountType();

		//Get client ID for connected client
		int getAccountClientID();

		//Get balance for this account
		double getAccountBalance();

		//Get accountInfo struct, used in serializing...
		DBAccountInfo getAccountInfo();

		//Set functions

		//Set account type, in case user changes account to a different one...
		void setAccountType(DBAType newType);

		//Set client ID, in case account is transferred for some reason?
		void setAccountClientID(int newClientID);

		//Set account balance, due to a transaction etc...
		void setBalance(double newBalance);

		//Set account info, used in case everything is changed at once
		void setAccountInfo(DBAccountInfo newAccountInfo);

		//Inherited functions

		//Display info of account as a string for terminal debugging
		std::string displayInfo();

		//Get log data format for account to be used in DBLogger
		//std::string getLogData();

		//Add Account info query for database
		std::string addInfoToDB();

		//Modify Account info query for account of the same account ID
		std::string modifyInfoInDB();

		//Delete Account info query for account of the same account ID
		std::string deleteInfoInDB();

		//Check if Account id is in database
		std::string checkObjectExists();
	};

	//Enummeration for transaction types
	enum DBTType { DBTNULL, ETRANSFER, CHEQUE, WITHDRAW, ACCOUNTTRANSFER };

	//Structure for DBTransaction object's info, to ease serialization
	struct DBTransactionInfo {
		int accountID;
		DBTType transactionType;
		char* transactionTime;
		double previousBalance;
		double newBalance;
		int secondaryAccount;
	};

	//DBTransaction object class
	class DBTransaction :public DBObject {
		DBTransactionInfo transactionInfo;

	public:
		//Constructors

		//Default constructor
		DBTransaction();

		//Struct constructor, for use after deserializing
		DBTransaction(const DBTransactionInfo copyInfo);

		//Copy constructor
		DBTransaction(DBTransaction& copyTransaction);

		//Parametrized constructor
		DBTransaction(int inputObjectID, int inputAccountID, DBTType inputTransactionType, char* transactionTime, double inputPreviousBalance, double inputNewBalance, int inputSecondaryAccount);

		//Get functions

		//Get account ID for connected account
		int getTransactionAccountID();

		//Get transaction type...
		DBTType getTransactionType();

		//Get time of transaction as C String
		char* getTransactionTime(int& lenOfArray);
		//Get time of transaction as Cpp String
		std::string getTransactionTime();

		//Get balance before transaction
		double getTransactionPreviousBal();

		//Get balance after transaction
		double getTransactionNewBal();

		//Get other account connected (relationship is implied through transaction type...)
		int getTransactionSecondaryAcc();

		//Get transaction info as a struct
		DBTransactionInfo getTransactionInfo();

		//Set functions

		//Set account ID for connected account
		void setTransactionAccountID(int newAccountID);

		//Set transaction type...
		void setTransactionType(DBTType newTransactionType);

		//Set time of transaction
		void setTransactionTime(char* newTransactionTime);

		//Set balance before transaction
		void setTransactionPreviousBal(double newTransactionPB);

		//Set balance after transaction
		void setTransactionNewBal(double newTransactionNB);

		//Set other account connected (relationship is implied through transaction type...)
		void setTransactionSecondaryAcc(int newTransactionSA);

		//Inherited functions

		//Display info of transaction as a string for terminal debugging
		std::string displayInfo();

		//Get log data format for transaction to be used in DBLogger
		//std::string getLogData();

		//Add Transaction info query for database
		std::string addInfoToDB();

		//Modify Transaction info query for transaction of the same transaction ID
		std::string modifyInfoInDB();

		//Delete Transaction info query for transaction of the same transaction ID
		std::string deleteInfoInDB();

		//Check if Transaction id is in database
		std::string checkObjectExists();
	};
}