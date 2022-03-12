#include <string>
#include <vector>

#include"DBAccess.h"
#include "DBObjects.h"

/*
* For all DB accessin functions that return an int non standard returns are -2 if ID doesn't exist / -1 for error (0 for successful)... just to keep them all standardized
*/

//DBAccessInterface source code
namespace EarnDB {
	//Constructors

	DBAccessInterface::DBAccessInterface() {
		this->setObjectID(0);
	}

	DBAccessInterface::DBAccessInterface(const DBAccessInterface& copyAccessObject) {
		this->setObjectID(copyAccessObject.objectID);
	}

	DBAccessInterface::DBAccessInterface(int newObjectID) {
		this->setObjectID(newObjectID);
	}

	//Get function

	int DBAccessInterface::getObjectID() {
		return this->objectID;
	}

	//Set function

	void DBAccessInterface::setObjectID(int newObjectID) {
		this->objectID = newObjectID;
	}
}

/*
//DBReader source code
namespace EarnDB {
	//Subfunctions for checkIDExists

	bool DBReader::checkClientIDExists(int checkClientID);

	bool DBReader::checkAccountIDExists(int checkAccountID);

	bool DBReader::checkTransactionIDExists(int checkTransactionID);

	//Get single objects

	int DBReader::getObjectInfo(int objectID, DBClient& copyClient);

	int DBReader::getObjectInfo(int objectID, DBAccount& copyAccount);

	int DBReader::getObjectInfo(int objectID, DBTransaction& copyTransaction);

	//Get all objects from a higher level ID

	int DBReader::getObjectsInfo(int& numOfClients, vector<DBClient>& clientsVec);

	int DBReader::getObjectsInfo(int clientID, int& numOfAccounts, vector<DBAccount>& clientAccountsVec);

	int DBReader::getObjectsInfo(int accountID, int& numOfTransactions, vector<DBTransaction>& accountTransactionsVec);

	//Subfunctions for checkID exists

	bool DBReader::checkIDExists(int checkID, DBOType idType) {
		bool outputResponse = false;

		if (CLIENT == idType) {
			outputResponse = this->checkClientIDExists(checkID);
		}
		else if (ACCOUNT == idType) {
			outputResponse = this->checkAccountIDExists(checkID);
		}
		else if (TRANSACTION == idType) {
			outputResponse = this->checkAccountIDExists(checkID);
		}

		return outputResponse;
	}
}

//DBValidation source code
namespace EarnDB {
	//Private validate client function

	//Client login function

}

//DBWriter source code
namespace EarnDB {
	//Add object to database

	//Modify object in database

	//Delete object in database

}

*/