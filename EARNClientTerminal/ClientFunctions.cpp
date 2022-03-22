

#include "ClientFunctions.h"
#include "../EARNNetworkAPI/DataTypes.h"
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void menuOne() {

	cout << "Welcome to EARN Banking System." << endl;
	cout << "1. Login" << endl;
	cout << "2. Create account" << endl;

	/*cout << "1. Create user" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Transfer" << endl;*/
	
}

void menuTwo() {


	cout << "1. Create user" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Transfer" << endl;

}

CreateAccount inputAccountInfo()
{
	cout << "Please input your first name" << endl;
	char firstName[STRING_LENGTH];
	cin.getline(firstName, STRING_LENGTH);

	cout << "Please input your last name" << endl;
	char lastName[STRING_LENGTH];
	cin.getline(lastName, STRING_LENGTH);

	
	cout << "Please input your email" << endl;
	char email[STRING_LENGTH];
	cin.getline(email, STRING_LENGTH);

	cout << "Please input your phoneNumber" << endl;
	char phoneNumber[STRING_LENGTH];
	cin.getline(phoneNumber, STRING_LENGTH);

	cout << "Please input your streetName" << endl;
	char streetName[STRING_LENGTH];
	cin.getline(streetName, STRING_LENGTH);

	cout << "Please input your city" << endl;
	char city[STRING_LENGTH];
	cin.getline(city, STRING_LENGTH);

	cout << "Please input your province" << endl;
	char province[STRING_LENGTH];
	cin.getline(province, STRING_LENGTH);

	cout << "Please input your zipcode" << endl;
	char zipcode[STRING_LENGTH];
	cin.getline(zipcode, STRING_LENGTH);

	int accID = 0;

	//CreateAccount* testAccount = new CreateAccount(firstName, lastName, userName, password, email, phoneNumber, streetName, city, province, accID);
	CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);
	return testAccount;	

	//CreateAccount = function()

}



Login inputLoginInfo()
{

	cout << "Please input your username" << endl;
	char userName[STRING_LENGTH];
	cin.getline(userName, STRING_LENGTH);

	cout << "Please input your password" << endl;
	char password[STRING_LENGTH];
	cin.getline(password, STRING_LENGTH);

	Login testLogin(userName, password);

	return testLogin;

}
