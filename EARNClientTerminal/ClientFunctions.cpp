

#include "ClientFunctions.h"
#include "../EARNNetworkAPI/DataTypes.h"
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void menuOne() {

	cout << "Welcome to EARN Banking System." << endl;
	cout << "1. Login" << endl;
	cout << "2. Create user" << endl;
	cout << "3. Forgot password" << endl;
}

void menuTwo() {

	cout << "Please select which account you want to operate in" << endl;
	cout << "1. Chequing Account" << endl;
	cout << "2. Savings Account" << endl;
	cout << "3. Logoff" << endl;
}

void menuThree(int choice) {

	if(choice == 1)
	{
		cout << "Chequings account" << endl << endl;

	}
	else
	{
		cout << "Savings account" << endl << endl;
	}

	cout << "1. Send E-Transfer" << endl;
	cout << "2. Receive E-Transfer" << endl;
	cout << "3. Transfer Between Accounts" << endl;
	cout << "4. Deposit cheque" << endl;
	cout << "5. View account details" << endl;
	cout << "6. View statements" << endl;
	cout << "7. View current balance" << endl;
	cout << "8. Go back to selecting an account" << endl;
	cout << "9. Logoff" << endl;

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
	cin >> userName;
	//cin.getline(userName, STRING_LENGTH);

	cout << "Please input your password" << endl;
	char password[STRING_LENGTH];
	cin >> password;
	//cin.getline(password, STRING_LENGTH);

	Login testLogin(userName, password);

	return testLogin;
}

Login inputForgotPassword()
{
	cout << "Please input your email for the account you forgot your password for" << endl;
	char userName[STRING_LENGTH];
	//cin.getline(userName, STRING_LENGTH);
	cin >> userName;

	char password[STRING_LENGTH] = {};
	Login forgotPassword(userName, password);

	return forgotPassword;
}

Transaction sendEtransfer(AccountInformation acc)
{
	cout << "Please select an amount to send" << endl;
	double amount;
	cin >> amount;

	cout << "Please select an account you are sending to" << endl;
	int sendAcc;
	cin >> sendAcc;

	double newBalance = acc.getAccountBalance() - amount;

	Transaction send(acc.getClientID(), ETRANSFER, acc.getAccountBalance(), newBalance, sendAcc);

	return send;
}

Transaction RecvEtransfer(AccountInformation acc) {

	cout << "Please enter the amount to deposit:" << endl;
	double amount;
	cin >> amount;

	double nBalance = acc.getAccountBalance() + amount;

	Transaction send(acc.getClientID(), ETRANSFER, acc.getAccountBalance(), nBalance, 0);		//secAcc set to zero because no acc needed

	return send;
}

Transaction sendBetweenAccounts(AccountInformation current, AccountInformation other) {

	int currentType = current.getAccountType();

	char accType[VARCHARLEN] = {};

	if (currentType == 1) {

		strcpy(accType, "Savings");
	}
	else {

		strcpy(accType, "Chequings");
	}
	
	cout << "Please enter the amount you would like to transfer to " << accType << " account:" << endl;
	double amount;
	cin >> amount;

	double newBalance = current.getAccountBalance() - amount;
	Transaction transferBetween(current.getClientID(), ACCOUNTTRANSFER, current.getAccountBalance(), newBalance, other.getClientID());

	return transferBetween;
}

Transaction depositCheque(AccountInformation acc) {

	cout << "Please enter the amount from the cheque:" << endl;
	double amount;
	cin >> amount;

	double nBalance = acc.getAccountBalance() + amount;

	Transaction send(acc.getClientID(), CHEQUE, acc.getAccountBalance(), nBalance, 0);		//secAcc set to zero because no acc needed

	return send;
}



