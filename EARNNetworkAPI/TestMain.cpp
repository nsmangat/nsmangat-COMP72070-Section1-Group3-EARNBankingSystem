//[DONE]	Change deserialize from just data to parsing whole received data		
//^use sizeof(header) 
//
//change sizeof time
//

//send back 2 account info objects on login, declare at beginning of main empty and popylate after successful login 
//



//Loop for checking the datatypes in serverMain
	//Create packet with just header info and use that to get the opType
	//Then use that in swicth case to determine what constructor needs to be called	
//Variable to determine DataType from the user input, need this to choose constructor on client side 
//Loop to make sure server and client dont shutdown
//Menu
//


#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <iostream>

#include "DataTypes.h"
#include "Packet.h"
//#include "EARNStructs.h"

using namespace std;
using namespace EarnStructs;

int main(void)
{

	//Deposit testobj(200, 1, 2);
	//testobj.setAccountID(123);
	//int size = sizeof(testobj);
	////int size = 16;
	//int check = testobj.getAccountID();
	//cout << "size of deposit: " << sizeof(testobj) << endl;


	//Packet testPacket(&testobj, size, 5);





	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);

	//testPacket.display();
	//cout << endl;

	////send 

	//char rxBuffer[300] = {};

	////char* Head[128];
	//int num;
	//memcpy(&num, txBuffer + 20, sizeof(int));

	//cout << "operation" << num << endl;

	//memcpy(rxBuffer, txBuffer + 132, 32);

	//int num1;
	//int num2;
	//int num3;		//accountID
	//int num4;
	//int num5;
	//int num6;
	//int num7;
	//int num8;

	//memcpy(&num1, rxBuffer, 4);
	//memcpy(&num2, rxBuffer + 4, 4);
	//memcpy(&num3, rxBuffer + 4 + 4, 4);
	//memcpy(&num4, rxBuffer + 12, 4);
	//memcpy(&num5, rxBuffer + 16, 4);
	//memcpy(&num6, rxBuffer + 20, 4);
	//memcpy(&num7, rxBuffer + 24, 4);
	//memcpy(&num8, rxBuffer + 28, 4);


	///*memcpy(&num1, rxBuffer, 4);
	//memcpy(&num2, rxBuffer + 20, 4);
	//memcpy(&num3, rxBuffer + 24, 4);
	//memcpy(&num4, rxBuffer + 28, 4);*/

	///*memcpy(&num1, rxBuffer, 4);
	//memcpy(&num2, rxBuffer + 4, 4);
	//memcpy(&num3, rxBuffer + 4 + 4, 4);
	//memcpy(&num4, rxBuffer + 28, 4);*/

	//cout << num1 << endl;
	//cout << num2 << endl;
	//cout << num3 << endl;
	//cout << num4 << endl;
	//cout << num5 << endl;
	//cout << num6 << endl;
	//cout << num7 << endl;
	//cout << num8 << endl;

	//char* Data[128];

	//MARCH 20///////////////////////////////////////////////////////////////////////////////////////


	//char firstName[EarnStructs::VARCHARLEN] = "firstname";
	//char lastName[EarnStructs::VARCHARLEN] = "lastname";
	//char username[EarnStructs::VARCHARLEN] = "username";
	//char password[EarnStructs::VARCHARLEN] = "password";
	//char email[EarnStructs::VARCHARLEN] = "email";
	//char phoneNumber[EarnStructs::VARCHARLEN] = "phone number";
	//char streetName[EarnStructs::VARCHARLEN] = "street name";
	//char city[EarnStructs::VARCHARLEN] = "city";
	//char province[EarnStructs::VARCHARLEN] = "province";
	//char zipcode[EarnStructs::ZIPLEN] = "12345";
	//int accID = 234;

	//CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);
	//Login testLogin(username, password);

	//int size1 = sizeof(testAccount);
	//int size2 = sizeof(testLogin);
	//Packet testPacket(&testAccount, size1, &testLogin, size2, 5);
	////Packet testPacket(&testLogin, size2, 5);

	//int sendSize = 0;
	// 
	//char* txBuffer = testPacket.serialize(sendSize);
	//char rxBuffer[1000] = {};

	//char rxBuffer1[1000] = {};
	//char rxBuffer2[1000] = {};
	////int crc;

	////memcpy(&crc, rxBuffer + , sizeof(int));
	////memcpy header to find operationtype

	//memcpy(rxBuffer, txBuffer, sendSize);

	//memcpy(rxBuffer1, rxBuffer, size1 + HeadSize);

	//memcpy(rxBuffer2, rxBuffer, HeadSize);
	//memcpy(rxBuffer2 + HeadSize, rxBuffer + HeadSize + size1, size2);
	//CreateAccount testAccountReceive(rxBuffer1);
	//Login testLoginRecv(rxBuffer2);

	////cout << crc << endl;



	///*for (int i = 0; i < 30; i++)
	//{
	//	int buf = 0;
	//	memcpy(&buf, rxBuffer + HeadSize + (i * 4), 4);
	//	cout << buf << endl;
	//}*/

	//testAccountReceive.display();
	//testLoginRecv.display();

	//testAccountReceive.display();

	//int tail;

	//memcpy(&tail, rxBuffer + 132 + 288, sizeof(int));

	//cout << tail << endl;

	//Packet test2(rxBuffer);
	//int size2 = 0;
	//
	//char* Buffer = test2.serialize(size2);

	//int num = 0;
	//memcpy(&num, Buffer + 132, sizeof(int));
	//cout << num << endl;
	//Packet checkcrc(Buffer);
	//int crc = checkcrc.getTail();
	////cout << crc << endl;

	//int opType = test2.getOperationType();

	//char *testTime = test2.getTime();



	//MARCH 20///////////////////////////////////////////////////////////////////////////////////////


	//March 21///////////////////////////////////////////////////////////////////////////////////////

	//int accID = 234;
	//TransactionType type = ETRANSFER;
	//double pBalance = 5.00;
	//double nBalance = 12.00;
	//int secAcc = 98776;

	//Transaction testTransaction(accID, type, pBalance, nBalance, secAcc);
	//int size3 = sizeof(testTransaction);
	//Packet testPacket(&testTransaction, size3, 1);


	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);
	//char rxBuffer[1000] = {};

	//memcpy(rxBuffer, txBuffer, sendSize);

	//Transaction testTransactionRecv(rxBuffer);

	//testTransactionRecv.display();




	/*int clientID = 234;
	AccountType type = CHEQUINGS;
	double accountBalance = 10.00;

	AccountInformation testAccountInformation(clientID, type, accountBalance);
	int size3 = sizeof(testAccountInformation);
	Packet testPacket(&testAccountInformation, size3, 1, 0);


	int sendSize = 0;
	char* txBuffer = testPacket.serialize(sendSize);
	char rxBuffer[1000] = {};

	memcpy(rxBuffer, txBuffer, sendSize);

	AccountInformation testAccountInformationRecv(rxBuffer);

	testAccountInformationRecv.display();*/

	//March 21///////////////////////////////////////////////////////////////////////////////////////





	//cout << opType << endl;
	//cout << testTime << endl;

	// garbage
	//Login testLogin(username, password);
	//int size = sizeof(testLogin);
	//testLogin.setAccountID(123);


	//cout << "size of login: " << sizeof(testLogin) << endl;


	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);

	//testPacket.display();
	//cout << endl;

	//char rxBuffer[300] = {};


	//memcpy(rxBuffer, txBuffer + 132, 68);

	//int num1;
	//int num2;
	//int num3;		//accountID
	//int num4;
	//char num5[20] = {};
	//char num6[20] = {};
	//int num7;
	//int num8;
	//int num9;

	//memcpy(&num1, rxBuffer, 4);
	//memcpy(&num2, rxBuffer + 4, 4);
	//memcpy(&num3, rxBuffer + 4 + 4, 4);
	//memcpy(&num4, rxBuffer + 12, 4);
	//memcpy(num5, rxBuffer + 16, 20);
	//memcpy(num6, rxBuffer + 36, 20);
	//memcpy(&num7, rxBuffer + 56, 4);
	//memcpy(&num8, rxBuffer + 60, 4);
	//memcpy(&num9, rxBuffer + 64, 4);

	//cout << num1 << endl;
	//cout << num2 << endl;
	//cout << num3 << endl;
	//cout << num4 << endl;
	//cout << num5 << endl;
	//cout << num6 << endl;
	//cout << num7 << endl;
	//cout << num8 << endl;
	//cout << num9 << endl;




	//char username[30] = "username";
	//char password[30] = "password";	

	//Login testLogin(username, password);

	//int size = sizeof(testLogin);
	//Packet testPacket(&testLogin, size, 5);


	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);
	//char rxBuffer[500] = {};

	////memcpy header to find operationtype

	//memcpy(rxBuffer, txBuffer + 132, 80);
	//Login testLoginReceive(rxBuffer);

	//testLoginReceive.display();



	//int amount = 200;
	//int depositID = 2;
	//int depositType = 123;

	//Deposit testDeposit(amount, depositID, depositType);

	//int size = sizeof(testDeposit);
	//Packet testPacket(&testDeposit, size, 5);


	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);
	//char rxBuffer[500] = {};

	////memcpy header to find operationtype

	//memcpy(rxBuffer, txBuffer + 132, 32);
	//Deposit testDepositReceive(rxBuffer);

	//testDepositReceive.display();


	//int amount = 200;
	//int depositID = 2;
	//int depositType = 123;

	//Withdraw testWithdraw(amount, depositID, depositType);

	//int size = sizeof(testWithdraw);
	//Packet testPacket(&testWithdraw, size, 5);


	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);
	//char rxBuffer[500] = {};

	////memcpy header to find operationtype

	//memcpy(rxBuffer, txBuffer + 132, 32);
	//Withdraw testDepositReceive(rxBuffer);

	//testDepositReceive.display();


	//int amount = 200;
	//int depositID = 2;
	//int depositType = 123;

	//TransferBetweenAccount testWithdraw(amount, depositID, depositType);

	//int size = sizeof(testWithdraw);
	//Packet testPacket(&testWithdraw, size, 5);


	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);
	//char rxBuffer[500] = {};

	////memcpy header to find operationtype

	//memcpy(rxBuffer, txBuffer + 132, 32);
	//TransferBetweenAccount testDepositReceive(rxBuffer);

	//testDepositReceive.display();

	////for getting info from Header
	//Packet test2(txBuffer);
	//int opType = test2.getOperationType();

	//char *testTime = test2.getTime();
	//cout << opType << endl;
	//cout << testTime << endl;

	//March 22///////////////////////////////////////////////////////////////////////////////////////


	char username[EarnStructs::VARCHARLEN] = "usernamestruct";
	char password[EarnStructs::VARCHARLEN] = "passwordstruct";

	Login structCheck(username, password);

	CredentialInfo test = structCheck.getLoginStruct();

	cout << test.username << endl;
	cout << test.userPasswordHash << endl;

	char firstName[EarnStructs::VARCHARLEN] = "firstname";
	char lastName[EarnStructs::VARCHARLEN] = "lastname";
	//char username[EarnStructs::VARCHARLEN] = "username";
	//char password[EarnStructs::VARCHARLEN] = "password";
	char email[EarnStructs::VARCHARLEN] = "email";
	char phoneNumber[EarnStructs::VARCHARLEN] = "phone number";
	char streetName[EarnStructs::VARCHARLEN] = "street name";
	char city[EarnStructs::VARCHARLEN] = "city";
	char province[EarnStructs::VARCHARLEN] = "province";
	char zipcode[EarnStructs::ZIPLEN] = "12345";
	int clientID = 234;

	CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, clientID);

	ClientInfo testClientInfo = testAccount.getClientInfoStruct();

	cout << testClientInfo.email << endl;

	AccountInformation oldAccount(1, clientID, SAVINGS, 20);
	AccountInformation newAccount;

	memcpy(&newAccount, &oldAccount, sizeof(oldAccount));

	newAccount.display();

	Transaction testTransaction(123, ETRANSFER, 2, 3, 4);
	Transaction copiedTransaction;
	memcpy(&copiedTransaction, &testTransaction, sizeof(Transaction));
	copiedTransaction.display();
}