#include <iostream>

#include"DBAccess.h"

//DBAccessInterface source code
namespace EarnDBAccess {
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