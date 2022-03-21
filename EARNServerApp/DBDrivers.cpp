#include <iostream>
#include <sstream>
#include <Windows.h>
#include <direct.h>

#include "DBDrivers.h"
#include"DBAccess.h"
#include "DBObjects.h"
#include <EARNStructs.h>

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
		return true;
	}

	int DBDriverInterface::checkIfDBExists() {

		try
		{
			// Connect to server on localhost as reader so nothing changes...
			mysqlx::abi2::r0::Session mySession(this->server, 33060, this->username, this->password, this->schema);
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;
			bool returnBool = this->initalizeDefaultDB();

			// Exit with error code
			return(returnBool);
		}

		return 0;
	}
}

//DBReader source code
namespace EarnDB {

	bool DBReader::checkClientIDExists(int checkClientID) {
		
		bool checkResult = false;	//bool we will be returning
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession("localhost", 33060, "EARNDBReader", "Gcugy6/fA{KR9H(r|:1Gp^qyd", "earnbankingdb");

			try
			{
				mySession.sql("USE EARNBankingDB").execute();

				std::cout << "checking if client is on DB..." << std::endl;
				
				mySession.sql("CALL checkClientExists(1, @my_var)").execute();
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @my_var").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();
				
				std::cout << "check client ID returned: " << (bool) resultRow[0] << std::endl;

				checkResult = (bool)resultRow[0];

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				exit(1);
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			exit(1);
		}
		return checkResult;
	}

	bool DBReader::checkAccountIDExists(int checkAccountID) {
		

		bool checkResult = false;	//bool we will be returning
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession("localhost", 33060, "EARNDBReader", "Gcugy6/fA{KR9H(r|:1Gp^qyd", "earnbankingdb");

			try
			{
				mySession.sql("USE EARNBankingDB").execute();

				std::cout << "checking if account is on DB..." << std::endl;

				mySession.sql("CALL checkAccountExists(1, @my_var)").execute();
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @my_var").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				std::cout << "check account ID returned: " << (bool)resultRow[0] << std::endl;

				checkResult = (bool)resultRow[0];

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				exit(1);
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			exit(1);
		}
		return checkResult;
	}

	bool DBReader::checkTransactionIDExists(int checkTransactionID) {

		bool checkResult = false;	//bool we will be returning
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession("localhost", 33060, "EARNDBReader", "Gcugy6/fA{KR9H(r|:1Gp^qyd", "earnbankingdb");

			try
			{
				mySession.sql("USE EARNBankingDB").execute();

				std::cout << "checking if trasaction is on DB..." << std::endl;

				mySession.sql("CALL checkTransactionExists(1, @my_var)").execute();
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @my_var").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				std::cout << "check transaction ID returned: " << (bool)resultRow[0] << std::endl;

				checkResult = (bool)resultRow[0];

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				exit(1);
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			exit(1);
		}
		return checkResult;
	}

	bool DBReader::checkIDExists(int checkID, EarnStructs::ObjectType idType) {
		bool outputResponse = false;

		if (EarnStructs::CLIENT == idType) {
			outputResponse = this->checkClientIDExists(checkID);
		}
		else if (EarnStructs::ACCOUNT == idType) {
			outputResponse = this->checkAccountIDExists(checkID);
		}
		else if (EarnStructs::TRANSACTION == idType) {
			outputResponse = this->checkAccountIDExists(checkID);
		}

		return outputResponse;
	}

	int DBReader::getObjectInfo(int objectID, DBClient& copyClient) {

		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession("localhost", 33060, "EARNDBReader", "Gcugy6/fA{KR9H(r|:1Gp^qyd", "earnbankingdb");

			try
			{
				mySession.sql("USE EARNBankingDB").execute();

				std::cout << "getting client from DB..." << std::endl;

				std::stringstream getQuery;
				getQuery << "CALL getClientInfo(" << objectID << ")";
				
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql(getQuery.str()).execute();

				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				//print results
				std::cout << "client returned:" << std::endl;
				std::cout << "Client ID: " << resultRow[0] << std::endl;
				std::cout << "Client First Name: " << resultRow[1] << std::endl;
				std::cout << "Client Last Name: " << resultRow[2] << std::endl;
				std::cout << "Client Email: " << resultRow[3] << std::endl;
				std::cout << "Client Phone Number: " << resultRow[4] << std::endl;
				std::cout << "Client Street: " << resultRow[5] << std::endl;
				std::cout << "Client City: " << resultRow[6] << std::endl;
				std::cout << "Client Province: " << resultRow[7] << std::endl;
				std::cout << "Client ZIP Code: " << resultRow[8] << std::endl;

				//now set the info into referenced client
				copyClient.setFirstName((std::string)resultRow[1]);
				copyClient.setLastName((std::string)resultRow[2]);
				copyClient.setEmail((std::string)resultRow[3]);
				copyClient.setPhoneNum((std::string)resultRow[4]);
				copyClient.setStreet((std::string)resultRow[5]);
				copyClient.setCity((std::string)resultRow[6]);
				copyClient.setProvince((std::string)resultRow[7]);
				copyClient.setZip((std::string)resultRow[9]);
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				exit(1);
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			exit(1);
		}
		return checkResult;
	}
}

//DBValidation source code
namespace EarnDB {
	

}

//DBWriter source code
namespace EarnDB {
	

}