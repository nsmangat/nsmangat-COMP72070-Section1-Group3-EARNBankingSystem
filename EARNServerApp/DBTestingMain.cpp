///*
#include <iostream>
#include "DBObjects.h"
#include "DBDrivers.h"
#include "DBAccess.h"
#include <EARNLogger.h>
#include <EARNStructs.h>
#include <Packet.h>
#include <DataTypes.h>

int main(void) {
	///operates all use cases in order, comment out sections to speed things up

	//initalize / check if db exists
	//EarnDBDrivers::DBDriverInterface::initalizeDefaultDB();

	std::string testServer = "localhost";

	std::string testSchema = "EARNBankingDB";

	//setup reader
	std::string readerUser = "EARNDBReader";
	std::string readerPass =	"Gcugy6/fA{KR9H(r|:1Gp^qyd";
	EarnDBDrivers::DBReader testReader(testServer,testSchema,readerUser,readerPass);
	
	//setup validation
	std::string writerUser = "EARNDBWriter";
	std::string writerPass =	"|RI?BEe8drU0JoD~_j*|=fS@=";
	EarnDBDrivers::DBWriter testWriter(testServer, testSchema, writerUser, writerPass);

	//setup writer
	std::string validationUser = "EARNDBValidation";
	std::string validationPass =	"@:+fA,UFr[xn_[3>QwBuB#9qi";
	EarnDBDrivers::DBValidation testValidator(testServer, testSchema, validationUser, validationPass);


	//now add a client

	EarnStructs::ClientInfo testClientInfo;
	string testFN("Bob");
	strcpy_s(testClientInfo.firstName, EarnStructs::VARCHARLEN, testFN.c_str());

	char testLN[EarnStructs::VARCHARLEN] = "Smith";
	strcpy_s(testClientInfo.lastName, EarnStructs::VARCHARLEN, testLN);

	char testEM[EarnStructs::VARCHARLEN] = "BobSmith.email.bob";
	strcpy_s(testClientInfo.email, EarnStructs::VARCHARLEN, testEM);

	char testPN[EarnStructs::VARCHARLEN] = "123-456-7890";
	strcpy_s(testClientInfo.phoneNumber, EarnStructs::VARCHARLEN, testPN);

	char testST[EarnStructs::VARCHARLEN] = "Alphabet Street";
	strcpy_s(testClientInfo.street, EarnStructs::VARCHARLEN, testST);

	char testCT[EarnStructs::VARCHARLEN] = "Toronto";
	strcpy_s(testClientInfo.city, EarnStructs::VARCHARLEN, testCT);

	char testPR[EarnStructs::VARCHARLEN] = "Ontario";
	strcpy_s(testClientInfo.province, EarnStructs::VARCHARLEN, testPR);

	char testZP[EarnStructs::ZIPLEN] = "B0B1T3";
	strcpy_s(testClientInfo.zipcode, EarnStructs::ZIPLEN, testZP);

	EarnDBObjects::DBClient testClient(testClientInfo);

	//add to db so id it updated
	EarnDBDrivers::DBResponses responseVal = testWriter.addObject(testClient);
	std::cout << "Adding client to DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;
	
	//modify client
	testClient.setFirstName("Bobby");
	responseVal = testWriter.modifyObjectInfo(testClient);
	std::cout << "Modifying client in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	//now add credentials
	EarnStructs::CredentialInfo testCredentialInfo;

	testCredentialInfo.clientID = testClient.getObjectID();// testClient.getObjectID();
	testCredentialInfo.usernumber = 12345;

	char testUN[EarnStructs::VARCHARLEN] = "bobjoe123";
	strcpy_s(testCredentialInfo.username, EarnStructs::VARCHARLEN, testUN);

	char testUPH[EarnStructs::VARCHARLEN] = "kill3rPassw03rd!!!";
	strcpy_s(testCredentialInfo.userPasswordHash, EarnStructs::VARCHARLEN, testUPH);

	EarnDBObjects::DBCredential testCredential(testCredentialInfo);

	responseVal = testWriter.addObject(testCredential);
	std::cout << "Adding Credential to DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	//modify credential
	char newTestUN[EarnStructs::VARCHARLEN] = "BobJoe321";

	testCredential.setUsername(newTestUN);
	
	strcpy_s(testCredentialInfo.username, EarnStructs::VARCHARLEN, newTestUN);
	
	responseVal = testWriter.modifyObjectInfo(testCredential);
	std::cout << "Modifying credential in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	//test each login method
	EarnDBObjects::DBClient structClient;
	testValidator.clientLogin(testCredentialInfo, structClient);
	structClient.displayInfo();

	EarnDBObjects::DBClient usernameClient;
	testValidator.clientLogin(testCredentialInfo.username, testCredentialInfo.userPasswordHash, usernameClient);
	usernameClient.displayInfo();

	EarnDBObjects::DBClient usernumberClient;
	testValidator.clientLogin(testCredentialInfo.usernumber, testCredentialInfo.userPasswordHash, usernumberClient);
	usernumberClient.displayInfo();
	//now add account

	EarnStructs::AccountInfo testAccountInfo;

	testAccountInfo.clientID = testClient.getObjectID();
	testAccountInfo.accountBalance = 123.456;
	testAccountInfo.accountType = EarnStructs::SAVINGS;

	EarnDBObjects::DBAccount testAccount(testAccountInfo);

	responseVal = testWriter.addObject(testAccount);
	std::cout << "Adding account to DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	//now add transaction

	EarnStructs::TransactionInfo testTransactionInfo;
	std::string timeStamp = getCurrentTime(DateFormat::YMD_HMS);

	strcpy_s(testTransactionInfo.transactionTime, EarnStructs::VARCHARLEN, timeStamp.c_str());

	testTransactionInfo.accountID = testAccount.getObjectID();
	testTransactionInfo.previousBalance = testAccount.getAccountBalance();

	double newBalance = testAccount.getAccountBalance() + 1000;

	testTransactionInfo.newBalance = newBalance;
	testAccount.setBalance(newBalance);

	testTransactionInfo.transactionType = EarnStructs::TransactionType::CHEQUE;
	testTransactionInfo.secondaryAccount = NULL;

	EarnDBObjects::DBTransaction testTransaction(testTransactionInfo);

	responseVal = testWriter.modifyObjectInfo(testAccount);
	std::cout << "Modify account in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	responseVal = testWriter.addObject(testTransaction);
	std::cout << "Adding transaction to DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	testTransaction.setTransactionType(EarnStructs::ACCOUNTTRANSFER);
	testTransaction.setTransactionSecondaryAcc(1234);
	testWriter.modifyObjectInfo(testTransaction);
	std::cout << "Modifying transaction in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	//now test logging

	//credential packet logging
	Login testLoginData(testCredentialInfo.username,testCredentialInfo.userPasswordHash);
	Packet testLoginPacket(&testLoginData, sizeof(testLoginData),EarnStructs::CREDENTIALS, EarnStructs::SAVINGS);
	testLoginPacket.setTime();
	EarnLogging::ConnectionLog testLoginLog(&testLoginPacket, EarnLogging::SERVERSYSTEM, EarnLogging::RECEIVE, "test log for log into csv");

	EarnLogging::EARNLogger testLogger("testLog.csv");
	testLogger.logData(&testLoginLog);

	//client packet logging
	CreateAccount testCreateClient(testClientInfo.firstName, testClientInfo.lastName, testClientInfo.email, testClientInfo.phoneNumber, testClientInfo.street, testClientInfo.city, testClientInfo.province, testClientInfo.zipcode, 2);
	Packet testCreateClientPacket(&testCreateClient, sizeof(testCreateClient), EarnStructs::CLIENT, EarnStructs::SAVINGS);
	testCreateClientPacket.setTime();
	EarnLogging::ConnectionLog testCreateClientLog(&testCreateClientPacket, EarnLogging::SERVERSYSTEM, EarnLogging::RECEIVE, "test log for client into csv");

	testLogger.logData(&testCreateClientLog);

	//transaction packet logging
	Transaction testTransactionData(testTransactionInfo.accountID, testTransactionInfo.transactionType, testTransactionInfo.previousBalance, testTransactionInfo.newBalance, testTransactionInfo.secondaryAccount);
	Packet testTransactionPacket(&testTransactionData, sizeof(testTransactionData), EarnStructs::TRANSACTION, EarnStructs::SAVINGS);
	testTransactionPacket.setTime();
	EarnLogging::ConnectionLog testTransactionLog(&testTransactionPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "test log for transaction");
	testLogger.logData(&testTransactionLog);

	//account packet logging
	AccountInformation testAccountData(testAccount.getObjectID(), testAccount.getAccountClientID(), testAccount.getAccountType(), testAccount.getAccountBalance());
	Packet testAccountPacket(&testAccountData, sizeof(testAccountData), EarnStructs::ACCOUNT, EarnStructs::SAVINGS);
	testAccountPacket.setTime();
	EarnLogging::ConnectionLog testAccountLog(&testAccountPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "test log for account");
	testLogger.logData(&testAccountLog);

	EarnDBObjects::DBClient testGetClient;
	
	responseVal = testReader.getObjectInfo(testClient.getObjectID(), testGetClient);
	std::cout << "getting client from DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	if (0 != strcmp(testGetClient.getFirstName().c_str(), testClient.getFirstName().c_str())) {
		std::cerr << "returned client is not the same" << std::endl;
	}

	EarnDBObjects::DBAccount testGetAccount;

	responseVal = testReader.getObjectInfo(testAccount.getObjectID(), testGetAccount);
	std::cout << "getting account from DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	if (testGetAccount.getAccountBalance() != testAccount.getAccountBalance()) {
		std::cerr << "returned account is not the same" << std::endl;
	}

	EarnDBObjects::DBTransaction testGetTransaction;

	responseVal = testReader.getObjectInfo(testTransaction.getObjectID(), testGetTransaction);
	std::cout << "getting transaction from DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	if (testGetTransaction.getTransactionPreviousBal() != testTransaction.getTransactionPreviousBal()) {
		std::cerr << "returned transaction is not the same" << std::endl;
	}

	//now test all deletes so I don't fill db while testing

	responseVal = testWriter.deleteObject(testClient);
	std::cout << "Deleting client in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	responseVal = testWriter.deleteObject(testCredential);
	std::cout << "Deleting credential in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	responseVal = testWriter.deleteObject(testAccount);
	std::cout << "Deleting account in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	responseVal = testWriter.deleteObject(testTransaction);
	std::cout << "Deleting transaction in DB returned: " << EarnDBDrivers::EnumToString(responseVal) << std::endl;

	return 0;
}

//*/