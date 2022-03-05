#define _CRT_SECURE_NO_WARNINGS

#include "DataTypes.h"

using namespace std;

CreateAccount::CreateAccount(string firstName, string lastName, string userName, string password, string email, string phoneNumber, string streetName, string city, string province, int accountID)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->userName = userName;
	this->password = password;
	this->email = email;
	this->phoneNumber = phoneNumber;
	this->streetName = streetName;
	this->city = city;
	this->province = province;
	this->accountID = accountID;
}

void CreateAccount::setFirstName(string fName) {

	this->firstName = fName;
}

string CreateAccount::getFirstName() {

	return this->firstName;
}

void CreateAccount::setLastName(string lName) {

	this->lastName = lName;
}

string CreateAccount::getLastName() {

	return this->lastName;
}

void CreateAccount::setUserName(string uName) {

	this->userName = uName;
}

string CreateAccount::getUserName() {

	return this->userName;
}

void CreateAccount::setpassword(string pass) {

	this->password = pass;
}

string CreateAccount::getPassword() {

	return this->password;
}

void CreateAccount::setEmail(string email) {

	this->email = email;
}

string CreateAccount::getEmail() {

	return this->email;
}

void CreateAccount::setPhoneNumber(string pNumber) {

	this->phoneNumber = pNumber;
}

string CreateAccount::getPhoneNumber() {

	return this->phoneNumber;
}

void CreateAccount::setStreetName(string StName) {

	this->streetName = StName;
}

string CreateAccount::getStreetName() {

	return this->streetName;
}

void CreateAccount::setCity(string cName) {

	this->city = cName;
}

string CreateAccount::getCity() {

	return this->city;
}

void CreateAccount::setProvince(string province) {

	this->province = province;
}

string CreateAccount::getProvince() {

	return this->province;
}

void CreateAccount::setAccountID(int accountID) {

	this->accountID;
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
	this->bankNumber = 0;
	//this->userName = userName;
	//this->password = password;
}

Login::Login(int bankNumber, char* password) {
	this->bankNumber = bankNumber;
	//this->password = password;
	strcpy(this->password, password);
	strcpy(this->userName, "");
}

//string Login::getUserName() {
//	return this->userName;
//}

//void Login::setUserName(string userName) {
//	this->userName = userName;
//}

//string Login::getPassword() {
//	return this->userName;
//}

//void Login::setPassword(string userName) {
//	this->userName = userName;
//}

char* Login::getUserName() {
	return this->userName;
}

void Login::setUserName(char* userName) {
	//this->userName = userName;

	strcpy(this->userName, userName);
}

char* Login::getPassword() {
	return this->password;
}

void Login::setPassword(char* password) {
	//this->password = password;

	strcpy(this->password, password);
}

int Login::getBankNumber() {
	return this->bankNumber;
}

void Login::setBankNumber(int bankNumber) {
	this->bankNumber = bankNumber;
}

void Login::setAccountID(int accountID) {
	this->accountID;
}

//Deposit Functions

Deposit::Deposit(int amount, int depositType, int DepositID) {

	this->amount = amount;
	this->depositType = depositType;
	this->depositID = DepositID;
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