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


	bool mainLoop = true;

	bool killswitchOne = true;
	bool killswitchTwo = true;
	bool killswitchThree = true;

	int choice;

	AccountInformation chequingLoginMain;
	AccountInformation savingsLoginMain;

	//main while loop 
	while (mainLoop)
	{
		
	//menu 1 
		while (killswitchOne) {
						
			killswitchTwo = true;
			killswitchThree = true;

			menuOne();
			int choice;
			cin >> choice;

			if (choice < 0 || choice > 3)
			{
				if (choice == 10) {
					cout << "Shutting Down." << endl;
				}
				else
					cout << "wrong input" << endl;	
			}
			

			char* txBuffer = nullptr;
			char rxBuffer[1000] = {};

			switch (choice) {

			case 1:	//Login
			{
				Login loginObj = inputLoginInfo();
				int loginSize = sizeof(loginObj);
				Packet loginPacket(&loginObj, loginSize, 2, 0);
				int totalSize = 0;
				txBuffer = loginPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				char rxBufferChequingLogin[1000] = {};
				char rxBufferSavingLogin[1000] = {};

				int sizeLoginRecv = sizeof(AccountInformation);


				memcpy(rxBufferChequingLogin, rxBuffer, sizeLoginRecv + HeadSize);

				Packet checkStatus(rxBufferChequingLogin);

				int status = checkStatus.getStatus();

				if (status == 1) {

					memcpy(rxBufferSavingLogin, rxBuffer, HeadSize);
					memcpy(rxBufferSavingLogin + HeadSize, rxBuffer + HeadSize + sizeLoginRecv, sizeLoginRecv);

					AccountInformation chequingLogin(rxBufferChequingLogin);
					AccountInformation savingsLogin(rxBufferSavingLogin);

					memcpy(&chequingLoginMain, &chequingLogin, sizeof(chequingLogin));
					memcpy(&savingsLoginMain, &savingsLogin, sizeof(savingsLogin));

					killswitchOne = false;
				}
				else
				{
					cout << "Login unsuccesful, please try again" << endl;
				}


				break;
			}
			case 2:	//Create new Account
			{
				CreateAccount newUser = inputAccountInfo();
				int newUserSize = sizeof(newUser);

				Login loginObj = inputLoginInfo();
				int loginSize = sizeof(loginObj);

				Packet loginPacket(&newUser, newUserSize, &loginObj, loginSize, 5);
				int totalSize = 0;
				txBuffer = loginPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				char rxBufferChequingLogin[1000] = {};
				char rxBufferSavingLogin[1000] = {};

				int sizeLoginRecv = sizeof(AccountInformation);


				memcpy(rxBufferChequingLogin, rxBuffer, sizeLoginRecv + HeadSize);

				Packet checkStatus(rxBufferChequingLogin);

				int status = checkStatus.getStatus();

				if (status == 1) {

					memcpy(rxBufferSavingLogin, rxBuffer, HeadSize);
					memcpy(rxBufferSavingLogin + HeadSize, rxBuffer + HeadSize + sizeLoginRecv, sizeLoginRecv);

					AccountInformation chequingLogin(rxBufferChequingLogin);
					AccountInformation savingsLogin(rxBufferSavingLogin);

					memcpy(&chequingLoginMain, &chequingLogin, sizeof(chequingLogin));
					memcpy(&savingsLoginMain, &savingsLogin, sizeof(savingsLogin));

					//killswitchOne = false;
				}
				else
				{
					cout << "Account creation unsuccesful, please try again" << endl;
				}
				break;
			}
			case 3:	//Forgot Password
			{

				Login loginObj = inputForgotPassword();
				int loginSize = sizeof(loginObj);

				Packet loginPacket(&loginObj, loginSize, 7, 0);
				int totalSize = 0;
				txBuffer = loginPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1)
				{
					cout << "The password reset link was sent to the email that is associated with this account" << endl;

				}
				else
				{
					cout << "Account not found, please try again" << endl;
				}

				break;
			}
			case 10:												//Exit, no menu option since admin command
			{
				Packet shutdownPacket(10, 0);

				int totalSize = 0;
				txBuffer = shutdownPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1)
				{
					cout << "Server Shutting Down." << endl;

					mainLoop = false;
					killswitchOne = false;
					killswitchTwo = false;
					killswitchThree = false;
				}
				else
				{
					cout << "Server failed to receive shutdwon message." << endl;
				}

				break;
			}
			default:
			{
				cout << "Wrong input, please try again" << endl;

				break;
			}
			}

		}

		//menu 2
		while (killswitchTwo) {

			char* txBuffer = nullptr;
			char rxBuffer[1000] = {};

			menuTwo();

			cin >> choice;
			if (choice < 0 || choice > 3)
			{

				cout << "Wrong input, please try again" << endl;	

			}
			else if (choice == 3)													//logoff from menu 2
			{
				int logoffSize = sizeof(chequingLoginMain);

				Packet logoffPacket(&chequingLoginMain, logoffSize, 8, choice);
				int totalSize = 0;

				txBuffer = logoffPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();
				//check if good packet
				if (status == 1) {

					cout << "Logoff succesful" << endl;

					killswitchOne = true;
					killswitchTwo = false;
					killswitchThree = false;
					break;
				}
				else
				{
					cout << "Logoff unsuccesful, please try again" << endl;
				}
			}
			else
			{
				killswitchTwo = false;
			}
			
			killswitchThree = true;

		}


		while (killswitchThree) {

			char* txBuffer = nullptr;
			char rxBuffer[1000] = {};

			int transactionChoice;
			menuThree(choice);
			cin >> transactionChoice;

			if (transactionChoice < 0 || transactionChoice > 9)
			{
				cout << "Wrong input, please try again" << endl;	
				break;
			}

			switch (transactionChoice) {
			case 1:	//send E-Transfer
			{
				Transaction sendEtransferTransaction;
				if (choice == 1)
				{
					sendEtransferTransaction = sendEtransfer(chequingLoginMain);
				}
				else
				{
					sendEtransferTransaction = sendEtransfer(savingsLoginMain);
				}

				int etransferSize = sizeof(sendEtransferTransaction);

				Packet etransferSendPacket(&sendEtransferTransaction, etransferSize, 4, choice);
				int totalSize = 0;

				txBuffer = etransferSendPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1) {

					if (choice == 1)
					{
						chequingLoginMain.display();
						chequingLoginMain.setAccountBalance(sendEtransferTransaction.getNewBalance());
						chequingLoginMain.display();

						break;
					}
					else if (choice == 2)
					{
						savingsLoginMain.setAccountBalance(sendEtransferTransaction.getNewBalance());
					}
				}
				else
				{
					cout << "E-Transfer unsuccesful, please try again" << endl;
				}

				break;
			}
			case 2:	//recv E-Transfer
			{
				Transaction recvEtransferTransaction;
				if (choice == 1)
				{
					recvEtransferTransaction = RecvEtransfer(chequingLoginMain);
				}
				else
				{
					recvEtransferTransaction = RecvEtransfer(savingsLoginMain);
				}

				int etransferSize = sizeof(recvEtransferTransaction);

				Packet etransferRecvPacket(&recvEtransferTransaction, etransferSize, 4, choice);
				int totalSize = 0;

				txBuffer = etransferRecvPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1) {

					if (choice == 1)
					{
						chequingLoginMain.display();
						chequingLoginMain.setAccountBalance(recvEtransferTransaction.getNewBalance());
						chequingLoginMain.display();

						break;
					}
					else if (choice == 2)
					{
						savingsLoginMain.setAccountBalance(recvEtransferTransaction.getNewBalance());
						savingsLoginMain.display();
					}
				}
				else
				{
					cout << "E-Transfer unsuccesful, please try again" << endl;
				}

				break;
			}
			case 3:									//transfer between accounts
			{
				Transaction transferTransaction;
				if (choice == 1)
				{
					transferTransaction = sendBetweenAccounts(chequingLoginMain, savingsLoginMain);
				}
				else
				{
					transferTransaction = sendBetweenAccounts(savingsLoginMain, chequingLoginMain);
				}

				int transferSize = sizeof(transferTransaction);

				Packet transferSendPacket(&transferTransaction, transferSize, 4, choice);
				int totalSize = 0;

				txBuffer = transferSendPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1) {

					if (choice == 1)
					{
						cout << "--Chequings Before--" << endl;
						chequingLoginMain.display();
						chequingLoginMain.setAccountBalance(transferTransaction.getNewBalance());

						double amount = transferTransaction.getPreviousBalance() - transferTransaction.getNewBalance();
						savingsLoginMain.setAccountBalance(savingsLoginMain.getAccountBalance() + amount);
						cout << "--Chequings After--" << endl;
						chequingLoginMain.display();
						savingsLoginMain.display();

						break;
					}
					else if (choice == 2)
					{
						cout << "--Savings Before--" << endl;
						savingsLoginMain.display();
						savingsLoginMain.setAccountBalance(transferTransaction.getNewBalance());

						double amount = transferTransaction.getPreviousBalance() - transferTransaction.getNewBalance();
						chequingLoginMain.setAccountBalance(chequingLoginMain.getAccountBalance() + amount);
						cout << "--Savings After--" << endl;
						savingsLoginMain.display();
						chequingLoginMain.display();

						cout << endl;
					}
				}
				else
				{
					cout << "Transfer between accounts unsuccesful, please try again" << endl;
				}

				break;
			}
			case 4:												//deposit cheque, basically same as receive e-transfer 
			{
				Transaction depositChequeTransaction;
				if (choice == 1)
				{
					depositChequeTransaction = depositCheque(chequingLoginMain);
				}
				else
				{
					depositChequeTransaction = depositCheque(savingsLoginMain);
				}

				int depositChequeSize = sizeof(depositChequeTransaction);

				Packet depositChequeRecvPacket(&depositChequeTransaction, depositChequeSize, 4, choice);
				int totalSize = 0;

				txBuffer = depositChequeRecvPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1) {

					if (choice == 1)
					{
						chequingLoginMain.display();
						chequingLoginMain.setAccountBalance(depositChequeTransaction.getNewBalance());
						chequingLoginMain.display();

						break;
					}
					else if (choice == 2)
					{
						savingsLoginMain.display();
						savingsLoginMain.setAccountBalance(depositChequeTransaction.getNewBalance());
						savingsLoginMain.display();
					}
				}
				else
				{
					cout << "Deposit Cheque unsuccesful, please try again" << endl;
				}


				break;
			}
			case 5:															//view account details 
			{
				int viewAccountSize = sizeof(chequingLoginMain);

				Packet viewAccountPacket(&chequingLoginMain, viewAccountSize, 3, choice);
				int totalSize = 0;

				txBuffer = viewAccountPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);


				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1) {

					CreateAccount AccountInfo(rxBuffer);

					AccountInfo.display();
				}
				else
				{
					cout << "View Account Info unsuccesful, please try again" << endl;
				}

				break;
			}
			case 6:												//view statements picture 
			{

				//send request to view picture

				Packet BFTRequest(9, 0);
				int size = 0;

				txBuffer = BFTRequest.serialize(size);
				send(ClientSocket, txBuffer, size, 0);


				//receiving bytes for picture
				int TotalSize = BFT_SIZE + HeadSize + sizeof(int);
				char RxBuffer[BFT_SIZE + HeadSize + sizeof(int)] = {};

			/*	recv(ClientSocket, RxBuffer, TotalSize, 0);*/

				char BFTBuffer[1024] = {};

				//memcpy(BFTBuffer, RxBuffer, TotalSize);

				char fName[50] = "recvImage.JPG";

				FILE* fp = fopen(fName, "wb");

				bool receivingBytesLoop = true;
				char ack[3] = "ok";

				while (receivingBytesLoop)
				{

					int size = recv(ClientSocket, RxBuffer, TotalSize, 0);
					memcpy(BFTBuffer, RxBuffer + HeadSize, BFT_SIZE);

					//int size = recv(ClientSocket, TxBuffer, sizeof(TxBuffer), 0);
					if (size > HeadSize + sizeof(int))
					{
						fwrite(BFTBuffer, sizeof(BFTBuffer), 1, fp);

						send(ClientSocket, ack, sizeof(ack), 0);
					}
					else
					{
						receivingBytesLoop = false;
					}

				}

				fclose(fp);

				cout << "\nStatements received!\n" << endl;

				break;
			}
			case 7:								//view current balance, client has balance so not sending any packets or anything 
			{
				if (choice == 1)
				{
					cout << chequingLoginMain.getAccountBalance() << endl;

					break;
				}
				else if (choice == 2)
				{
					cout << savingsLoginMain.getAccountBalance() << endl;


					break;
				}
			case 8:										//go back to previous menu ie menu 2 to switch accounts (or log off)
			{
				killswitchOne = false;
				killswitchTwo = true;
				killswitchThree = false;
				break;
			}
			case 9:										//log off 
			{
				int logoffSize = sizeof(chequingLoginMain);

				Packet logoffPacket(&chequingLoginMain, logoffSize, 8, choice);
				int totalSize = 0;

				txBuffer = logoffPacket.serialize(totalSize);

				send(ClientSocket, txBuffer, totalSize, 0);

				recv(ClientSocket, rxBuffer, sizeof(rxBuffer), 0);

				Packet checkStatus(rxBuffer);

				int status = checkStatus.getStatus();

				if (status == 1) {

					cout << "Logoff succesful" << endl;

					killswitchOne = true;
					killswitchThree = false;
					break;
				}
				else
				{
					cout << "Logoff unsuccesful, please try again" << endl;
				}

				break;
			}
			default:
			{
				cout << "Wrong input, please try again" << endl;

				break;
			}
			}

			}

		}
	}

	cout << "\n\nClient Shutting Down." << endl;

	closesocket(ClientSocket);

	//frees Winsock DLL resources
	WSACleanup();
}