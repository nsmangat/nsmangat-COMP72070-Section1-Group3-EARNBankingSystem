///*
#define _CRT_SECURE_NO_WARNINGS

#include <windows.networking.sockets.h>
#pragma comment(lib, "Ws2_32.lib")

#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#include <vector>
#include <functional>

#include <DataTypes.h>		//"../EARNNetworkAPI/DataTypes.h"
#include <Packet.h>			//"../EARNNetworkAPI/Packet.h"
#include <EARNStructs.h>	//"../EARNNetworkAPI/EARNStructs.h"
#include <EARNLogger.h>
#include "DBDrivers.h"
#include "DBObjects.h"

using namespace std;
using namespace EarnDBDrivers;
using namespace EarnDBObjects;
using namespace EarnLogging;

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
	if (::bind(ServerSocket, (struct sockaddr*)&SvrAddr, sizeof(SvrAddr)) == SOCKET_ERROR)
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


	std::cout << "Waiting for client connection\n" << endl;

	//accepts a connection from a client
	SOCKET ConnectionSocket;
	ConnectionSocket = SOCKET_ERROR;
	if ((ConnectionSocket = accept(ServerSocket, NULL, NULL)) == SOCKET_ERROR) {
		closesocket(ServerSocket);
		WSACleanup();
		return 0;
	}


	bool killSwitch = true;

	//just create all three ahead of time since they will all be used...
	string testServer = "localhost";

	string testSchema = "EARNBankingDB";

	//setup reader
	string readerUser = "EARNDBReader";
	string readerPass = "Gcugy6/fA{KR9H(r|:1Gp^qyd";
	DBReader serverDBReader(testServer, testSchema, readerUser, readerPass);

	//setup validation
	string writerUser = "EARNDBWriter";
	string writerPass = "|RI?BEe8drU0JoD~_j*|=fS@=";
	DBWriter serverDBWriter(testServer, testSchema, writerUser, writerPass);

	//setup writer
	string validationUser = "EARNDBValidation";
	string validationPass = "@:+fA,UFr[xn_[3>QwBuB#9qi";
	DBValidation serverDBValidator(testServer, testSchema, validationUser, validationPass);

	EarnLogging::EARNLogger testLogger("ConnectionLogs.csv");

	while (killSwitch)
	{
		char rxBuffer[1000] = {};


		recv(ConnectionSocket, rxBuffer, sizeof(rxBuffer), 0);

		Packet checkOperation(rxBuffer);		//get just the headerswit

		EarnLogging::ConnectionLog receiveLog(&checkOperation, SERVERSYSTEM, RECEIVE, "received log from client");
		testLogger.logData(&receiveLog);

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

			CreateAccount RxClient(rxBuffer1, 12);
			Login RxLogin(rxBuffer2, 4);

			RxClient.display();
			RxLogin.display();

			//database authenticates 
			DBClient newClient(RxClient.getClientInfoStruct());
			DBResponses responseVal = serverDBWriter.addObject(newClient);

			RxLogin.setClientID(newClient.getObjectID());

			//unique enough for program to make user numbers...
			string hashString;
			hashString += newClient.getFirstName();
			hashString += newClient.getLastName();
			hashString += to_string(newClient.getObjectID());

			size_t newUserNum = hash<string>{} (hashString);

			RxLogin.setUserNumber((unsigned int)newUserNum);

			EarnDBObjects::DBCredential newLoginValidation(RxLogin.getLoginStruct());
			responseVal = serverDBWriter.addObject(newLoginValidation);

			AccountInformation newChequing(newClient.getObjectID(), CHEQUINGS, 0);
			DBAccount newChequingAccount(newChequing.getAccountInfoStruct());

			responseVal = serverDBWriter.addObject(newChequingAccount);

			newChequingAccount.getObjectID();

			AccountInformation newSavings(newClient.getObjectID(), SAVINGS, 0);
			DBAccount newSavingsAccount(newSavings.getAccountInfoStruct());

			responseVal = serverDBWriter.addObject(newSavingsAccount);

			int size3 = sizeof(newChequing);
			Packet startup(&newChequing, size3, &newSavings, size3, 6);

			if (DBSuccess == responseVal) {
				startup.setStatus(1);
			}
			else {
				startup.setStatus(0);
			}

			int totalSize = 0;
			char* txBuffer = startup.serialize(totalSize);

			EarnLogging::ConnectionLog sendLog(&startup, SERVERSYSTEM, SEND, "sending response for client creation");
			testLogger.logData(&sendLog);

			send(ConnectionSocket, txBuffer, totalSize, 0);

			break;
		}
		case CREDENTIALS:		//Validate username and password
		{
			Login userLogin(rxBuffer, 12);

			userLogin.display();



			//database authenticates 
			DBClient currentClient;
			DBResponses clientResponse = serverDBValidator.clientLogin(userLogin.getLoginStruct(), currentClient);

			if (DBSuccess == clientResponse) {
				vector<DBAccount> clientAccounts;

				int numOfAccounts;
				DBResponses responseVal = serverDBReader.getObjectsInfo(currentClient.getObjectID(), numOfAccounts, clientAccounts);

				AccountInformation chequingLogin(currentClient.getObjectID(), clientAccounts[0].getAccountType(), clientAccounts[0].getAccountBalance());
				AccountInformation savingsLogin(currentClient.getObjectID(), clientAccounts[1].getAccountType(), clientAccounts[1].getAccountBalance());

				int size3 = sizeof(chequingLogin);

				Packet LoginSuccess(&chequingLogin, size3, &savingsLogin, size3, 6);

				if (DBSuccess == responseVal) {
					LoginSuccess.setStatus(1);
				}
				else {
					LoginSuccess.setStatus(0);
				}

				int totalSizeLogin = 0;
				char* txBufferLogin = LoginSuccess.serialize(totalSizeLogin);

				EarnLogging::ConnectionLog sendLog(&LoginSuccess, SERVERSYSTEM, SEND, "sending response for login");
				testLogger.logData(&sendLog);

				send(ConnectionSocket, txBufferLogin, totalSizeLogin, 0);

			}
			else {

				Packet LoginFail(2, 0);
				LoginFail.setStatus(0);

				int totalSizeLogin = 0;
				char* txBufferLogin = LoginFail.serialize(totalSizeLogin);

				EarnLogging::ConnectionLog sendLog(&LoginFail, SERVERSYSTEM, SEND, "sending error response for login");
				testLogger.logData(&sendLog);

				send(ConnectionSocket, txBufferLogin, totalSizeLogin, 0);
			}
			break;
		}

		case ACCOUNT:		//Request info for View account info
		{

			AccountInformation recvAccount(rxBuffer);

			int id = recvAccount.getClientID();


			//database gets client info 
			DBClient dbClientInfo;
			DBResponses responseVal = serverDBReader.getObjectInfo(id, dbClientInfo);

			//char firstName[EarnStructs::VARCHARLEN] = "servername";
			//char lastName[EarnStructs::VARCHARLEN] = "serverlastname";
			//char email[EarnStructs::VARCHARLEN] = "serveremail";
			//char phoneNumber[EarnStructs::VARCHARLEN] = "serverphone number";
			//char streetName[EarnStructs::VARCHARLEN] = "serverstreet name";
			//char city[EarnStructs::VARCHARLEN] = "servercity";
			//char province[EarnStructs::VARCHARLEN] = "serverprovince";
			//char zipcode[EarnStructs::ZIPLEN] = "pi123";
			//int accID = 999;

			int stringLen;
			CreateAccount serverAccount((char*)dbClientInfo.getFirstName().c_str(), (char*)dbClientInfo.getLastName().c_str(), (char*)dbClientInfo.getEmail().c_str(), (char*)dbClientInfo.getPhoneNum().c_str(), (char*)dbClientInfo.getStreet().c_str(), (char*)dbClientInfo.getCity().c_str(), (char*)dbClientInfo.getProvince().c_str(), (char*)dbClientInfo.getZip().c_str(), dbClientInfo.getObjectID());

			int viewAccountSize = sizeof(CreateAccount);
			Packet viewAccount(&serverAccount, viewAccountSize, 1, 0);
			if (DBSuccess == responseVal) {
				viewAccount.setStatus(1);
			}
			else {
				viewAccount.setStatus(0);
			}

			int viewAccountTotalSize = 0;

			char* viewAccountTxBuffer = viewAccount.serialize(viewAccountTotalSize);

			send(ConnectionSocket, viewAccountTxBuffer, viewAccountTotalSize, 0);

			break;
		}
		case TRANSACTION:		//Can be any of the transaction types
		{
			Transaction TransactionRecv(rxBuffer, 16);

			TransactionRecv.display();
			int currentTransaction = TransactionRecv.getTransactionType();
			//database stuff

			double difference = TransactionRecv.getNewBalance() - TransactionRecv.getPreviousBalance();

			DBAccount currentAccount;
			serverDBReader.getObjectInfo(TransactionRecv.getAccID(), currentAccount);

			DBTransaction newTransaction(TransactionRecv.getTransactionInfoStruct());

			currentAccount.setBalance(TransactionRecv.getNewBalance());

			if (ACCOUNTTRANSFER == (TransactionType)TransactionRecv.getTransactionType()) {
				DBAccount otherAccount;
				serverDBReader.getObjectInfo(TransactionRecv.getSecondaryAccount(), otherAccount);

				double previousBalance = otherAccount.getAccountBalance();
				double newBalance = previousBalance - difference;

				otherAccount.setBalance(newBalance);

				TransactionInfo otherTransactionInfo;
				otherTransactionInfo.accountID = otherAccount.getObjectID();
				otherTransactionInfo.newBalance = newBalance;
				otherTransactionInfo.previousBalance = previousBalance;
				otherTransactionInfo.secondaryAccount = currentAccount.getObjectID();
				strncpy(otherTransactionInfo.transactionTime, newTransaction.getTransactionTime().c_str(), VARCHARLEN);
				otherTransactionInfo.transactionType = ACCOUNTTRANSFER;

				DBTransaction otherTransaction(otherTransactionInfo);
				serverDBWriter.addObject(otherTransaction);
				serverDBWriter.modifyObjectInfo(otherAccount);
			}

			serverDBWriter.addObject(newTransaction);
			serverDBWriter.modifyObjectInfo(currentAccount);

			Packet clientPacket(4, 0);
			clientPacket.setStatus(1);

			int clientTotalSize = 0;
			char* clientTxBuffer = clientPacket.serialize(clientTotalSize);

			send(ConnectionSocket, clientTxBuffer, clientTotalSize, 0);

			EarnLogging::ConnectionLog sendLog(&clientPacket, SERVERSYSTEM, SEND, "sending response for view client");
			testLogger.logData(&sendLog);


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
			BFTSend.setTime();
			EarnLogging::ConnectionLog initialSendLog(&BFTSend, SERVERSYSTEM, SEND, "beginning large file transfer...");
			testLogger.logData(&initialSendLog);

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

			EarnLogging::ConnectionLog finalSendLog(&BFTSend, SERVERSYSTEM, SEND, "finished large file transfer");
			testLogger.logData(&finalSendLog);

			fclose(fp);


			//database stuff

			break;
		}
		//case STARTUPACCOUNTINFO:		
		//{
		//	//database stuff

		//	killSwitch = false;
		//	break;
		//}
		case FORGETPASSWORD:		//Validate email for reset password link
		{
			Login testLogin(rxBuffer, 12);

			testLogin.display();

			//database authenticates 


			Packet LoginSuccess(7, 0);
			LoginSuccess.setStatus(1);
			int totalSizeLogin = 0;
			char* txBufferLogin = LoginSuccess.serialize(totalSizeLogin);

			send(ConnectionSocket, txBufferLogin, totalSizeLogin, 0);

			EarnLogging::ConnectionLog sendLog(&LoginSuccess, SERVERSYSTEM, SEND, "sending response for forgotten password");
			testLogger.logData(&sendLog);

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

			EarnLogging::ConnectionLog sendLog(&clientPacket2, SERVERSYSTEM, SEND, "sending response for logoff");
			testLogger.logData(&sendLog);

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

			EarnLogging::ConnectionLog sendLog(&shutdownPacket, SERVERSYSTEM, SEND, "sending response for shutdown");
			testLogger.logData(&sendLog);

			killSwitch = false;
			break;
		}
		default:		//loopback
		{

			break;
		}
		}

	}

	std::cout << "\n\nShutting down server" << endl;

	closesocket(ConnectionSocket);	//closes incoming socket
	closesocket(ServerSocket);	    //closes server socket	
	WSACleanup();					//frees Winsock resources



}

//*/