#define _CRT_SECURE_NO_WARNINGS
#include "clientapp.h"
#include "ui_clientapp.h"
#define MAX_BUFFER 30
#define MAX_ZIPCODE 6
#define RAW_BUFFER_SIZE 500
#define BFT_SIZE_CLIENT 1200
#include <QIODevice>
#include <QFile>
#include <QTextStream>
#include <QBuffer>
#include <QByteArray>
#include <QImage>
#include <cstring>
#include <QSaveFile>

AccountInformation chequingLoginMain;
AccountInformation savingsLoginMain;
//EarnLogging::EARNLogger testLogger("../ConnectionLog.csv");

QString logPath = QDir::currentPath() + QString::fromStdString("ConnectionLog.csv");
EarnLogging::EARNLogger testLogger(logPath.toStdString());

ClientApp::ClientApp(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ClientApp)
{
    ui->setupUi(this);

}

ClientApp::~ClientApp()
{
    delete this->socket;
    delete ui;
}
QTcpSocket* ClientApp::connectServer()
{
    socket = new QTcpSocket();

    QString IP;
    int port;
    port = 27000;
    IP = "127.0.0.1";

    socket->connectToHost(IP, port);

    //Waiting for the connection to succeed
    if (!socket->waitForConnected(27000))
    {
        qDebug() << "Connection failed!";
        return NULL;
    }
    qDebug() << "Connect successfully!";

    return socket;
}
void ClientApp::socket_Read_Data()
{
    QByteArray buffer;
    //Read Buffer Data
    buffer = socket->readAll();
}
void ClientApp::display_Balance()
{
    ui->ChequingBalance_label->setText(QString::number(chequingLoginMain.getAccountBalance()));
    ui->SavingBalance_label->setText(QString::number(savingsLoginMain.getAccountBalance()));


}
void ClientApp::display_Account_Info()
{
    //Display user's data in
    ui->Name_label->setText("");
    ui->PhoneNum_label->setText("");
    ui->PostalCode_label->setText("");
    ui->Address_label->setText("");
    ui->Email_label->setText("");
}

void ClientApp::on_BackToMenu_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    disconnect();
}

void ClientApp::on_Login_pushButton_clicked()
{

    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    char cardNum[45];
    char password[45];

    strcpy(cardNum, ui->CardNum_lineEdit->text().toStdString().c_str());
    strcpy(password, ui->Password_lineEdit->text().toStdString().c_str());

    Login loginObj(cardNum, password);

    //send to server
    int loginSize = sizeof(loginObj);
    Packet loginPacket(&loginObj, loginSize, 2, 0);
    int totalSize = 0;
    txBuffer = loginPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&loginPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for login");
    testLogger.logData(&sendLog);


    socket->write(txBuffer, 500);    //send
    socket->flush();

    //recieve data from server
    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, RAW_BUFFER_SIZE);

    int sizeLoginRecv = sizeof(AccountInformation);
    char rxBufferChequingLogin[1000] = {};
    char rxBufferSavingLogin[1000] = {};


    memcpy(rxBufferChequingLogin, rxBuffer, sizeLoginRecv + HeadSize);

    Packet checkStatus(rxBufferChequingLogin);

    int status = checkStatus.getStatus();   //verify the return message type (success/fail)
    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recieve response for login");
    testLogger.logData(&recvLog);

    if (status == 1) {

        memcpy(rxBufferSavingLogin, rxBuffer, HeadSize);
        memcpy(rxBufferSavingLogin + HeadSize, rxBuffer + HeadSize + sizeLoginRecv, sizeLoginRecv);

        AccountInformation chequingLogin(rxBufferChequingLogin);
        AccountInformation savingsLogin(rxBufferSavingLogin);

        memcpy(&chequingLoginMain, &chequingLogin, sizeof(chequingLogin));
        memcpy(&savingsLoginMain, &savingsLogin, sizeof(savingsLogin));

        ui->stackedWidget->setCurrentIndex(3);

    }
    else
    {
        QMessageBox::warning(this, "Login", "Card number or password is incorrect.");
    }

    ui->CardNum_lineEdit->clear();
    ui->Password_lineEdit->clear();
}

void ClientApp::on_SendResetLink_pushButton_clicked()
{


    char cardNum[MAX_BUFFER];
    char password[MAX_BUFFER] = {};
    char* rxBuffer = new char[RAW_BUFFER_SIZE];
    char* txBuffer = new char[RAW_BUFFER_SIZE];

    strcpy(cardNum, ui->email_lineEdit->text().toStdString().c_str());

    Login loginObj(cardNum, password);

    int loginSize = sizeof(loginObj);

    Packet resetAcc(&loginObj, loginSize, 7, 0);
    int totalSize = 0;
    txBuffer = resetAcc.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&resetAcc, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for reset password link");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();
    socket->waitForReadyRead();
    socket->read(rxBuffer, RAW_BUFFER_SIZE);   //recv

    char rxBufferArray[1000] = {};
    memcpy(rxBufferArray, rxBuffer, totalSize);     //check


    Packet checkStatus(rxBufferArray);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account reset link");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1)
    {
        QMessageBox::information(this, "Reset Password", "A reset link is sent to your email.");
    }
    else {
        QMessageBox::warning(this, "Reset Password", "Email is inavlid.");
    }
    ui->email_lineEdit->clear();
}

void ClientApp::on_BackToLogin_pushButton_clicked() //logout
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

void ClientApp::on_BackToLogin_pushButton_2_clicked() //logout
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);


    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

void ClientApp::on_ResetPassword_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ClientApp::on_Signin_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ClientApp::on_Logout_pushButton_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

//---------Menu page---------
void ClientApp::on_ViewStatement_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void ClientApp::on_E_Transfer_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void ClientApp::on_Deposit_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void ClientApp::on_AddAcc_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void ClientApp::on_ViewAcc_pushButton_clicked()
{
    int viewAccountSize = sizeof(chequingLoginMain);

    Packet viewAccountPacket(&chequingLoginMain, viewAccountSize, 3, 0);
    int totalSize = 0;
    char* txBuffer = new char[1000];
    txBuffer = viewAccountPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&viewAccountPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for view account info");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();


    // Read Buffer Data
    socket->waitForReadyRead();
    char* rxBuffer = new char[500];
    int num = socket->read(rxBuffer, 500);

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for view account info");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        CreateAccount AccountInfoTest(rxBuffer, 16);
        QString fullName = QString::fromStdString(AccountInfoTest.getFirstName()) + " " + QString::fromStdString(AccountInfoTest.getLastName());;
        ui->Name_label->setText(fullName);
        ui->PhoneNum_label->setText(QString::fromStdString(AccountInfoTest.getPhoneNumber()));
        ui->PostalCode_label_2->setText(QString::fromStdString(AccountInfoTest.getZipcode()));
        ui->Address_label->setText(QString::fromStdString(AccountInfoTest.getStreetName()) + ", " + QString::fromStdString(AccountInfoTest.getCity()) + ", " + QString::fromStdString(AccountInfoTest.getProvince()));
        ui->Email_label->setText(QString::fromStdString(AccountInfoTest.getEmail()));
    }
    else
    {
        QMessageBox::critical(
                    this,
                    tr("View Account"),
                    tr("Unable to view account information at the moment"));
    }


    ui->stackedWidget->setCurrentIndex(8);
}

//-------Add Account Page-----
void ClientApp::on_BackToMenu_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void ClientApp::on_Logout_pushButton_5_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

//-------View Transaction Activities Page-----
void ClientApp::on_ImageDisplayPushButton_clicked()
{
    Packet BFTRequest(9, 0);
    int size = 0;
    //char* rxBuffer = new char[RAW_BUFFER_SIZE];
    char* txBuffer = new char[500];
    txBuffer = BFTRequest.serialize(size);

    EarnLogging::ConnectionLog sendLog(&BFTRequest, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for view statements image");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, size);    //send
    socket->flush();

    //receiving bytes for picture
    int TotalSize = BFT_SIZE + HeadSize + sizeof(int);
    char RxBuffer[BFT_SIZE + HeadSize + sizeof(int)] = {};

    char BFTBuffer[BFT_SIZE] = {};

    //char fName[500] = "C:/Users/eazaz/Downloads/nsmangat-COMP72070-Section1-Group3-EARNBankingSystem-MergingFInalRelease/nsmangat-COMP72070-Section1-Group3-EARNBankingSystem-MergingFInalRelease/EARNClientApp/recvImage.JPG";
    QString fName = QDir::currentPath() + "/../recvImage.jpg";
    FILE* fp = fopen(fName.toStdString().c_str(), "wb");
    bool receivingBytesLoop = true;
    char ack[3] = "ok";

    //file.open(QIODevice::WriteOnly);
    //qDebug() << "File Opened!";
    //QTextStream out(&file);
    while (receivingBytesLoop)
    {
        socket->waitForReadyRead();
        int size = socket->read(RxBuffer, TotalSize);       //recv

        memcpy(BFTBuffer, RxBuffer + HeadSize, BFT_SIZE);

        //int size = recv(ClientSocket, TxBuffer, sizeof(TxBuffer), 0);
        if (size > (int)(HeadSize + sizeof(int)))
        {
            fwrite(BFTBuffer, sizeof(BFTBuffer), 1, fp);

            socket->write(ack, sizeof(ack));    //send
            socket->flush();
        }
        else
        {
            receivingBytesLoop = false;
        }

    }
    fclose(fp);


    QPixmap pic(fName);
    ui->labelImage->setPixmap(pic);
}


void ClientApp::on_BackToMenu_pushButton_clicked()
{
    ui->labelImage->clear();
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientApp::on_Logout_pushButton_2_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv



    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}


void ClientApp::on_BackToMenu_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientApp::on_Logout_pushButton_3_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

//-------e-Transfer Page-----
void ClientApp::on_Send_pushButton_clicked()
{

    if (ui->Amount_lineEdit->text() == "" || ui->To_lineEdit->text() == "")
    {
        QMessageBox::information(
                    this,
                    tr("Transaction"),
                    tr("Transaction InCompleted"));
    }
    else
    {
        double amount = ui->Amount_lineEdit->text().toDouble();
        int sendAcc = ui->To_lineEdit->text().toInt();
        double newBalance;
        int choice;
        QString chequingType = "Chequing Account";
        //QString savingType = "Saving";
        Transaction sendEtransferTransaction;
        int etransferSize;
        int totalSize = 0;
        char* rxBuffer = new char[RAW_BUFFER_SIZE];
        char* txBuffer = new char[RAW_BUFFER_SIZE];

        if (ui->From_comboBox->currentText() == chequingType)
        {
            newBalance = chequingLoginMain.getAccountBalance() - amount;
            Transaction sendEtransfer(chequingLoginMain.getObjectID(), ETRANSFER, chequingLoginMain.getAccountBalance(), newBalance, sendAcc);
            sendEtransferTransaction = sendEtransfer;
            choice = 1;
            etransferSize = sizeof(sendEtransferTransaction);
            Packet etransferSendPacket(&sendEtransferTransaction, etransferSize, 4, choice);
            txBuffer = etransferSendPacket.serialize(totalSize);

            EarnLogging::ConnectionLog sendLog(&etransferSendPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for e-transfer");
            testLogger.logData(&sendLog);

        }
        else
        {
            newBalance = savingsLoginMain.getAccountBalance() - amount;
            Transaction sendEtransfer(savingsLoginMain.getObjectID(), ETRANSFER, savingsLoginMain.getAccountBalance(), newBalance, sendAcc);
            sendEtransferTransaction = sendEtransfer;
            choice = 2;
            etransferSize = sizeof(sendEtransferTransaction);
            Packet etransferSendPacket(&sendEtransferTransaction, etransferSize, 4, choice);
            txBuffer = etransferSendPacket.serialize(totalSize);

            EarnLogging::ConnectionLog sendLog(&etransferSendPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for e-transfer");
            testLogger.logData(&sendLog);
        }

        // int etransferSize = sizeof(sendEtransferTransaction);
        //Packet etransferSendPacket(&sendEtransferTransaction, etransferSize, 4, choice);


        socket->write(txBuffer, totalSize);    //send
        socket->flush();
        socket->waitForReadyRead(30000);
        socket->read(rxBuffer, RAW_BUFFER_SIZE);   //recv

        Packet checkStatus(rxBuffer);       //deserialize

        EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for e-transfer");
        testLogger.logData(&recvLog);

        int status = checkStatus.getStatus();

        if (status == 1) {
            QMessageBox::information(
                        this,
                        tr("Transaction"),
                        tr("Transaction Completed"));

            if (choice == 1)
            {

                chequingLoginMain.setAccountBalance(sendEtransferTransaction.getNewBalance());

            }
            else if (choice == 2)
            {
                savingsLoginMain.setAccountBalance(sendEtransferTransaction.getNewBalance());
            }
        }
        else {
            QMessageBox::critical(
                        this,
                        tr("Transaction"),
                        tr("Transaction Incompleted. Insufficient funds."));
        }
        ui->To_lineEdit->clear();
        ui->Amount_lineEdit->clear();
    }
}

void ClientApp::on_BackToMenu_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientApp::on_Logout_pushButton_4_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

void ClientApp::on_DepositComplete_pushButton_clicked()
{
    //Verify that all required fields are filled
    if (!ui->FrontpageImage_label->pixmap().isNull() && !ui->BackpageImage_label->pixmap().isNull()
            && ui->Amount_lineEdit_2->isModified())
    {
        int choice;
        double amount = ui->Amount_lineEdit_2->text().toDouble();
        Transaction depositChequeTransaction;
        int depositChequeSize;
        int totalSize = 0;
        char* rxBuffer = new char[RAW_BUFFER_SIZE];
        char* txBuffer = new char[RAW_BUFFER_SIZE];

        if (ui->AccType_comboBox->currentText() == "Chequing Account")
        {
            //depositChequeTransaction = depositCheque(chequingLoginMain);

            double nBalance = chequingLoginMain.getAccountBalance() + amount;

            Transaction send(chequingLoginMain.getObjectID(), CHEQUE, chequingLoginMain.getAccountBalance(), nBalance, 0);		//secAcc set to zero because no acc needed
            depositChequeTransaction = send;
            choice = 1;
            depositChequeSize = sizeof(depositChequeTransaction);

        }
        else
        {
            //depositChequeTransaction = depositCheque(savingsLoginMain);
            double nBalance = savingsLoginMain.getAccountBalance() + amount;

            Transaction send(savingsLoginMain.getObjectID(), CHEQUE, savingsLoginMain.getAccountBalance(), nBalance, 0);		//secAcc set to zero because no acc needed
            depositChequeTransaction = send;
            choice = 2;
            depositChequeSize = sizeof(depositChequeTransaction);

        }

        Packet depositChequeRecvPacket(&depositChequeTransaction, depositChequeSize, 4, choice);

        txBuffer = depositChequeRecvPacket.serialize(totalSize);

        EarnLogging::ConnectionLog sendLog(&depositChequeRecvPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for deposit");
        testLogger.logData(&sendLog);

        socket->write(txBuffer, totalSize);    //send
        socket->flush();
        socket->waitForReadyRead();

        socket->read(rxBuffer, RAW_BUFFER_SIZE);   //recv

        Packet checkStatus(rxBuffer);

        EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for deposit");
        testLogger.logData(&recvLog);

        int status = checkStatus.getStatus();

        if (status == 1) {

            //Successful message
            QMessageBox::information(
                        this,
                        tr("Deposit"),
                        tr("Deposit submitted.\nSent images will be verifed and balance will officially updated in 3 business days."));

            if (choice == 1)
            {
                chequingLoginMain.setAccountBalance(depositChequeTransaction.getNewBalance());
            }
            else if (choice == 2)
            {
                savingsLoginMain.setAccountBalance(depositChequeTransaction.getNewBalance());
            }
        }
        else
        {
            //Unsuccessful message
            QMessageBox::information(
                        this,
                        tr("Deposit"),
                        tr("Deposit Unsuccessful. Please try again."));
        }

        //Clear input information after completing deposit
        ui->FrontpageImage_label->clear();
        ui->BackpageImage_label->clear();
        ui->Amount_lineEdit_2->clear();

    }
    else
    {
        //Fail message if required field(s) is missing
        QMessageBox::critical(
                    this,
                    tr("Deposit"),
                    tr("Insufficient information"));
    }

}

void ClientApp::on_AddFrontpage_pushButton_clicked()
{
    //Ask user to select image from their computer to load to the application
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Image(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(fileName, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(fileName);      //verify that image is loaded successfully
        if (valid)
        {
            //Set/Display the selected image to the label to let the user know
            ui->FrontpageImage_label->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::warning(
                        this,
                        tr("Image Error"),
                        tr("Unable to load image."));
        }
    }
}

void ClientApp::on_AddBackpage_pushButton_clicked()
{
    //Ask user to select image from their computer to load to the application
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Image(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (QString::compare(fileName, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(fileName);
        if (valid)
        {

            ui->BackpageImage_label->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::warning(
                        this,
                        tr("Image Error"),
                        tr("Unable to load image."));
        }
    }
}

void ClientApp::on_InvestingAcc_checkBox_stateChanged(int arg)
{
    //add investing account type if check box is checked
    if (ui->InvestingAcc_checkBox->isChecked())
    {
        //over write the account options
        ui->From_comboBox->clear();
        ui->AccType_comboBox->clear();
        ui->From_comboBox->addItems({ "Chequing","Saving","Investing" });
        ui->AccType_comboBox->addItems({ "Chequing","Saving","Investing" });
    }
    else //remove the investing acc option when the check box is unchecked
    {
        ui->From_comboBox->clear();
        ui->AccType_comboBox->clear();
        ui->From_comboBox->addItems({ "Chequing","Saving" });
        ui->AccType_comboBox->addItems({ "Chequing","Saving" });

    }
}

void ClientApp::on_BackToMenu_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientApp::on_Logout_pushButton_6_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

void ClientApp::on_Transfer_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void ClientApp::on_Logout_pushButton_7_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

void ClientApp::on_Send_pushButton_2_clicked()             //Send to my accs
{
    if (ui->From_comboBox_2->currentIndex() == ui->To_comboBox->currentIndex()) //if send chequing to chequing or saving to saving
    {
        QMessageBox::critical(
                    this,
                    tr("Error"),
                    tr("FROM and TO fields are the same."));
    }
    else if (ui->Amount_lineEdit_3->text() != "")
    {
        int choice;
        Transaction transferTransaction;
        double amount = ui->Amount_lineEdit_3->text().toDouble();

        if (ui->From_comboBox_2->currentText() == "Chequing Account") {
            choice = 1;
        }
        else {
            choice = 2;
        }

        if (choice == 1)
        {
            double newBalance = chequingLoginMain.getAccountBalance() - amount;
            Transaction transferBetween(chequingLoginMain.getObjectID(), ACCOUNTTRANSFER, chequingLoginMain.getAccountBalance(), newBalance, savingsLoginMain.getObjectID());
            transferTransaction = transferBetween;
        }
        else
        {
            double newBalance = savingsLoginMain.getAccountBalance() - amount;
            Transaction transferBetween(savingsLoginMain.getObjectID(), ACCOUNTTRANSFER, savingsLoginMain.getAccountBalance(), newBalance, chequingLoginMain.getObjectID());
            transferTransaction = transferBetween;
        }

        int transferSize = sizeof(transferTransaction);

        Packet transferSendPacket(&transferTransaction, transferSize, 4, choice);
        int totalSize = 0;
        char* rxBuffer = new char[RAW_BUFFER_SIZE];
        char* txBuffer = new char[RAW_BUFFER_SIZE];

        txBuffer = transferSendPacket.serialize(totalSize);

        EarnLogging::ConnectionLog sendLog(&transferSendPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for transfer between my accounts");
        testLogger.logData(&sendLog);

        socket->write(txBuffer, totalSize);    //send
        socket->flush();
        socket->waitForReadyRead();
        socket->read(rxBuffer, RAW_BUFFER_SIZE);   //recv

        Packet checkStatus(rxBuffer);

        EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for transfer between my accounts");
        testLogger.logData(&recvLog);

        int status = checkStatus.getStatus();

        if (status == 1) {

            if (choice == 1)
            {
                chequingLoginMain.setAccountBalance(transferTransaction.getNewBalance());

                double amount = transferTransaction.getPreviousBalance() - transferTransaction.getNewBalance();
                savingsLoginMain.setAccountBalance(savingsLoginMain.getAccountBalance() + amount);

                QMessageBox::information(
                            this,
                            tr("Transaction"),
                            tr("Transaction Completed"));

            }
            else if (choice == 2)
            {

                savingsLoginMain.setAccountBalance(transferTransaction.getNewBalance());

                double amount = transferTransaction.getPreviousBalance() - transferTransaction.getNewBalance();
                chequingLoginMain.setAccountBalance(chequingLoginMain.getAccountBalance() + amount);

                QMessageBox::information(
                            this,
                            tr("Transaction"),
                            tr("Transaction Completed"));
            }
        }
        else
        {

            QMessageBox::information(
                        this,
                        tr("Transaction"),
                        tr("Transaction Incompleted. Insufficient funds"));
        }
    }

    else {
        QMessageBox::critical(
                    this,
                    tr("Error"),
                    tr("AMOUNT field is not filled."));
    }
    ui->Amount_lineEdit_3->clear();
}

void ClientApp::on_Signup_pushButton_clicked()  //Create new user
{
    if (ui->FirstName_lineEdit->text() != "" &&
            ui->LastName_lineEdit->text() != "" &&
            ui->UserName_lineEdit->text() != "" &&
            ui->NewPassword_lineEdit->text() != "" &&
            ui->ConfirmPassword_lineEdit->text() != "" &&
            ui->Email_lineEdit->text() != "" &&
            ui->Street_lineEdit->text() != "" &&
            ui->City_lineEdit->text() != "" &&
            ui->Province_lineEdit->text() != "" &&
            ui->PostalCode_lineEdit->text() != "" &&
            ui->Phone_lineEdit->text() != "")
    {

        char firstName[45] = {};
        char lastName[45] = {};
        char email[45] = {};
        char phoneNumber[45] = {};
        char street[45] = {};
        char city[45] = {};
        char province[45] = {};
        char zipcode[6] = {};

        char userName[45] = {};
        char password[45] = {};

        int accountID = 0;

        strcpy(firstName, ui->FirstName_lineEdit->text().toStdString().c_str());
        strcpy(lastName, ui->LastName_lineEdit->text().toStdString().c_str());
        strcpy(email, ui->Email_lineEdit->text().toStdString().c_str());
        strcpy(phoneNumber, ui->Phone_lineEdit->text().toStdString().c_str());
        strcpy(street, ui->Street_lineEdit->text().toStdString().c_str());
        strcpy(city, ui->City_lineEdit->text().toStdString().c_str());
        strcpy(province, ui->Province_lineEdit->text().toStdString().c_str());
        strcpy(zipcode, ui->PostalCode_lineEdit->text().toStdString().c_str());

        strcpy(userName, ui->UserName_lineEdit->text().toStdString().c_str());
        strcpy(password, ui->ConfirmPassword_lineEdit->text().toStdString().c_str());

        //Call the constructor CreateAccount
        CreateAccount acc(firstName, lastName, email, phoneNumber, street, city, province, zipcode, accountID);
        Login loginSetup(userName, password);

        int accSize = 344;
        int loginSize = sizeof(loginSetup);
        Packet loginPacket(&acc, accSize, &loginSetup, loginSize, 5);
        int totalSize = 0;
        char* txBuffer = new char[1000];
        txBuffer = loginPacket.serialize(totalSize);

        //        char rxBuffer1[1000] = {};
        //        char rxBuffer2[1000] = {};

        //        int size1 = sizeof(CreateAccount);
        //        int size2 = sizeof(Login);
        //        memcpy(rxBuffer1, txBuffer, size1 + HeadSize);		//get account info

        //        memcpy(rxBuffer2, txBuffer, HeadSize);
        //        memcpy(rxBuffer2 + HeadSize, txBuffer + HeadSize + size1, size2);	//get login info

        //        CreateAccount RxClient(rxBuffer1);
        //        Login RxLogin(rxBuffer2,12);



        EarnLogging::ConnectionLog sendLog(&loginPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account creation");
        testLogger.logData(&sendLog);

        socket->write(txBuffer, totalSize);    //send
        socket->flush();

        //recieve data from server

        // Read Buffer Data
        socket->waitForReadyRead(30000);
        char* rxBuffer = new char[500];


        int num = socket->read(rxBuffer, 500);

        int sizeLoginRecv = sizeof(AccountInformation) + 8;
        char rxBufferChequingLogin[1000] = {};
        char rxBufferSavingLogin[1000] = {};


        memcpy(rxBufferChequingLogin, rxBuffer, sizeLoginRecv + HeadSize);

        Packet checkStatus(rxBufferChequingLogin);

        EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account creation");
        testLogger.logData(&recvLog);

        int status = checkStatus.getStatus();   //verify the return message type (success/fail)

        if (status == 1) {

            memcpy(rxBufferSavingLogin, rxBuffer, HeadSize);
            memcpy(rxBufferSavingLogin + HeadSize, rxBuffer + HeadSize + sizeLoginRecv, sizeLoginRecv);

            AccountInformation chequingLogin(rxBufferChequingLogin);
            AccountInformation savingsLogin(rxBufferSavingLogin);

            memcpy(&chequingLoginMain, &chequingLogin, sizeof(chequingLogin));
            memcpy(&savingsLoginMain, &savingsLogin, sizeof(savingsLogin));




            /*
            ui->stackedWidget->setCurrentIndex(8);
            double balance = chequingLoginMain.getAccountBalance();
            QString balancestr = QString::number(balance);
            ui->ChequingBalance_label->setText(balancestr);
            */
            QMessageBox::information(
                        this,
                        tr("Sign In"),
                        tr("Account creation is completed."));

            ui->FirstName_lineEdit->clear();
            ui->LastName_lineEdit->clear();
            ui->UserName_lineEdit->clear();
            ui->NewPassword_lineEdit->clear();
            ui->ConfirmPassword_lineEdit->clear();
            ui->Email_lineEdit->clear();
            ui->Street_lineEdit->clear();
            ui->City_lineEdit->clear();
            ui->Province_lineEdit->clear();
            ui->PostalCode_lineEdit->clear();
            ui->Phone_lineEdit->clear();

            ui->stackedWidget->setCurrentIndex(0);
        }
        else
        {
            QMessageBox::warning(this, "Sign up", "Create account is unsuccessful.");
        }


    }
    else
    {
        QMessageBox::critical(
                    this,
                    tr("Error"),
                    tr("All fields are not filled."));
    }


}

void ClientApp::on_Logout_pushButton_8_clicked()
{
    int logoffSize = sizeof(chequingLoginMain);

    Packet logoffPacket(&chequingLoginMain, logoffSize, 8, 1);

    int totalSize = 0;
    char* rxBuffer = new char[500];
    char* txBuffer = new char[500];

    txBuffer = logoffPacket.serialize(totalSize);

    EarnLogging::ConnectionLog sendLog(&logoffPacket, EarnLogging::CLIENTSYSTEM, EarnLogging::SEND, "Sending request for account log off");
    testLogger.logData(&sendLog);

    socket->write(txBuffer, totalSize);    //send
    socket->flush();

    socket->waitForReadyRead();
    int num = socket->read(rxBuffer, 500);  //recv

    Packet checkStatus(rxBuffer);

    EarnLogging::ConnectionLog recvLog(&checkStatus, EarnLogging::CLIENTSYSTEM, EarnLogging::RECEIVE, "Recving response for account log off");
    testLogger.logData(&recvLog);

    int status = checkStatus.getStatus();

    if (status == 1) {

        ui->stackedWidget->setCurrentIndex(0);
    }
    else
    {
        qDebug("Logoff unsuccesful, please try again");
    }

}

void ClientApp::on_BackToMenu_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientApp::on_ViewBalance_pushButton_clicked()
{
    ui->ChequingBalance_label->setText(QString::number(chequingLoginMain.getAccountBalance()));
    ui->SavingBalance_label->setText(QString::number(savingsLoginMain.getAccountBalance()));

    ui->stackedWidget->setCurrentIndex(10);
}

