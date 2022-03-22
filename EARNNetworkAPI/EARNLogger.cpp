#include <iostream>
#include <sstream>
#include "EARNStructs.h"
#include "EARNLogger.h"

namespace EarnLogger {

	ConnectionLog::ConnectionLog(Packet* inputPacket, SystemType inputSystemType, RecvOrSend inputDirection, std::string inputLogComment) {
		this->parentPacket = inputPacket;
		this->currentSystem = inputSystemType;
		this->packetDirection = inputDirection;
		this->logComment = inputLogComment;
	}

	SystemType ConnectionLog::getSystemType() {
		return this->currentSystem;
	}

	RecvOrSend ConnectionLog::getPacketDirection() {
		return this->packetDirection;
	}

	std::string ConnectionLog::getLogComment() {
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
		outputLog << this->parentPacket->getTime() << ",";

		//Then from & to IP's
		outputLog << "From IP,";
		outputLog << "To IP,";

		//Then Packet Type
		outputLog << "Packet Type,";

		//Then System Type
		outputLog << EnumToString(this->getSystemType()) << ",";

		//Then CRC
		outputLog << this->parentPacket->getTail() << ",";

		//Then DataSize
		outputLog << "DataSize,";

		//Then Log comment
		outputLog << this->getLogComment() << ",";
		
		//Then parse status
		string statusString;
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

		outputLog << EnumToString(this->getPacketDirection()) << "\n";
	}
	
	std::string ConnectionLog::logColumnTemplate() {
		std::stringstream outputColumns;

		outputColumns << "Time of Event,";
		outputColumns << "From IP,";
		outputColumns << "To IP,";
		outputColumns << "Packet Type,";
		outputColumns << "System Type,";
		outputColumns << "CRC,";
		outputColumns << "DataSize,";
		outputColumns << "Log Comment,";
		outputColumns << "Success / Fail,";
		outputColumns << "Error Dump ID,";
		outputColumns << "Send / Receive\n";

		return outputColumns.str();
	}

	void ConnectionLog::changePacketInfo(Packet* inputPacket) {
		this->parentPacket = inputPacket;
	}
}