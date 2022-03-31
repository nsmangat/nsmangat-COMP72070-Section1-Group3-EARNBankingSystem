#define _CRT_SECURE_NO_WARNINGS

#include "DataTypes.h"
#include "EARNStructs.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstring>
#define START_BASE


using namespace std;
using namespace EarnStructs;

//Library func for get time used elsewhere in the program
std::string getCurrentTime(DateFormat logDateFormat) {
	std::stringstream outputTime;
	time_t rawtime;
	struct tm logTime;

	time(&rawtime);

	gmtime_s(&logTime, &rawtime);

	if (YMD_HMS == logDateFormat) {

		outputTime << std::put_time(&logTime, "%Y/%m/%d %H:%M:%S");
	}
	else if (MDY_HMS == logDateFormat) {
		outputTime << std::put_time(&logTime, "%m/%d/%Y %H:%M:%S");
	}
	else if (DMY_HMS == logDateFormat) {
		outputTime << std::put_time(&logTime, "%d/%m/%Y %H:%M:%S");
	}
	else {
		outputTime << "TIME CALCULATION ERROR";
	}

	return outputTime.str();
}

//Create Account

CreateAccount::CreateAccount(char* firstName, char* lastName, char* email, char* phoneNumber, char* streetName, char* city, char* province, char* zipcode, int accountID)
{
	strcpy(user.firstName, firstName);
	strcpy(user.lastName, lastName);
	strcpy(user.email, email);
	strcpy(user.phoneNumber, phoneNumber);
	strcpy(user.street, streetName);
	strcpy(user.city, city);
	strcpy(user.province, province);
	strcpy(user.zipcode, zipcode);
	this->accountID = accountID;
}

CreateAccount::CreateAccount(char* src) {

	int count = 0;
	int startBase = 12;

	memcpy(&accountID, src + HeadSize +  8, sizeof(int));
    memcpy(&user, src + HeadSize + startBase, sizeof(user));
//	memcpy(user.firstName, src + HeadSize + startBase, sizeof(user.firstName));
//	count++;
//	memcpy(user.lastName, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
//	count++;
//	memcpy(user.email, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
//	count++;
//	memcpy(user.phoneNumber, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
//	count++;
//	memcpy(user.street, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
//	count++;
//	memcpy(user.city, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
//	count++;
//	memcpy(user.province, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
//	count++;
//	memcpy(user.zipcode, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.zipcode));

}

void CreateAccount::setFirstName(char* fName) {

	strcpy(user.firstName, fName);
}

char* CreateAccount::getFirstName() {

	return user.firstName;
}

void CreateAccount::setLastName(char* lName) {

	strcpy(user.lastName, lName);
}

char* CreateAccount::getLastName() {

	return user.lastName;
}


void CreateAccount::setEmail(char* email) {

	strcpy(user.email, email);
}

char* CreateAccount::getEmail() {

	return user.email;
}

void CreateAccount::setPhoneNumber(char* pNumber) {

	strcpy(user.phoneNumber, pNumber);
}

char* CreateAccount::getPhoneNumber() {

	return user.phoneNumber;
}

void CreateAccount::setStreetName(char* StName) {

	strcpy(user.street, StName);
}

char* CreateAccount::getStreetName() {

	return user.street;
}

void CreateAccount::setCity(char* cName) {

	strcpy(user.city, cName);
}

char* CreateAccount::getCity() {

	return user.city;
}

void CreateAccount::setProvince(char* province) {

	strcpy(user.province, province);
}

char* CreateAccount::getProvince() {

	return user.province;
}

void CreateAccount::setZipcode(char* zipcode) {

	strcpy(user.zipcode, zipcode);
}

char* CreateAccount::getZipcode() {

	return user.zipcode;
}

void CreateAccount::setAccountID(int accountID) {

	this->accountID = accountID;
}

int CreateAccount::getAccountID() {

	return this->accountID;
}

void CreateAccount::display() {

	cout << "firstName: " << user.firstName << endl;
	cout << "lastName: " << user.lastName << endl;
	cout << "email: " << user.email << endl;
	cout << "phone Number: " << user.phoneNumber << endl;
	cout << "streetname: " << user.street << endl;
	cout << "city: " << user.city << endl;
	cout << "province: " << user.province << endl;
	cout << "zipcode: " << user.zipcode << endl;
	cout << "accountID: " << accountID << endl;
}


//Login

ClientInfo CreateAccount::getClientInfoStruct() {

	return this->user;
}

Login::Login(char* Username, char* password) {

	strcpy(login.username, Username);
	strcpy(login.userPasswordHash, password);
	login.clientID = 0;
	login.usernumber = 0;
}


Login::Login(char* src, int startBase) {

	//int count = 0;
	

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));

	memcpy(&login, src + HeadSize + startBase, sizeof(login));
}

int Login::getClientID() {
	
	return login.clientID;
}

void Login::setClientID(int clientID) {

	login.clientID = clientID;
}

char* Login::getUserName() {

	return login.username;
}

void Login::setUserName(char* userName) {

	strcpy(login.username, userName);
}


int Login::getUserNumber() {

	return login.usernumber;
}

void Login::setUserNumber(int userNumber) {

	login.usernumber = userNumber;
}


char* Login::getPassword() {

	return login.userPasswordHash;
}

void Login::setPassword(char* password) {

	strcpy(login.userPasswordHash, password);
}


void Login::setAccountID(int accountID) {
	this->accountID = accountID;
}

void Login::display() {

	cout << "cientID: " << login.clientID << endl;
	cout << "userName: " << login.username << endl;
	cout << "usernumber: " << login.usernumber<< endl;
	cout << "password: " << login.userPasswordHash << endl;
}


//get struct 
CredentialInfo Login::getLoginStruct() {

	return login;

}

//Transaction

Transaction::Transaction(int accID, TransactionType type, double pBalance, double nBalance, int secAcc) {

	this->accountID = accID;
	TInfo.accountID = accID;

	TInfo.transactionType = type;

	this->setTransactionTime();

	TInfo.previousBalance = pBalance;
	TInfo.newBalance = nBalance;

	TInfo.secondaryAccount = secAcc;

}

Transaction::Transaction(char* src) {

	int count = 0;
	int startBase = 12;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));
	memcpy(&TInfo, src + HeadSize + startBase, sizeof(TInfo));

}

Transaction::Transaction() {

	this->accountID = 0;
	TInfo.accountID = 0;

	TInfo.transactionType = TRANSACTIONNULL;

	//this->setTransactionTime();
	char test[VARCHARLEN] = "";
	strcpy(TInfo.transactionTime, test);
	TInfo.previousBalance = 0;
	TInfo.newBalance = 0;

	TInfo.secondaryAccount = 0;
}

int Transaction::getAccID() {

	return TInfo.accountID;
}

void Transaction::setAccID(int accID) {

	TInfo.accountID = accID;
}

int Transaction::getTransactionType() {

	return TInfo.transactionType;
}

void Transaction::setTransactionType(TransactionType type) {

	TInfo.transactionType = type;
}

char* Transaction::getTransactionTime() {

	return TInfo.transactionTime;
}

void Transaction::setTransactionTime() {
	
	strcpy(TInfo.transactionTime, getCurrentTime(YMD_HMS).c_str());
}

double Transaction::getPreviousBalance() {

	return TInfo.previousBalance;
}

void Transaction::setPreviousBalance(double pBalance) {

	TInfo.previousBalance = pBalance;
}

double Transaction::getNewBalance() {

	return TInfo.newBalance;
}

void Transaction::setNewBalance(double nBalance) {

	TInfo.newBalance = nBalance;
}

int Transaction::getSecondaryAccount() {

	return TInfo.secondaryAccount;
}

void Transaction::setSecondaryAccount(int accNum) {

	TInfo.secondaryAccount = accNum;
}


void Transaction::display() {

	cout << "accountID: " << TInfo.accountID << endl;
	cout << "TransactionType: " << TInfo.transactionType << endl;
	cout << "Time: " << TInfo.transactionTime << endl;
	cout << "Previous Balance: " << TInfo.previousBalance << endl;
	cout << "New Balance: " << TInfo.newBalance << endl;
	cout << "Secondary Account: " << TInfo.secondaryAccount << endl;
}


TransactionInfo Transaction::getTransactionInfoStruct() {

	return TInfo;
}


// AccountInfo

AccountInformation::AccountInformation(int id, AccountType type, double balance) {

	this->accountID = id;
	accInfo.clientID = id;
	accInfo.accountType = type;
	accInfo.accountBalance = balance;
}

AccountInformation::AccountInformation(char* src) {

	int count = 0;
	int startBase = 16;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));
	memcpy(&accInfo, src + HeadSize + startBase, sizeof(accInfo));

}

AccountInformation::AccountInformation() {

	this->accountID = 0;
	accInfo.clientID = 0;
	accInfo.accountType = ACCOUNTNULL;
	accInfo.accountBalance = 0;

}

int AccountInformation::getClientID()
{
	return accInfo.clientID;
}

void AccountInformation::setClientID(int id)
{
	accInfo.clientID = id;
}

int AccountInformation::getAccountType()
{
	return accInfo.accountType;
}

void AccountInformation::setAccountType(AccountType type)
{
	accInfo.accountType = type;
}

double AccountInformation::getAccountBalance() {

	return accInfo.accountBalance;

}

void AccountInformation::setAccountBalance(double balance)
{
	accInfo.accountBalance = balance;
}

void AccountInformation::display() {

	cout << "Client ID: " << accInfo.clientID << endl;
	cout << "AccountType: " << accInfo.accountType << endl;
	cout << "Balance: $" << accInfo.accountBalance << endl;
	
}

//get struct
AccountInfo AccountInformation::getAccountInfoStruct() {
	
	return accInfo;
}
