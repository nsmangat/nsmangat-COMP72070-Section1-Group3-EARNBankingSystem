#include <string>
#include <sstream>
#include <Windows.h>
#include <direct.h>
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

		//input server IP / localhost
		std::cout << "Please enter your mysql server address (localhost for local server)\n:";
		std::string inputServer;
		std::getline(std::cin, inputServer);

		//input username
		std::cout << "admin username to run initalization script(commonly root)\n: ";
		std::string rootUsername;
		std::getline(std::cin, rootUsername);

		//hide console input and request password
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode = 0;
		GetConsoleMode(hStdin, &mode);
		SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

		std::cout << "Please enter your password\n:";
		std::string rootPassword;
		std::getline(std::cin, rootPassword);

		//set back to normal in case of other inputs somewhere else...
		SetConsoleMode(hStdin, mode);

		//set paths & stuff for chdir + system to use
		std::string sqlPath;
		sqlPath = (std::string)"C:\\Program Files\\MySQL\\MySQL Server 8.0\\bin\\";
		std::string initFile = "\\EarnDBInitalization.sql\"";

		//save working dir since that is where .sql is...
		char workingDir[128];
		std::cout << _getcwd(workingDir, 128) << std::endl;

		std::stringstream sqlStream;
		sqlStream << "mysql --batch -h" << inputServer << " -u" << rootUsername << " -p" << rootPassword << " < \"" << workingDir << initFile;
		
		std::string fullCommand = sqlStream.str();
		std::cout << fullCommand.c_str() << std::endl << std::endl;

		//set working dir to sql server where mysql init script lives then run it
		_chdir(sqlPath.c_str());
		system(fullCommand.c_str());

		//Some nice output to say what happened...
		char newDir[128];
		_getcwd(newDir, 128);

		std::cout << "Ran Sql Script : \"" << fullCommand << "\" in: \""<< newDir << "\"" << std::endl;
		
		//change dir back and tell server user
		_chdir(workingDir);
		std::cout << "Setting working directory back to: \"" << workingDir << "\"";		
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