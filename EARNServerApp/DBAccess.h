#pragma once
#include <Windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <string>
#include <vector>

#include "DBObjects.h"

namespace EarnDB {
	using namespace std;

	//virtual access interface for DB
	class DBAccessInterface {
		int objectID;

	public:
		//Constructors

		//default constructor
		DBAccessInterface();

		//copy constructor
		DBAccessInterface(const DBAccessInterface& copyAccessObject);
		
		//parametrized constructor
		DBAccessInterface(int newObjectID);

		//get ID function for lower level classes to "reach up"
		int getObjectID();

		//set ID function in case the object is uninitalized
		void setObjectID(int newObjectID);

		//Virtualized functions for lower level implementations
		virtual string addInfoToDB() = 0;
		virtual string modifyInfoInDB() = 0;
		virtual string deleteInfoInDB() = 0;
	};

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
		int getObjectsInfo(int& numOfClients, vector<DBClient>& clientsVec);

		//Get all Accounts of a client from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int clientID, int& numOfAccounts, vector<DBAccount>& clientAccountsVec);

		//Get all Transactions of an account from database (-2 if ID doesn't exist / -1 for error)
		int getObjectsInfo(int accountID, int& numOfTransactions, vector<DBTransaction>& accountTransactionsVec);

		//Check ID function(s) for given ID num, and specified ID type
		bool checkIDExists(int checkID, DBOType idType);
	};

	class DBValidation {
		//Private validate client function used by login
		int validateClient(string usernameOrNum, string passwordHash);

	public:
		//Client login function, returns NULL for incorrect login
		DBClient clientLogin(string usernameORNum, string passwordHash);
	};

	class DBWriter {
	public:
		//Add object to database (-2 if ID doesn't exist / -1 for error)
		int addObject(DBObject inputObj);

		//Modify object in database (-2 if ID doesn't exist / -1 for error)
		int modifyObjectInfo(DBObject inputObj);

		//Delete object in database (-2 if ID doesn't exist / -1 for error)
		int deleteObject(DBObject inputObj);
	};
}
