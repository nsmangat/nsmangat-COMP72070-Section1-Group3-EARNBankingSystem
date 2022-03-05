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

	}HEAD;

	char* Data;
	char* TxBuffer;
	int Tail;

public:

	Packet(DataTypes *data, int size, int OpType) {

		if (Data) {

			delete Data;
		}
		Data = new char[size];

		memcpy(Data, data, size);

		strncpy(HEAD.toIP, IP_ADDR, IP_SIZE);
		strcpy(HEAD.fromIP, IP_ADDR);
		
		HEAD.operationType = OpType;
		HEAD.dataSize = size;
		HEAD.branchID = 001;
		Tail = 0;

	}

	void setTime() {

		time_t now = time(0);
		char* time = ctime(&now);
		//HEAD.TimeOfSend = ctime(&now);
		strcpy(HEAD.TimeOfSend, time);
	}

	//Would have to create a packet object and use that to serialize everything

	char* serialize(int &size) {

		if (TxBuffer) {

			delete TxBuffer;
		}

		size = sizeof(Header) + HEAD.dataSize + sizeof(int);

		TxBuffer = new char[size];

		setTime();

		//cout << "HEad size: " << sizeof(Header);
		

		memcpy(TxBuffer, &HEAD, sizeof(Header));
		memcpy(TxBuffer + sizeof(Header), Data, HEAD.dataSize);
		memcpy(TxBuffer + sizeof(Header) + HEAD.dataSize, &Tail, sizeof(Tail));

		return TxBuffer;
	}

	void display() {

		cout << "to IP: " << HEAD.toIP << endl;
		cout << "From IP:" << HEAD.fromIP << endl;
		cout << "Op Type:" << HEAD.operationType << endl;
		cout << "Data Size:" << HEAD.dataSize << endl;
		cout << "Time of Send:" << HEAD.TimeOfSend << endl;
		cout << "Branch ID:" << HEAD.branchID << endl;

		cout << "Tail:" << Tail << endl;
		cout << "Data:" << &Data << endl;
	}


};
