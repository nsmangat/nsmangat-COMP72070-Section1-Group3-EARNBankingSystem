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
		char rxBuffer[1000] = {};


		recv(ConnectionSocket, rxBuffer, sizeof(rxBuffer), 0);

		Packet checkOperation(rxBuffer);		//get just the headerswit

		//check objecttype
		int operation = checkOperation.getObjectType();

		char TxBuffer[1000] = {};
		int sendSize = 0;
		//switch cases

		switch (operation) {

		case OBJECTNULL:
		{




			break;
		}
		case CREATEACCOUNT:		//When account needs to be created
		{
			char rxBuffer1[1000] = {};
			char rxBuffer2[1000] = {};

			int size1 = sizeof(CreateAccount);
			int size2 = sizeof(Login);
			memcpy(rxBuffer1, rxBuffer, size1 + HeadSize);		//get account info

			memcpy(rxBuffer2, rxBuffer, HeadSize);
			memcpy(rxBuffer2 + HeadSize, rxBuffer + HeadSize + size1, size2);	//get login info

			CreateAccount testAccountRecv(rxBuffer1);
			Login testLoginRecv(rxBuffer2);

			testAccountRecv.display();
			testLoginRecv.display();

			//database authenticates 

			int clientID = 100;

			AccountInformation chequing(clientID, CHEQUINGS, 0);
			AccountInformation savings(clientID, SAVINGS, 0);

			int size3 = sizeof(chequing);

			Packet startup(&chequing, size3, &savings, size3, 6);
			startup.setStatus(1);
			int totalSize = 0;
			char* txBuffer = startup.serialize(totalSize);

			send(ConnectionSocket, txBuffer, totalSize, 0);

			break;
		}
		case CREDENTIALS:		//Validate username and password
		{
			Login testLogin(rxBuffer);

			testLogin.display();



			//database authenticates 



			int clientIDlogin = 200;

			AccountInformation chequingLogin(clientIDlogin, CHEQUINGS, 500);
			AccountInformation savingsLogin(clientIDlogin, SAVINGS, 100);

			int size3 = sizeof(chequingLogin);

			Packet LoginSuccess(&chequingLogin, size3, &savingsLogin, size3, 6);
			LoginSuccess.setStatus(1);
			int totalSizeLogin = 0;
			char* txBufferLogin = LoginSuccess.serialize(totalSizeLogin);

			send(ConnectionSocket, txBufferLogin, totalSizeLogin, 0);

			break;
		}

		case ACCOUNT:		//Request info for View account info
		{

			AccountInformation recvAccount(rxBuffer);

			int id = recvAccount.getClientID();


			//database gets client info 

			char firstName[EarnStructs::VARCHARLEN] = "servername";
			char lastName[EarnStructs::VARCHARLEN] = "serverlastname";
			char email[EarnStructs::VARCHARLEN] = "serveremail";
			char phoneNumber[EarnStructs::VARCHARLEN] = "serverphone number";
			char streetName[EarnStructs::VARCHARLEN] = "serverstreet name";
			char city[EarnStructs::VARCHARLEN] = "servercity";
			char province[EarnStructs::VARCHARLEN] = "serverprovince";
			char zipcode[EarnStructs::ZIPLEN] = "pi123";
			int accID = 999;

			CreateAccount serverAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);
			int viewAccountSize = sizeof(CreateAccount);
			Packet viewAccount(&serverAccount, viewAccountSize, 1, 0);
			viewAccount.setStatus(1);
			int viewAccountTotalSize = 0;

			char* viewAccountTxBuffer = viewAccount.serialize(viewAccountTotalSize);

			send(ConnectionSocket, viewAccountTxBuffer, viewAccountTotalSize, 0);

			break;
		}
		case TRANSACTION:		//Can be any of the transaction types
		{
			Transaction TransactionRecv(rxBuffer);

			TransactionRecv.display();
			int currentTransaction = TransactionRecv.getTransactionType();
			//database stuff

			Packet clientPacket(4, 0);
			clientPacket.setStatus(1);

			int clientTotalSize = 0;
			char* clientTxBuffer = clientPacket.serialize(clientTotalSize);

			send(ConnectionSocket, clientTxBuffer, clientTotalSize, 0);




			//buffertransfer

			break;
		}
		case BIGFILETRANSFER:		//Send an image
		{

			char BFTBuffer[BFT_SIZE];

			FILE* fp = fopen("Statement.jpeg", "rb");

			int len;
			char buf[3] = {};
			Packet BFTSend(BFTBuffer, checkOperation.getObjectType());
			char* BFTSendBuffer;

			while ((len = fread(BFTBuffer, sizeof(BFTBuffer), 1, fp)) > 0)
			{

				BFTSend.setDataBFT(BFTBuffer);
				int size = 0;
				BFTSendBuffer = BFTSend.serialize(size);

				send(ConnectionSocket, BFTSendBuffer, size, 0);

				recv(ConnectionSocket, buf, sizeof(buf), 0);
			}

			Packet empty(9, 0);
			int size1 = 0;
			char* doneBuffer = empty.serialize(size1);

			send(ConnectionSocket, doneBuffer, size1, 0);

			fclose(fp);

			
			//database stuff

			break;
		}
		case STARTUPACCOUNTINFO:		
		{
			//database stuff

			killSwitch = false;
			break;
		}
		case FORGETPASSWORD:		//Validate email for reset password link
		{
			Login testLogin(rxBuffer);

			testLogin.display();

			//database authenticates 


			Packet LoginSuccess(7, 0);
			LoginSuccess.setStatus(1);
			int totalSizeLogin = 0;
			char* txBufferLogin = LoginSuccess.serialize(totalSizeLogin);

			send(ConnectionSocket, txBufferLogin, totalSizeLogin, 0);
			//database stuff

			
			break;
		}
		case LOGOFF:		//Logoff account
		{
			Packet clientPacket2(8, 0);
			clientPacket2.setStatus(1);
			int clientTotalSize2 = 0;
			char* clientTxBuffer2 = clientPacket2.serialize(clientTotalSize2);


			send(ConnectionSocket, clientTxBuffer2, clientTotalSize2, 0);

			//database stuff

			break;
		}
		case SHUTDOWN:		//shutdown the server
		{
			Packet shutdownPacket(10, 0);
			shutdownPacket.setStatus(1);
			int shutdownTotalSize2 = 0;
			char* shutdownTxBuffer2 = shutdownPacket.serialize(shutdownTotalSize2);


			send(ConnectionSocket, shutdownTxBuffer2, shutdownTotalSize2, 0);

			killSwitch = false;
			break;
		}
		default:		//loopback
		{

			break;
		}
		}

	}

	cout << "\n\nShutting down server" << endl;

	closesocket(ConnectionSocket);	//closes incoming socket
	closesocket(ServerSocket);	    //closes server socket	
	WSACleanup();					//frees Winsock resources



}