#include <iostream>
#include "EARNStructs.h"

namespace EarnStructs {

	const std::string EnumToString(ObjectType inputType)
	{
		switch (inputType)
		{
		case OBJECTNULL:	return "OBJECTNULL";
		case CLIENT:		return "CLIENT";
		case CREDENTIALS:	return "CREDENTIALS";
		case ACCOUNT:		return "ACCOUNT";
		case TRANSACTION:	return "TRANSACTION";
		default:			return "[Unknown Type]";
		}
	}

	const std::string EnumToString(AccountType inputType)
	{
		switch (inputType)
		{
		case ACCOUNTNULL:	return "ACCOUNTNULL";
		case CHEQUINGS:		return "CHEQUINGS";
		case SAVINGS:		return "SAVINGS";
		default:			return "[Unknown Type]";
		}
	}

	const std::string EnumToString(TransactionType inputType)
	{
		switch (inputType)
		{
		case TRANSACTIONNULL:	return "TRANSACTIONNULL";
		case ETRANSFER:			return "ETRANSFER";
		case CHEQUE:			return "CHEQUE";
		case WITHDRAW:			return "WITHDRAW";
		case ACCOUNTTRANSFER:	return "ACCOUNTTRANSFER";
		default:				return "[Unknown Type]";
		}
	}
}