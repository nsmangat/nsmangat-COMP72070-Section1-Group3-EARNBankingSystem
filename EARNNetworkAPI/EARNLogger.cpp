//#include <iostream>
#include <sstream>
#include <fstream>
//#include <filesystem>
//#include <ctime>
//#include <iomanip>

#include "EARNStructs.h"
#include "EARNLogger.h"

//EARNLogger source
namespace EarnLogging {
	//Constructor
	
	EARNLogger::EARNLogger(std::string inputFilePath) {
		this->logFilePath = inputFilePath;
	}

	//Time / Get functions

	std::string EARNLogger::getCurrentTime(DateFormat logDateFormat) {
		std::stringstream outputTime;
		time_t rawtime;
		struct tm logTime;

		time(&rawtime);

		gmtime_s(&logTime, &rawtime);

		if (YMD_HMS == logDateFormat) {
			
			outputTime << std::put_time(&logTime, "%Y/%m/%d %H:%M:%S");
		}
		else if (MDY_HMS == logDateFormat) {
			outputTime << std::put_time(&logTime, "%m/%d/%Y %H:%M:%S");
		}
		else if (DMY_HMS == logDateFormat) {
			outputTime << std::put_time(&logTime, "%d/%m/%Y %H:%M:%S");
		}
		else {
			outputTime << "TIME CALCULATION ERROR";
		}

		return outputTime.str();
	}

	std::string EARNLogger::getLogFilePath() {
		return this->logFilePath;
	}

	//log data function
	bool EARNLogger::logData(EARNLogObject* inputObject) {
		//first set up columns in case we need to instantiate
		std::stringstream logStream;
		std::stringstream logColumns;

		//"wrap" objects logs in time logged & comment so that they are consistent + if all logs require these two fields they can always end with ',' without worrying about output...
		logColumns << "Time Logged (UTC)," << inputObject->logColumnTemplate() << "Log Comment";
		
		//then setup log row itself
		logStream << this->getCurrentTime(YMD_HMS) << "," << inputObject->getloginfo() << inputObject->getLogComment() << '\n';

		//create file checker of type in (read only)
		std::ifstream fileCheck;

		fileCheck.open(this->getLogFilePath(),std::fstream::in);

		//if file doesn't exist instantiate log with columns we put above
		if (!fileCheck) {
			std::cout << "file doesn't exist, instantiating csv" << std::endl;
			fileCheck.close();
			//close read only filestream and create new output stream
			std::ofstream fileInit;
			fileInit.open(this->getLogFilePath(), std::fstream::out);
			fileInit << logColumns.str() << '\n';
			fileInit.close();
		}
		else {
			//get first line of .csv to check it is the correct columns
			std::string csvColumns;
			std::getline(fileCheck, csvColumns);

			//if first line is not correct then exit in case wrong log file, otherwise move on
			if (0 != strcmp(logColumns.str().c_str(), csvColumns.c_str())) {
				return false;
			}
			fileCheck.close();
		}

		//open again now that it exists and append data
		std::ofstream fileStream;
		fileStream.open(this->getLogFilePath(), std::fstream::app);
		fileStream << logStream.str();
		fileStream.close();

		return true;
	}
}

//EARNLogObject source
namespace EarnLogging {
	EARNLogObject::EARNLogObject() {
		this->setLogComment("");
	}

	EARNLogObject::EARNLogObject(std::string inputLogComment) {
		this->setLogComment(inputLogComment);
	}

	std::string EARNLogObject::getLogComment() {
		return this->logComment;
	}

	void EARNLogObject::setLogComment(std::string inputComment) {
		this->logComment = inputComment;
	}

}

//ConnectionLog source
namespace EarnLogging {

	ConnectionLog::ConnectionLog(Packet* inputPacket, SystemType inputSystemType, RecvOrSend inputDirection, std::string inputLogComment) :EARNLogObject(inputLogComment){
		this->parentPacket = inputPacket;
		this->currentSystem = inputSystemType;
		this->packetDirection = inputDirection;
		this->setLogComment(inputLogComment);
	}

	SystemType ConnectionLog::getSystemType() {
		return this->currentSystem;
	}

	RecvOrSend ConnectionLog::getPacketDirection() {
		return this->packetDirection;
	}

	/*
	Connection Log Template									
	Time of Event	From IP			To IP			Packet Type		System Type			DataSize	Log Comment				Success / Fail		Error Dump ID		send/receive
					IP Sending		IP Receiving					Client / Server					Client ID X Created							0 if successful	
	*/
	std::string ConnectionLog::getloginfo() {
		std::stringstream outputLog;

		//Get time
		outputLog << std::string(this->parentPacket->getTime()) << ",";

		//Then from & to IP's
		outputLog << this->parentPacket->getIP() << ",";

		outputLog << this->parentPacket->getIP() << ",";

		//Then Packet Type
		outputLog << this->parentPacket->getObjectType() << ",";

		//Then System Type
		outputLog << EnumToString(this->getSystemType()) << ",";

		//Then CRC
		outputLog << this->parentPacket->getTail() << ",";

		//Then DataSize
		outputLog << this->parentPacket->getDataSize() << ",";
		
		//Then parse status
		std::string statusString;
		if (1 == this->parentPacket->getStatus()) {
			statusString = "Success";
		}
		else if (2 == this->parentPacket->getStatus()) {
			statusString = "Failure";
		}
		else {
			statusString = "Unknown / Default Status";
		}

		outputLog << statusString << ",";

		//Then parse error
		int errorID = 0;
		if (2 == this->parentPacket->getStatus()) {
			//log errors here and return id
			//errorID = ErrorLogger(this.parentPacket);
		}

		outputLog << errorID << ",";

		outputLog << EnumToString(this->getPacketDirection()) << ",";

		return outputLog.str();
	}
	
	std::string ConnectionLog::logColumnTemplate() {
		std::stringstream outputColumns;

		outputColumns << "Time Sent (UTC),";
		outputColumns << "From IP,";
		outputColumns << "To IP,";
		outputColumns << "Packet Type,";
		outputColumns << "System Type,";
		outputColumns << "CRC,";
		outputColumns << "DataSize,";
		outputColumns << "Success / Fail,";
		outputColumns << "Error Dump ID,";
		outputColumns << "Send / Receive,";


		return outputColumns.str();
	}

	void ConnectionLog::changePacketInfo(Packet* inputPacket) {
		this->parentPacket = inputPacket;
	}
}