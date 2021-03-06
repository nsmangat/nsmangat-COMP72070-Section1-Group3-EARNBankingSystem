#include <vector>
#include <iostream>
#include <sstream>
#include <cctype>

#include "DBAccess.h"
#include "DBObjects.h"
#include <EARNStructs.h>

//DBObject class source code, and library funcs splitting up namespace to make it easier to read & collapse code areas...
namespace EarnDBObjects {
	int cleanCharString(char* inputCharString) {
		char* currentChar = inputCharString;
		int outputCount = 0;
		do {
			outputCount++;
			currentChar = (inputCharString + outputCount);
		} while (std::isprint(*(currentChar)));

		outputCount++;
		*(currentChar) = *(inputCharString + outputCount);

		if ('\0' != *(currentChar)) {
			*(currentChar) = '\0';
		}

		return outputCount;
	}

	//Constructors

	DBObject::DBObject() {
		this->setDBOType(EarnStructs::OBJECTNULL);	//type is null telling me it is unallocated...
	}

	DBObject::DBObject(const DBObject& copyObject) :EarnDBAccess::DBAccessInterface(copyObject) {
		this->setDBOType(copyObject.objectType);
	}

	DBObject::DBObject(EarnStructs::ObjectType initalizeType, int objectID) : EarnDBAccess::DBAccessInterface(objectID) {
		this->setDBOType(initalizeType);
	}

	//Get function

	EarnStructs::ObjectType DBObject::getDBOType() {
		return this->objectType;
	}

	//Set function

	void DBObject::setDBOType(EarnStructs::ObjectType inputType) {
		this->objectType = inputType;
	}
}

//DBClient class source code
namespace EarnDBObjects {
	//Constructors

	DBClient::DBClient() :DBObject(EarnStructs::CLIENT, 0) {
		//manually allocate them as null just in case (could ignore, but wanted the assurance...)
		this->setFirstName(NULL);
		this->setLastName(NULL);
		this->setEmail(NULL);
		this->setPhoneNum(NULL);
		this->setStreet(NULL);
		this->setCity(NULL);
		this->setProvince(NULL);
		this->setZip(NULL);
	}

	DBClient::DBClient(const EarnStructs::ClientInfo& copyInfo) :DBObject(EarnStructs::CLIENT, 0) {
		this->setFirstName(copyInfo.firstName);
		this->setLastName(copyInfo.lastName);
		this->setEmail(copyInfo.email);
		this->setPhoneNum(copyInfo.phoneNumber);
		this->setStreet(copyInfo.street);
		this->setCity(copyInfo.city);
		this->setProvince(copyInfo.province);
		this->setZip(copyInfo.zipcode);
	}

	DBClient::DBClient(int inputObjectID, const char* inputFirst, const char* inputLast, const char* inputEmail, const char* inputPhone, const char* inputStreet, const char* inputCity, const char* inputProvince, const char* inputZip) :DBObject(EarnStructs::CLIENT, inputObjectID) {
		this->setFirstName(inputFirst);
		this->setLastName(inputLast);
		this->setEmail(inputEmail);
		this->setPhoneNum(inputPhone);
		this->setStreet(inputStreet);
		this->setCity(inputCity);
		this->setProvince(inputProvince);
		this->setZip(inputZip);
	}

	DBClient::DBClient(const DBClient& copyClient) :DBObject::DBObject(copyClient) {
		this->setFirstName(copyClient.clientInfo.firstName);
		this->setLastName(copyClient.clientInfo.lastName);
		this->setEmail(copyClient.clientInfo.email);
		this->setPhoneNum(copyClient.clientInfo.phoneNumber);
		this->setStreet(copyClient.clientInfo.street);
		this->setCity(copyClient.clientInfo.city);
		this->setProvince(copyClient.clientInfo.province);
		this->setZip(copyClient.clientInfo.zipcode);
	}

	//Get functions

	const char* DBClient::getFirstName(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.firstName);	//since it will always be an array of 45
		return (const char*)(this->clientInfo.firstName);	//cast pointer to first name as a const so it cannot be altered...
	}
	std::string DBClient::getFirstName() {
		std::string outputFirstName(this->clientInfo.firstName);	//simplest way to do this...
		return outputFirstName;	//use substr so I don't get a bunch of junk after...
	}

	const char* DBClient::getLastName(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.lastName);
		return (const char*)(this->clientInfo.lastName);
	}
	std::string DBClient::getLastName() {
		std::string outputLastName(this->clientInfo.lastName);
		return outputLastName;
	}

	const char* DBClient::getEmail(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.email);
		return (const char*)(this->clientInfo.email);
	}
	std::string DBClient::getEmail() {
		std::string outputEmail(this->clientInfo.email);
		return outputEmail;
	}

	const char* DBClient::getPhoneNum(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.phoneNumber);
		return (const char*)(this->clientInfo.phoneNumber);
	}
	std::string DBClient::getPhoneNum() {
		std::string outputPhoneNum(this->clientInfo.phoneNumber);
		return outputPhoneNum;
	}

	const char* DBClient::getStreet(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.street);
		return (const char*)(this->clientInfo.street);
	}
	std::string DBClient::getStreet() {
		std::string outputStreet(this->clientInfo.street);
		return outputStreet;
	}

	const char* DBClient::getCity(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.city);
		return (const char*)(this->clientInfo.city);
	}
	std::string DBClient::getCity() {
		std::string outputCity(this->clientInfo.city);
		return outputCity;
	}

	const char* DBClient::getProvince(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.province);
		return (const char*)(this->clientInfo.province);
	}
	std::string DBClient::getProvince() {
		std::string outputProvince(this->clientInfo.province);
		return outputProvince;
	}

	const char* DBClient::getZip(int& lenOfArray) {
		lenOfArray = strlen(this->clientInfo.zipcode);
		return (const char*)(this->clientInfo.zipcode);
	}
	std::string DBClient::getZip() {
		std::string outputZip(this->clientInfo.zipcode);
		return outputZip;
	}

	EarnStructs::ClientInfo DBClient::getClientInfo() {
		return this->clientInfo;
	}

	//Set functions

	void DBClient::setFirstName(const char* newFirst) {
		if (NULL != newFirst) {
			strcpy_s(this->clientInfo.firstName, EarnStructs::VARCHARLEN, newFirst);
		}
	}
	void DBClient::setFirstName(std::string newFirst) {
		if (!newFirst.empty()) {
			strcpy_s(this->clientInfo.firstName, EarnStructs::VARCHARLEN, newFirst.c_str());
		}
	}

	void DBClient::setLastName(const char* newLast) {
		if (NULL != newLast) {
			strcpy_s(this->clientInfo.lastName, EarnStructs::VARCHARLEN, newLast);
		}
	}
	void DBClient::setLastName(std::string newLast) {
		if (!newLast.empty()) {
			strcpy_s(this->clientInfo.lastName, EarnStructs::VARCHARLEN, newLast.c_str());
		}
	}

	void DBClient::setEmail(const char* newEmail) {
		if (NULL != newEmail) {
			strcpy_s(this->clientInfo.email, EarnStructs::VARCHARLEN, newEmail);
		}
	}
	void DBClient::setEmail(std::string newEmail) {
		if (!newEmail.empty()) {
			strcpy_s(this->clientInfo.email, EarnStructs::VARCHARLEN, newEmail.c_str());
		}
	}

	void DBClient::setPhoneNum(const char* newPhone) {
		if (NULL != newPhone) {
			strcpy_s(this->clientInfo.phoneNumber, EarnStructs::VARCHARLEN, newPhone);
		}
	}
	void DBClient::setPhoneNum(std::string newPhone) {
		if (!newPhone.empty()) {
			strcpy_s(this->clientInfo.phoneNumber, EarnStructs::VARCHARLEN, newPhone.c_str());
		}
	}

	void DBClient::setStreet(const char* newStreet) {
		if (NULL != newStreet) {
			strcpy_s(this->clientInfo.street, EarnStructs::VARCHARLEN, newStreet);
		}
	}
	void DBClient::setStreet(std::string newStreet) {
		if (!newStreet.empty()) {
			strcpy_s(this->clientInfo.street, EarnStructs::VARCHARLEN, newStreet.c_str());
		}
	}

	void DBClient::setCity(const char* newCity) {
		if (NULL != newCity) {
			strcpy_s(this->clientInfo.city, EarnStructs::VARCHARLEN, newCity);
		}
	}
	void DBClient::setCity(std::string newCity) {
		if (!newCity.empty()) {
			strcpy_s(this->clientInfo.city, EarnStructs::VARCHARLEN, newCity.c_str());
		}
	}

	void DBClient::setProvince(const char* newProvince) {
		if (NULL != newProvince) {
			strcpy_s(this->clientInfo.province, EarnStructs::VARCHARLEN, newProvince);
		}
	}
	void DBClient::setProvince(std::string newProvince) {
		if (!newProvince.empty()) {
			strcpy_s(this->clientInfo.province, EarnStructs::VARCHARLEN, newProvince.c_str());
		}
	}

	void DBClient::setZip(const char* newZip) {
		if (NULL != newZip) {
			strcpy_s(this->clientInfo.zipcode, EarnStructs::ZIPLEN, newZip);
		}
	}
	void DBClient::setZip(std::string newZip) {
		if (!newZip.empty()) {
			strcpy_s(this->clientInfo.zipcode, EarnStructs::ZIPLEN, newZip.c_str());
		}
	}

	//No set with struct since you should be using a constructor for that!

	//Inherited functions

	std::string DBClient::displayInfo() {

		//Set formatted output for output string so that it has each var / line...
		std::stringstream outputStream;
		outputStream << "Client ID: " << this->getObjectID() << '\n';
		outputStream << "First Name: " << this->getFirstName() << '\n';
		outputStream << "Last Name: " << this->getLastName() << '\n';
		outputStream << "Email: " << this->getEmail() << '\n';
		outputStream << "Phone Number: " << this->getPhoneNum() << '\n';
		outputStream << "Street: " << this->getStreet() << '\n';
		outputStream << "City: " << this->getCity() << '\n';
		outputStream << "Province: " << this->getProvince() << '\n';
		outputStream << "Zip" << this->getZip() << '\n';

		//lets me allocate it simpler (IMO)
		return outputStream.str();
	}

	//std::string DBClient::getLogData() {

	//}

	std::string DBClient::getInfoFromDB() {
		/*
			IN check_client_id INT,
			OUT check_result BOOL
		*/

		std::stringstream outputQuery;
		outputQuery << "CALL getClientInfo(" << this->getObjectID() << ")";

		return outputQuery.str();
	}

	std::string DBClient::addInfoToDB() {
		/*
			IN input_firstName VARCHAR(45),
			IN input_lastName VARCHAR(45),
			IN input_email VARCHAR(45),
			IN input_phone_number VARCHAR(45),
			IN input_street VARCHAR(45),
			IN input_city VARCHAR(45),
			IN input_zipCode VARCHAR(6),
			OUT new_client_id INT)
		*/

		//setup output call based on addClient procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL addClient('" << this->getFirstName();
		outputQuery << "', '" << this->getLastName();
		outputQuery << "', '" << this->getEmail();
		outputQuery << "', '" << this->getPhoneNum();
		outputQuery << "', '" << this->getStreet();
		outputQuery << "', '" << this->getCity();
		outputQuery << "', '" << this->getProvince();
		outputQuery << "', '" << this->getZip();
		outputQuery << "', @newID)";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBClient::modifyInfoInDB() {
		/*
			IN input_client_id INT,
			IN input_firstName VARCHAR(45),
			IN input_lastName VARCHAR(45),
			IN input_email VARCHAR(45),
			IN input_number VARCHAR(45),
			IN input_street VARCHAR(45),
			IN input_city VARCHAR(45),
			IN input_zipCode VARCHAR(6)
		*/

		//setup output call based on updateClient procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL updateClient('" << this->getObjectID();
		outputQuery << "', '" << this->getFirstName();
		outputQuery << "', '" << this->getLastName();
		outputQuery << "', '" << this->getEmail();
		outputQuery << "', '" << this->getPhoneNum();
		outputQuery << "', '" << this->getStreet();
		outputQuery << "', '" << this->getCity();
		outputQuery << "', '" << this->getProvince();
		outputQuery << "', '" << this->getZip();
		outputQuery << "')";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBClient::deleteInfoInDB() {
		/*
			IN input_client_id INT
		*/

		//setup output call based on deleteClient procedure in mySql DB (inputs above)
		std::stringstream outputQuery;
		outputQuery << "CALL deleteClient(" << this->getObjectID() << ")";
		return outputQuery.str();
	}

	std::string DBClient::checkObjectExists() {
		/*
			IN check_client_id INT,
			OUT check_result BOOL)
		*/
		//setup output call based on checkClientExists procedure in mySql DB (inputs above)
		std::stringstream outputQuery;
		outputQuery << "CALL checkClientExists(" << this->getObjectID() << ", @checkResult)";
		return outputQuery.str();
	}
}

//DBCredential class source code
namespace EarnDBObjects {
	//Constructors

	DBCredential::DBCredential() :DBObject(EarnStructs::CREDENTIALS, 0) {
		this->setClientID(NULL);
		this->setUsername(NULL);
		this->setUsernumber(NULL);
		this->setPasswordHash(NULL);
	}

	DBCredential::DBCredential(const EarnStructs::CredentialInfo copyInfo) :DBObject(EarnStructs::CREDENTIALS, 0) {
		this->setClientID(copyInfo.clientID);
		this->setUsername(copyInfo.username);
		this->setUsernumber(copyInfo.usernumber);
		this->setPasswordHash(copyInfo.userPasswordHash);
	}

	DBCredential::DBCredential(const DBCredential& copyCredentials) :DBObject(copyCredentials) {
		this->setClientID(copyCredentials.credentialInfo.clientID);
		this->setUsername(copyCredentials.credentialInfo.username);
		this->setUsernumber(copyCredentials.credentialInfo.usernumber);
		this->setPasswordHash(copyCredentials.credentialInfo.userPasswordHash);
	}

	DBCredential::DBCredential(int inputObjectID, int inputClientID, const char* inputUsername, unsigned int inputUsernumber, const char* inputPasswordHash) :DBObject(EarnStructs::CREDENTIALS, inputObjectID) {
		this->setClientID(inputClientID);
		this->setUsername(inputUsername);
		this->setUsernumber(inputUsernumber);
		this->setPasswordHash(inputPasswordHash);
	}

	//Get functions

	int DBCredential::getClientID() {
		return this->credentialInfo.clientID;
	}

	const char* DBCredential::getUsername(int& lenOfArray) {
		lenOfArray = EarnStructs::VARCHARLEN;
		return (const char*)(this->credentialInfo.username);
	}
	std::string DBCredential::getUsername() {
		std::string outputUsernameOrNum(this->credentialInfo.username);
		return outputUsernameOrNum.substr(0, strlen(this->credentialInfo.username));
	}

	unsigned int DBCredential::getUsernumber() {
		return this->credentialInfo.usernumber;
	}

	const char* DBCredential::getPasswordHash(int& lenOfArray) {
		lenOfArray = EarnStructs::VARCHARLEN;
		return (const char*)(this->credentialInfo.userPasswordHash);
	}
	std::string DBCredential::getPasswordHash() {
		std::string outputPasswordHash(this->credentialInfo.userPasswordHash);
		return outputPasswordHash.substr(0, strlen(this->credentialInfo.userPasswordHash));
	}

	EarnStructs::CredentialInfo DBCredential::getCredentialInfo() {
		return this->credentialInfo;
	}

	//Set functions

	void DBCredential::setClientID(int newClientID) {
		this->credentialInfo.clientID = newClientID;
	}

	void DBCredential::setUsername(const char* newUsername) {
		if (NULL != newUsername) {
			strcpy_s(this->credentialInfo.username, EarnStructs::VARCHARLEN, newUsername);
		}
	}
	void DBCredential::setUsername(std::string newUsername) {
		if (!newUsername.empty()) {
			strcpy_s(this->credentialInfo.username, EarnStructs::VARCHARLEN, newUsername.c_str());
		}
	}

	void DBCredential::setUsernumber(unsigned int newUsernumber) {
		this->credentialInfo.usernumber = newUsernumber;
	}

	void DBCredential::setPasswordHash(const char* newPasswordHash) {
		if (NULL != newPasswordHash) {
			strcpy_s(this->credentialInfo.userPasswordHash, EarnStructs::VARCHARLEN, newPasswordHash);
		}
	}
	void DBCredential::setPasswordHash(std::string newPasswordHash) {
		if (!newPasswordHash.empty()) {
			strcpy_s(this->credentialInfo.userPasswordHash, EarnStructs::VARCHARLEN, newPasswordHash.c_str());
		}
	}

	//Inherited functions

	std::string DBCredential::displayInfo() {
		std::stringstream outputStream;
		outputStream << "Credential ID: " << this->getObjectID() << '\n';
		outputStream << "Client ID: " << this->getClientID() << '\n';
		outputStream << "Username: " << this->getUsername() << '\n';
		outputStream << "Usernumber: " << this->getUsernumber() << '\n';
		outputStream << "Password Hash: " << this->getPasswordHash() << '\n';

		return outputStream.str();
	}

	//std::string DBCredential::getLogData() {

	//}

	std::string DBCredential::getInfoFromDB() {
		/*
			IN check_credential_id INT,
			OUT check_result BOOL
		*/

		std::stringstream outputQuery;
		outputQuery << "CALL getCredentialInfo(" << this->getObjectID() << ")";

		return outputQuery.str();
	}

	std::string DBCredential::addInfoToDB() {
		/*
			IN input_client_id INT,
			IN input_username VARCHAR(45),
			IN input_usernumber INT UNSIGNED,
			IN input_password_hash VARCHAR(45),
			OUT new_credential_id INT
		*/

		//setup output call based on addCredential procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL addCredential(" << this->getClientID();
		outputQuery << ", '" << this->getUsername();
		outputQuery << "', " << this->getUsernumber();
		outputQuery << ", '" << this->getPasswordHash();
		outputQuery << "', @newID)";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBCredential::modifyInfoInDB() {
		/*
			IN input_client_id INT,
			IN input_username VARCHAR(45),
			IN input_usernumber INT,
			IN input_password_hash VARCHAR(45)
		*/

		//setup output call based on updateCredential procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL updateCredential(" << this->getClientID();
		outputQuery << ", '" << this->getUsername();
		outputQuery << "', " << this->getUsernumber();
		outputQuery << ", '" << this->getPasswordHash();
		outputQuery << "')";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBCredential::deleteInfoInDB() {
		/*
			IN input_credential_id INT
		*/

		//setup output call based on deleteCredential procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL deleteCredential(" << this->getClientID() << ")";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBCredential::checkObjectExists() {
		/*
			IN check_credential_id INT,
			OUT check_result BOOL
		*/

		//setup output call based on checkCredentialExists procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL checkCredentialExists(" << this->getClientID() << ", @checkResult)";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}
}

//DBAccount class source code
namespace EarnDBObjects {
	//Constructors

	DBAccount::DBAccount() :DBObject(EarnStructs::ACCOUNT, 0) {
		this->setAccountClientID(0);
		this->setAccountType(EarnStructs::ACCOUNTNULL);
		this->setBalance(NULL);
	}

	DBAccount::DBAccount(const EarnStructs::AccountInfo copyInfo) :DBObject(EarnStructs::ACCOUNT, 0) {
		this->setAccountClientID(copyInfo.clientID);
		this->setAccountType(copyInfo.accountType);
		this->setBalance(copyInfo.accountBalance);
	}

	DBAccount::DBAccount(const DBAccount& copyAccount) :DBObject(copyAccount) {
		this->setAccountClientID(copyAccount.accountInfo.clientID);
		this->setAccountType(copyAccount.accountInfo.accountType);
		this->setBalance(copyAccount.accountInfo.accountBalance);
	}

	DBAccount::DBAccount(int inputObjectID, int inputClientID, EarnStructs::AccountType inputAccountType, double inputBalance) :DBObject(EarnStructs::ACCOUNT, inputObjectID) {
		this->setAccountClientID(inputClientID);
		this->setAccountType(inputAccountType);
		this->setBalance(inputBalance);
	}

	//Get functions

	EarnStructs::AccountType DBAccount::getAccountType() {
		return this->accountInfo.accountType;
	}

	int DBAccount::getAccountClientID() {
		return this->accountInfo.clientID;
	}

	double DBAccount::getAccountBalance() {
		return this->accountInfo.accountBalance;
	}

	EarnStructs::AccountInfo DBAccount::getAccountInfo() {
		return this->accountInfo;
	}

	//Set functions

	void DBAccount::setAccountType(EarnStructs::AccountType newType) {
		this->accountInfo.accountType = newType;
	}

	void DBAccount::setAccountClientID(int newClientID) {
		this->accountInfo.clientID = newClientID;
	}

	void DBAccount::setBalance(double newBalance) {
		this->accountInfo.accountBalance = newBalance;
	}

	void DBAccount::setAccountInfo(EarnStructs::AccountInfo newAccountInfo) {
		this->accountInfo = newAccountInfo;
	}

	//Inherited functions

	std::string DBAccount::displayInfo() {

		//Set formatted output for output string so that it has each var / line...
		std::stringstream outputStream;
		outputStream << "Account ID: " << this->getObjectID() << '\n';
		outputStream << "Client ID: " << this->getAccountClientID() << '\n';
		outputStream << "Account Type: " << EnumToString(this->getAccountType()) << '\n';
		outputStream << "Balance: " << this->getAccountBalance() << '\n';

		//lets me allocate it simpler (IMO)
		return outputStream.str();
	}

	//std::string DBAccount::getLogData() {

	//}

	std::string DBAccount::getInfoFromDB() {
		/*
			IN check_account_id INT,
			OUT check_result BOOL
		*/

		std::stringstream outputQuery;
		outputQuery << "CALL getAccountInfo(" << this->getObjectID() << ")";

		return outputQuery.str();
	}

	std::string DBAccount::addInfoToDB() {
		/*
			IN input_client_id INT,
			IN input_account_type INT,
			OUT new_account_id INT
		*/

		//setup output call based on addAccount procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL addAccount(" << this->getAccountClientID();
		outputQuery << ", " << this->getAccountType();
		outputQuery << ", @newID)";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBAccount::modifyInfoInDB() {
		/*
			IN input_account_id INT,
			IN input_client_id INT,
			IN input_account_type INT,
			IN input_balance DOUBLE
		*/

		//setup output call based on updateAccount procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL updateAccount(" << this->getObjectID();
		outputQuery << ", " << this->getAccountClientID();
		outputQuery << ", " << this->getAccountType();
		outputQuery << ", " << this->getAccountBalance();
		outputQuery << ")";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBAccount::deleteInfoInDB() {
		/*
			IN input_account_id INT
		*/

		//setup output call based on deleteAccount procedure in mySql DB (inputs above)
		std::stringstream outputQuery;
		outputQuery << "CALL deleteAccount(" << this->getObjectID() << ")";
		return outputQuery.str();
	}

	std::string DBAccount::checkObjectExists() {
		/*
			IN check_account_id INT,
			OUT check_result BOOL
		*/
		//setup output call based on checkAccountExists procedure in mySql DB (inputs above)
		std::stringstream outputQuery;
		outputQuery << "CALL checkAccountExists(" << this->getObjectID() << ", @checkResult)";
		return outputQuery.str();
	}
}

//DBTransaction class source code
namespace EarnDBObjects {
	//Constructors

	DBTransaction::DBTransaction() :DBObject(EarnStructs::TRANSACTION, 0) {
		this->setTransactionAccountID(0);
		this->setTransactionType(EarnStructs::TRANSACTIONNULL);
		this->setTransactionTime(NULL);
		this->setTransactionPreviousBal(0);
		this->setTransactionNewBal(0);
		this->setTransactionSecondaryAcc(0);
	}

	DBTransaction::DBTransaction(const EarnStructs::TransactionInfo copyInfo) :DBObject(EarnStructs::TRANSACTION, 0) {
		this->setTransactionAccountID(copyInfo.accountID);
		this->setTransactionType(copyInfo.transactionType);
		this->setTransactionTime(copyInfo.transactionTime);
		this->setTransactionPreviousBal(copyInfo.previousBalance);
		this->setTransactionNewBal(copyInfo.newBalance);
		this->setTransactionSecondaryAcc(copyInfo.secondaryAccount);
	}

	DBTransaction::DBTransaction(const DBTransaction& copyTransaction) :DBObject(copyTransaction) {
		this->setTransactionAccountID(copyTransaction.transactionInfo.accountID);
		this->setTransactionType(copyTransaction.transactionInfo.transactionType);
		this->setTransactionTime(copyTransaction.transactionInfo.transactionTime);
		this->setTransactionPreviousBal(copyTransaction.transactionInfo.previousBalance);
		this->setTransactionNewBal(copyTransaction.transactionInfo.newBalance);
		this->setTransactionSecondaryAcc(copyTransaction.transactionInfo.secondaryAccount);
	}

	DBTransaction::DBTransaction(int inputObjectID, int inputAccountID, EarnStructs::TransactionType inputTransactionType, const char* transactionTime, double inputPreviousBalance, double inputNewBalance, int inputSecondaryAccount) :DBObject(EarnStructs::TRANSACTION, inputObjectID) {
		this->setTransactionAccountID(inputAccountID);
		this->setTransactionType(inputTransactionType);
		this->setTransactionTime(transactionTime);
		this->setTransactionPreviousBal(inputPreviousBalance);
		this->setTransactionNewBal(inputNewBalance);
		this->setTransactionSecondaryAcc(inputSecondaryAccount);
	}

	//Get functions

	int DBTransaction::getTransactionAccountID() {
		return this->transactionInfo.accountID;
	}

	EarnStructs::TransactionType DBTransaction::getTransactionType() {
		return this->transactionInfo.transactionType;
	}

	const char* DBTransaction::getTransactionTime(int& lenOfArray) {
		lenOfArray = strlen(this->transactionInfo.transactionTime);
		return this->transactionInfo.transactionTime;
	}
	std::string DBTransaction::getTransactionTime() {
		std::string outputTime(this->transactionInfo.transactionTime);
		return outputTime.substr(0, strlen(this->transactionInfo.transactionTime));
	}

	double DBTransaction::getTransactionPreviousBal() {
		return this->transactionInfo.previousBalance;
	}

	double DBTransaction::getTransactionNewBal() {
		return this->transactionInfo.newBalance;
	}

	int DBTransaction::getTransactionSecondaryAcc() {
		return this->transactionInfo.secondaryAccount;
	}

	EarnStructs::TransactionInfo DBTransaction::getTransactionInfo() {
		return this->transactionInfo;
	}

	//Set functions

	void DBTransaction::setTransactionAccountID(int newAccountID) {
		this->transactionInfo.accountID = newAccountID;
	}

	void DBTransaction::setTransactionType(EarnStructs::TransactionType newTransactionType) {
		this->transactionInfo.transactionType = newTransactionType;
	}

	void DBTransaction::setTransactionTime(const char* newTransactionTime) {
		if (NULL != newTransactionTime) {
			strcpy_s(this->transactionInfo.transactionTime, EarnStructs::VARCHARLEN, newTransactionTime);
		}
	}
	void DBTransaction::setTransactionTime(std::string newTransactionTime) {
		if (!newTransactionTime.empty()) {
			strcpy_s(this->transactionInfo.transactionTime, EarnStructs::VARCHARLEN, newTransactionTime.c_str());
		}
	}

	void DBTransaction::setTransactionPreviousBal(double newTransactionPB) {
		this->transactionInfo.previousBalance = newTransactionPB;
	}

	void DBTransaction::setTransactionNewBal(double newTransactionNB) {
		this->transactionInfo.newBalance = newTransactionNB;
	}

	void DBTransaction::setTransactionSecondaryAcc(int newTransactionSA) {
		this->transactionInfo.secondaryAccount = newTransactionSA;
	}

	//Inherited functions

	std::string DBTransaction::displayInfo() {

		//Set formatted output for output string so that it has each var / line...
		std::stringstream outputStream;
		outputStream << "Transaction ID: " << this->getObjectID() << '\n';
		outputStream << "Account ID: " << this->getTransactionAccountID() << '\n';
		outputStream << "Transaction Type: " << EnumToString(this->getTransactionType()) << '\n';
		outputStream << "Transaction Time: " << this->getTransactionTime() << '\n';
		outputStream << "Previous Balance: " << this->getTransactionPreviousBal() << '\n';
		outputStream << "New Balance: " << this->getTransactionNewBal() << '\n';
		outputStream << "Secondary Account: " << this->getTransactionSecondaryAcc() << '\n';

		//lets me allocate it simpler (IMO)
		return outputStream.str();
	}

	//std::string DBTransaction::getLogData() {

	//}


	std::string DBTransaction::getInfoFromDB() {
		/*
			IN check_transaction_id INT,
			OUT check_result BOOL
		*/

		std::stringstream outputQuery;
		outputQuery << "CALL getTransactionInfo(" << this->getObjectID() << ")";

		return outputQuery.str();
	}

	std::string DBTransaction::addInfoToDB() {
		/*
			IN input_account_id INT,
			IN input_type_id INT,
			IN input_previous_balance DOUBLE,
			IN input_new_balance DOUBLE,
			IN input_secondary_id INT,
			OUT new_transaction_id INT
		*/

		//setup output call based on addTransaction procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL addTransaction(" << this->getTransactionAccountID();
		outputQuery << ", " << this->getTransactionType();
		outputQuery << ", '" << this->getTransactionTime();
		outputQuery << "', " << this->getTransactionPreviousBal();
		outputQuery << ", " << this->getTransactionNewBal();
		outputQuery << ", " << this->getTransactionSecondaryAcc();
		outputQuery << ", @newID)";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBTransaction::modifyInfoInDB() {
		/*
			IN input_transaction_id INT,
			IN input_account_id INT,
			IN input_type_id INT,
			IN input_previous_balance DOUBLE,
			IN input_new_balance DOUBLE,
			IN input_secondary_id INT
		*/

		//setup output call based on updateTransaction procedure in mySql DB (inputs above)

		std::stringstream outputQuery;
		outputQuery << "CALL updateTransaction(" << this->getObjectID();
		outputQuery << ", " << this->getTransactionAccountID();
		outputQuery << ", " << this->getTransactionType();
		outputQuery << ", '" << this->getTransactionTime();
		outputQuery << "', " << this->getTransactionPreviousBal();
		outputQuery << ", " << this->getTransactionNewBal();
		outputQuery << ", " << this->getTransactionSecondaryAcc();
		outputQuery << ")";

		//lets me allocate it simpler (IMO)
		return outputQuery.str();
	}

	std::string DBTransaction::deleteInfoInDB() {
		/*
			IN input_transaction_id INT
		*/

		//setup output call based on deleteAccount procedure in mySql DB (inputs above)
		std::stringstream outputQuery;
		outputQuery << "CALL deleteTransaction(" << this->getObjectID() << ")";
		return outputQuery.str();
	}

	std::string DBTransaction::checkObjectExists() {
		/*
			IN check_transaction_id INT,
			OUT check_result BOOL
		*/
		//setup output call based on checkTransactionExists procedure in mySql DB (inputs above)
		std::stringstream outputQuery;
		outputQuery << "CALL checkTransactionExists(" << this->getObjectID() << ", @checkResult)";
		return outputQuery.str();
	}
}