#include <iostream>
#include <vector>
#include <cerrno>
#include <mysqlx/xdevapi.h>
#include <sstream>
#include <Windows.h>
#include <direct.h>

#include "DBDrivers.h"
#include"DBAccess.h"
#include "DBObjects.h"
#include <EARNStructs.h>

//DBDriverInterface & enum to string source code
namespace EarnDBDrivers {

	const std::string EnumToString(DBErrorType inputType)
	{
		switch (inputType)
		{
		case NO_DB_FOUND:		return "NO_DB_FOUND";
		case BAD_OBJECT_CREDENTIALS:	return "BAD_OBJECT_CREDENTIALS";
		case BAD_DB_CREDENTIALS:	return "BAD_DB_CREDENTIALS";
		case INSUFFICIENT_BALANCE:		return "INSUFFICIENT_BALANCE";
		case ACCOUNT_NOT_FOUND:	return "ACCOUNT_NOT_FOUND";
		case CLIENT_NOT_FOUND:	return "CLIENT_NOT_FOUND";
		case TRANSACTION_NOT_FOUND:		return "TRANSACTION_NOT_FOUND";
		case READ_ERROR:	return "READ_ERROR";
		case WRITE_ERROR:	return "WRITE_ERROR";
		case VALIDATION_ERROR:		return "VALIDATION_ERROR";
		default:			return "[Unknown Type]";
		}
	}

	const std::string EnumToString(DBSUCCESSTYPE inputType)
	{
		switch (inputType)
		{
		case DB_FOUND:		return "DB_FOUND";
		case GOOD_OBJECT_CREDENTIALS:	return "GOOD_OBJECT_CREDENTIALS";
		case GOODD_DB_CREDENTIALS:	return "GOODD_DB_CREDENTIALS";
		case SUFFICIENT_BALANCE:		return "SUFFICIENT_BALANCE";
		case ACCOUNT_FOUND:	return "ACCOUNT_FOUND";
		case CLIENT_FOUND:	return "CLIENT_FOUND";
		case TRANSACTION_FOUND:		return "TRANSACTION_FOUND";
		case READ_SUCCESS:	return "READ_SUCCESS";
		case WRITE_SUCCESS:	return "WRITE_SUCCESS";
		case VALIDATION_SUCCESS:		return "VALIDATION_SUCCESS";
		default:			return "[Unknown Type]";
		}
	}

	//Constructor
	DBDriverInterface::DBDriverInterface(
		std::string inputServer,
		std::string inputSchema,
		std::string inputUsername,
		std::string inputPassword)
		:
		server(inputServer),
		schema(inputSchema),
		username(inputUsername),
		password(inputPassword) {
		//Always run this when instantiating the class, just to make sure it will exist for the runtime of the object
		if (!this->checkIfDBExists()) {
			std::cout << "Error connecting to database...";
			//if it doesn't exist then just run the init request command...
			this->initalizeDefaultDB();
		}
	}

	//Get functions

	const std::string DBDriverInterface::getServer() {
		return this->server;
	}

	const std::string DBDriverInterface::getSchema() {
		return this->schema;
	}

	const std::string DBDriverInterface::getUsername() {
		return this->username;
	}

	const std::string DBDriverInterface::getPassword() {
		return this->password;
	}

	//Check & Initalize functions

	int DBDriverInterface::initalizeDefaultDB() {

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

		//set working dir to sql server where mysql init script lives then run it, while checking for errors
		int initSuccess = _chdir(sqlPath.c_str());

		if (initSuccess) {
			switch (errno)
			{
			case ENOENT:
				std::cerr << "ERROR: ENOENT - Unable to locate the directory: " << sqlPath << std::endl;
				break;
			case EINVAL:
				std::cerr << "ERROR: EINVAL - Invalid buffer." << std::endl;
				break;
			default:
				std::cerr << "ERROR: Unknown error." << std::endl;
			}
			//return early for an error
			return initSuccess;
		}

		initSuccess = system(fullCommand.c_str());
		if (initSuccess) {
			switch (errno) {
			case E2BIG:
				std::cerr << "ERROR: E2BIG - Argument list too large for system." << std::endl;
				break;
			case ENOENT:
				std::cerr << "ERROR: ENOENT - Command interpreter cannot be found." << std::endl;
				break;
			case ENOEXEC:
				std::cerr << "ERROR: ENOEXEC - Command - interpreter file cannot be executed because the format is not valid." << std::endl;
				break;
			case ENOMEM:
				std::cerr << "ERROR: ENOMEM - Memory Error (Not enough memory is available to execute command; or available memory has been corrupted, etc)" << std::endl;
			}
			//return early for an error
			return initSuccess;
		}

		//Some nice output to say what happened...
		char newDir[128];
		std::cout << "Ran Sql Script : \"" << fullCommand << "\" in: \"" << _getcwd(newDir, 128) << "\"" << std::endl;

		//change dir back and tell server user
		initSuccess = _chdir(workingDir);
		if (initSuccess) {

			switch (errno)
			{
			case ENOENT:
				std::cerr << "ERROR: ENOENT - Unable to locate the directory: " << sqlPath << std::endl;
				break;
			case EINVAL:
				std::cerr << "ERROR: EINVAL - Invalid buffer." << std::endl;
				break;
			default:
				std::cerr << "ERROR: Unknown error." << std::endl;
			}
			//return early for error
			return initSuccess;
		}

		std::cout << "Setting working directory back to: \"" << workingDir << "\"";

		return initSuccess;
	}

	int DBDriverInterface::checkIfDBExists() {

		try
		{
			// Connect to server on localhost as reader so nothing changes...
			mysqlx::abi2::r0::Session mySession(this->server, serverDBPort, this->username, this->password, this->schema);
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;
			int returnVal = this->initalizeDefaultDB();

			// Exit with error code
			return(returnVal);
		}

		return 0;
	}
}

//DBReader source code
namespace EarnDBDrivers {
	//Constructor
	DBReader::DBReader(
		std::string inputServer,
		std::string inputSchema,
		std::string inputUsername,
		std::string inputPassword)
		:
		DBDriverInterface(
			inputServer,
			inputSchema,
			inputUsername,
			inputPassword) {

		//nothing to do here so just leave it...

	}

	//Check functions

	int DBReader::checkClientIDExists(int checkClientID) {

		int checkResult;	//int we will be returning
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "checking if client is on DB..." << std::endl;

				//create a temporary client with only that id
				EarnDBObjects::DBClient copyClient;
				copyClient.setObjectID(checkClientID);

				mySession.sql(copyClient.getInfoFromDB()).execute();

				//now get OUT based on what the input var was (check function name)
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @checkResult").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				std::cout << "check client ID returned: " << (bool)resultRow[0] << std::endl;

				checkResult = (bool)resultRow[0];

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				return DBSqlError;
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			return DBConnError;
		}
		return checkResult;
	}

	int DBReader::checkAccountIDExists(int checkAccountID) {

		int checkResult;	//int we will be returning
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "checking if account is on DB..." << std::endl;

				//create a temporary account with only that id
				EarnDBObjects::DBAccount copyAccount;
				copyAccount.setObjectID(checkAccountID);

				mySession.sql(copyAccount.getInfoFromDB()).execute();

				//now get OUT based on what the input var was (check function name)
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @checkResult").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				std::cout << "check account ID returned: " << (bool)resultRow[0] << std::endl;

				checkResult = (bool)resultRow[0];

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				return DBSqlError;
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			return DBConnError;
		}
		return checkResult;
	}

	int DBReader::checkTransactionIDExists(int checkTransactionID) {

		int checkResult;	//int we will be returning
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getUsername(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "checking if transaction is on DB..." << std::endl;

				//create a temporary transaction with only that id
				EarnDBObjects::DBTransaction copyTransaction;
				copyTransaction.setObjectID(checkTransactionID);

				mySession.sql(copyTransaction.getInfoFromDB()).execute();

				//now get OUT based on what the input var was (check function name)
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @checkResult").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				std::cout << "check transaction ID returned: " << (bool)resultRow[0] << std::endl;

				checkResult = (bool)resultRow[0];

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				return DBSqlError;
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			return DBConnError;
		}
		return checkResult;
	}

	int DBReader::checkCredentialIDExists(int checkCredentialID) {

		int checkResult;	//bool we will be returning
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getUsername(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "checking if transaction is on DB..." << std::endl;

				//create a temporary transaction with only that id
				EarnDBObjects::DBCredential copyCredential;
				copyCredential.setObjectID(checkCredentialID);

				mySession.sql(copyCredential.getInfoFromDB()).execute();

				//now get OUT based on what the input var was (check function name)
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @checkResult").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				std::cout << "check credential ID returned: " << (bool)resultRow[0] << std::endl;

				checkResult = (bool)resultRow[0];

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				return DBSqlError;
			}

			// Note: session is closed automatically when session object
			// is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			return DBConnError;
		}
		return checkResult;
	}

	int DBReader::checkIDExists(int checkID, EarnStructs::ObjectType idType) {
		int outputResponse = DBSuccess;

		if (EarnStructs::CLIENT == idType) {
			outputResponse = this->checkClientIDExists(checkID);
		}
		else if (EarnStructs::ACCOUNT == idType) {
			outputResponse = this->checkAccountIDExists(checkID);
		}
		else if (EarnStructs::TRANSACTION == idType) {
			outputResponse = this->checkAccountIDExists(checkID);
		}
		else if (EarnStructs::CREDENTIALS == idType) {
			outputResponse = this->checkCredentialIDExists(checkID);
		}
		else {
			outputResponse = DBUnknownError;	//unknown reponse... shouldn't even be hit though from sub functions
		}

		return outputResponse;
	}

	//Get single functions

	int DBReader::getObjectInfo(int objectID, EarnDBObjects::DBClient& copyClient) {

		int getResult;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "getting client from DB..." << std::endl;

				//format query
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql(copyClient.getInfoFromDB()).execute();

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
				copyClient.setObjectID(resultRow[0]);
				copyClient.setFirstName((std::string)resultRow[1]);
				copyClient.setLastName((std::string)resultRow[2]);
				copyClient.setEmail((std::string)resultRow[3]);
				copyClient.setPhoneNum((std::string)resultRow[4]);
				copyClient.setStreet((std::string)resultRow[5]);
				copyClient.setCity((std::string)resultRow[6]);
				copyClient.setProvince((std::string)resultRow[7]);
				copyClient.setZip((std::string)resultRow[9]);

				getResult = DBSuccess;
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				getResult = DBSqlError;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			getResult = DBConnError;
		}

		return getResult;
	}

	int DBReader::getObjectInfo(int objectID, EarnDBObjects::DBAccount& copyAccount) {
		int getResult;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "getting account from DB..." << std::endl;

				//format query
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql(copyAccount.getInfoFromDB()).execute();

				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				//print results
				std::cout << "account returned:" << std::endl;
				std::cout << "Account ID: " << resultRow[0] << std::endl;
				std::cout << "Client ID: " << resultRow[1] << std::endl;

				EarnStructs::AccountType getType = ((EarnStructs::AccountType)(int)resultRow[2]);
				std::cout << "Account Type: " << typeid(getType).name() << std::endl;
				std::cout << "Account Balance: $" << resultRow[3] << std::endl;

				//now set the info into referenced account
				copyAccount.setObjectID(resultRow[0]);
				copyAccount.setAccountClientID((int)resultRow[1]);
				copyAccount.setAccountType(getType);
				copyAccount.setBalance((double)resultRow[3]);

				getResult = DBSuccess;
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				getResult = DBSqlError;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			getResult = DBConnError;
		}

		return getResult;
	}

	int DBReader::getObjectInfo(int objectID, EarnDBObjects::DBTransaction& copyTransaction) {

		int getResult;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "getting transaction from DB..." << std::endl;

				//format query
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql(copyTransaction.getInfoFromDB()).execute();

				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				//print results
				std::cout << "transaction returned:" << std::endl;
				std::cout << "Transaction ID: " << resultRow[0] << std::endl;
				std::cout << "Account ID: " << resultRow[1] << std::endl;

				EarnStructs::TransactionType getType = ((EarnStructs::TransactionType)(int)resultRow[2]);
				std::cout << "Transaction Type: " << typeid(getType).name() << std::endl;

				std::cout << "Previous Balance: $" << resultRow[3] << std::endl;
				std::cout << "New Balance: $" << resultRow[4] << std::endl;
				std::cout << "Secondary Account: " << resultRow[5] << std::endl;

				//now set the info into referenced client
				copyTransaction.setObjectID(resultRow[0]);
				copyTransaction.setTransactionAccountID((int)resultRow[1]);
				copyTransaction.setTransactionType(getType);
				copyTransaction.setTransactionPreviousBal((double)resultRow[3]);
				copyTransaction.setTransactionNewBal((double)resultRow[4]);
				copyTransaction.setTransactionSecondaryAcc((int)resultRow[5]);

				getResult = DBSuccess;
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				getResult = DBSqlError;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			getResult = DBConnError;
		}

		return getResult;
	}

	//Get multiple functions

	int DBReader::getObjectsInfo(int& numOfClients, std::vector<EarnDBObjects::DBClient>& clientsVec) {

		int getResult;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "getting Clients from DB..." << std::endl;

				//format query
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("CALL getAllClientsInfo()").execute();
				if (returnResult.hasData()) {
					mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

					if (resultRow)
					{
						std::cout << "List of Clients in DB: " << std::endl;
						int clientCount = 0;
						do {
							clientCount++;

							std::cout << "Client #" << clientCount << ": " << std::endl << std::endl;

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
							EarnDBObjects::DBClient newClient(
								(int)resultRow[0],
								((std::string)resultRow[1]).c_str(),
								((std::string)resultRow[2]).c_str(),
								((std::string)resultRow[3]).c_str(),
								((std::string)resultRow[4]).c_str(),
								((std::string)resultRow[5]).c_str(),
								((std::string)resultRow[6]).c_str(),
								((std::string)resultRow[7]).c_str(),
								((std::string)resultRow[8]).c_str());

							clientsVec.push_back(newClient);

							std::cout << std::endl;
						} while ((resultRow = returnResult.fetchOne()));

						//now set num of clients after all have been added
						numOfClients = clientCount;
					}
					else
					{
						std::cout << "Empty list of rows." << std::endl;
						getResult = -3;
					}
				}
				else
				{
					std::cout << "No row result." << std::endl;
					getResult = -3;
				}

				getResult = 0;
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				getResult = -1;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			getResult = -2;
		}

		return getResult;
	}

	int DBReader::getObjectsInfo(int clientID, int& numOfAccounts, std::vector<EarnDBObjects::DBAccount>& clientAccountsVec) {

		int getResult;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "getting Accounts from DB..." << std::endl;

				//format query
				std::stringstream getAccountsQuery;
				getAccountsQuery << "CALL getAccountsForClient(" << clientID << ")";
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql(getAccountsQuery.str()).execute();
				if (returnResult.hasData()) {
					mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

					if (resultRow)
					{
						std::cout << "List of Accounts for Client " << clientID << " in DB: " << std::endl;
						int accountCount = 0;
						do {
							accountCount++;
							std::cout << "Account #" << accountCount << ": " << std::endl << std::endl;

							//print results
							std::cout << "account returned:" << std::endl;
							std::cout << "Account ID: " << resultRow[0] << std::endl;
							std::cout << "Client ID: " << resultRow[1] << std::endl;

							EarnStructs::AccountType getType = ((EarnStructs::AccountType)(int)resultRow[2]);
							std::cout << "Account Type: " << typeid(getType).name() << std::endl;
							std::cout << "Account Balance: $" << resultRow[3] << std::endl;

							//now set the info into referenced account
							EarnDBObjects::DBAccount newAccount(
								(int)resultRow[0],
								(int)resultRow[1],
								getType,
								(double)resultRow[3]);

							clientAccountsVec.push_back(newAccount);

							std::cout << std::endl;
						} while ((resultRow = returnResult.fetchOne()));

						//now set num of clients after all have been added
						numOfAccounts = accountCount;
					}
					else
					{
						std::cout << "Empty list of rows." << std::endl;
						getResult = -3;
					}
				}
				else
				{
					std::cout << "No row result." << std::endl;
					getResult = -3;
				}

				getResult = 0;
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				getResult = -1;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			getResult = -2;
		}

		return getResult;
	}

	int DBReader::getObjectsInfo(int accountID, int& numOfTransactions, std::vector<EarnDBObjects::DBTransaction>& accountTransactionsVec) {

		int getResult;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "getting Transactions from DB..." << std::endl;

				//format query
				std::stringstream getAccountsQuery;
				getAccountsQuery << "CALL getTransactionsForAccount(" << accountID << ")";
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql(getAccountsQuery.str()).execute();
				if (returnResult.hasData()) {
					mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

					if (resultRow)
					{
						std::cout << "List of Transactions for Account " << accountID << " in DB: " << std::endl;
						int transactionCount = 0;
						do {
							transactionCount++;
							std::cout << "Transaction #" << transactionCount << ": " << std::endl << std::endl;

							//print results
							std::cout << "transaction returned:" << std::endl;
							std::cout << "Transaction ID: " << resultRow[0] << std::endl;
							std::cout << "Account ID: " << resultRow[1] << std::endl;

							EarnStructs::TransactionType getType = ((EarnStructs::TransactionType)(int)resultRow[2]);
							std::cout << "Transaction Type: " << typeid(getType).name() << std::endl;
							std::cout << "Transaction Time: $" << resultRow[3] << std::endl;
							std::cout << "Previous Balance: $" << resultRow[4] << std::endl;
							std::cout << "New Balance: $" << resultRow[5] << std::endl;
							std::cout << "Secondary Account: " << resultRow[6] << std::endl;

							//now set the info into referenced client
							EarnDBObjects::DBTransaction newTransaction(
								(int)resultRow[0],
								(int)resultRow[1],
								getType,
								((std::string)resultRow[3]).c_str(),
								(double)resultRow[4],
								(double)resultRow[5],
								(int)resultRow[6]);

							accountTransactionsVec.push_back(newTransaction);

							std::cout << std::endl;
						} while ((resultRow = returnResult.fetchOne()));

						//now set num of clients after all have been added
						numOfTransactions = transactionCount;
					}
					else
					{
						std::cout << "Empty list of rows." << std::endl;
						getResult = -3;
					}
				}
				else
				{
					std::cout << "No row result." << std::endl;
					getResult = -3;
				}

				getResult = 0;
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				getResult = -1;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			getResult = -2;
		}

		return getResult;
	}
}

//DBValidation source code
namespace EarnDBDrivers {
	//Constructor
	DBValidation::DBValidation(
		std::string inputServer,
		std::string inputSchema,
		std::string inputUsername,
		std::string inputPassword)
		:
		DBReader(
			inputServer,
			inputSchema,
			inputUsername,
			inputPassword) {
		//nothing to do here so just leave it...
	}

	//Validation functions

	int DBValidation::validateClient(int usernumber, std::string username, std::string passwordHash) {

		int returnID = 0;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "checking login validation information against DB..." << std::endl;

				//format query
				std::stringstream queryString;

				//usernumber == 0 if we are using string otherwise use number
				if (0 == usernumber) {
					queryString << "CALL checkLoginNamePass(" << username << ", " << passwordHash << ", @returnID)";
				}
				else {
					queryString << "CALL checkLoginNumberPass(" << usernumber << ", " << passwordHash << ", @returnID)";
				}

				mySession.sql(queryString.str()).execute();

				//now get OUT based on what the input var was (check function name)
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @returnID").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				//print results
				std::cout << "login attempt returned client id:" << resultRow[0] << std::endl;
				returnID = (int)resultRow[0];
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cout << "The following error occurred: " << err << std::endl;
				returnID = -1;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cout << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			returnID = -2;
		}

		return returnID;
	}

	EarnDBObjects::DBClient DBValidation::clientLogin(std::string username, std::string passwordHash) {
		EarnDBObjects::DBClient returnClient;
		int returnID = this->validateClient(0, username, passwordHash);

		//(-3 if ID doesn't exist, -2 for conenction error, -1 for sql error)
		if (returnID > 0) {

			//overload return ID for second operation, since it's return overwrites last...
			returnID = this->getObjectInfo(returnID, returnClient);
			if (0 < returnID) {
				std::cout << "Client found returning info..." << std::endl;
			}
			else if (-3 == returnID) {
				std::cerr << "ERROR: couldn't get info... ID doesn't exist" << std::endl;
			}
			else if (-2 == returnID) {
				std::cerr << "ERROR: DB connection error" << std::endl;
			}
			else if (-1 == returnID) {
				std::cerr << "ERROR: sql error" << std::endl;
			}
			else {
				std::cerr << "ERROR: unknown error" << std::endl;
			}
		}
		else if (0 == returnID) {
			std::cerr << "ERROR: validation error client ID not returned..." << std::endl;
		}
		else if (-2 == returnID) {
			std::cerr << "ERROR: DB connection error" << std::endl;
		}
		else if (-1 == returnID) {
			std::cerr << "ERROR: sql error" << std::endl;
		}
		else {
			std::cerr << "ERROR: unknown error" << std::endl;
		}

		//return the client anyways since it will  be empty if nothing was found
		return returnClient;
	}

	EarnDBObjects::DBClient DBValidation::clientLogin(int usernumber, std::string passwordHash) {
		EarnDBObjects::DBClient returnClient;
		int returnID = this->validateClient(usernumber, "", passwordHash);

		//(-3 if ID doesn't exist, -2 for conenction error, -1 for sql error)
		if (returnID > 0) {

			//overload return ID for second operation, since it's return overwrites last...
			returnID = this->getObjectInfo(returnID, returnClient);
			if (0 < returnID) {
				std::cout << "Client found returning info..." << std::endl;
			}
			else if (-3 == returnID) {
				std::cerr << "ERROR: couldn't get info... ID doesn't exist" << std::endl;
			}
			else if (-2 == returnID) {
				std::cerr << "ERROR: DB connection error" << std::endl;
			}
			else if (-1 == returnID) {
				std::cerr << "ERROR: sql error" << std::endl;
			}
			else {
				std::cerr << "ERROR: unknown error" << std::endl;
			}
		}
		else if (0 == returnID) {
			std::cerr << "ERROR: validation error client ID not returned..." << std::endl;
		}
		else if (-2 == returnID) {
			std::cerr << "ERROR: DB connection error" << std::endl;
		}
		else if (-1 == returnID) {
			std::cerr << "ERROR: sql error" << std::endl;
		}
		else {
			std::cerr << "ERROR: unknown error" << std::endl;
		}

		//return the client anyways since it will  be empty if nothing was found
		return returnClient;
	}

	EarnDBObjects::DBClient DBValidation::clientLogin(EarnStructs::CredentialInfo inputCredentials) {
		EarnDBObjects::DBClient returnClient;
		int returnID = this->validateClient(inputCredentials.usernumber, inputCredentials.username, inputCredentials.userPasswordHash);

		//(-3 if ID doesn't exist, -2 for conenction error, -1 for sql error)
		if (returnID > 0) {
			
			//overload return ID for second operation, since it's return overwrites last...
			returnID = this->getObjectInfo(returnID, returnClient);
			if (0 < returnID) {
				std::cout << "Client found returning info..." << std::endl;
			}
			else if (-3 == returnID) {
				std::cerr << "ERROR: couldn't get info... ID doesn't exist" << std::endl;
			}
			else if (-2 == returnID) {
				std::cerr << "ERROR: DB connection error" << std::endl;
			}
			else if (-1 == returnID) {
				std::cerr << "ERROR: sql error" << std::endl;
			}
			else {
				std::cerr << "ERROR: unknown error" << std::endl;
			}
		}
		else if (0 == returnID) {
			std::cerr << "ERROR: validation error client ID not returned..." << std::endl;
		}
		else if (-2 == returnID) {
			std::cerr << "ERROR: DB connection error" << std::endl;
		}
		else if (-1 == returnID) {
			std::cerr << "ERROR: sql error" << std::endl;
		}
		else {
			std::cerr << "ERROR: unknown error" << std::endl;
		}

		//return the client anyways since it will  be empty if nothing was found
		return returnClient;
	}
}

//DBWriter source code
namespace EarnDBDrivers {
	//Constructor
	DBWriter::DBWriter(
		std::string inputServer,
		std::string inputSchema,
		std::string inputUsername,
		std::string inputPassword)
		:
		DBReader(
			inputServer,
			inputSchema,
			inputUsername,
			inputPassword) {

		//nothing to do here so just leave it...

	}

	int DBWriter::addObject(EarnDBObjects::DBObject& inputObj) {

		int returnID = 0;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "adding object to database" << std::endl;

				mySession.sql(inputObj.addInfoToDB()).execute();

				//now get OUT based on what the input var was (check function name)
				mysqlx::abi2::r0::SqlResult returnResult = mySession.sql("SELECT @newID").execute();
				mysqlx::abi2::r0::Row resultRow = returnResult.fetchOne();

				//print results
				std::cout << "allocated new object id:" << resultRow[0] << std::endl;
				returnID = (int)resultRow[0];
			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cerr << "The following error occurred: " << err << std::endl;
				returnID = -1;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cerr << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			returnID = -2;
		}

		return returnID;
	}

	int DBWriter::modifyObjectInfo(EarnDBObjects::DBObject& inputObj) {

		int returnVal = 0;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "adding object to database" << std::endl;

				mySession.sql(inputObj.modifyInfoInDB()).execute();

				//nothing to check, leave that for function that calls this...
				returnVal = 0;

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cerr << "The following error occurred: " << err << std::endl;
				returnVal = -1;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cerr << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			returnVal = -2;
		}

		return returnVal;
	}

	int DBWriter::deleteObject(EarnDBObjects::DBObject& inputObj) {

		int returnID = 0;
		try
		{
			// Connect to server on localhost
			mysqlx::abi2::r0::Session mySession(this->getServer(), serverDBPort, this->getUsername(), this->getPassword(), this->getSchema());

			try
			{
				std::stringstream schemaString;
				schemaString << "USE " << this->getSchema();
				mySession.sql(schemaString.str()).execute();

				std::cout << "adding object to database" << std::endl;

				mySession.sql(inputObj.deleteInfoInDB()).execute();

			}
			catch (const mysqlx::abi2::r0::Error& err)
			{
				std::cerr << "The following error occurred: " << err << std::endl;
				returnID = -1;
			}

			// Note: session is closed automatically when session object is destructed.
		}
		catch (const mysqlx::abi2::r0::Error& err)
		{
			std::cerr << "The database session could not be opened: " << err << std::endl;

			// Exit with error code
			returnID = -2;
		}

		return returnID;
	}
}