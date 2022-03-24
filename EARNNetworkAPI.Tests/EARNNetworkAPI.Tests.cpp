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
		
		TEST_METHOD(T001_CreateAccountParameterConstructor_CreateAccountDetails_CreateAccountWithInput)
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
	};
}
