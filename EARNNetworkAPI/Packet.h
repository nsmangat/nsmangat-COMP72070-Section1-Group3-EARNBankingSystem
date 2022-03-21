#pragma once

#include "DataTypes.h"
#include <ctime>

//
#define IP_SIZE 10
#define IP_ADDR "127.0.0.1"

class Packet {

	struct Header {

		char toIP[IP_SIZE];
		char fromIP[IP_SIZE];
		int operationType;
		int dataSize;
		char TimeOfSend[100];
		int branchID;
		int accountType;				//chequing or savings

	}HEAD;

	char* Data;
	char* TxBuffer;
	int Tail = 0;

public:

	Packet(DataTypes* data, int size, int OpType);
	Packet(DataTypes* data1, int size1, DataTypes* data2, int size2, int OpType);

	Packet(char* src);									//to populate header

	Packet(int OpType, int AccType);

	void setTime();

	//Would have to create a packet object and use that to serialize everything

	char* serialize(int& size);

	void display();

	int getOperationType();							//get operations for header 

	int getAccountType();

	void setAccountType(int accountType);

	char* getTime();

	int getTail();

};
