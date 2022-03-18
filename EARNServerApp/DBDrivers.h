#pragma once
#include <string>
#include <vector>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include "DBAccess.h"
#include "DBObjects.h"

namespace EarnDB {
	//DB enummerations for success & failure

	//DB flags for type of DB error (used in logging failed DB actions)
	enum DBErrorType { NO_DB_FOUND, BAD_OBJECT_CREDENTIALS, BAD_DB_CREDENTIALS, INSUFFICIENT_BALANCE, ACCOUNT_NOT_FOUND, CLIENT_NOT_FOUND, TRANSACTION_NOT_FOUND, READ_ERROR, WRITE_ERROR, VALIDATION_ERROR };
	
	//DB flags for type of DB interaction (used in logging standard DB actions)
	enum DBSUCCESSTYPE { DB_FOUND, GOOD_OBJECT_CREDENTIALS, GOODD_DB_CREDENTIALS, SUFFICIENT_BALANCE, ACCOUNT_FOUND, CLIENT_FOUND, TRANSACTION_FOUND, READ_SUCCESS, WRITE_SUCCESS, VALIDATION_SUCCESS };
	
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
		DBDriverInterface(std::string inputServer, std::string inputSchema, std::string inputUsername, std::string inputPassword);// , DBLogger(DBLoggerPath);

		//Inherited Initalization functions

		//Initalize DBDriver & Connection for children, since it's the same each time... Also logs given an error
		bool initalizeDBDriverConnection(sql::Driver* DBdriver, sql::Connection* DBConnection);

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
	class DBReader {
		//Subfunctions for checkIDExists

		//Check if Client ID is in database
		bool checkClientIDExists(int checkClientID);

		//Check if Account ID is in database
		bool checkAccountIDExists(int checkAccountID);

		//Check if Transaction / Invoice ID is in database
		bool checkTransactionIDExists(int checkTransactionID);

	public:
		//Get single objects

		//Get Client from database (-2 if ID doesn't exist / -1 for error)
		int getObjectInfo(int objectID, DBClient& copyClient);

		//Get Account from database (-2 if ID doesn't exist / -1 for error)
		int getObjectInfo(int objectID, DBAccount& copyAccount);

		//Get Transaction from database (-2 if ID doesn't exist / -1 for error)
		int getObjectInfo(int objectID, DBTransaction& copyTransaction);

		//Get all objects from a higher level ID

		//Get all Clients from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int& numOfClients, std::vector<DBClient>& clientsVec);

		//Get all Accounts of a client from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int clientID, int& numOfAccounts, std::vector<DBAccount>& clientAccountsVec);

		//Get all Transactions of an account from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int accountID, int& numOfTransactions, std::vector<DBTransaction>& accountTransactionsVec);

		//Check ID function(s) for given ID num, and specified ID type
		bool checkIDExists(int checkID, EarnStructs::ObjectType idType);
	};

	//DB Validation class (used for login / finding client for associated username/Num & password
	class DBValidation {
		//Private validate client function used by login
		int validateClient(std::string usernameOrNum, std::string passwordHash);

	public:
		//Client login function, returns NULL for incorrect login
		DBClient clientLogin(std::string usernameORNum, std::string passwordHash);
	};

	//DB Writer class (used in adding, modifying, and deleting info)
	class DBWriter {
	public:
		//Add object to database (object's allocated ID on success, -2 for DB insert error,  -1 for general / unknown error)
		int addObject(DBObject inputObj);

		//Modify object in database (-2 if ID doesn't exist / -1 for error)
		int modifyObjectInfo(DBObject inputObj);

		//Delete object in database (-2 if ID doesn't exist / -1 for error)
		int deleteObject(DBObject inputObj);
	};
}
