#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <memory>
#include <iostream>
#include <fstream>

#define STRING_LENGTH 30
const int HeadSize = 136;

using namespace std;

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
	 //virtual void setAccountID(int num) = 0;
	 virtual void display() = 0;
 };

 class CreateAccount: public DataTypes {		//size 290

	 char firstName[STRING_LENGTH];
	 char lastName[STRING_LENGTH];
	 char userName[STRING_LENGTH];
	 char password[STRING_LENGTH];
	 char email[STRING_LENGTH];
	 char phoneNumber[STRING_LENGTH];
	 char streetName[STRING_LENGTH];
	 char city[STRING_LENGTH];
	 char province[STRING_LENGTH];

 public:

	 CreateAccount(char* firstName, char* lastName, char* userName, char* password, char* email, char* phoneNumber, char* streetName, char* city, char* province, int accountID);	
	 CreateAccount(char* src);

	 void setFirstName(char* fName);
	 char* getFirstName(); 

	 void setLastName(char* lName); 
	 char* getLastName();

	 void setUserName(char* uName);
	 char* getUserName(); 

	 void setpassword(char* pass); 
	 char* getPassword(); 

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

	 void setAccountID(int accountID);

	 void display();
};

 class Login : public DataTypes {		//size 80

	 //string userName;
	 //string password;

	 char userName[STRING_LENGTH];
	 char password[STRING_LENGTH];
	//int bankNumber;
	 
 public:

	 //Login(string Username, string password);
	 Login(char* Username, char* password); 
	 //Login(int bankNumber, string password); 
	 //Login(int bankNumber, char* password); 

	 Login(char* src);

	 //string getUserName(); 
	 //void setUserName(string userName); 

	 //string getPassword(); 
	 //void setPassword(string userName); 

	 char* getUserName(); 
	 void setUserName(char* userName); 

	 char* getPassword(); 
	 void setPassword(char* userName); 

	/* int getBankNumber(); 
	 void setBankNumber(int bankNumber);*/

	 void setAccountID(int accountID); 

	 void display();
 };

 class Deposit : public DataTypes{		//Size 12

	 int amount;
	 int depositType;
	 int depositID;

 public:

	 Deposit(int amount, int depositType, int DepositID);
	 Deposit(char* src);

	 void setAmount(int amount);
	 int getAmount();

	 void setDepositType(int Type);
	 int getDepositType();

	 void setDepositID(int ID);
	 int getDepositID();

	 void setAccountID(int accountID);
	 int getAccountID();

	 void display();
 };

 class Withdraw : public DataTypes {		//size 12

	 int amount;
	 int withdrawType;
	 int withdrawTypeID;

 public:

	 Withdraw(int amount, int withdrawType, int withdrawTypeID);
	 Withdraw(char* src);

	 void setAmount(int amount);
	 int getAmount();

	 void setWithdrawType(int Type);
	 int getWithdrawType();

	 void setWithdrawTypeID(int ID);
	 int getWithdrawTypeID();

	 void setAccountID(int accountID);
	 void display();

 };

 class TransferBetweenAccount : public DataTypes {		//size 12

	 int amount;
	 int receiverAccountID;
	 int transferID;

 public:

	 TransferBetweenAccount(int amount, int receiverAccountID, int transferID);
	 TransferBetweenAccount(char* src);

	 void setAmount(int amount);
	 int getAmount();

	 void setReceiverAccountID(int receiverAccountID);
	 int getReceiverAccountID();

	 void setTransferID(int transferID);
	 int getTransferID();

	 void setAccountID(int accountID);
	 void display();
 };

 class TransactionConfirmation : public DataTypes {

	 int currentBalance;
	 int transactionID;

 public:
	 TransactionConfirmation(char* src);							//client receives confirmation

	 int getCurrentBalance();
	 void setCurrentBalance(int currentBalance);

	 int getTransactionID();
	 void setTransactionID(int transactionID);

 };
