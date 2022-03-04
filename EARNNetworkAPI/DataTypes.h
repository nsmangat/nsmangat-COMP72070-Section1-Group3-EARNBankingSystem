#pragma once

#include <memory>
#include <iostream>
#include <fstream>

using namespace std;


 class DataTypes {
	
 protected:
	int accountID;

 public:
	 virtual void setAccountID() = 0;
 };

 class CreateAccount: public DataTypes {

	 string firstName;
	 string lastName;
	 string userName;
	 string password;
	 string email;
	 string phoneNumber;
	 string streetName;
	 string city;
	 string province;

 public:

	 CreateAccount(string firstName, string lastName, string userName, string password, string email, string phoneNumber, string streetName, string city, string province, int accountID);	

	 void setFirstName(string fName);

	 string getFirstName(); 

	 void setLastName(string lName); 
	 
	 string getLastName();

	 void setUserName(string uName);

	 string getUserName(); 

	 void setpassword(string pass); 

	 string getPassword(); 

	 void setEmail(string email); 

	 string getEmail(); 

	 void setPhoneNumber(string pNumber); 

	 string getPhoneNumber(); 

	 void setStreetName(string StName);

	 string getStreetName(); 

	 void setCity(string cName);

	 string getCity(); 

	 void setProvince(string province); 

	 string getProvince(); 

	 void setAccountID(int accountID);
};

 class Login : public DataTypes {

	 string userName;
	 string password;
	 int bankNumber;

 public:

	 Login(string Username, string password); 
	 Login(int bankNumber, string password); 

	 string getUserName(); 
	 void setUserName(string userName); 

	 string getPassword(); 
	 void setPassword(string userName); 

	 int getBankNumber(); 
	 void setBankNumber(int bankNumber);

	 void setAccountID(int accountID); 
 };

 class Deposit : public DataTypes {

	 int amount;
	 int depositType;
	 int depositID;

 public:

	 Deposit(int amount, int depositType, int DepositID);

	 void setAmount(int amount);
	 int getAmount();

	 void setDepositType(int Type);
	 int getDepositType();

	 void setDepositID(int ID);
	 int getDepositID();

	 void setAccountID(int accountID);

 };

 class Withdraw : public DataTypes {

	 int amount;
	 int withdrawType;
	 int withdrawTypeID;

 public:

	 Withdraw(int amount, int withdrawType, int withdrawTypeID);

	 void setAmount(int amount);
	 int getAmount();

	 void setWithdrawType(int Type);
	 int getWithdrawType();

	 void setWithdrawTypeID(int ID);
	 int getWithdrawTypeID();

	 void setAccountID(int accountID);
 };

 class TransferBetweenAccount : public DataTypes {

	 int amount;
	 int receiverAccountID;
	 int transferID;

 public:

	 TransferBetweenAccount(int amount, int receiverAccountID, int transferID);

	 void setAmount(int amount);
	 int getAmount();

	 void setReceiverAccountID(int receiverAccountID);
	 int getReceiverAccountID();

	 void setTransferID(int transferID);
	 int getTransferID();

	 void setAccountID(int accountID);

 };