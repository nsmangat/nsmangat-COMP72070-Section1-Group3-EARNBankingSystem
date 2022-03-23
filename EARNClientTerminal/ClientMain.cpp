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


	//char firstName[EarnStructs::VARCHARLEN] = "firstname";
	//char lastName[EarnStructs::VARCHARLEN] = "lastname";
	//char email[EarnStructs::VARCHARLEN] = "email";
	//char phoneNumber[EarnStructs::VARCHARLEN] = "phone number";
	//char streetName[EarnStructs::VARCHARLEN] = "street name";
	//char city[EarnStructs::VARCHARLEN] = "city";
	//char province[EarnStructs::VARCHARLEN] = "province";
	//char zipcode[EarnStructs::ZIPLEN] = "zip12";
	//int accID = 234;

	//char username[EarnStructs::VARCHARLEN] = "username";
	//char password[EarnStructs::VARCHARLEN] = "password";

	//CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);
	//Login testLogin(username, password);

	//int size1 = sizeof(CreateAccount);
	//int size2 = sizeof(Login);

	//Packet testPacket(&testAccount, size1, &testLogin, size2, 5);

	//testAccount.display();
	//testLogin.display();
	////int size = sizeof(test);
	////Packet testPacket(&test, size, 0, 0);


	//int sendSize = 0;
	//char* txBuffer = testPacket.serialize(sendSize);

	//char rxBuffer[1000] = {};
	//memcpy(rxBuffer, txBuffer, sendSize);
	//
	//
	//char rxBuffer1[1000] = {};
	//char rxBuffer2[1000] = {};


	//memcpy(rxBuffer1, rxBuffer, size1 + HeadSize);

	//memcpy(rxBuffer2, rxBuffer, HeadSize);
	//memcpy(rxBuffer2 + HeadSize, rxBuffer + HeadSize + size1, size2);

	//CreateAccount testAccountRecv(rxBuffer1);
	//Login testLoginRecv(rxBuffer2);

	//cout << endl;
	//testAccountRecv.display();
	//testLoginRecv.display();


	//send(ClientSocket, txBuffer, sendSize, 0);


	//char rxBufferMain[1000] = {};

	//recv(ClientSocket, rxBufferMain, sizeof(rxBuffer), 0);
	//char rxBufferChequing[1000] = {};
	//char rxBufferSaving[1000] = {};
	//
	////memcpy(rxBufferChequing, rxBufferMain, sendSize);


	//int size3 = sizeof(AccountInformation);
	//


	//memcpy(rxBufferChequing, rxBufferMain, size3 + HeadSize);

	//memcpy(rxBufferSaving, rxBufferMain, HeadSize);
	//memcpy(rxBufferSaving + HeadSize, rxBufferMain + HeadSize + size3, size3);
	//
	//AccountInformation chequing(rxBufferChequing);
	//AccountInformation savings(rxBufferSaving);
	//cout << endl;
	//chequing.display();
	//savings.display();
	//cout << endl;



	////Credential

	//char usernameTest[EarnStructs::VARCHARLEN] = "username2";
	//char passwordTest[EarnStructs::VARCHARLEN] = "password2";
	//Login testLoginMain(usernameTest, passwordTest);

	//int sizeLogin = sizeof(Login);

	//Packet loginPacket(&testLoginMain, sizeLogin, 2, 1);
	//int loginSize = 0;
	//char* loginTxBuffer = loginPacket.serialize(loginSize);


	//send(ClientSocket, loginTxBuffer, loginSize, 0);

	//char rxBufferLoginSuccess[1000] = {};

	//recv(ClientSocket, rxBufferLoginSuccess, sizeof(rxBufferLoginSuccess), 0);

	//char rxBufferChequingLogin[1000] = {};
	//char rxBufferSavingLogin[1000] = {};
	//
	////memcpy(rxBufferChequing, rxBufferMain, sendSize);


	//int sizeLoginRecv = sizeof(AccountInformation);
	//


	//memcpy(rxBufferChequingLogin, rxBufferLoginSuccess, sizeLoginRecv + HeadSize);

	//memcpy(rxBufferSavingLogin, rxBufferLoginSuccess, HeadSize);
	//memcpy(rxBufferSavingLogin + HeadSize, rxBufferLoginSuccess + HeadSize + sizeLoginRecv, sizeLoginRecv);
	//
	//AccountInformation chequingLogin(rxBufferChequingLogin);
	//AccountInformation savingsLogin(rxBufferSavingLogin);
	//cout << endl;
	//chequingLogin.display();
	//savingsLogin.display();
	//cout << endl;


	////View Account


	//Packet clientPacket(1, 0);
	//int clientPacketSize = 0;
	//char* clientTxBuffer = clientPacket.serialize(clientPacketSize);

	//send(ClientSocket, clientTxBuffer, clientPacketSize, 0);

	//char rxBufferView[1000] = {};
	//recv(ClientSocket, rxBufferView, sizeof(rxBufferView), 0);

	//CreateAccount viewTest(rxBufferView);

	//viewTest.display();



	////Transaction ie etransfer


	//Transaction testTransaction(786, ETRANSFER, 100, 80, 1234);

	//int transactionSize = sizeof(testTransaction);

	//Packet transactionPacket(&testTransaction, transactionSize, 4, 1);

	//int transactionTotalSize = 0;

	//char* transactiontxBuffer = transactionPacket.serialize(transactionTotalSize);

	//send(ClientSocket, transactiontxBuffer, transactionTotalSize, 0);


	//char rxBufferTransfer[1000] = {};
	//recv(ClientSocket, rxBufferTransfer, sizeof(rxBufferTransfer), 0);

	//Packet transferSuccess(rxBufferTransfer);
	//int checkSuccess = transferSuccess.getStatus();

	//if(checkSuccess = 1)
	//{
	//	cout << "Update balance" << endl;
	//}




	bool mainLoop = true;


	//main while loop 
	while (mainLoop)
	{
		bool killswitchOne = true;
		bool killswitchTwo = true;
		bool killswitchThree = true;

		AccountInformation chequingLoginMain;
		AccountInformation savingsLoginMain;

		while (killswitchOne) {

			menuOne();
			int choice;
			cin >> choice;

			if (choice < 0 || choice > 3)
			{
				cout << "wrong input" << endl;	//put logic to go back to login menu
			}


			char* txBuffer = nullptr;
			char rxBuffer[1000] = {};

			switch (choice) {

			case 1:
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
			case 2:
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

					killswitchOne = false;
				}
				else
				{
					cout << "Account creation unsuccesful, please try again" << endl;
				}
				break;
			}
			case 3:
			{

				Login loginObj = inputForgotPassword();
				int loginSize = sizeof(loginObj);

				Packet loginPacket(&loginObj, loginSize, 5, 0);
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
			default:
			{
				cout << "Wrong input, please try again" << endl;

				break;
			}
			}

		}

		//bool killswitchTwo = true;
		int choice;
		while (killswitchTwo) {

			char* txBuffer = nullptr;
			char rxBuffer[1000] = {};

			menuTwo();

			cin >> choice;
			if (choice < 0 || choice > 3)
			{
				cout << "Wrong input, please try again" << endl;	//put logic to go back to login menu

			}
			else if (choice == 3)
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

					killswitchTwo = false;
					killswitchThree = false;
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

		}

		//bool killswitchThree = true;

		while (killswitchThree) {

			char* txBuffer = nullptr;
			char rxBuffer[1000] = {};

			int transactionChoice;
			menuThree(choice);
			cin >> transactionChoice;

			if (transactionChoice < 0 || transactionChoice > 9)
			{
				cout << "Wrong input, please try again" << endl;	//put logic to go back to login menu
				break;
			}

			switch (transactionChoice) {
			case 1:
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
			case 2:
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
			case 3:
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
			case 4:
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
			case 5:
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
			case 6:
			{


				break;
			}
			case 7:
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
			case 8:
			{


				break;
			}
			case 9:
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



		closesocket(ClientSocket);

		//frees Winsock DLL resources
		WSACleanup();



	}

}