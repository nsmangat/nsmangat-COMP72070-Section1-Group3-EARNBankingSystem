#pragma once
#include <iostream>
#include <vector>
#include <mysqlx/xdevapi.h>
#include "DBAccess.h"
#include "DBObjects.h"

namespace EarnDB {
	//DB enummerations for success & failure

	//DB flags for type of DB error (used in logging failed DB actions)
	enum DBErrorType { NO_DB_FOUND, BAD_OBJECT_CREDENTIALS, BAD_DB_CREDENTIALS, INSUFFICIENT_BALANCE, ACCOUNT_NOT_FOUND, CLIENT_NOT_FOUND, TRANSACTION_NOT_FOUND, READ_ERROR, WRITE_ERROR, VALIDATION_ERROR };
	
	//Converts enum to string depending on type
	inline const std::string EnumToString(DBErrorType inputType)
	{
		switch (inputType)
		{
		case NO_DB_FOUND:		return "NO_DB_FOUND";
		case BAD_OBJECT_CREDENTIALS:	return "BAD_OBJECT_CREDENTIALS";
		case BAD_DB_CREDENTIALS:	return "BAD_DB_CREDENTIALS";
		case INSUFFICIENT_BALANCE:		return "INSUFFICIENT_BALANCE";
		case ACCOUNT_NOT_FOUND:	return "ACCOUNT_NOT_FOUND";
		case CLIENT_NOT_FOUND:	return "CLIENT_NOT_FOUND";
		case TRANSACTION_NOT_FOUND:		return "TRANSACTION_NOT_FOUND";
		case READ_ERROR:	return "READ_ERROR";
		case WRITE_ERROR:	return "WRITE_ERROR";
		case VALIDATION_ERROR:		return "VALIDATION_ERROR";
		default:			return "[Unknown Type]";
		}
	}

	//DB flags for type of DB interaction (used in logging standard DB actions)
	enum DBSUCCESSTYPE { DB_FOUND, GOOD_OBJECT_CREDENTIALS, GOODD_DB_CREDENTIALS, SUFFICIENT_BALANCE, ACCOUNT_FOUND, CLIENT_FOUND, TRANSACTION_FOUND, READ_SUCCESS, WRITE_SUCCESS, VALIDATION_SUCCESS };
	
	//Converts enum to string depending on type
	inline const std::string EnumToString(DBSUCCESSTYPE inputType)
	{
		switch (inputType)
		{
		case DB_FOUND:		return "DB_FOUND";
		case GOOD_OBJECT_CREDENTIALS:	return "GOOD_OBJECT_CREDENTIALS";
		case GOODD_DB_CREDENTIALS:	return "GOODD_DB_CREDENTIALS";
		case SUFFICIENT_BALANCE:		return "SUFFICIENT_BALANCE";
		case ACCOUNT_FOUND:	return "ACCOUNT_FOUND";
		case CLIENT_FOUND:	return "CLIENT_FOUND";
		case TRANSACTION_FOUND:		return "TRANSACTION_FOUND";
		case READ_SUCCESS:	return "READ_SUCCESS";
		case WRITE_SUCCESS:	return "WRITE_SUCCESS";
		case VALIDATION_SUCCESS:		return "VALIDATION_SUCCESS";
		default:			return "[Unknown Type]";
		}
	}

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
		
		//Initalize DB if it doesn't exist, used in checkIFDBExists function and can be used as a static function when server boots up
		static bool initalizeDefaultDB();

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

		//Check if Client ID is in database
		bool checkClientIDExists(int checkClientID);

		//Check if Account ID is in database
		bool checkAccountIDExists(int checkAccountID);

		//Check if Transaction / Invoice ID is in database
		bool checkTransactionIDExists(int checkTransactionID);

		//Check if Credential ID is in database (debugging)
		bool checkCredentialIDExists(int checkCredentialID);

	public:
		//Constructor
		DBReader(
			std::string inputServer,
			std::string inputSchema,
			std::string inputUsername,
			std::string inputPassword);

		//Get single objects

		//Get Client from database (-2 if ID doesn't exist / -1 for error)
		int getObjectInfo(int objectID, DBClient& copyClient);

		//Get Account from database (-2 if ID doesn't exist / -1 for error)
		int getObjectInfo(int objectID, DBAccount& copyAccount);

		//Get Transaction from database (-2 if ID doesn't exist / -1 for error)
		int getObjectInfo(int objectID, DBTransaction& copyTransaction);

		//Get Object from database, using DBOType and pass by reference
		int getObjectInfo(int objectID, DBObject& copyObject);
		//Get all objects from a higher level ID

		//Get all Clients from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int& numOfClients, std::vector<EarnDB::DBClient>& clientsVec);

		//Get all Accounts of a client from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int clientID, int& numOfAccounts, std::vector<EarnDB::DBAccount>& clientAccountsVec);

		//Get all Transactions of an account from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int accountID, int& numOfTransactions, std::vector<EarnDB::DBTransaction>& accountTransactionsVec);

		//Check ID function(s) for given ID num, and specified ID type
		bool checkIDExists(int checkID, EarnStructs::ObjectType idType);
	};

	//DB Validation class (used for login / finding client for associated username/Num & password
	class DBValidation :public DBDriverInterface {
		//Private validate client function used by login
		int validateClient(int usernumber, std::string username, std::string passwordHash);

	public:
		//Constructor
		DBValidation(
			std::string inputServer,
			std::string inputSchema,
			std::string inputUsername,
			std::string inputPassword);

		//Client login function through username & pass, returns NULL for incorrect login
		DBClient clientLogin(DBReader& copyReader, std::string username, std::string passwordHash);

		//Client login function through usernumber & pass, returns NULL for incorrect login
		DBClient clientLogin(DBReader& copyReader, int usernumber, std::string passwordHash);

		//Client login function using CredentialInfo struct, returns NULL for incorrect login
		DBClient clientLogin(DBReader& copyReader, EarnStructs::CredentialInfo inputCredentials);
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
		int addObject(DBObject& inputObj);

		//Modify object in database (0 for success, -1 for error, -2 for DB Connection error)
		int modifyObjectInfo(DBObject& inputObj);

		//Delete object in database (0 for success, -1 for error, -2 for DB Connection error)
		int deleteObject(DBObject& inputObj);
	};
}
