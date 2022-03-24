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

	EarnStructs::ClientInfo testClientInfo = { 0 };
	char testFN[] = "Bob";
	memcpy_s(testClientInfo.firstName, EarnStructs::VARCHARLEN, testFN, sizeof(testFN));

	char testLN[] = "Smith";
	memcpy_s(testClientInfo.lastName, EarnStructs::VARCHARLEN, testLN, sizeof(testLN));

	char testEM[] = "BobSmith@email.bob";
	memcpy_s(testClientInfo.email, EarnStructs::VARCHARLEN, , testEM, sizeof(testEM));

	char testPN[] = "123-456-7890";
	memcpy_s(testClientInfo.phoneNumber, EarnStructs::VARCHARLEN, testPN, sizeof(testPN));

	char testST[] = "Alphabet Street";
	memcpy_s(testClientInfo.street, EarnStructs::VARCHARLEN, testST, sizeof(testST));

	char testCT[] = "Toronto";
	memcpy_s(testClientInfo.city, EarnStructs::VARCHARLEN, testCT, sizeof(testCT));

	char testPN[] = "Ontario";
	memcpy_s(testClientInfo.province, EarnStructs::VARCHARLEN, testPN, sizeof(testPN));


	memcpy_s(testClientInfo.zipcode, EarnStructs::VARCHARLEN, "B0B 1T3", EarnStructs::ZIPLEN);

	EarnDBObjects::DBClient tesFtClient(testClientInfo);

	EarnStructs::AccountInfo testAccountInfo = { 0 };

	testAccountInfo.clientID = testClient.getObjectID();
	testAccountInfo.accountBalance = 123.456;
	testAccountInfo.accountType = EarnStructs::SAVINGS;

	EarnDBObjects::DBAccount testAccount(testAccountInfo);

	EarnStructs::TransactionInfo testTransactionInfo = { 0 };
	std::string timeStamp = EarnLogging::EARNLogger::getCurrentTime(EarnLogging::DateFormat::YMD_HMS);
	memcpy(testTransactionInfo.transactionTime, timeStamp.c_str(), EarnStructs::VARCHARLEN);

	testTransactionInfo.accountID = testAccount.getObjectID();
	testTransactionInfo.previousBalance = testAccount.getAccountBalance();

	double newBalance = testAccount.getAccountBalance() + 1000;

	testTransactionInfo.newBalance = newBalance;
	testAccount.setBalance(newBalance);

	testTransactionInfo.transactionType = EarnStructs::TransactionType::CHEQUE;
	testTransactionInfo.secondaryAccount = NULL;

	return 0;
}

//*/