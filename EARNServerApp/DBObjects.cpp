#include "DBObjects.h"
#include "DBAccess.h"

//DBObject class source code, splitting up namespace to make it easier to read & collapse code areas...
namespace EarnDB {
	//Constructors

	DBObject::DBObject() {
		this->setDBOType(DBONULL);	//type is null telling me it is unallocated...
	}
	
	DBObject::DBObject(const DBObject& copyObject) : DBAccessInterface(copyObject) {
		this->setDBOType(copyObject.objectType);
	}

	DBObject::DBObject(DBOType initalizeType, int objectID) : DBAccessInterface(objectID) {
		this->setDBOType(initalizeType);
	}

	//Get function

	DBOType DBObject::getDBOType() {
		return this->objectType;
	}

	//Set function

	void DBObject::setDBOType(DBOType inputType) {
		this->objectType = inputType;
	}
}

//DBClient class source code
namespace EarnDB {
	//Constructors

	DBClient::DBClient() {
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

	DBClient::DBClient(const DBClientInfo copyInfo) {
		this->setFirstName(copyInfo.firstName);
		this->setLastName(copyInfo.lastName);
		this->setEmail(copyInfo.email);
		this->setPhoneNum(copyInfo.phoneNumber);
		this->setStreet(copyInfo.street);
		this->setCity(copyInfo.city);
		this->setProvince(copyInfo.province);
		this->setZip(copyInfo.zipcode);	
	}

	DBClient::DBClient(const DBClient& copyClient) : DBObject::DBObject(copyClient) {
		this->setFirstName(copyClient.clientInfo.firstName);
		this->setLastName(copyClient.clientInfo.lastName);
		this->setEmail(copyClient.clientInfo.email);
		this->setPhoneNum(copyClient.clientInfo.phoneNumber);
		this->setStreet(copyClient.clientInfo.street);
		this->setCity(copyClient.clientInfo.city);
		this->setProvince(copyClient.clientInfo.province);
		this->setZip(copyClient.clientInfo.zipcode);
	}

	DBClient::DBClient(int inputobjectID, char inputFirst[VARCHARLEN], char inputLast[VARCHARLEN], char inputEmail[VARCHARLEN], char inputPhone[VARCHARLEN], char inputStreet[VARCHARLEN], char inputCity[VARCHARLEN], char inputProvince[VARCHARLEN], char inputZip[ZIPLEN]) :DBObject(CLIENT, inputobjectID) {
		this->setFirstName(inputFirst);
		this->setLastName(inputLast);
		this->setEmail(inputEmail);
		this->setPhoneNum(inputPhone);
		this->setStreet(inputStreet);
		this->setCity(inputCity);
		this->setProvince(inputProvince);
		this->setZip(inputZip);
	}

	//Get functions

	const char* DBClient::getFirstName(int& lenOfArray) {
		lenOfArray = VARCHARLEN;	//since it will always be an array of 45
		return (const char*)(this->clientInfo.firstName);	//cast pointer to first name as a const so it cannot be altered...
	}
	string DBClient::getFirstName() {
		string outputFirstName(this->clientInfo.firstName);	//simplest way to do this...
		return outputFirstName;
	}

	const char* DBClient::getLastName(int& lenOfArray) {
		lenOfArray - VARCHARLEN;
		return (const char*)(this->clientInfo.lastName);
	}
	string DBClient::getLastName() {
		string outputLastName(this->clientInfo.lastName);
		return outputLastName;
	}

	const char* DBClient::getEmail(int& lenOfArray) {
		lenOfArray - VARCHARLEN;
		return (const char*)(this->clientInfo.email);
	}
	string DBClient::getEmail() {
		string outputEmail(this->clientInfo.email);
		return outputEmail;
	}

	const char* DBClient::getPhoneNum(int& lenOfArray) {
		lenOfArray = VARCHARLEN;
		return (const char*)(this->clientInfo.phoneNumber);
	}
	string DBClient::getPhoneNum() {
		string outputPhoneNum(this->clientInfo.phoneNumber);
		return outputPhoneNum;
	}

	const char* DBClient::getStreet(int& lenOfArray) {
		lenOfArray = VARCHARLEN;
		return (const char*)(this->clientInfo.street);
	}
	string DBClient::getStreet() {
		string outputStreet(this->clientInfo.street);
		return outputStreet;
	}

	const char* DBClient::getCity(int& lenOfArray) {
		lenOfArray = VARCHARLEN;
		return (const char*)(this->clientInfo.city);
	}
	string DBClient::getCity() {
		string outputCity(this->clientInfo.city);
		return outputCity;
	}

	const char* DBClient::getProvince(int& lenOfArray) {
		lenOfArray = VARCHARLEN;
		return (const char*)(this->clientInfo.province);
	}
	string DBClient::getProvince() {
		string outputProvince(this->clientInfo.province);
		return outputProvince;
	}

	const char* DBClient::getZip(int& lenOfArray) {
		lenOfArray = ZIPLEN;
		return (const char*)(this->clientInfo.zipcode);
	}
	string DBClient::getZip() {
		string outputZip(this->clientInfo.zipcode);
		return outputZip;
	}

	DBClientInfo DBClient::getClientInfo() {
		return this->clientInfo;
	}

	//Set functions

	void DBClient::setFirstName(char newFirst[VARCHARLEN]) {
		memcpy(this->clientInfo.firstName, newFirst, VARCHARLEN);
	}
	void DBClient::setFirstName(string newFirst) {
		memcpy(this->clientInfo.firstName, newFirst.c_str(), VARCHARLEN);
	}

	void DBClient::setLastName(char newLast[VARCHARLEN]) {
		memcpy(this->clientInfo.lastName, newLast, VARCHARLEN);
	}
	void DBClient::setLastName(string newLast) {
		memcpy(this->clientInfo.lastName, newLast.c_str(), VARCHARLEN);
	}

	void DBClient::setEmail(char newEmail[VARCHARLEN]) {
		memcpy(this->clientInfo.email, newEmail, VARCHARLEN);
	}
	void DBClient::setEmail(string newEmail) {
		memcpy(this->clientInfo.email, newEmail.c_str(), VARCHARLEN);
	}

	void DBClient::setPhoneNum(char newPhone[VARCHARLEN]) {
		memcpy(this->clientInfo.phoneNumber, newPhone, VARCHARLEN);
	}
	void DBClient::setPhoneNum(string newPhone) {
		memcpy(this->clientInfo.phoneNumber, newPhone.c_str(), VARCHARLEN);
	}

	void DBClient::setStreet(char newStreet[VARCHARLEN]) {
		memcpy(this->clientInfo.street, newStreet, VARCHARLEN);
	}
	void DBClient::setStreet(string newStreet) {
		memcpy(this->clientInfo.street, newStreet.c_str(), VARCHARLEN);
	}

	void DBClient::setCity(char newCity[VARCHARLEN]) {
		memcpy(this->clientInfo.city, newCity, VARCHARLEN);
	}
	void DBClient::setCity(string newCity) {
		memcpy(this->clientInfo.city, newCity.c_str(), VARCHARLEN);
	}

	void DBClient::setProvince(char newProvince[VARCHARLEN]) {
		memcpy(this->clientInfo.province, newProvince, VARCHARLEN);
	}
	void DBClient::setProvince(string newProvince) {
		memcpy(this->clientInfo.province, newProvince.c_str(), VARCHARLEN);
	}

	void DBClient::setZip(char newZip[ZIPLEN]) {
		memcpy(this->clientInfo.zipcode, newZip, ZIPLEN);
	}
	void DBClient::setZip(string newZip) {
		memcpy(this->clientInfo.zipcode, newZip.c_str(), ZIPLEN);
	}

	//Inherited functions

	//string DBClient::displayInfo() {

	//}

	//string DBClient::getLogData() {

	//}

	//string DBClient::addInfoToDB() {

	//}

	//string DBClient::modifyInfoInDB() {

	//}

	//string DBClient::deleteInfoInDB() {

	//}
}

//DBAccount class source code
namespace EarnDB {
	//Constructors

	DBAccount::DBAccount() {
		this->setAccountClientID(0);
		this->setAccountType(DBANULL);
		this->setBalance(NULL);
	}
	
	DBAccount::DBAccount(const DBAccountInfo copyInfo) {
		this->setAccountClientID(copyInfo.clientID);
		this->setAccountType(copyInfo.accountType);
		this->setBalance(copyInfo.accountBalance);
	}

	DBAccount::DBAccount(const DBAccount& copyAccount) : DBObject(copyAccount) {
		this->setAccountClientID(copyAccount.accountInfo.clientID);
		this->setAccountType(copyAccount.accountInfo.accountType);
		this->setBalance(copyAccount.accountInfo.accountBalance);
	}

	DBAccount::DBAccount(int inputObjectID, int inputClientID, DBAType inputAccountType, double inputBalance) : DBObject(ACCOUNT, inputObjectID) {
		this->setAccountClientID(inputClientID);
		this->setAccountType(inputAccountType);
		this->setBalance(inputBalance);
	}

	//Get functions

	DBAType DBAccount::getAccountType() {
		return this->accountInfo.accountType;
	}

	int DBAccount::getAccountClientID() {
		return this->accountInfo.clientID;
	}

	double DBAccount::getAccountBalance() {
		return this->accountInfo.accountBalance;
	}

	DBAccountInfo DBAccount::getAccountInfo() {
		return this->accountInfo;
	}

	//Set functions

	void DBAccount::setAccountType(DBAType newType) {
		this->accountInfo.accountType = newType;
	}

	void DBAccount::setAccountClientID(int newClientID) {
		this->accountInfo.clientID = newClientID;
	}

	void DBAccount::setBalance(double newBalance) {
		this->accountInfo.accountBalance = newBalance;
	}

	void DBAccount::setAccountInfo(DBAccountInfo newAccountInfo) {
		this->accountInfo = newAccountInfo;
	}

	//Inherited functions

	//string DBAccount::displayInfo() {

	//}

	//string DBAccount::getLogData() {

	//}

	//string DBAccount::addInfoToDB() {

	//}

	//string DBAccount::modifyInfoInDB() {

	//}

	//string DBAccount::deleteInfoInDB() {

	//}
}

//DBTransaction class source code
namespace EarnDB {
	//Constructors

	//default constructor
	DBTransaction::DBTransaction() {
		this->setTransactionAccountID(0);
		this->setTransactionType(DBTNULL);
		this->setTransactionTime(NULL);
		this->setTransactionPreviousBal(0);
		this->setTransactionNewBal(0);
		this->setTransactionSecondaryAcc(0);
	}

	//struct constructor, for use after deserializing
	DBTransaction::DBTransaction(const DBTransactionInfo copyInfo) {
		this->setTransactionAccountID(copyInfo.accountID);
		this->setTransactionType(copyInfo.transactionType);
		this->setTransactionTime(copyInfo.transactionTime);
		this->setTransactionPreviousBal(copyInfo.previousBalance);
		this->setTransactionNewBal(copyInfo.newBalance);
		this->setTransactionSecondaryAcc(copyInfo.secondaryAccount);
	}

	//copy constructor
	DBTransaction::DBTransaction(DBTransaction& copyTransaction) :DBObject(copyTransaction) {
		this->setTransactionAccountID(copyTransaction.transactionInfo.accountID);
		this->setTransactionType(copyTransaction.transactionInfo.transactionType);
		this->setTransactionTime(copyTransaction.transactionInfo.transactionTime);
		this->setTransactionPreviousBal(copyTransaction.transactionInfo.previousBalance);
		this->setTransactionNewBal(copyTransaction.transactionInfo.newBalance);
		this->setTransactionSecondaryAcc(copyTransaction.transactionInfo.secondaryAccount);
	}

	//parametrized constructor
	DBTransaction::DBTransaction(int inputObjectID, int inputAccountID, DBTType inputTransactionType, char* transactionTime, double inputPreviousBalance, double inputNewBalance, int inputSecondaryAccount) :DBObject(TRANSACTION, inputObjectID) {
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

	DBTType DBTransaction::getTransactionType() {
		return this->transactionInfo.transactionType;
	}

	char* DBTransaction::getTransactionTime() {
		return this->transactionInfo.transactionTime;
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

	DBTransactionInfo DBTransaction::getTransactionInfo() {
		return this->transactionInfo;
	}

	//Set functions

	void DBTransaction::setTransactionAccountID(int newAccountID) {
		this->transactionInfo.accountID = newAccountID;
	}

	void DBTransaction::setTransactionType(DBTType newTransactionType) {
		this->transactionInfo.transactionType = newTransactionType;
	}

	void DBTransaction::setTransactionTime(char* newTransactionTime) {
		this->transactionInfo.transactionTime = newTransactionTime;
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

	//string DBTransaction::displayInfo() {

	//}

	//string DBTransaction::getLogData() {

	//}

	//string DBTransaction::addInfoToDB() {

	//}

	//string DBTransaction::modifyInfoInDB() {

	//}

	//string DBTransaction::deleteInfoInDB() {

	//}
}