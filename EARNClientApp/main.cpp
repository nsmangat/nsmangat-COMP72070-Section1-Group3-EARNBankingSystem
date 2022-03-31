#include "clientapp.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ClientApp w;
    w.show();
    QTcpSocket* socketP = w.connectServer();
    int exitVal = a.exec();
    Packet shutdownPacket(10, 0);
    shutdownPacket.setStatus(1);
    int shutdownTotalSize2 = 0;
    char* shutdownTxBuffer2 = shutdownPacket.serialize(shutdownTotalSize2);

    socketP->write(shutdownTxBuffer2, shutdownTotalSize2);    //send
    socketP->flush();
    socketP->waitForReadyRead();
    char rxBuffer[500];
    socketP->read(rxBuffer, 500);

    EarnLogging::ConnectionLog sendLog(&shutdownPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "sending request for shutdown");

    QString logPath = QDir::currentPath() + QString::fromStdString("ConnectionLog.csv");
    EarnLogging::EARNLogger testLogger(logPath.toStdString());
    testLogger.logData(&sendLog);

    socketP->disconnectFromHost();
    return exitVal;
}
