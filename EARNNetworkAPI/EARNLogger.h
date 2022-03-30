#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include "EARNStructs.h"
#include "Packet.h"

namespace EarnLogging {

	//Generic Log Object implemented by subtypes
	class EARNLogObject {

		//string used for log comments field since most logs should have it in them...
		std::string logComment;

	public:
		//Constructors

		//Default constructor
		EARNLogObject();

		//Constructor for EARNLogObject, just requite input for this alternative
		EARNLogObject(std::string inputComment);

		//Get the log info about the object as a string to allow it to be written imediately
		virtual std::string getloginfo() = 0;

		//static Columns string for connection log, used in log initalization
		virtual std::string logColumnTemplate() = 0;

		//Get log comment for object
		std::string getLogComment();

		//Set log comment for object
		void setLogComment(std::string inputComment);
	};

	class EARNLogger {
		//path to log file specified during creation
		std::string logFilePath;

		//Get log file path for writing log information
		std::string getLogFilePath();

	public:
		EARNLogger(std::string logFilePath);

		bool logData(EARNLogObject* inputObject);
	};

	//enum for types of systems
	enum SystemType{ NOSYSTEM, CLIENTSYSTEM, SERVERSYSTEM};
	
	//Converts enum to string depending on type
	inline const std::string EnumToString(SystemType inputType)
	{
		switch (inputType)
		{
		case NOSYSTEM:		return "NOSYSTEM";
		case CLIENTSYSTEM:	return "CLIENTSYSTEM";
		case SERVERSYSTEM:	return "SERVERSYSTEM";
		default:			return "[Unknown Type]";
		}
	};

	enum RecvOrSend{NODIRECTION, RECEIVE, SEND};
	//Converts enum to string depending on type
	inline const std::string EnumToString(RecvOrSend inputType)
	{
		switch (inputType)
		{
		case NODIRECTION:		return "NODIRECTION";
		case RECEIVE:	return "RECEIVE";
		case SEND:	return "SEND";
		default:			return "[Unknown Type]";
		}
	};

	//Concrete Log Object for connection / packets
	class ConnectionLog :public EARNLogObject {
		Packet* parentPacket;
		SystemType currentSystem;
		RecvOrSend packetDirection;

	public:
		//Constructor

		//Constructor for ConnectionLog Object, requires a packet to be used...
		ConnectionLog(Packet* inputPacket, SystemType inputSystemType, RecvOrSend inputDirection, std::string inputLogComment);

		//Get System Type Enum
		SystemType getSystemType();

		//Get Packet Direction Enum
		RecvOrSend getPacketDirection();

		//Get the log info about the packet as a string to allow it to be written imediately
		std::string getloginfo();

		//static Columns string for connection log, used in log initalization
		std::string logColumnTemplate();

		//change the Packet in the class
		void changePacketInfo(Packet* inputPacket);
	};
}