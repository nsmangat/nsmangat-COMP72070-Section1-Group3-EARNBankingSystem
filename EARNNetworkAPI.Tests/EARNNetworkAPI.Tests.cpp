#include "pch.h"
#include "CppUnitTest.h"
#include "../EARNNetworkAPI/DataTypes.h"
#include "../EARNNetworkAPI/EARNStructs.h"
#include "../EARNNetworkAPI/Packet.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EARNNetworkAPITests
{
	TEST_CLASS(EARNNetworkAPITests)
	{
	public:
		
		TEST_METHOD(T001_CreateAccountParameterConstructor_CreateAccountDetails_CreateAccountWithInput)						//Client test CreateUser-001
		{
			char firstName[EarnStructs::VARCHARLEN] = "testname";
			char lastName[EarnStructs::VARCHARLEN] = "testlastname";
			char email[EarnStructs::VARCHARLEN] = "testemail";
			char phoneNumber[EarnStructs::VARCHARLEN] = "testphone number";
			char streetName[EarnStructs::VARCHARLEN] = "teststreet name";
			char city[EarnStructs::VARCHARLEN] = "testcity";
			char province[EarnStructs::VARCHARLEN] = "testprovince";
			char zipcode[EarnStructs::ZIPLEN] = "pi123";
			int accID = 999;
			

			CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);

			Assert::AreEqual(testAccount.getFirstName(), firstName);
			Assert::AreEqual(testAccount.getLastName(), lastName);
			Assert::AreEqual(testAccount.getEmail(), email);
			Assert::AreEqual(testAccount.getPhoneNumber(), phoneNumber);
			Assert::AreEqual(testAccount.getStreetName(), streetName);
			Assert::AreEqual(testAccount.getCity(), city);
			Assert::AreEqual(testAccount.getProvince(), province);
			Assert::AreEqual(testAccount.getZipcode(), zipcode);
			Assert::AreEqual(testAccount.getAccountID(), accID);
			
		}

		TEST_METHOD(T002_CreateAccountUsingBuffer_CreateAccountDetailsSerialized_CreateAccountObject)						//Client test CreateUser-002
		{
			char firstName[EarnStructs::VARCHARLEN] = "testname";
			char lastName[EarnStructs::VARCHARLEN] = "testlastname";
			char email[EarnStructs::VARCHARLEN] = "testemail";
			char phoneNumber[EarnStructs::VARCHARLEN] = "testphone number";
			char streetName[EarnStructs::VARCHARLEN] = "teststreet name";
			char city[EarnStructs::VARCHARLEN] = "testcity";
			char province[EarnStructs::VARCHARLEN] = "testprovince";
			char zipcode[EarnStructs::ZIPLEN] = "pi123";
			int accID = 999;

			CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);

			int size = sizeof(testAccount);
			Packet testPacket(&testAccount, size, 5, 0);

			int sendSize = 0;
	 
			char* txBuffer = testPacket.serialize(sendSize);

			CreateAccount testCreateAccountBuffer(txBuffer);
			

			Assert::AreEqual(testCreateAccountBuffer.getFirstName(), firstName);
			Assert::AreEqual(testCreateAccountBuffer.getLastName(), lastName);
			Assert::AreEqual(testCreateAccountBuffer.getEmail(), email);
			Assert::AreEqual(testCreateAccountBuffer.getPhoneNumber(), phoneNumber);
			Assert::AreEqual(testCreateAccountBuffer.getStreetName(), streetName);
			Assert::AreEqual(testCreateAccountBuffer.getCity(), city);
			Assert::AreEqual(testCreateAccountBuffer.getProvince(), province);
			Assert::AreEqual(testCreateAccountBuffer.getZipcode(), zipcode);
			Assert::AreEqual(testCreateAccountBuffer.getAccountID(), accID);

			
		}

		TEST_METHOD(T003_CreateAccount_CreateAccountObject_ClientInfoStruct)						//Client test CreateUser-002
		{
			char firstName[EarnStructs::VARCHARLEN] = "testname";
			char lastName[EarnStructs::VARCHARLEN] = "testlastname";
			char email[EarnStructs::VARCHARLEN] = "testemail";
			char phoneNumber[EarnStructs::VARCHARLEN] = "testphone number";
			char streetName[EarnStructs::VARCHARLEN] = "teststreet name";
			char city[EarnStructs::VARCHARLEN] = "testcity";
			char province[EarnStructs::VARCHARLEN] = "testprovince";
			char zipcode[EarnStructs::ZIPLEN] = "pi123";
			int accID = 999;

			CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);
			ClientInfo testClientInfo;
			
			testClientInfo = testAccount.getClientInfoStruct();


			Assert::AreEqual(testAccount.getFirstName(), testClientInfo.firstName);
			Assert::AreEqual(testAccount.getLastName(), testClientInfo.lastName);
			Assert::AreEqual(testAccount.getEmail(), testClientInfo.email);
			Assert::AreEqual(testAccount.getPhoneNumber(), testClientInfo.phoneNumber);
			Assert::AreEqual(testAccount.getStreetName(), testClientInfo.street);
			Assert::AreEqual(testAccount.getCity(), testClientInfo.city);
			Assert::AreEqual(testAccount.getProvince(), testClientInfo.province);
			Assert::AreEqual(testAccount.getZipcode(), testClientInfo.zipcode);
			//Assert::AreEqual(testCreateAccountBuffer.getAccountID(), testClientInfo.accID);
			

			
		}




	};

	TEST_CLASS(LoginTests)
	{
	public:

		TEST_METHOD(T001_CreateLoginObjUserNamePassword_Username_Password_SameAsInput)						//Client test CreateUser-001
		{
			char username[EarnStructs::VARCHARLEN] = "username";
			char password[EarnStructs::VARCHARLEN] = "password";

			Login testLogin(username, password);

			Assert::AreEqual(username, testLogin.getUserName());
			Assert::AreEqual(password, testLogin.getPassword());

		}
		TEST_METHOD(T002_CreateLoginObjBuffer_Buffer_UsernamePassword)						//Client test CreateUser-001
		{
			char username[EarnStructs::VARCHARLEN] = "username";
			char password[EarnStructs::VARCHARLEN] = "password";

			Login testLogin(username, password);
			
			Packet testPacket(&testLogin, sizeof(Login), 2, 0);
			int size = 0;
			char* txBuffer = testPacket.serialize(size);

			Login testLoginBuffer(txBuffer);
			

			Assert::AreEqual(username, testLoginBuffer.getUserName());
			Assert::AreEqual(password, testLoginBuffer.getPassword());
		}

		TEST_METHOD(T003_GetCredentialInfoStruct_Values_SameAsInput)						//Client test CreateUser-001
		{
			char username[EarnStructs::VARCHARLEN] = "username";
			char password[EarnStructs::VARCHARLEN] = "password";

			Login testLogin(username, password);
			CredentialInfo testStruct;
			testStruct = testLogin.getLoginStruct();


			Assert::AreEqual(testStruct.username, testLogin.getUserName());
			Assert::AreEqual(testStruct.userPasswordHash, testLogin.getPassword());
			

		}

	};

	TEST_CLASS(TransactionTests)
	{
	public:

		TEST_METHOD(T001_CreateTransactionObjDefault_Empty)						//Client test CreateUser-001
		{
		
			Transaction testTransaction;

			Assert::AreEqual(0, testTransaction.getAccID());
			Assert::AreEqual(0, testTransaction.getTransactionType());
			Assert::AreEqual(0, testTransaction.getPreviousBalance(), 0.1);
			Assert::AreEqual(0, testTransaction.getNewBalance(), 0.1);
			Assert::AreEqual(0, testTransaction.getSecondaryAccount());

		}

		TEST_METHOD(T002_CreateTransactionObjParameterized_Values_SameAsInput)						//Client test CreateUser-001
		{
			int accId = 123;
			TransactionType type = ETRANSFER;
			double pBalance = 2.99;
			double nBalance = 5.99;
			int secAcc = 456;

			Transaction testTransaction(accId, type, pBalance, nBalance, secAcc);

			Assert::AreEqual(accId, testTransaction.getAccID());
			Assert::AreEqual(1, testTransaction.getTransactionType());
			Assert::AreEqual(pBalance, testTransaction.getPreviousBalance());
			Assert::AreEqual(nBalance, testTransaction.getNewBalance());
			Assert::AreEqual(secAcc, testTransaction.getSecondaryAccount());

		}

		TEST_METHOD(T003_CreateTransactionObjBuffer_Buffer_UsernamePassword)						//Client test CreateUser-001
		{
			int accId = 123;
			TransactionType type = ETRANSFER;
			double pBalance = 2.99;
			double nBalance = 5.99;
			int secAcc = 456;

			Transaction testTransaction(accId, type, pBalance, nBalance, secAcc);
			
			Packet testPacket(&testTransaction, sizeof(Transaction), 4, 0);
			int size = 0;
			char* txBuffer = testPacket.serialize(size);

			Transaction testTransactionBuffer(txBuffer);

			Assert::AreEqual(accId, testTransactionBuffer.getAccID());
			Assert::AreEqual(1, testTransactionBuffer.getTransactionType());
			Assert::AreEqual(pBalance, testTransactionBuffer.getPreviousBalance());
			Assert::AreEqual(nBalance, testTransactionBuffer.getNewBalance());
			Assert::AreEqual(secAcc, testTransactionBuffer.getSecondaryAccount());


		}

		TEST_METHOD(T004_GetTransactionInfoStruct_Values_SameAsInput)						//Client test CreateUser-001
		{
			int accId = 123;
			TransactionType type = ETRANSFER;
			double pBalance = 2.99;
			double nBalance = 5.99;
			int secAcc = 456;

			Transaction testTransaction(accId, type, pBalance, nBalance, secAcc);
			TransactionInfo testStruct;
			testStruct = testTransaction.getTransactionInfoStruct();
			

			Assert::AreEqual(testStruct.accountID, testTransaction.getAccID());
			Assert::AreEqual(testStruct.transactionType, testTransaction.getTransactionType(), 0.1);
			Assert::AreEqual(testStruct.previousBalance, testTransaction.getPreviousBalance(), 0.1);
			Assert::AreEqual(testStruct.newBalance, testTransaction.getNewBalance(), 0.1);
			Assert::AreEqual(testStruct.secondaryAccount, testTransaction.getSecondaryAccount());

		}
	
	};

	TEST_CLASS(AccountInfoTests)
	{
	public:

		TEST_METHOD(T001_AccountInfoObjDefault_Empty)						//Client test CreateUser-001
		{

			AccountInformation testAccount;

			Assert::AreEqual(0, testAccount.getClientID());
			Assert::AreEqual(0, testAccount.getAccountType());
			Assert::AreEqual(0, testAccount.getAccountBalance(), 0.1);

		}

		TEST_METHOD(T002_CreateAccountInfoObjParameterized_Values_SameAsInput)						//Client test CreateUser-001
		{
			int clientId = 123;
			AccountType type = ACCOUNTNULL;
			double Balance = 200.99;			

			AccountInformation testAccount(clientId, type, Balance);

			Assert::AreEqual(clientId, testAccount.getClientID());
			Assert::AreEqual(0, testAccount.getAccountType());
			Assert::AreEqual(Balance, testAccount.getAccountBalance(), 0.1);			

		}

		TEST_METHOD(T003_CreateAccountInfoObjBuffer_Buffer_UsernamePassword)						//Client test CreateUser-001
		{
			int clientId = 123;
			AccountType type = ACCOUNTNULL;
			double Balance = 200.99;

			AccountInformation testAccount(clientId, type, Balance);

			Packet testPacket(&testAccount, sizeof(AccountInformation), 4, 0);
			int size = 0;
			char* txBuffer = testPacket.serialize(size);

			AccountInformation testAccount2(txBuffer);

			Assert::AreEqual(testAccount.getClientID(), testAccount2.getClientID());
			Assert::AreEqual(testAccount.getAccountType(), testAccount2.getAccountType());
			Assert::AreEqual(testAccount.getAccountBalance(), testAccount2.getAccountBalance(), 0.1);

		}

		TEST_METHOD(T004_GetAccountInfoStruct_Values_SameAsInput)						//Client test CreateUser-001
		{
			int clientId = 123;
			AccountType type = ACCOUNTNULL;
			double Balance = 200.99;

			AccountInformation testAccount(clientId, type, Balance);
			AccountInfo testStruct;
			testStruct = testAccount.getAccountInfoStruct();


			Assert::AreEqual(testStruct.clientID, testAccount.getClientID());
			Assert::AreEqual(testStruct.accountType, testAccount.getAccountType(), 0.1);
			Assert::AreEqual(testStruct.accountBalance, testAccount.getAccountBalance(), 0.1);
			

		}

	};



	TEST_CLASS(PacketTests)
	{
	public:

		TEST_METHOD(T001_PacketConstructor_LoginObject_LoginTypePacket)											//client Packet-001
		{
			char username[EarnStructs::VARCHARLEN] = "username";
			char password[EarnStructs::VARCHARLEN] = "password";

			Login testLogin(username, password);
			
			Packet testPacket(&testLogin, sizeof(Login), 2, 0);
			int size = sizeof(Login);

			Assert::AreEqual(size, testPacket.getDataSize());
			Assert::AreEqual(2, testPacket.getObjectType());
			Assert::AreEqual(0, testPacket.getAccountType());
		}

		TEST_METHOD(T002_PacketConstructorNoData_ZeroAndZero_PacketNoData)						//Client test Packet-002
		{
			Packet testPacket(5, 0);
			Assert::AreEqual(0, testPacket.getDataSize());
		}

		TEST_METHOD(T003_CreateTransactionObjBuffer_Buffer_UsernamePassword)					//Client test Packet-004
		{
			char username[EarnStructs::VARCHARLEN] = "username";
			char password[EarnStructs::VARCHARLEN] = "password";

			Login testLogin(username, password);
			
			Packet testPacket(&testLogin, sizeof(Login), 2, 0);
			int size = 0;
			char* txBuffer = testPacket.serialize(size);

			Login testLoginBuffer(txBuffer);
			

			Assert::AreEqual(username, testLoginBuffer.getUserName());
			Assert::AreEqual(password, testLoginBuffer.getPassword());
		}

		TEST_METHOD(T004_CreatePacketObjBuffer_Buffer_zeroAndFour)						//Client test CreateUser-001
		{
			int clientId = 123;
			AccountType type = ACCOUNTNULL;
			double Balance = 200.99;

			AccountInformation testAccount(clientId, type, Balance);

			Packet testPacket(&testAccount, sizeof(AccountInformation), 4, 0);
			int size = 0;
			char* txBuffer = testPacket.serialize(size);

			Packet testPacket2(txBuffer);

			
			Assert::AreEqual(0, testPacket2.getDataSize());
			Assert::AreEqual(4, testPacket2.getObjectType());

		}

		TEST_METHOD(T005_PacketConstructorTwoDatatypes_NewAccountAndLoginDetails_CreateAccountPacket)					//client test createaccount-006
		{
			char firstName[EarnStructs::VARCHARLEN] = "firstname";
			char lastName[EarnStructs::VARCHARLEN] = "lastname";
			char username[EarnStructs::VARCHARLEN] = "username";
			char password[EarnStructs::VARCHARLEN] = "password";
			char email[EarnStructs::VARCHARLEN] = "email";
			char phoneNumber[EarnStructs::VARCHARLEN] = "phone number";
			char streetName[EarnStructs::VARCHARLEN] = "street name";
			char city[EarnStructs::VARCHARLEN] = "city";
			char province[EarnStructs::VARCHARLEN] = "province";
			char zipcode[EarnStructs::ZIPLEN] = "12345";
			int accID = 234;

			CreateAccount testAccount(firstName, lastName, email, phoneNumber, streetName, city, province, zipcode, accID);
			Login testLogin(username, password);

			int size1 = sizeof(testAccount);
			int size2 = sizeof(testLogin);
			Packet testPacket(&testAccount, size1, &testLogin, size2, 5);

			int sendSize = 0;
	 
			char* txBuffer = testPacket.serialize(sendSize);
			char rxBuffer[1000] = {};

			char rxBuffer1[1000] = {};
			char rxBuffer2[1000] = {};

			//memcpy header to find operationtype

			memcpy(rxBuffer, txBuffer, sendSize);

			memcpy(rxBuffer1, rxBuffer, size1 + HeadSize);

			memcpy(rxBuffer2, rxBuffer, HeadSize);
			memcpy(rxBuffer2 + HeadSize, rxBuffer + HeadSize + size1, size2);
			CreateAccount testAccountReceive(rxBuffer1);
			Login testLoginRecv(rxBuffer2);

			Assert::AreEqual(testAccountReceive.getFirstName(), firstName);
			Assert::AreEqual(testAccountReceive.getLastName(), lastName);
			Assert::AreEqual(testAccountReceive.getEmail(), email);
			Assert::AreEqual(testAccountReceive.getPhoneNumber(), phoneNumber);
			Assert::AreEqual(testAccountReceive.getStreetName(), streetName);
			Assert::AreEqual(testAccountReceive.getCity(), city);
			Assert::AreEqual(testAccountReceive.getProvince(), province);
			Assert::AreEqual(testAccountReceive.getZipcode(), zipcode);

			Assert::AreEqual(testLoginRecv.getUserName(), username);
			Assert::AreEqual(testLoginRecv.getPassword(), password);

		}
	

	};


}
