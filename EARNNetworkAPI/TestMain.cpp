#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <iostream>

#include "DataTypes.h"
#include "Packet.h"


using namespace std;

int main(void)
{

	Deposit testobj(200, 1, 2);
	testobj.setAccountID(123);
	int size = sizeof(testobj);
	//int size = 16;
	int check = testobj.getAccountID();
	cout << "size of deposit: " << sizeof(testobj) << endl;


	Packet testPacket(&testobj, size, 5);



	

	int sendSize = 0;
	char* txBuffer = testPacket.serialize(sendSize);

	testPacket.display();
	cout << endl;

	//send 

	char rxBuffer[300] = {};

	//char* Head[128];
	int num;
	memcpy(&num, txBuffer + 20, sizeof(int));

	cout << "operation" << num << endl;

	memcpy(rxBuffer, txBuffer + 132, 32);

	int num1;
	int num2;
	int num3;		//accountID
	int num4;
	int num5;
	int num6;
	int num7;
	int num8;

	memcpy(&num1, rxBuffer, 4);
	memcpy(&num2, rxBuffer + 4, 4);
	memcpy(&num3, rxBuffer + 4 + 4, 4);
	memcpy(&num4, rxBuffer + 12, 4);
	memcpy(&num5, rxBuffer + 16, 4);
	memcpy(&num6, rxBuffer + 20, 4);
	memcpy(&num7, rxBuffer + 24, 4);
	memcpy(&num8, rxBuffer + 28, 4);


	/*memcpy(&num1, rxBuffer, 4);
	memcpy(&num2, rxBuffer + 20, 4);
	memcpy(&num3, rxBuffer + 24, 4);
	memcpy(&num4, rxBuffer + 28, 4);*/

	/*memcpy(&num1, rxBuffer, 4);
	memcpy(&num2, rxBuffer + 4, 4);
	memcpy(&num3, rxBuffer + 4 + 4, 4);
	memcpy(&num4, rxBuffer + 28, 4);*/

	cout << num1 << endl;
	cout << num2 << endl;
	cout << num3 << endl;
	cout << num4 << endl;
	cout << num5 << endl;
	cout << num6 << endl;
	cout << num7 << endl;
	cout << num8 << endl;

	//char* Data[128];
	



}