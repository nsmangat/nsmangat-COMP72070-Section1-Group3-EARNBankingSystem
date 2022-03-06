#pragma once
#include <string>
#include "DBAccess.h"

#define VARCHAR_LENGTH 45;
#define ZIP_LENGTH 6;

using namespace std;

class DBObject :DBAccessObject {
	DBOType objectType;
public:
	DBObject(DBOType initalizeType, int objectID);

	DBOType getDBType();
	virtual string displayInfo() = 0;
};

class DBClient :DBObject {
	string firstName;
	string lastName;
	string email;
	string phoneNumber;
	string street;
	string city;
	string province;
	string zipcode;
public:
	DBClient(DBClient& copyClient);
	string displayInfo();

};

class DBAccount :DBObject {

};

class DBTransaction: DBObject{

};
