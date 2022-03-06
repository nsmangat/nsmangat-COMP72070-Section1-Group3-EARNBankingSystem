#pragma once
#include <Windows.h>
#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>
#include <string>
#include <vector>

#include "DBObjects.h"

using namespace std;

class DBAccessObject {
	int objectID;
public:
	DBAccessObject(DBAccessObject& copyObject);
	DBAccessObject(int newObjectID);

	virtual string addInfoToDB() = 0;
	virtual string modifyInfoInDB() = 0;
	virtual string deleteInfoInDB() = 0;

	int getObjectID();
};

//enummeration for different types of DBObjects
enum DBOType{ ACCOUNT, CLIENT, TRANSACTION};

class DBReader{
	//subfunctions for checkIDExists
	bool checkClientIDExists(int checkClientID);
	bool checkAccountIDExists(int checkAccountID);
	bool checkTransactionIDExists(int checkTransactionID);

public:
	//get single objects
	bool getObjectInfo(int objectID, DBClient& copyClient);
	bool getObjectInfo(int objectID, DBAccount& copyAccount);
	bool getObjectInfo(int objectID, DBTransaction& copyTransaction);

	//get all object from a table related (all clients, accounts of client, and invoices for account
	bool getObjectsInfo(int& numOfClients, vector<DBClient>& clientsVec);
	bool getObjectsInfo(int clientID, int& numOfAccounts, vector<DBAccount>& clientAccountsVec);
	bool getObjectsInfo(int accountID, int& numOfTransactions, vector<DBTransaction>& accountTransactionsVec);

	//check if id exists... with sub functions for each option
	bool checkIDExists(int checkID, DBOType idType);
};

class DBValidation{
	int validateClient(string usernameOrNum, string passwordHash);
public:
	DBClient clientLogin(string usernameORNum, string passwordHash);
};

class DBWriter{
public:
	bool addObject(DBObject inputObj);
	bool modifyObjectInfo(DBObject inputObj);
	bool deleteObject(DBObject inputObj);
};