#define _CRT_SECURE_NO_WARNINGS
#ifndef CLIENTAPP_H
#define CLIENTAPP_H
#include <cstring>
#include <QWidget>
#include <QInputDialog>
#include <QLineEdit>
#include <QPixmap>
#include <QFileDialog>
#include <QThread>
#include <iostream>
#include <string>
#include "../EARNNetworkAPI/DataTypes.h"
#include "../EARNNetworkAPI/Packet.h"
#include <QFile>
#include <QTextStream>
#include "../EARNNetworkAPI/EARNStructs.h"
//#include "../EARNClientTerminal/ClientFunctions.h"
#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QtNetwork/QHostAddress>
#include "../EARNNetworkAPI/EARNLogger.h"
#include "../EARNNetworkAPI/EARNStructs.h"
extern AccountInformation chequingLoginMain;
extern AccountInformation savingsLoginMain;


//QT_BEGIN_NAMESPACE
namespace Ui { class ClientApp; }
//QT_END_NAMESPACE

class ClientApp : public QWidget
{
    Q_OBJECT

public:
    explicit ClientApp(QWidget* parent = 0);
    void connectServer();
    ~ClientApp();
private:
    Ui::ClientApp *ui;
    QTcpSocket *socket;

private slots:

    void display_Balance();
    void socket_Read_Data();

   void on_BackToMenu_pushButton_6_clicked();

    void on_Login_pushButton_clicked();

    //void on_pushButton_4_clicked();

    void on_SendResetLink_pushButton_clicked();

    void on_BackToLogin_pushButton_clicked();

    void on_BackToLogin_pushButton_2_clicked();

    void on_ResetPassword_pushButton_clicked();

    void on_Signin_pushButton_clicked();

    void on_Logout_pushButton_clicked();

    void on_ViewStatement_pushButton_clicked();

    void on_E_Transfer_pushButton_clicked();

    void on_Deposit_pushButton_clicked();

    void on_AddAcc_pushButton_clicked();

    void on_ViewAcc_pushButton_clicked();

    void on_BackToMenu_pushButton_4_clicked();

    void on_Logout_pushButton_5_clicked();

    void on_ImageDisplayPushButton_clicked();

    void on_BackToMenu_pushButton_clicked();

    void on_Logout_pushButton_2_clicked();

    //void on_ToOtherPeople_pushButton_clicked();

//    void on_ToMyAcc_pushButton_pressed();

    void on_BackToMenu_pushButton_2_clicked();

    void on_Logout_pushButton_3_clicked();

    void on_Send_pushButton_clicked();

    void on_BackToMenu_pushButton_3_clicked();

    void on_Logout_pushButton_4_clicked();

    void on_DepositComplete_pushButton_clicked();


    void on_AddFrontpage_pushButton_clicked();

    void on_AddBackpage_pushButton_clicked();

    void on_InvestingAcc_checkBox_stateChanged(int arg1);

    void display_Account_Info();

    void on_BackToMenu_pushButton_5_clicked();

    void on_Logout_pushButton_6_clicked();

    void on_Transfer_pushButton_clicked();

    void on_Logout_pushButton_7_clicked();

    void on_Send_pushButton_2_clicked();

    void on_Signup_pushButton_clicked();


    void on_Logout_pushButton_8_clicked();
    void on_BackToMenu_pushButton_7_clicked();
    void on_ViewBalance_pushButton_clicked();
};
#endif // CLIENTAPP_H
