#define _CRT_SECURE_NO_WARNINGS

#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>

#include "../EARNNetworkAPI/DataTypes.h"
#include "../EARNNetworkAPI/Packet.h"
#include "../EARNNetworkAPI/EARNStructs.h"
#include "ClientFunctions.h"


using namespace std;

int main(void) {

	WSADATA wsaData;
	if ((WSAStartup(MAKEWORD(2, 2), &wsaData)) != 0) {
		return 0;
	}

	//initializes socket. SOCK_STREAM: TCP
	SOCKET ClientSocket;
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ClientSocket == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	//Connect socket to specified server
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;						//Address family type itnernet
	SvrAddr.sin_port = htons(27000);					//port (host to network conversion)
	SvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");	//IP address
	if ((connect(ClientSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr))) == SOCKET_ERROR) {
		closesocket(ClientSocket);
		WSACleanup();
		return 0;
	}


	//menuOne();


	//CreateAccount test = inputAccountInfo();
	//Login loginTest = inputLoginInfo();

	
	char firstName[EarnStructs::VARCHARLEN] = "firstname";
	char lastName[EarnStructs::VARCHARLEN] = "lastname";
	char email[EarnStructs::VARCHARLEN] = "email";
	char phoneNumber[EarnStructs::VARCHARLEN] = "phone number";
	char streetName[EarnStructs::VARCHARLEN] = "street name";
	char city[EarnStructs::VARCHARLEN] = "city";
	char province[EarnStructs::VARCHARLEN] = "province";
	char zipcode[EarnStructs::ZIPLEN] = "zip12";
	int accID = 234;

	char username[EarnStructs::VARCHARLEN] = "username";
	char password[EarnStructs::VARCHARLEN] = "password";

	CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);
	Login testLogin(username, password);

	int size1 = sizeof(CreateAccount);
	int size2 = sizeof(Login);

	Packet testPacket(&testAccount, size1, &testLogin, size2, 5);

	testAccount.display();
	testLogin.display();
	//int size = sizeof(test);
	//Packet testPacket(&test, size, 0, 0);


	int sendSize = 0;
	char* txBuffer = testPacket.serialize(sendSize);

	char rxBuffer[1000] = {};
	memcpy(rxBuffer, txBuffer, sendSize);
	
	
	char rxBuffer1[1000] = {};
	char rxBuffer2[1000] = {};


	memcpy(rxBuffer1, rxBuffer, size1 + HeadSize);

	memcpy(rxBuffer2, rxBuffer, HeadSize);
	memcpy(rxBuffer2 + HeadSize, rxBuffer + HeadSize + size1, size2);

	CreateAccount testAccountRecv(rxBuffer1);
	Login testLoginRecv(rxBuffer2);

	cout << endl;
	testAccountRecv.display();
	testLoginRecv.display();


	send(ClientSocket, txBuffer, sendSize, 0);


	char rxBufferMain[1000] = {};

	recv(ClientSocket, rxBufferMain, sizeof(rxBuffer), 0);
	char rxBufferChequing[1000] = {};
	char rxBufferSaving[1000] = {};
	
	//memcpy(rxBufferChequing, rxBufferMain, sendSize);


	int size3 = sizeof(AccountInformation);
	


	memcpy(rxBufferChequing, rxBufferMain, size3 + HeadSize);

	memcpy(rxBufferSaving, rxBufferMain, HeadSize);
	memcpy(rxBufferSaving + HeadSize, rxBufferMain + HeadSize + size3, size3);
	
	AccountInformation chequing(rxBufferChequing);
	AccountInformation savings(rxBufferSaving);
	cout << endl;
	chequing.display();
	savings.display();
	cout << endl;



	//Credential

	char usernameTest[EarnStructs::VARCHARLEN] = "username2";
	char passwordTest[EarnStructs::VARCHARLEN] = "password2";
	Login testLoginMain(usernameTest, passwordTest);

	int sizeLogin = sizeof(Login);

	Packet loginPacket(&testLoginMain, sizeLogin, 2, 1);
	int loginSize = 0;
	char* loginTxBuffer = loginPacket.serialize(loginSize);


	send(ClientSocket, loginTxBuffer, loginSize, 0);

	char rxBufferLoginSuccess[1000] = {};

	recv(ClientSocket, rxBufferLoginSuccess, sizeof(rxBufferLoginSuccess), 0);

	char rxBufferChequingLogin[1000] = {};
	char rxBufferSavingLogin[1000] = {};
	
	//memcpy(rxBufferChequing, rxBufferMain, sendSize);


	int sizeLoginRecv = sizeof(AccountInformation);
	


	memcpy(rxBufferChequingLogin, rxBufferLoginSuccess, sizeLoginRecv + HeadSize);

	memcpy(rxBufferSavingLogin, rxBufferLoginSuccess, HeadSize);
	memcpy(rxBufferSavingLogin + HeadSize, rxBufferLoginSuccess + HeadSize + sizeLoginRecv, sizeLoginRecv);
	
	AccountInformation chequingLogin(rxBufferChequingLogin);
	AccountInformation savingsLogin(rxBufferSavingLogin);
	cout << endl;
	chequingLogin.display();
	savingsLogin.display();
	cout << endl;


	//View Account


	Packet clientPacket(1, 0);
	int clientPacketSize = 0;
	char* clientTxBuffer = clientPacket.serialize(clientPacketSize);

	send(ClientSocket, clientTxBuffer, clientPacketSize, 0);

	char rxBufferView[1000] = {};
	recv(ClientSocket, rxBufferView, sizeof(rxBufferView), 0);

	CreateAccount viewTest(rxBufferView);

	viewTest.display();



	//Transaction ie etransfer


	Transaction testTransaction(786, ETRANSFER, 100, 80, 1234);

	int transactionSize = sizeof(testTransaction);

	Packet transactionPacket(&testTransaction, transactionSize, 4, 1);

	int transactionTotalSize = 0;

	char* transactiontxBuffer = transactionPacket.serialize(transactionTotalSize);

	send(ClientSocket, transactiontxBuffer, transactionTotalSize, 0);


	char rxBufferTransfer[1000] = {};
	recv(ClientSocket, rxBufferTransfer, sizeof(rxBufferTransfer), 0);

	Packet transferSuccess(rxBufferTransfer);
	int checkSuccess = transferSuccess.getStatus();

	if(checkSuccess = 1)
	{
		cout << "Update balance" << endl;
	}



	closesocket(ClientSocket);

	//frees Winsock DLL resources
	WSACleanup();





}