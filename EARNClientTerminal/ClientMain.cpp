#define _CRT_SECURE_NO_WARNINGS

#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>

#include "../EARNNetworkAPI/DataTypes.h"
#include "../EARNNetworkAPI/Packet.h"
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

	CreateAccount test = inputAccountInfo();

	test.display();

	///*char firstName[30] = "firstname";
	//char lastName[30] = "lastname";
	//char username[30] = "username";
	//char password[30] = "password";
	//char email[30] = "email";
	//char phoneNumber[30] = "phone number";
	//char streetName[30] = "street name";
	//char city[30] = "city";
	//char province[30] = "province";
	//int accID = 234;

	//CreateAccount testAccount(firstName, lastName, username, password, email, phoneNumber, streetName, city, province, accID);

	int size = sizeof(test);
	Packet testPacket(&test, size, 0);


	int sendSize = 0;
	char* txBuffer = testPacket.serialize(sendSize);



	send(ClientSocket, txBuffer, sendSize, 0);


	closesocket(ClientSocket);

	//frees Winsock DLL resources
	WSACleanup();





}