#pragma once
#include <string>

namespace EarnDB {

	//virtual access interface for DB
	class DBAccessInterface {
		int objectID;

	public:
		//Constructors

		//Default constructor
		DBAccessInterface();

		//Copy constructor
		DBAccessInterface(const DBAccessInterface& copyAccessObject);

		//Parametrized constructor
		DBAccessInterface(int newObjectID);

		//Get ID function for lower level classes to "reach up"
		int getObjectID();

		//Set ID function in case the object is uninitalized
		void setObjectID(int newObjectID);

		//Virtualized functions for lower level implementations

		//Get Object info query from DB, @checkResult for OUT var
		virtual std::string getInfoFromDB() = 0;

		//Add info from object into database, @newID for OUT var
		virtual std::string addInfoToDB() = 0;

		//Modify info of object in database related to object
		virtual std::string modifyInfoInDB() = 0;

		//Delete info of object in database related to object
		virtual std::string deleteInfoInDB() = 0;

		//Check if object type exists, @checkResult for OUT var
		virtual std::string checkObjectExists() = 0;
	};
}
