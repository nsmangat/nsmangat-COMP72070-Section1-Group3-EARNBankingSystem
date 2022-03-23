#include "pch.h"
#include "CppUnitTest.h"

//test headers
#include <DBObjects.h>
#include <EARNStructs.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DBClientTests
{

	///DBO_SX_FY_TZ_input_output_expected
	///DBO = Object name, X = series, Y = function in series, Z = test for function
	///Naming Sequences so I can keep track of functions and hopefully speed up testing everything...?
		///will be done based on least -> most dependant (ie 0 = independant ... n = most dependant functions)
	
	/*
	*	DBClient tests
	* 
	*	"000 series" = constructors, destructors,static functions
	*		DBClient_S000_F000_TZ	=	DBClient();
	*		DBClient_S000_F001_TZ	=	DBClient(const EarnStructs::ClientInfo copyInfo);
	*		DBClient_S000_F002_TZ	=	DBClient(int inputObjectID, const char* inputFirst, const char* inputLast, const char* inputEmail, const char* inputPhone, const char* inputStreet, const char* inputCity, const char* inputProvince, const char* inputZip);
	* 
	*	"001 series" = only calls 0 series, operators, copy constructors
	*		DBClient_S001_F000_TZ	=	DBClient(const DBClient& copyClient);
	* 
	*		"0011 series" = get functions
	*			DBClient_S0011_F000_TZ	=	const char* getFirstName(int& lenOfArray);
	*			DBClient_S0011_F001_TZ	=	std::string getFirstName();
	* 
	*			DBClient_S0011_F002_TZ	=	const char* getLastName(int& lenOfArray);
	*			DBClient_S0011_F003_TZ	=	std::string getLastName();
	* 
	*			DBClient_S0011_F004_TZ	=	const char* getEmail(int& lenOfArray);
	*			DBClient_S0011_F005_TZ	=	std::string getEmail();
	* 
	*			DBClient_S0011_F006_TZ	=	const char* getPhoneNum(int& lenOfArray);
	*			DBClient_S0011_F007_TZ	=	std::string getPhoneNum();
	* 
	*			DBClient_S0011_F008_TZ	=	const char* getStreet(int& lenOfArray);
	*			DBClient_S0011_F009_TZ	=	std::string getStreet();
	* 
	*			DBClient_S0011_F010_TZ	=	const char* getCity(int& lenOfArray);
	*			DBClient_S0011_F011_TZ	=	std::string getCity();
	* 
	*			DBClient_S0011_F012_TZ	=	const char* getProvince(int& lenOfArray);
	*			DBClient_S0011_F013_TZ	=	std::string getProvince();
	* 
	*			DBClient_S0011_F014_TZ	=	const char* getZip(int& lenOfArray);
	*			DBClient_S0011_F015_TZ	=	std::string getZip();
	* 
	*			DBClient_S0011_F016_TZ	=	EarnStructs::ClientInfo getClientInfo();
	* 
	*		"0012 series = set functions
	*			DBClient_S0012_F000_TZ	=	void setFirstName(const char* newFirst);
	*			DBClient_S0012_F001_TZ	=	void setFirstName(std::string newFirst);
	* 
	*			DBClient_S0012_F002_TZ	=	void setLastName(const char* newLast);
	*			DBClient_S0012_F003_TZ	=	void setLastName(std::string newLast);
	* 
	*			DBClient_S0012_F004_TZ	=	void setEmail(const char* newEmail);
	*			DBClient_S0012_F005_TZ	=	void setEmail(std::string newEmail);
	* 
	*			DBClient_S0012_F006_TZ	=	void setPhoneNum(const char* newPhone);
	*			DBClient_S0012_F007_TZ	=	void setPhoneNum(std::string newPhone);
	* 
	*			DBClient_S0012_F008_TZ	=	void setStreet(const char* newStreet);
	*			DBClient_S0012_F009_TZ	=	void setStreet(std::string newStreet);
	* 
	*			DBClient_S0012_F010_TZ	=	void setCity(const char* newCity);
	*			DBClient_S0012_F011_TZ	=	void setCity(std::string newCity);
	* 
	*			DBClient_S0012_F012_TZ	=	void setProvince(const char* newProvince);
	*			DBClient_S0012_F013_TZ	=	void setProvince(std::string newProvince);
	* 
	*			DBClient_S0012_F014_TZ	=	void setZip(const char* newZip);
	*			DBClient_S0012_F015_TZ	=	void setZip(std::string newZip);
	* 
	*	"002 series" = calls levels 0 - 1
	*		DBClient_S002_F000_TZ	=	std::string displayInfo();
	* 
	*		//Not implemented so skip
	*		DBClient_S002_F001_TZ	=	//std::string getLogData();
	* 
	*		DBClient_S002_F002_TZ	=	std::string getInfoFromDB();
	*		DBClient_S002_F003_TZ	=	std::string addInfoToDB();
	*		DBClient_S002_F004_TZ	=	std::string modifyInfoInDB();
	*		DBClient_S002_F005_TZ	=	std::string deleteInfoInDB();
	*		DBClient_S002_F006_TZ	=	std::string checkObjectExists();
	*/

	TEST_CLASS(DBClient_S000_F000_TZ)
	{
	public:

		TEST_METHOD(F000_constructorWNoVal_emptyClient_isClient)
		{
			//	Arrange & Act
			EarnDBObjects::DBClient testClient();

			//	Assert

			Assert::IsTrue(typeid(EarnDBObjects::DBClient()) == typeid(testClient));
		}
	};

	TEST_CLASS(DBClient_S000_F001_TZ)
	{
	public:

		TEST_METHOD(F001_constructorWStruct_fullClient_isClientWVals)
		{
			//	Arrange
			EarnStructs::ClientInfo testClientInfo = {};
			
			//allocate some dummy data
			memcpy(testClientInfo.firstName, "Bob", EarnStructs::VARCHARLEN);
			memcpy(testClientInfo.lastName, "Smith", EarnStructs::VARCHARLEN);
			memcpy(testClientInfo.email, "BobSmith@email.bob", EarnStructs::VARCHARLEN);
			memcpy(testClientInfo.phoneNumber, "123-456-7890", EarnStructs::VARCHARLEN);
			memcpy(testClientInfo.street, "Alphabet Street", EarnStructs::VARCHARLEN);
			memcpy(testClientInfo.city, "Toronto", EarnStructs::VARCHARLEN);
			memcpy(testClientInfo.province, "Ontario", EarnStructs::VARCHARLEN);
			memcpy(testClientInfo.zipcode, "B0B 1T3", EarnStructs::VARCHARLEN);

			//	Act
			EarnDBObjects::DBClient testClient(testClientInfo);

			EarnStructs::ClientInfo receivedClientInfo = testClient.getClientInfo();

			bool checkValSame = true;

			if (testClientInfo.firstName != receivedClientInfo.firstName) { checkValSame = false; }
			if (testClientInfo.lastName != receivedClientInfo.lastName) { checkValSame = false; }
			if (testClientInfo.email != receivedClientInfo.email) { checkValSame = false; }
			if (testClientInfo.phoneNumber != receivedClientInfo.phoneNumber) { checkValSame = false; }
			if (testClientInfo.street != receivedClientInfo.street) { checkValSame = false; }
			if (testClientInfo.city != receivedClientInfo.city) { checkValSame = false; }
			if (testClientInfo.province != receivedClientInfo.province) { checkValSame = false; }
			if (testClientInfo.zipcode != receivedClientInfo.zipcode) { checkValSame = false; }

			//	Assert
			Assert::IsTrue(checkValSame);
		}
	};

	TEST_CLASS(DBClient_S002_F000_TZ)
	{
	public:

		TEST_METHOD(F000_input_output_expected)
		{
		}
	};
}
