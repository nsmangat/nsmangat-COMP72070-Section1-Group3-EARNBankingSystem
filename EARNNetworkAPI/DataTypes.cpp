#define _CRT_SECURE_NO_WARNINGS

#include "DataTypes.h"
#define START_BASE


using namespace std;

CreateAccount::CreateAccount(char* firstName, char* lastName, char* userName, char* password, char* email, char* phoneNumber, char* streetName, char* city, char* province, int accountID)
{
	strcpy(this->firstName, firstName);
	strcpy(this->lastName, lastName);
	strcpy(this->userName, userName);
	strcpy(this->password, password);
	strcpy(this->email, email);
	strcpy(this->phoneNumber, phoneNumber);
	strcpy(this->streetName, streetName);
	strcpy(this->city, city);
	strcpy(this->province, province);
	this->accountID = accountID;
}

CreateAccount::CreateAccount(char* src) {

	int count = 0;
	int startBase = 16;


	memcpy(&accountID, src + HeadSize +  8, sizeof(int));
	memcpy(this->firstName, src + HeadSize + startBase, sizeof(firstName));
	count++;
	memcpy(this->lastName, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));
	count++;
	memcpy(this->userName, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));
	count++;
	memcpy(this->password, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));
	count++;
	memcpy(this->email, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));
	count++;
	memcpy(this->phoneNumber, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));
	count++;
	memcpy(this->streetName, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));
	count++;
	memcpy(this->city, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));
	count++;
	memcpy(this->province, src + HeadSize + startBase + (count * sizeof(firstName)), sizeof(firstName));

}

void CreateAccount::setFirstName(char* fName) {

	strcpy(this->firstName, fName);
}

char* CreateAccount::getFirstName() {

	return this->firstName;
}

void CreateAccount::setLastName(char* lName) {

	strcpy(this->lastName, lName);
}

char* CreateAccount::getLastName() {

	return this->lastName;
}

void CreateAccount::setUserName(char* uName) {

	strcpy(this->userName, uName);
}

char* CreateAccount::getUserName() {

	return this->userName;
}

void CreateAccount::setpassword(char* pass) {

	strcpy(this->password, pass);
}

char* CreateAccount::getPassword() {

	return this->password;
}

void CreateAccount::setEmail(char* email) {

	strcpy(this->email, email);
}

char* CreateAccount::getEmail() {

	return this->email;
}

void CreateAccount::setPhoneNumber(char* pNumber) {

	strcpy(this->phoneNumber, pNumber);
}

char* CreateAccount::getPhoneNumber() {

	return this->phoneNumber;
}

void CreateAccount::setStreetName(char* StName) {

	strcpy(this->streetName, StName);
}

char* CreateAccount::getStreetName() {

	return this->streetName;
}

void CreateAccount::setCity(char* cName) {

	strcpy(this->city, cName);
}

char* CreateAccount::getCity() {

	return this->city;
}

void CreateAccount::setProvince(char* province) {

	strcpy(this->province, province);
}

char* CreateAccount::getProvince() {

	return this->province;
}

void CreateAccount::setAccountID(int accountID) {

	this->accountID;
}

void CreateAccount::display() {

	cout << "firstName: " << firstName << endl;
	cout << "lastName: " << lastName << endl;
	cout << "username: " << userName << endl;
	cout << "password: " << password << endl;
	cout << "email: " << email << endl;
	cout << "phone Number: " << phoneNumber << endl;
	cout << "streetname: " << streetName << endl;
	cout << "city: " << city << endl;
	cout << "province: " << province << endl;
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

	strcpy(this->userName, Username);
	strcpy(this->password, password);
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

	int count = 0;
	int startBase = 16;

	memcpy(&accountID, src + HeadSize + 8, sizeof(int));
	memcpy(this->userName, src + HeadSize + startBase + (count * STRING_LENGTH), STRING_LENGTH);
	count++;
	memcpy(this->password, src + HeadSize + startBase + (count * STRING_LENGTH), STRING_LENGTH);

}

char* Login::getUserName() {

	return this->userName;
}

void Login::setUserName(char* userName) {

	strcpy(this->userName, userName);
}

char* Login::getPassword() {

	return this->password;
}

void Login::setPassword(char* password) {

	strcpy(this->password, password);
}


void Login::setAccountID(int accountID) {
	this->accountID = accountID;
}

void Login::display() {

	cout << "userName: " << userName << endl;
	cout << "password: " << password << endl;
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

