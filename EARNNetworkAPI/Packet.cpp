#define _CRT_SECURE_NO_WARNINGS

#include "Packet.h"

#include <ctime>



Packet::Packet(DataTypes* data, int size, int OpType) {

	if (Data) {

		delete Data;
	}
	Data = new char[size];

	memcpy(Data, data, size);

	strncpy(HEAD.toIP, IP_ADDR, IP_SIZE);
	strcpy(HEAD.fromIP, IP_ADDR);

	HEAD.accountType = 0;
	HEAD.operationType = OpType;
	HEAD.dataSize = size;
	HEAD.branchID = 1;
	Tail = 12345;
}

Packet::Packet(char* src)									//to populate header on server 
{
	memcpy(&HEAD, src, sizeof(HEAD));
	int previousSize = HEAD.dataSize;
	
	HEAD.dataSize = 0;
	Data = nullptr;
	TxBuffer = nullptr;
	//Tail = 122;

	memcpy(&Tail, src + HeadSize + previousSize, sizeof(int));
}

Packet::Packet(int OpType, int AccType) {								//for client side for a request not requiring datatype ie view account 

	
	strncpy(HEAD.toIP, IP_ADDR, IP_SIZE);
	strcpy(HEAD.fromIP, IP_ADDR);

	HEAD.accountType = AccType;
	HEAD.operationType = OpType;
	HEAD.dataSize = 0;
	HEAD.branchID = 1;

	Data = nullptr;
	TxBuffer = nullptr;

	Tail = 0;
}

void Packet::setTime() {

	time_t now = time(0);
	char* time = ctime(&now);
	//HEAD.TimeOfSend = ctime(&now);
	strcpy(HEAD.TimeOfSend, time);
}

//Would have to create a packet object and use that to serialize everything

char* Packet::serialize(int& size) {

	if (TxBuffer) {

		delete TxBuffer;
	}

	size = sizeof(Header) + HEAD.dataSize + sizeof(int);

	TxBuffer = new char[size];

	setTime();

	//cout << "HEad size: " << sizeof(Header);


	memcpy(TxBuffer, &HEAD, sizeof(Header));
	if(Data == nullptr)
	{		
		memcpy(TxBuffer + sizeof(Header), &Tail, sizeof(Tail));
	}
	else
	{
		memcpy(TxBuffer + sizeof(Header), Data, HEAD.dataSize);

		memcpy(TxBuffer + sizeof(Header) + HEAD.dataSize, &Tail, sizeof(Tail));
	}
	

	return TxBuffer;
}

void Packet::display() {

	cout << "to IP: " << HEAD.toIP << endl;
	cout << "From IP:" << HEAD.fromIP << endl;
	cout << "Op Type:" << HEAD.operationType << endl;
	cout << "Data Size:" << HEAD.dataSize << endl;
	cout << "Time of Send:" << HEAD.TimeOfSend << endl;
	cout << "Branch ID:" << HEAD.branchID << endl;

	cout << "Tail:" << Tail << endl;
	cout << "Data:" << &Data << endl;
}

int Packet::getOperationType() {									//get operations for header 

	return HEAD.operationType;
}

char* Packet::getTime() {

	return HEAD.TimeOfSend;
}

int Packet::getTail() {

	return Tail;
}

int Packet::getAccountType() {

	return HEAD.accountType;
}

void Packet::setAccountType(int accountType) {

	HEAD.accountType = accountType;
}