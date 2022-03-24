#pragma once
#include <iostream>
#include <vector>
#include <mysqlx/xdevapi.h>
#include <sstream>
#include <Windows.h>
#include <direct.h>

#include"DBAccess.h"
#include "DBObjects.h"
#include <EARNStructs.h>

namespace EarnDBDrivers {
	//DB enummerations for success & failure

	//DB flags for type of DB error (used in logging failed DB actions)
	enum DBErrorType { NO_DB_FOUND, BAD_OBJECT_CREDENTIALS, BAD_DB_CREDENTIALS, INSUFFICIENT_BALANCE, ACCOUNT_NOT_FOUND, CLIENT_NOT_FOUND, TRANSACTION_NOT_FOUND, READ_ERROR, WRITE_ERROR, VALIDATION_ERROR };

	//Converts enum to string depending on type
	const std::string EnumToString(DBErrorType inputType);

	//DB flags for type of DB interaction (used in logging standard DB actions)
	enum DBSUCCESSTYPE { DB_FOUND, GOOD_OBJECT_CREDENTIALS, GOODD_DB_CREDENTIALS, SUFFICIENT_BALANCE, ACCOUNT_FOUND, CLIENT_FOUND, TRANSACTION_FOUND, READ_SUCCESS, WRITE_SUCCESS, VALIDATION_SUCCESS };

	//Converts enum to string depending on type
	const std::string EnumToString(DBSUCCESSTYPE inputType);

	//since this is always used and would have to get changed everywhere
	const int serverDBPort = 33060;

	//macros for response errors in case they need to be changed later... names self explanitory
	
	const int DBSuccess = 0;

	const int DBFail = 1;

	const int DBNoID = -1;

	const int DBConnError = -2;

	const int DBSqlError = -3;

	const int DBUnknownError = -4;

	//DB Driver parent interface, used by reader, writer & validation (can also be used independantly)
	class DBDriverInterface {
		//needed to start connections

		const std::string server;
		const std::string schema;
		const std::string username;
		const std::string password;
		//just keep logger inside DBDrivers since it will always be used in it's functionalities

		//DBLogger DBLogger;

	public:
		//Constructor

		//Will always use parametrized because of the const values needed...
		DBDriverInterface(
			std::string inputServer,
			std::string inputSchema,
			std::string inputUsername,
			std::string inputPassword);
		//, DBLogger(DBLoggerPath);

		//Get functions (protected due to password call & no other obvious solution...

		//get server string for children db connections
		const std::string getServer();

		//get schema string for children db connections
		const std::string getSchema();

		//get username string for children db connections
		const std::string getUsername();

		//get password string for children db connections
		const std::string getPassword();

		//Check & Initalize functions

		//Initalize DB if it doesn't exist, used in checkIFDBExists function and can be used as a static function when server boots up (errors are according to _chdir, system errno responses...)
		static int initalizeDefaultDB();

		//Checks if the DB exists (0 for exists, -1 for doesn't exist but now initalized, -2 for doesn't exist & error initalizing
		int checkIfDBExists();

		//Call DBLogger given success / error to log DB information

		/*
		//Call DBLogger for an error
		bool callDBLoggerError(std::string DBObjectLogInfo, DBErrorType errorType);

		//Call DBLogger for an expected instance
		bool callDBLoggerSUCCESS(std::string DBObjectLogInfo, DBSUCCESSTYPE successType);
		*/
	};

	//DB Reader class (used in initalizing one or more objects from the database, any read only functionality)
	class DBReader :public DBDriverInterface {
		//Subfunctions for checkIDExists

		//Check if Client ID is in database (0 for success, 1 for no ID, -2 for conenction error, -3 for sql error)
		int checkClientIDExists(int checkClientID);

		//Check if Account ID is in database (0 for success, 1 for no ID, -2 for conenction error, -3 for sql error)
		int checkAccountIDExists(int checkAccountID);

		//Check if Transaction / Invoice ID is in database (0 for success, 1 for no ID, -2 for conenction error, -3 for sql error)
		int checkTransactionIDExists(int checkTransactionID);

		//Check if Credential ID is in database (debugging) (0 for success, 1 for no ID, -2 for conenction error, -3 for sql error)
		int checkCredentialIDExists(int checkCredentialID);

	public:
		//Constructor
		DBReader(
			std::string inputServer,
			std::string inputSchema,
			std::string inputUsername,
			std::string inputPassword);

		//Get single objects

		//Get Client from database (0 for success, -1 if ID doesn't exist, -2 for connection error, -3 for sql error)
		int getObjectInfo(int objectID, EarnDBObjects::DBClient& copyClient);

		//Get Account from database (-3 if ID doesn't exist, -2 for connection error, -1 for sql error)
		int getObjectInfo(int objectID, EarnDBObjects::DBAccount& copyAccount);

		//Get Transaction from database (-3 if ID doesn't exist, -2 for connection error, -1 for sql error)
		int getObjectInfo(int objectID, EarnDBObjects::DBTransaction& copyTransaction);

		//Get all objects from a higher level ID

		//Get all Clients from database (-3 if ID doesn't exist, -2 for connection error, -1 for sql error)
		int getObjectsInfo(int& numOfClients, std::vector<EarnDBObjects::DBClient>& clientsVec);

		//Get all Accounts of a client from database (-3 if ID doesn't exist, -2 for conecetion error, -1 for sql error)
		int getObjectsInfo(int clientID, int& numOfAccounts, std::vector<EarnDBObjects::DBAccount>& clientAccountsVec);

		//Get all Transactions of an account from database (-3 if ID doesn't exist, -2 for connection error, -1 for sql error)
		int getObjectsInfo(int accountID, int& numOfTransactions, std::vector<EarnDBObjects::DBTransaction>& accountTransactionsVec);

		//Check ID function(s) for given ID num, and specified ID type (0 for success, 1 for no ID, -2 for connection error, -3 for sql error)
		int checkIDExists(int checkID, EarnStructs::ObjectType idType);
	};

	//DB Validation class (used for login / finding client for associated username/Num & password
	class DBValidation :public DBReader {
		//Private validate client function used by login
		int validateClient(int usernumber, std::string username, std::string passwordHash);

	public:
		//Constructor
		DBValidation(
			std::string inputServer,
			std::string inputSchema,
			std::string inputUsername,
			std::string inputPassword);

		//Client login function through username & pass (NULL for incorrect login on validation side, -3 if ID doesn't exist / client could be gotten,  -2 for conenction error, -1 for sql error)
		EarnDBObjects::DBClient clientLogin(std::string username, std::string passwordHash);

		//Client login function through usernumber & pass (NULL for incorrect login on validation side, -3 if ID doesn't exist / client could be gotten,  -2 for conenction error, -1 for sql error)
		EarnDBObjects::DBClient clientLogin(int usernumber, std::string passwordHash);

		//Client login function using CredentialInfo struct (NULL for incorrect login on validation side, -3 if ID doesn't exist / client could be gotten,  -2 for conenction error, -1 for sql error)
		EarnDBObjects::DBClient clientLogin(EarnStructs::CredentialInfo inputCredentials);
	};

	////DB Writer class (used in adding, modifying, and deleting info)
	class DBWriter :public DBReader {
	public:
		//Constructor
		DBWriter(
			std::string inputServer,
			std::string inputSchema,
			std::string inputUsername,
			std::string inputPassword);

		//Add object to database (object's allocated ID on success, -1 for error)
		int addObject(EarnDBObjects::DBObject& inputObj);

		//Modify object in database (0 for success, -1 for sql error, -2 for DB Connection error)
		int modifyObjectInfo(EarnDBObjects::DBObject& inputObj);

		//Delete object in database (0 for success, -1 for sql error, -2 for DB Connection error)
		int deleteObject(EarnDBObjects::DBObject& inputObj);
	};
}
