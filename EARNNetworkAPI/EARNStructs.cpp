#include <iostream>
#include "EARNStructs.h"

namespace EarnStructs {
	//OBJECTNULL, CLIENT, CREDENTIALS, ACCOUNT, TRANSACTION, CREATEACCOUNT, STARTUPACCOUNTINFO, FORGETPASSWORD, LOGOFF, BIGFILETRANSFER, SHUTDOWN
	const std::string EnumToString(ObjectType inputType)
	{
		switch (inputType)
		{
		case OBJECTNULL:			return "OBJECTNULL";
		case CLIENT:				return "CLIENT";
		case CREDENTIALS:			return "CREDENTIALS";
		case ACCOUNT:				return "ACCOUNT";
		case TRANSACTION:			return "TRANSACTION";
		case CREATEACCOUNT:			return "CREATEACCOUNT";
		case STARTUPACCOUNTINFO:	return "STARTUPACCOUNTINFO";
		case FORGETPASSWORD:		return "FORGETPASSWORD";
		case LOGOFF:				return "LOGOFF";
		case BIGFILETRANSFER:		return "BIGFILETRANSFER";
		case SHUTDOWN:				return "SHUTDOWN";
		default:					return "[Unknown Type]";
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
		default:				return "[Unknown Type]";
		}
	}
}