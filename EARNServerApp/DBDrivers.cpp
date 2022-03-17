#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "DBDrivers.h"
#include"DBAccess.h"
#include "DBObjects.h"

//DBReader source code
namespace EarnDB {
	
	//Constructor
	DBDriverInterface::DBDriverInterface(std::string inputServer, std::string inputSchema, std::string inputUsername, std::string inputPassword) : server(inputServer), schema(inputSchema), username(inputUsername), password(password)	{
		//Always run this when instantiating the class, just to make sure it will exist for the runtime of the object
		if (!this->checkIfDBExists()) {
			std::cout << "Error connecting to database...";
			//if it doesn't exist then just run the init request command...
			this->initalizeDefaultDB();
		}
	}
	//Check & Initalize functions

	bool DBDriverInterface::initalizeDefaultDB() {
		std::cout << "Please enter your mysql server address\n:";
		std::string inputServer;
		std::getline(std::cin, inputServer);

		std::cout<<"admin username to run initalization script(commonly root)\n: ";
			std::string rootUsername;
		std::getline(std::cin, rootUsername);

		std::cout << "Please enter your password\n:";
		std::string rootPassword;
		std::getline(std::cin, rootPassword);

		std::stringstream initCommand;
		initCommand << "mysql - h " << inputServer << " - u " << rootUsername << " - p " << rootPassword << " " << " < " << "../EarnDBInitalization.sql";

		int returnStatus = system(initCommand.str().c_str());

		if (returnStatus) {
			return true;
		}
		else {
			return false;
		}
	}

	int DBDriverInterface::checkIfDBExists() {

		//Create sql controller / driver vars
		sql::Driver* driver;
		sql::Connection* con;
		
		//Try to establish a connection
		try
		{
			driver = get_driver_instance();
			con = driver->connect(this->server, this->username, this->password);
		}
		catch (sql::SQLException e)
		{
			std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;

			std::cout << "Creating DB from forewards engineer..." << std::endl;

			bool initalizationResult = this->initalizeDefaultDB();

			return initalizationResult;
		}

		delete con;	//think this is how to end connection...
		return 0;
	}
}

//DBReader source code
namespace EarnDB {

	//Check & Initalize functions

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
	

}

//DBWriter source code
namespace EarnDB {
	

}