#define _CRT_SECURE_NO_WARNINGS

#include "DataTypes.h"
#include "EARNStructs.h"
#define START_BASE


using namespace std;
using namespace EarnStructs;

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
	int startBase = 16;
	//clientinfo struct is 321


	memcpy(&accountID, src + HeadSize +  8, sizeof(int));
	memcpy(user.firstName, src + HeadSize + startBase, sizeof(user.firstName));
	count++;
	memcpy(user.lastName, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
	count++;
	memcpy(user.email, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
	count++;
	memcpy(user.phoneNumber, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
	count++;
	memcpy(user.street, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
	count++;
	memcpy(user.city, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
	count++;
	memcpy(user.province, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.firstName));
	count++;
	memcpy(user.zipcode, src + HeadSize + startBase + (count * sizeof(user.firstName)), sizeof(user.zipcode));

	//memcpy(&user, src + HeadSize + 16, sizeof(user));
	/*cout << sizeof(user) << endl;
	cout << sizeof(CreateAccount) << endl;*/
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

//void CreateAccount::setUserName(char* uName) {
//
//	strcpy(user.userName, uName);
//}

//char* CreateAccount::getUserName() {

//	return this->userName;
//}

//void CreateAccount::setpassword(char* pass) {

//	strcpy(this->password, pass);
//}

//char* CreateAccount::getPassword() {

//	return this->password;
//}

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

	this->accountID;
}

void CreateAccount::display() {

	cout << "firstName: " << user.firstName << endl;
	cout << "lastName: " << user.lastName << endl;
	/*cout << "username: " << user.userName << endl;
	cout << "password: " << user.password << endl;*/
	cout << "email: " << user.email << endl;
	cout << "phone Number: " << user.phoneNumber << endl;
	cout << "streetname: " << user.street << endl;
	cout << "city: " << user.city << endl;
	cout << "province: " << user.province << endl;
	cout << "zipcode: " << user.zipcode << endl;
	cout << "accountID: " << accountID << endl;
}

// Login Functions

//Login::Login(string Username, string password) {
//	this->userName = userName;
//	this->password = password;
//}

//Login::Login(int bankNumber, string password) {
//	this->bankNumber = bankNumber;
//	this->password = password;
//}

Login::Login(char* Username, char* password) {

	strcpy(login.username, Username);
	strcpy(login.userPasswordHash, password);
	login.clientID = 22;
	login.usernumber = 33;
	//this->bankNumber = 3;
	//this->userName = userName;
	//this->password = password;
}

//Login::Login(int bankNumber, char* password) {
//	this->bankNumber = bankNumber;
//	//this->password = password;
//	strcpy(this->password, password);
//	strcpy(this->userName, "");
//}

Login::Login(char* src) {

	//int count = 0;
	int startBase = 16;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));

	//memcpy(&login.clientID, src + HeadSize + startBase, sizeof(int));
	//memcpy(&login.usernumber, src + HeadSize + startBase + sizeof(int), sizeof(int));
	//memcpy(login.username, src + HeadSize + startBase + sizeof(int), sizeof(login.username));
	//memcpy(login.userPasswordHash, src + HeadSize + startBase + sizeof(int) + sizeof(int) + VARCHARLEN, sizeof(login.userPasswordHash));
	//cout << sizeof(login.userPasswordHash) << endl;
	//memcpy(login.username, src + HeadSize + startBase + sizeof(int), sizeof(login.username));
	//count++;

	//int num1;
	//int num2;
	//memcpy(&num1, src + HeadSize + startBase + sizeof(int) + VARCHARLEN, sizeof(int));
	//memcpy(&num2, src + HeadSize + startBase + sizeof(int) + 4 + VARCHARLEN, sizeof(int));
	//cout << num1 << endl;
	//cout << num2 << endl;

	//memcpy(&login.usernumber, src + HeadSize + startBase + sizeof(int) + VARCHARLEN, sizeof(int));
	//memcpy(login.userPasswordHash, src + HeadSize + startBase + sizeof(int) + sizeof(int) + VARCHARLEN, VARCHARLEN);


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


//Deposit Functions

Deposit::Deposit(int amount, int depositType, int DepositID) {

	this->amount = amount;
	this->depositType = depositType;
	this->depositID = DepositID;
}

Deposit::Deposit(char* src) {

	int count = 0;
	int startBase = 16;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));
	memcpy(&amount, src + HeadSize + startBase, sizeof(int));
	count++;
	memcpy(&depositType, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));
	count++;
	memcpy(&depositID, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));
}

void Deposit::display() {

	cout << "amount: " << amount << endl;
	cout << "depositType: " << depositType << endl;
	cout << "depositID: " << depositID << endl;
}

void Deposit::setAmount(int amount) {

	this->amount = amount;
}

int Deposit::getAmount() {

	return this->amount;
}

void Deposit::setDepositType(int Type) {

	this->depositType = Type;
}

int Deposit::getDepositType() {

	return this->depositType;
}

void Deposit::setDepositID(int ID) {

	this->depositID = ID;
}
void Deposit::setAccountID(int accountID) {
	this->accountID = accountID;
}

int Deposit::getAccountID() {

	return this->accountID;
}
int Deposit::getDepositID() {

	return this->depositID;
}





//Withdrawal Functions

Withdraw::Withdraw(int amount, int withdrawType, int withdrawTypeID) {

	this->amount = amount;
	this->withdrawType = withdrawType;
	this->withdrawTypeID = withdrawTypeID;
}

Withdraw::Withdraw(char* src) {

	int count = 0;
	int startBase = 16;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));
	memcpy(&amount, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));
	count++;
	memcpy(&withdrawType, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));
	count++;
	memcpy(&withdrawTypeID, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));

}

void Withdraw::display() {

	cout << "amount: " << amount << endl;
	cout << "withdrawType: " << withdrawType << endl;
	cout << "withdrawID: " << withdrawTypeID << endl;
}

void Withdraw::setAmount(int amount) {

	this->amount = amount;
}

int Withdraw::getAmount() {

	return this->amount;
}

void Withdraw::setWithdrawType(int Type) {

	this->withdrawType = Type;
}

int Withdraw::getWithdrawType() {

	return this->withdrawType;
}

void Withdraw::setWithdrawTypeID(int ID) {

	this->withdrawTypeID = ID;
}

int Withdraw::getWithdrawTypeID() {

	return this->withdrawTypeID;
}

void Withdraw::setAccountID(int accountID) {
	this->accountID;
}

//TransferBetweenAccounts Functions

TransferBetweenAccount::TransferBetweenAccount(int amount, int receiverAccountID, int transferID) {

	this->amount = amount;
	this->receiverAccountID = receiverAccountID;
	this->transferID = transferID;
}

TransferBetweenAccount::TransferBetweenAccount(char* src) {

	int count = 0;
	int startBase = 16;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));
	memcpy(&amount, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));
	count++;
	memcpy(&receiverAccountID, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));
	count++;
	memcpy(&transferID, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));

}

void TransferBetweenAccount::display() {

	cout << "amount: " << amount << endl;
	cout << "receiverAccountID: " << receiverAccountID << endl;
	cout << "transferID: " << transferID << endl;
}

void TransferBetweenAccount::setAmount(int amount) {

	this->amount = amount;
}
int TransferBetweenAccount::getAmount() {

	return this->amount;
}

void TransferBetweenAccount::setReceiverAccountID(int receiverAccountID) {

	this->receiverAccountID = receiverAccountID;
}

int TransferBetweenAccount::getReceiverAccountID() {

	return this->receiverAccountID;
}

void TransferBetweenAccount::setTransferID(int transferID) {

	this->transferID = transferID;
}

int TransferBetweenAccount::getTransferID() {

	return this->transferID;
}

void TransferBetweenAccount::setAccountID(int accountID) {

	this->accountID;
}


// TransactionConfirmation

TransactionConfirmation::TransactionConfirmation(char* src) {

	int count = 0;
	int startBase = 16;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));
	memcpy(&currentBalance, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));
	count++;
	memcpy(&transactionID, src + HeadSize + startBase + (count * sizeof(int)), sizeof(int));

}

int TransactionConfirmation::getCurrentBalance() {

	return currentBalance;
}

void TransactionConfirmation::setCurrentBalance(int num) {

	this->currentBalance = num;
}

int TransactionConfirmation::getTransactionID() {

	return transactionID;
}

void TransactionConfirmation::setTransactionID(int num) {

	this->transactionID = num;
}

