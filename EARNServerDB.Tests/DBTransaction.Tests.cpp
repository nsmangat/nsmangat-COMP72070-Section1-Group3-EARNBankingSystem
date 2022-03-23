#include "pch.h"
#include "CppUnitTest.h"

//test headers
#include <DBObjects.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DBTransactionTests
{

	///DBO_SX_FY_TZ_input_output_expected
	///DBO = Object name, X = series, Y = function in series, Z = test for function
	///Naming Sequences so I can keep track of functions and hopefully speed up testing everything...?
		///will be done based on least -> most dependant (ie 0 = independant ... n = most dependant functions)
	
	/*
	*	DBTransaction tests
	*
	*	"0 series" = constructors, destructors,static functions
	*	DBTransaction_S000_F000_TZ	=	
	*
	*	"1XX series" = only calls 0 series, operators, copy constructors
	*	DBTransaction_S001_F000_TZ	=	
	*
	*	"2XX series" = calls levels 0 - 1
	*	DBTransaction_S002_F000_TZ	=	
	*/

	TEST_CLASS(DBTransaction_S000_F000_TZ)
	{
	public:

		TEST_METHOD(F000_input_output_expected)
		{
		}
	};

	TEST_CLASS(DBTransaction_S001_F000_TZ)
	{
	public:

		TEST_METHOD(F000_input_output_expected)
		{
		}
	};

	TEST_CLASS(DBTransaction_S002_F000_TZ)
	{
	public:

		TEST_METHOD(F000_input_output_expected)
		{
		}
	};
}
