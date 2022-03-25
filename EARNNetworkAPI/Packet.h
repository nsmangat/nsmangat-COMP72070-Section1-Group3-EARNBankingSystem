#pragma once

#include "DataTypes.h"
#include <ctime>

//
#define IP_SIZE 10
#define IP_ADDR "127.0.0.1"
#define BFT_SIZE 1024

class Packet {

	struct Header {

		char toIP[IP_SIZE];
		char fromIP[IP_SIZE];
		int objectType;					//type of packet ie transaction packet, view account packet, logoff packet ect. 
		int dataSize;
		char TimeOfSend[VARCHARLEN];
		int accountType;				//chequing or savings
		int status;						//0 for default, 1 for success, 2 for failure

	}HEAD;

	char* Data;
	char* TxBuffer;
	int Tail = 0;

public:

	Packet(DataTypes* data, int size, int OpType, int accType);
	Packet(DataTypes* data1, int size1, DataTypes* data2, int size2, int OpType);
	Packet(char* src, int objType);

	Packet(char* src);									//to populate header

	Packet(int OpType, int AccType);

	void setTime();

	//Would have to create a packet object and use that to serialize everything

	char* serialize(int& size);

	void display();

	int getObjectType();							//get operations for header 

	int getAccountType();

	void setAccountType(int accountType);

	char* getTime();

	int getTail();

	void setStatus(int num);
	int getStatus();

	char* getIP();
	int getDataSize();

	void setDataBFT(char* BFTBuffer);

};
