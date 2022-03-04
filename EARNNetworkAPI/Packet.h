#pragma once

#include "DataTypes.h"
#include <ctime>

//
#define IP_SIZE 9
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

	Packet(DataTypes data, int size, int OpType) {

		if (Data) {

			delete Data;
		}
		Data = new char[size];

		memcpy(Data, &data, size);

		strcpy(HEAD.toIP, IP_ADDR);
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

		int TotalSize = sizeof(Header) + size + sizeof(int);

		TxBuffer = new char[TotalSize];

		setTime();

		memcpy(TxBuffer, &HEAD, sizeof(Header));
		memcpy(TxBuffer + sizeof(Header), Data, size);
		memcpy(TxBuffer + sizeof(Header) + size, &Tail, sizeof(Tail));

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

		cout << "Data:" << Data << endl;

	}


};
