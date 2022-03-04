#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <iostream>


using namespace std;

int main(void)
{
	char test[50];

	time_t now = time(0);
	char* time = ctime(&now);
	//HEAD.TimeOfSend = ctime(&now);
	strcpy(test, time);

	cout << test << endl;
}