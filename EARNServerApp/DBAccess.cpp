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

//DBReader source code
namespace EarnDB {
	//Subfunctions for checkID exists

	//Get single objects

	//Get multiple objects

	//check ID exists public
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
