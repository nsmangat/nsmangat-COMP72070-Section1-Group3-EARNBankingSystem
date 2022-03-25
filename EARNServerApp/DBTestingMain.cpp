///*
#include <iostream>
#include "DBObjects.h"
#include "DBDrivers.h"
#include "DBAccess.h"
#include <EARNLogger.h>
#include <EARNStructs.h>

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


	////now add a client

	//EarnStructs::ClientInfo testClientInfo;
	//string testFN("Bob");
	//strcpy_s(testClientInfo.firstName, EarnStructs::VARCHARLEN, testFN.c_str());

	//char testLN[EarnStructs::VARCHARLEN] = "Smith";
	//strcpy_s(testClientInfo.lastName, EarnStructs::VARCHARLEN, testLN);

	//char testEM[EarnStructs::VARCHARLEN] = "BobSmith.email.bob";
	//strcpy_s(testClientInfo.email, EarnStructs::VARCHARLEN, testEM);

	//char testPN[EarnStructs::VARCHARLEN] = "123-456-7890";
	//strcpy_s(testClientInfo.phoneNumber, EarnStructs::VARCHARLEN, testPN);

	//char testST[EarnStructs::VARCHARLEN] = "Alphabet Street";
	//strcpy_s(testClientInfo.street, EarnStructs::VARCHARLEN, testST);

	//char testCT[EarnStructs::VARCHARLEN] = "Toronto";
	//strcpy_s(testClientInfo.city, EarnStructs::VARCHARLEN, testCT);

	//char testPR[EarnStructs::VARCHARLEN] = "Ontario";
	//strcpy_s(testClientInfo.province, EarnStructs::VARCHARLEN, testPR);

	//char testZP[EarnStructs::VARCHARLEN] = "B0B1T3";
	//strcpy_s(testClientInfo.zipcode, EarnStructs::VARCHARLEN, testZP);

	//EarnDBObjects::DBClient testClient(testClientInfo);

	//add to db so id it updated
	//testWriter.addObject(testClient);

	//now add credentials
	EarnStructs::CredentialInfo testCredentialInfo;

	testCredentialInfo.clientID = 1;// testClient.getObjectID();
	testCredentialInfo.usernumber = 12345;

	char testUN[EarnStructs::VARCHARLEN] = "bobjoe123";
	strcpy_s(testCredentialInfo.username, EarnStructs::VARCHARLEN, testUN);

	char testUPH[EarnStructs::VARCHARLEN] = "kill3rPassw03rd!!!";
	strcpy_s(testCredentialInfo.userPasswordHash, EarnStructs::VARCHARLEN, testUPH);

	EarnDBObjects::DBCredential testCredential(testCredentialInfo);

	//testWriter.addObject(testCredential);

	EarnDBObjects::DBClient loggedInClient = testValidator.clientLogin(testCredentialInfo);
	//now add account

	EarnStructs::AccountInfo testAccountInfo;

	testAccountInfo.clientID = 1;// testClient.getObjectID();
	testAccountInfo.accountBalance = 123.456;
	testAccountInfo.accountType = EarnStructs::SAVINGS;

	EarnDBObjects::DBAccount testAccount(testAccountInfo);

	testWriter.addObject(testAccount);

	//now add transaction

	EarnStructs::TransactionInfo testTransactionInfo;
	std::string timeStamp = EarnLogging::EARNLogger::getCurrentTime(EarnLogging::DateFormat::YMD_HMS);

	strcpy_s(testTransactionInfo.transactionTime, EarnStructs::VARCHARLEN, timeStamp.c_str());

	testTransactionInfo.accountID = testAccount.getObjectID();
	testTransactionInfo.previousBalance = testAccount.getAccountBalance();

	double newBalance = testAccount.getAccountBalance() + 1000;

	testTransactionInfo.newBalance = newBalance;
	testAccount.setBalance(newBalance);

	testTransactionInfo.transactionType = EarnStructs::TransactionType::CHEQUE;
	testTransactionInfo.secondaryAccount = NULL;

	EarnDBObjects::DBTransaction testTransaction(testTransactionInfo);

	testWriter.modifyObjectInfo(testAccount);

	testWriter.addObject(testTransaction);

	return 0;
}

//*/