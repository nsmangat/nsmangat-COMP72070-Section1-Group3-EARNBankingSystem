#pragma once

#include "../EARNNetworkAPI/DataTypes.h"
#include <iostream>


void menuOne();
void menuTwo();
void menuThree(int choice);


//MenuOne
Login inputLoginInfo();
CreateAccount inputAccountInfo();
Login inputForgotPassword();

//MenuThree
Transaction sendEtransfer(AccountInformation acc);
Transaction RecvEtransfer(AccountInformation acc);
Transaction sendBetweenAccounts(AccountInformation current, AccountInformation other);
Transaction depositCheque(AccountInformation acc);