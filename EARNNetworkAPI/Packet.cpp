#define _CRT_SECURE_NO_WARNINGS

#include "Packet.h"
#include <cstring>
#include <ctime>


Packet::Packet(DataTypes* data, int size, int OpType, int accType) {

//	if (Data) {

//		delete Data;
//	}
    Data = new char[size];

	memcpy(Data, data, size);

	strncpy(HEAD.toIP, IP_ADDR, IP_SIZE);
	strcpy(HEAD.fromIP, IP_ADDR);

	HEAD.accountType = accType;
	HEAD.objectType = OpType;
	HEAD.dataSize = size;
	HEAD.status = 0;
	Tail = 12345;
}

//for parsing 2 structs ie for CreateAccount need CreateAccount and Login object 
Packet::Packet(DataTypes* data1, int size1, DataTypes* data2, int size2, int OpType) {

//	if (Data) {

//		delete Data;
//	}
	Data = new char[size1 + size2];

	memcpy(Data, data1, size1);
	memcpy(Data + size1, data2, size2);

	strncpy(HEAD.toIP, IP_ADDR, IP_SIZE);
	strcpy(HEAD.fromIP, IP_ADDR);

	HEAD.accountType = 0;
	HEAD.objectType = OpType;
	HEAD.dataSize = size1 + size2;
	//HEAD.branchID = 1;
	Tail = 12345;
}

Packet::Packet(char* src)									//to populate header on server 
{
	memcpy(&HEAD, src, sizeof(HEAD));
	int previousSize = HEAD.dataSize;
	
	HEAD.dataSize = 0;
	Data = nullptr;
	TxBuffer = nullptr;

	memcpy(&Tail, src + HeadSize + previousSize, sizeof(int));
}

Packet::Packet(int OpType, int AccType) {								//for client side for a request not requiring datatype ie view account 

	
	strncpy(HEAD.toIP, IP_ADDR, IP_SIZE);
	strcpy(HEAD.fromIP, IP_ADDR);

	HEAD.accountType = AccType;
	HEAD.objectType = OpType;
	HEAD.dataSize = 0;

	Data = nullptr;
	TxBuffer = nullptr;

	Tail = 0;
}

Packet::Packet(char* src, int objType) {					//BFT

//	if (Data) {

//		delete Data;
//	}
	Data = new char[BFT_SIZE];
	
	memcpy(Data, src, BFT_SIZE);
	
	strncpy(HEAD.toIP, IP_ADDR, IP_SIZE);
	strcpy(HEAD.fromIP, IP_ADDR);

	HEAD.accountType = 0;
	HEAD.objectType = objType;
	HEAD.dataSize = 1024;
	HEAD.status = 0;
	Tail = 12345;

}

void Packet::setDataBFT(char* BFTBuffer) {

//	if (Data) {

//		delete Data;
//	}
	Data = new char[BFT_SIZE];

	memcpy(Data, BFTBuffer, BFT_SIZE);
}


void Packet::setTime() {

	
	strcpy(HEAD.TimeOfSend, getCurrentTime(YMD_HMS).c_str());
}

//Would have to create a packet object and use that to serialize everything

char* Packet::serialize(int& size) {

//	if (TxBuffer) {

//		delete TxBuffer;
//	}

	size = sizeof(Header) + HEAD.dataSize + sizeof(int);

	TxBuffer = new char[size];

	setTime();

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
	cout << "Object Type:" << HEAD.objectType << endl;
	cout << "Data Size:" << HEAD.dataSize << endl;
	cout << "Time of Send:" << HEAD.TimeOfSend << endl;
	//cout << "Branch ID:" << HEAD.branchID << endl;

	cout << "Tail:" << Tail << endl;
	cout << "Data:" << &Data << endl;
}
//get operations for header

int Packet::getObjectType() {
	return HEAD.objectType;
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

void Packet::setStatus(int num) {

	HEAD.status = num;
}

int Packet::getStatus() {
	return HEAD.status;
}

char* Packet::getIP() {

	return HEAD.fromIP;
}

int Packet::getDataSize() {

	return HEAD.dataSize;
}

