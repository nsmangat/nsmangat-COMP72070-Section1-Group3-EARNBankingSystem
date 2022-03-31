#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <memory>
#include <iostream>
#include <fstream>
#include "EARNStructs.h"

#define STRING_LENGTH 30
const int HeadSize = 84;
enum dataTypeChoice { CreateUserType, LoginType, DepositType, WithdrawType, TransferType, LogoffType };

using namespace std;
using namespace EarnStructs;

//library def for time function
enum DateFormat { YMD_HMS, MDY_HMS, DMY_HMS };

std::string getCurrentTime(DateFormat logDateFormat);

//bytes 8-12 are the accountID
//bytes 1-16 are together in the beginnning 
//last 2 bytes are after the child object
//Total bytes are 18
//crc is after data
//ie src + head size + data = 132+288 if create account, then crc right after ie starting at 422

class DataTypes {

protected:
	int accountID;

public:
	virtual void display() = 0;
};

class CreateAccount : public DataTypes {		//size 290

	EarnStructs::ClientInfo user;

public:

	CreateAccount(char* firstName, char* lastName, char* email, char* phoneNumber, char* streetName, char* city, char* province, char* zipcode, int accountID);
	CreateAccount(char* src, int startBase);

	void setFirstName(char* fName);
	char* getFirstName();

	void setLastName(char* lName);
	char* getLastName();

	void setEmail(char* email);
	char* getEmail();

	void setPhoneNumber(char* pNumber);
	char* getPhoneNumber();

	void setStreetName(char* StName);
	char* getStreetName();

	void setCity(char* cName);
	char* getCity();

	void setProvince(char* province);
	char* getProvince();

	void setZipcode(char* zipcode);
	char* getZipcode();

	void setAccountID(int accountID);
	int getAccountID();

	void display();

	ClientInfo getClientInfoStruct();
};

class Login : public DataTypes {		//size 80

	CredentialInfo login;

public:

	Login(char* Username, char* password);
	Login(char* src, int startBase);

	int getClientID();
	void setClientID(int clientID);

	char* getUserName();
	void setUserName(char* userName);

	int getUserNumber();
	void setUserNumber(int clientID);

	char* getPassword();
	void setPassword(char* userName);

	void setAccountID(int accountID);

	void display();

	CredentialInfo getLoginStruct();
};


class Transaction : public DataTypes {

	TransactionInfo TInfo;

public:

	Transaction(int accID, TransactionType type, double pBalance, double nBalance, int secAcc);
	Transaction(char* src, int startBase);
	Transaction();

	void display();

	int getAccID();
	void setAccID(int accID);

	int getTransactionType();
	void setTransactionType(TransactionType type);

	char* getTransactionTime();
	void setTransactionTime();

	double getPreviousBalance();
	void setPreviousBalance(double pBalance);

	double getNewBalance();
	void setNewBalance(double nBalance);

	int getSecondaryAccount();
	void setSecondaryAccount(int accNum);

	TransactionInfo getTransactionInfoStruct();

	//add function to calculate new balance
};

class AccountInformation : public DataTypes {

	AccountInfo accInfo;

public:

	AccountInformation(int id, AccountType type, double balance);
	AccountInformation(char* src);
	AccountInformation();

	void display();

	int getClientID();
	void setClientID(int id);

	int getAccountType();
	void setAccountType(AccountType type);

	double getAccountBalance();
	void setAccountBalance(double balance);

	AccountInfo getAccountInfoStruct();
};