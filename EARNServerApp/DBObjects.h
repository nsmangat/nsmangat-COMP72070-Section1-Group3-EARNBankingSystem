#pragma once
#include "DBAccess.h"
#include <EARNStructs.h>

#include <string>
#include <time.h>

namespace EarnDB  {
	
	//DBObject Interface / abstract class, used by client, account, etc...
	class DBObject :public DBAccessInterface {
		EarnStructs::ObjectType objectType;

	public:
		//Constructors...

		//Default constructor
		DBObject();

		//Copy constructor
		DBObject(const DBObject& copyObject);

		//Parametrized constructor
		DBObject(EarnStructs::ObjectType initalizeType, int objectID);

		//Get function for DBOType
		EarnStructs::ObjectType getDBOType();

		//Set function for DBType
		void setDBOType(EarnStructs::ObjectType inputType);

		//Display Info about Object to terminal (debugging purposes).
		virtual std::string displayInfo() = 0;
	};

	//DBClient object class
	class DBClient :public DBObject {
		EarnStructs::ClientInfo clientInfo;

	public:
		//Constructors

		//Default constructor
		DBClient();

		//Struct constructor, for use after deserializing
		DBClient(const EarnStructs::ClientInfo copyInfo);

		//Copy constructor
		DBClient(const DBClient& copyClient);

		//Parametrized constructor
		DBClient(int inputObjectID, const char* inputFirst, const char* inputLast, const char* inputEmail, const char* inputPhone, const char* inputStreet, const char* inputCity, const char* inputProvince, const char* inputZip);

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
		EarnStructs::ClientInfo getClientInfo();

		//Set functions

		//Set first name from C string
		void setFirstName(const char* newFirst);
		//Set first name from Cpp string
		void setFirstName(std::string newFirst);

		//Set last name from C string
		void setLastName(const char* newLast);
		//Set last name from Cpp string
		void setLastName(std::string newLast);

		//Set email from C string
		void setEmail(const char* newEmail);
		//Set email from Cpp string
		void setEmail(std::string newEmail);

		//Set phone number from C string
		void setPhoneNum(const char* newPhone);
		//Set phone number from Cpp string
		void setPhoneNum(std::string newPhone);

		//Set street from C string
		void setStreet(const char* newStreet);
		//Set street from Cpp string
		void setStreet(std::string newStreet);

		//Set city from C string
		void setCity(const char* newCity);
		//Set city from Cpp string
		void setCity(std::string newCity);

		//Set province from C string
		void setProvince(const char* newProvince);
		//Set province from Cpp string
		void setProvince(std::string newProvince);

		//Set zip code from C string
		void setZip(const char* newZip);
		//Set zip code from Cpp string
		void setZip(std::string newZip);

		//Inherited functions

		//Display info of client as a string for terminal debugging
		std::string displayInfo();

		//Get log data format for client to be used in DBLogger
		//std::string getLogData();

		//Get Client info query from database, @checkResult for OUT var
		std::string getInfoFromDB();

		//Add Client info query for database, @newID for OUT var
		std::string addInfoToDB();

		//Modify Client info query for client of the same client ID
		std::string modifyInfoInDB();

		//Delete Client info query for client of the same client ID
		std::string deleteInfoInDB();

		//Check if client id is in database, @checkResult for OUT var
		std::string checkObjectExists();
	};

	//DBCredential / validation object class
	class DBCredential :public DBObject {
		EarnStructs::CredentialInfo credentialInfo;

	public:
		//Constructors

		//Default constructor
		DBCredential();

		//Struct constructor, for use after deserializing
		DBCredential(const EarnStructs::CredentialInfo copyInfo);

		//Copy constructor
		DBCredential(const DBCredential& copyCredentials);

		//Parametrized constructor
		DBCredential(int inputObjectID, int inputClientID, char inputUserName[EarnStructs::VARCHARLEN], int inputUserNumber, char inputPasswordHash[EarnStructs::VARCHARLEN]);

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
		EarnStructs::CredentialInfo getCredentialInfo();

		//Set functions

		//Set ClientID as int
		void setClientID(int newClientID);

		//Set Username or Usernumber from C string
		void setUsername(char newUsername[EarnStructs::VARCHARLEN]);
		//Set Username or Usernumber from Cpp string
		void setUsername(std::string newUsernameOrNum);

		//Set Usernumber as int
		void setUsernumber(int newUsernumber);

		//Set PasswordHash from C string
		void setPasswordHash(char newPasswordHash[EarnStructs::VARCHARLEN]);
		//Set PasswordHash from Cpp string
		void setPasswordHash(std::string newPasswordHash);

		//Inherited functions

		//Display info of credentials as a string for terminal debugging
		std::string displayInfo();

		//Get log data format for credentials to be used in DBLogger
		//std::string getLogData();

		//Get Credential info query from database, @checkResult for OUT var
		std::string getInfoFromDB();

		//Add Credential info query for database, @newID for OUT var
		std::string addInfoToDB();

		//Modify Credential info query for credential of the same credential ID
		std::string modifyInfoInDB();

		//Delete Credential info query for credential of the same credential ID
		std::string deleteInfoInDB();

		//Check if Credential id is in database, @checkResult for OUT var
		std::string checkObjectExists();
	};

	//DBAccount object class
	class DBAccount :public DBObject {
		EarnStructs::AccountInfo accountInfo;

	public:
		//Constructors

		//Default constructor
		DBAccount();

		//Struct constructor, for use after deserializing
		DBAccount(const EarnStructs::AccountInfo copyInfo);

		//Copy constructor
		DBAccount(const DBAccount& copyAccount);

		//Parametrized constructor
		DBAccount(int inputObjectID, int inputClientID, EarnStructs::AccountType inputAccountType, double inputBalance);

		//Get functions

		//Get account type...
		EarnStructs::AccountType getAccountType();

		//Get client ID for connected client
		int getAccountClientID();

		//Get balance for this account
		double getAccountBalance();

		//Get accountInfo struct, used in serializing...
		EarnStructs::AccountInfo getAccountInfo();

		//Set functions

		//Set account type, in case user changes account to a different one...
		void setAccountType(EarnStructs::AccountType newType);

		//Set client ID, in case account is transferred for some reason?
		void setAccountClientID(int newClientID);

		//Set account balance, due to a transaction etc...
		void setBalance(double newBalance);

		//Set account info, used in case everything is changed at once
		void setAccountInfo(EarnStructs::AccountInfo newAccountInfo);

		//Inherited functions

		//Display info of account as a string for terminal debugging
		std::string displayInfo();

		//Get log data format for account to be used in DBLogger
		//std::string getLogData();

		//Get Account info query from database, @checkResult for OUT var
		std::string getInfoFromDB();

		//Add Account info query for database, @newID for OUT var
		std::string addInfoToDB();

		//Modify Account info query for account of the same account ID
		std::string modifyInfoInDB();

		//Delete Account info query for account of the same account ID
		std::string deleteInfoInDB();

		//Check if Account id is in database. @checkResult for OUT var
		std::string checkObjectExists();
	};

	//DBTransaction object class
	class DBTransaction :public DBObject {
		EarnStructs::TransactionInfo transactionInfo;

	public:
		//Constructors

		//Default constructor
		DBTransaction();

		//Struct constructor, for use after deserializing
		DBTransaction(const EarnStructs::TransactionInfo copyInfo);

		//Copy constructor
		DBTransaction(DBTransaction& copyTransaction);

		//Parametrized constructor
		DBTransaction(int inputObjectID, int inputAccountID, EarnStructs::TransactionType inputTransactionType, const char* transactionTime, double inputPreviousBalance, double inputNewBalance, int inputSecondaryAccount);

		//Get functions

		//Get account ID for connected account
		int getTransactionAccountID();

		//Get transaction type...
		EarnStructs::TransactionType getTransactionType();

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
		EarnStructs::TransactionInfo getTransactionInfo();

		//Set functions

		//Set account ID for connected account
		void setTransactionAccountID(int newAccountID);

		//Set transaction type...
		void setTransactionType(EarnStructs::TransactionType newTransactionType);

		//Set time of transaction
		void setTransactionTime(const char* newTransactionTime);

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

		//Get Transaction info query from database, @checkResult for OUT var
		std::string getInfoFromDB();

		//Add Transaction info query for database, @newID for OUT var
		std::string addInfoToDB();

		//Modify Transaction info query for transaction of the same transaction ID
		std::string modifyInfoInDB();

		//Delete Transaction info query for transaction of the same transaction ID
		std::string deleteInfoInDB();

		//Check if Transaction id is in database, @checkResult for OUT var
		std::string checkObjectExists();
	};
}