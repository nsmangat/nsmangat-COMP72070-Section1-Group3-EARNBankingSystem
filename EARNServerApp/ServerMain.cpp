#define _CRT_SECURE_NO_WARNINGS

#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>

#include "../EARNNetworkAPI/DataTypes.h"
#include "../EARNNetworkAPI/Packet.h"


using namespace std;

int main(void) {

	//starts Winsock DLLs		
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		return 0;

	//create server socket
	SOCKET ServerSocket;
	ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET) {
		WSACleanup();
		return 0;
	}

	//binds socket to address
	sockaddr_in SvrAddr;
	SvrAddr.sin_family = AF_INET;
	SvrAddr.sin_addr.s_addr = INADDR_ANY;
	SvrAddr.sin_port = htons(27000);
	if (bind(ServerSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr)) == SOCKET_ERROR)
	{
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	//listen on a socket
	if (listen(ServerSocket, 1) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}


	cout << "Waiting for client connection\n" << endl;

	//accepts a connection from a client
	SOCKET ConnectionSocket;
	ConnectionSocket = SOCKET_ERROR;
	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}

	bool killSwitch = true;

	while (killSwitch)
	{
		char rxBuffer[500] = {};


		recv(ConnectionSocket, rxBuffer, sizeof(rxBuffer), 0);

		Packet checkOperation(rxBuffer);		//get just the headerswit

		//check crc
		int operation = checkOperation.getOperationType();

		char TxBuffer[500] = {};
		int sendSize = 0;
		//switch cases

		switch (operation) {

		case CreateUserType:
		{
			CreateAccount newUser(rxBuffer);

			newUser.display();
			killSwitch = false;
			break;
		}
		case LoginType:
		{
			Login newLogin(rxBuffer);

			break;
		}
		case DepositType:
		{
			Deposit newDeposit(rxBuffer);

			break;
		}

		case WithdrawType:
		{
			Withdraw newWithdraw(rxBuffer);
			int thing = 0;


			break;
		}
		case TransferType:
		{
			TransferBetweenAccount newTransfer(rxBuffer);
			//database stuff



			//buffertransfer

			break;
		}
		case LogoffType:
		{			
			//database stuff

			//buffertransfer
			killSwitch = false;
			break;
		}
		default:
		{
			killSwitch = false;

			break;
		}

		}

		//send(ConnectionSocket, txBuffer, sendSize, 0);
	}





	closesocket(ConnectionSocket);	//closes incoming socket
	closesocket(ServerSocket);	    //closes server socket	
	WSACleanup();					//frees Winsock resources


}