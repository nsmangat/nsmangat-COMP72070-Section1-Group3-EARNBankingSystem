#pragma once

#include <memory>
#include <iostream>
#include <fstream>

using namespace std;


 class DataTypes {
	
	int AccountID;

 public:
	 virtual void setAccountID() = 0;

 };

 class createAccount: public DataTypes {
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

	 void setFirstName(string fName) {
		 
		 this->firstName = fName;
	 }

	 string getFirstName() {
		 
		 return this->firstName;
	 }

	 void setLastName(string lName) {
		 
		 this->lastName = lName;
	 }
	 
	 string getLastName() {

		 return this->lastName;
	 }

	 void setUserName(string uName) {

		 this->userName = uName;
	 }

	 string getUserName() {

		 return this->userName;
	 }

	 void setpassword(string pass) {

		 this->password = pass;
	 }

	 string getPassword() {

		 return this->password;
	 }

	 void setEmail(string email) {

		 this->email = email;
	 }

	 string getEmail() {

		 return this->email;
	 }

	 void setPhoneNumber(string pNumber) {

		 this->phoneNumber = pNumber;
	 }

	 string getPhoneNumber() {

		 return this->phoneNumber;
	 }

	 void setStreetName(string StName) {

		 this->streetName = StName;
	 }

	 string getStreetName() {

		 return this->streetName;
	 }

	 void setCity(string cName) {

		 this->city = cName;
	 }

	 string getCity() {

		 return this->city;
	 }

	 void setProvince(string province) {
		 this->province = province;
	 }

	 string getProvince() {
		 return this->province;
	 }
};

 class login : public DataTypes {
	 string userName;
	 string password;
	 int bankNumber;

 public:

 };

 class deposit : public DataTypes {

	 int amount;
	 int depositType;
	 int depositID;

 public:


 };

 class Withdraw : public DataTypes {
	 int amount;
	 int withdrawType;
	 int withdrawTypeID;

 public:

 };

 class transferBetweenAccount : public Datatypes {
	 int amount;
	 int receiverAccountID;
	 int transferID;

 public:

 };