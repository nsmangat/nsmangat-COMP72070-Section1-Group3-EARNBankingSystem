/********************************************************************************
** Form generated from reading UI file 'clientapp.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTAPP_H
#define UI_CLIENTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientApp
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page2_Login;
    QLabel *Login_label;
    QLabel *CarNum_label;
    QLabel *PassWord_label;
    QPushButton *Login_pushButton;
    QLineEdit *CardNum_lineEdit;
    QLineEdit *Password_lineEdit;
    QPushButton *Signin_pushButton;
    QPushButton *ResetPassword_pushButton;
    QWidget *Reset_page;
    QLabel *Login_label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *cardNum_label;
    QLineEdit *cardNum_lineEdit_1;
    QLabel *email_label;
    QLineEdit *email_lineEdit;
    QPushButton *SendResetLink_pushButton;
    QPushButton *BackToLogin_pushButton;
    QWidget *page3_Signup;
    QLabel *SignupMsg_label;
    QLabel *Signup_label;
    QPushButton *BackToLogin_pushButton_2;
    QWidget *page4_Menu;
    QPushButton *ViewStatement_pushButton;
    QPushButton *Transfer_pushButton;
    QPushButton *AddAcc_pushButton;
    QPushButton *Deposit_pushButton;
    QPushButton *ViewAcc_pushButton;
    QLabel *Menu_label;
    QPushButton *Logout_pushButton;
    QWidget *page5_Statments;
    QLabel *ViewStatement_label;
    QPushButton *Logout_pushButton_2;
    QPushButton *BackToMenu_pushButton;
    QLabel *labelImage;
    QPushButton *ImageDisplayPushButton;
    QWidget *page6_Transfer;
    QLabel *Transfer_label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ToMyAcc_pushButton;
    QPushButton *ToOtherPeople_pushButton;
    QLineEdit *From_lineEdit;
    QLineEdit *To_lineEdit;
    QLineEdit *Amount_lineEdit;
    QLabel *From_label;
    QLabel *To_label;
    QLabel *Amount_label;
    QPushButton *Send_pushButton;
    QPushButton *BackToMenu_pushButton_2;
    QPushButton *Logout_pushButton_3;
    QWidget *page7_Deposit;
    QLabel *Deposit_label;
    QLabel *Frontpage_label;
    QPushButton *pushButton_3;
    QLabel *DepositComplete_label;
    QLabel *Frontpage_label_2;
    QPushButton *Logout_pushButton_4;
    QPushButton *BackToMenu_pushButton_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *AddFrontpage_pushButton;
    QPushButton *AddBackPage_pushButton;
    QLineEdit *lineEdit;
    QLabel *Frontpage_label_3;
    QLabel *Frontpage_label_4;
    QLineEdit *lineEdit_2;
    QWidget *page8_AddAcc;
    QLabel *AddAcc_label;
    QCheckBox *SavingAcc_checkBox;
    QCheckBox *InvestingAcc_checkBox;
    QPushButton *Logout_pushButton_5;
    QPushButton *BackToMenu_pushButton_4;
    QWidget *page9_MyAcc;
    QLabel *MyAcc_label;
    QPushButton *Logout_pushButton_6;
    QPushButton *BackToMenu_pushButton_5;

    void setupUi(QWidget *ClientApp)
    {
        if (ClientApp->objectName().isEmpty())
            ClientApp->setObjectName(QString::fromUtf8("ClientApp"));
        ClientApp->resize(800, 600);
        gridLayout = new QGridLayout(ClientApp);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(ClientApp);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("color:white;"));
        stackedWidget->setMidLineWidth(-5);
        page2_Login = new QWidget();
        page2_Login->setObjectName(QString::fromUtf8("page2_Login"));
        page2_Login->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)\n"
""));
        Login_label = new QLabel(page2_Login);
        Login_label->setObjectName(QString::fromUtf8("Login_label"));
        Login_label->setGeometry(QRect(330, 40, 101, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        Login_label->setFont(font);
        CarNum_label = new QLabel(page2_Login);
        CarNum_label->setObjectName(QString::fromUtf8("CarNum_label"));
        CarNum_label->setGeometry(QRect(170, 160, 151, 31));
        QFont font1;
        font1.setPointSize(14);
        CarNum_label->setFont(font1);
        PassWord_label = new QLabel(page2_Login);
        PassWord_label->setObjectName(QString::fromUtf8("PassWord_label"));
        PassWord_label->setGeometry(QRect(170, 280, 151, 21));
        PassWord_label->setFont(font1);
        Login_pushButton = new QPushButton(page2_Login);
        Login_pushButton->setObjectName(QString::fromUtf8("Login_pushButton"));
        Login_pushButton->setGeometry(QRect(310, 400, 121, 51));
        QFont font2;
        font2.setPointSize(12);
        Login_pushButton->setFont(font2);
        CardNum_lineEdit = new QLineEdit(page2_Login);
        CardNum_lineEdit->setObjectName(QString::fromUtf8("CardNum_lineEdit"));
        CardNum_lineEdit->setGeometry(QRect(170, 200, 401, 51));
        Password_lineEdit = new QLineEdit(page2_Login);
        Password_lineEdit->setObjectName(QString::fromUtf8("Password_lineEdit"));
        Password_lineEdit->setGeometry(QRect(170, 310, 401, 51));
        Signin_pushButton = new QPushButton(page2_Login);
        Signin_pushButton->setObjectName(QString::fromUtf8("Signin_pushButton"));
        Signin_pushButton->setGeometry(QRect(290, 500, 171, 31));
        QFont font3;
        font3.setUnderline(true);
        Signin_pushButton->setFont(font3);
        ResetPassword_pushButton = new QPushButton(page2_Login);
        ResetPassword_pushButton->setObjectName(QString::fromUtf8("ResetPassword_pushButton"));
        ResetPassword_pushButton->setGeometry(QRect(440, 280, 131, 21));
        ResetPassword_pushButton->setFont(font3);
        stackedWidget->addWidget(page2_Login);
        Reset_page = new QWidget();
        Reset_page->setObjectName(QString::fromUtf8("Reset_page"));
        Reset_page->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)\n"
""));
        Login_label_2 = new QLabel(Reset_page);
        Login_label_2->setObjectName(QString::fromUtf8("Login_label_2"));
        Login_label_2->setGeometry(QRect(260, 60, 271, 51));
        Login_label_2->setFont(font);
        gridLayoutWidget = new QWidget(Reset_page);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(170, 170, 401, 211));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        cardNum_label = new QLabel(gridLayoutWidget);
        cardNum_label->setObjectName(QString::fromUtf8("cardNum_label"));

        gridLayout_2->addWidget(cardNum_label, 0, 0, 1, 1);

        cardNum_lineEdit_1 = new QLineEdit(gridLayoutWidget);
        cardNum_lineEdit_1->setObjectName(QString::fromUtf8("cardNum_lineEdit_1"));

        gridLayout_2->addWidget(cardNum_lineEdit_1, 0, 1, 1, 1);

        email_label = new QLabel(gridLayoutWidget);
        email_label->setObjectName(QString::fromUtf8("email_label"));

        gridLayout_2->addWidget(email_label, 1, 0, 1, 1);

        email_lineEdit = new QLineEdit(gridLayoutWidget);
        email_lineEdit->setObjectName(QString::fromUtf8("email_lineEdit"));

        gridLayout_2->addWidget(email_lineEdit, 1, 1, 1, 1);

        SendResetLink_pushButton = new QPushButton(Reset_page);
        SendResetLink_pushButton->setObjectName(QString::fromUtf8("SendResetLink_pushButton"));
        SendResetLink_pushButton->setGeometry(QRect(280, 440, 201, 51));
        BackToLogin_pushButton = new QPushButton(Reset_page);
        BackToLogin_pushButton->setObjectName(QString::fromUtf8("BackToLogin_pushButton"));
        BackToLogin_pushButton->setGeometry(QRect(30, 20, 111, 29));
        stackedWidget->addWidget(Reset_page);
        page3_Signup = new QWidget();
        page3_Signup->setObjectName(QString::fromUtf8("page3_Signup"));
        page3_Signup->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)\n"
""));
        SignupMsg_label = new QLabel(page3_Signup);
        SignupMsg_label->setObjectName(QString::fromUtf8("SignupMsg_label"));
        SignupMsg_label->setGeometry(QRect(70, 230, 681, 121));
        SignupMsg_label->setFont(font2);
        SignupMsg_label->setContextMenuPolicy(Qt::ActionsContextMenu);
        Signup_label = new QLabel(page3_Signup);
        Signup_label->setObjectName(QString::fromUtf8("Signup_label"));
        Signup_label->setGeometry(QRect(310, 40, 151, 71));
        Signup_label->setFont(font);
        BackToLogin_pushButton_2 = new QPushButton(page3_Signup);
        BackToLogin_pushButton_2->setObjectName(QString::fromUtf8("BackToLogin_pushButton_2"));
        BackToLogin_pushButton_2->setGeometry(QRect(40, 30, 111, 29));
        stackedWidget->addWidget(page3_Signup);
        page4_Menu = new QWidget();
        page4_Menu->setObjectName(QString::fromUtf8("page4_Menu"));
        page4_Menu->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)\n"
""));
        ViewStatement_pushButton = new QPushButton(page4_Menu);
        ViewStatement_pushButton->setObjectName(QString::fromUtf8("ViewStatement_pushButton"));
        ViewStatement_pushButton->setGeometry(QRect(190, 170, 171, 91));
        ViewStatement_pushButton->setFont(font2);
        Transfer_pushButton = new QPushButton(page4_Menu);
        Transfer_pushButton->setObjectName(QString::fromUtf8("Transfer_pushButton"));
        Transfer_pushButton->setGeometry(QRect(420, 170, 171, 91));
        Transfer_pushButton->setFont(font2);
        AddAcc_pushButton = new QPushButton(page4_Menu);
        AddAcc_pushButton->setObjectName(QString::fromUtf8("AddAcc_pushButton"));
        AddAcc_pushButton->setGeometry(QRect(420, 280, 171, 91));
        AddAcc_pushButton->setFont(font2);
        Deposit_pushButton = new QPushButton(page4_Menu);
        Deposit_pushButton->setObjectName(QString::fromUtf8("Deposit_pushButton"));
        Deposit_pushButton->setGeometry(QRect(190, 280, 171, 91));
        Deposit_pushButton->setFont(font2);
        ViewAcc_pushButton = new QPushButton(page4_Menu);
        ViewAcc_pushButton->setObjectName(QString::fromUtf8("ViewAcc_pushButton"));
        ViewAcc_pushButton->setGeometry(QRect(290, 400, 171, 91));
        ViewAcc_pushButton->setFont(font2);
        Menu_label = new QLabel(page4_Menu);
        Menu_label->setObjectName(QString::fromUtf8("Menu_label"));
        Menu_label->setGeometry(QRect(350, 50, 101, 51));
        Menu_label->setFont(font);
        Logout_pushButton = new QPushButton(page4_Menu);
        Logout_pushButton->setObjectName(QString::fromUtf8("Logout_pushButton"));
        Logout_pushButton->setGeometry(QRect(670, 30, 83, 29));
        stackedWidget->addWidget(page4_Menu);
        page5_Statments = new QWidget();
        page5_Statments->setObjectName(QString::fromUtf8("page5_Statments"));
        page5_Statments->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)\n"
""));
        ViewStatement_label = new QLabel(page5_Statments);
        ViewStatement_label->setObjectName(QString::fromUtf8("ViewStatement_label"));
        ViewStatement_label->setGeometry(QRect(210, 40, 351, 61));
        ViewStatement_label->setFont(font);
        Logout_pushButton_2 = new QPushButton(page5_Statments);
        Logout_pushButton_2->setObjectName(QString::fromUtf8("Logout_pushButton_2"));
        Logout_pushButton_2->setGeometry(QRect(680, 30, 83, 29));
        BackToMenu_pushButton = new QPushButton(page5_Statments);
        BackToMenu_pushButton->setObjectName(QString::fromUtf8("BackToMenu_pushButton"));
        BackToMenu_pushButton->setGeometry(QRect(20, 30, 111, 29));
        labelImage = new QLabel(page5_Statments);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(140, 170, 491, 341));
        labelImage->setFrameShape(QFrame::WinPanel);
        labelImage->setFrameShadow(QFrame::Sunken);
        labelImage->setScaledContents(true);
        ImageDisplayPushButton = new QPushButton(page5_Statments);
        ImageDisplayPushButton->setObjectName(QString::fromUtf8("ImageDisplayPushButton"));
        ImageDisplayPushButton->setGeometry(QRect(310, 118, 141, 31));
        stackedWidget->addWidget(page5_Statments);
        page6_Transfer = new QWidget();
        page6_Transfer->setObjectName(QString::fromUtf8("page6_Transfer"));
        page6_Transfer->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)\n"
""));
        Transfer_label = new QLabel(page6_Transfer);
        Transfer_label->setObjectName(QString::fromUtf8("Transfer_label"));
        Transfer_label->setGeometry(QRect(320, 50, 141, 41));
        Transfer_label->setFont(font);
        horizontalLayoutWidget = new QWidget(page6_Transfer);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 120, 621, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ToMyAcc_pushButton = new QPushButton(horizontalLayoutWidget);
        ToMyAcc_pushButton->setObjectName(QString::fromUtf8("ToMyAcc_pushButton"));

        horizontalLayout->addWidget(ToMyAcc_pushButton);

        ToOtherPeople_pushButton = new QPushButton(horizontalLayoutWidget);
        ToOtherPeople_pushButton->setObjectName(QString::fromUtf8("ToOtherPeople_pushButton"));

        horizontalLayout->addWidget(ToOtherPeople_pushButton);

        From_lineEdit = new QLineEdit(page6_Transfer);
        From_lineEdit->setObjectName(QString::fromUtf8("From_lineEdit"));
        From_lineEdit->setGeometry(QRect(160, 230, 451, 51));
        To_lineEdit = new QLineEdit(page6_Transfer);
        To_lineEdit->setObjectName(QString::fromUtf8("To_lineEdit"));
        To_lineEdit->setGeometry(QRect(160, 320, 451, 51));
        Amount_lineEdit = new QLineEdit(page6_Transfer);
        Amount_lineEdit->setObjectName(QString::fromUtf8("Amount_lineEdit"));
        Amount_lineEdit->setGeometry(QRect(160, 410, 451, 51));
        From_label = new QLabel(page6_Transfer);
        From_label->setObjectName(QString::fromUtf8("From_label"));
        From_label->setGeometry(QRect(160, 210, 63, 20));
        To_label = new QLabel(page6_Transfer);
        To_label->setObjectName(QString::fromUtf8("To_label"));
        To_label->setGeometry(QRect(160, 300, 63, 20));
        Amount_label = new QLabel(page6_Transfer);
        Amount_label->setObjectName(QString::fromUtf8("Amount_label"));
        Amount_label->setGeometry(QRect(160, 390, 71, 20));
        Send_pushButton = new QPushButton(page6_Transfer);
        Send_pushButton->setObjectName(QString::fromUtf8("Send_pushButton"));
        Send_pushButton->setGeometry(QRect(600, 510, 101, 31));
        Send_pushButton->setFont(font2);
        BackToMenu_pushButton_2 = new QPushButton(page6_Transfer);
        BackToMenu_pushButton_2->setObjectName(QString::fromUtf8("BackToMenu_pushButton_2"));
        BackToMenu_pushButton_2->setGeometry(QRect(30, 30, 111, 29));
        Logout_pushButton_3 = new QPushButton(page6_Transfer);
        Logout_pushButton_3->setObjectName(QString::fromUtf8("Logout_pushButton_3"));
        Logout_pushButton_3->setGeometry(QRect(670, 30, 83, 29));
        stackedWidget->addWidget(page6_Transfer);
        page7_Deposit = new QWidget();
        page7_Deposit->setObjectName(QString::fromUtf8("page7_Deposit"));
        page7_Deposit->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)"));
        Deposit_label = new QLabel(page7_Deposit);
        Deposit_label->setObjectName(QString::fromUtf8("Deposit_label"));
        Deposit_label->setGeometry(QRect(320, 50, 141, 41));
        Deposit_label->setFont(font);
        Frontpage_label = new QLabel(page7_Deposit);
        Frontpage_label->setObjectName(QString::fromUtf8("Frontpage_label"));
        Frontpage_label->setGeometry(QRect(60, 170, 231, 31));
        QFont font4;
        font4.setPointSize(10);
        Frontpage_label->setFont(font4);
        pushButton_3 = new QPushButton(page7_Deposit);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(660, 520, 91, 31));
        QFont font5;
        font5.setPointSize(11);
        pushButton_3->setFont(font5);
        DepositComplete_label = new QLabel(page7_Deposit);
        DepositComplete_label->setObjectName(QString::fromUtf8("DepositComplete_label"));
        DepositComplete_label->setGeometry(QRect(310, 100, 161, 21));
        DepositComplete_label->setFont(font4);
        DepositComplete_label->setLayoutDirection(Qt::LeftToRight);
        DepositComplete_label->setStyleSheet(QString::fromUtf8("color: rgb(255, 238, 106);"));
        DepositComplete_label->setAlignment(Qt::AlignCenter);
        DepositComplete_label->setIndent(0);
        Frontpage_label_2 = new QLabel(page7_Deposit);
        Frontpage_label_2->setObjectName(QString::fromUtf8("Frontpage_label_2"));
        Frontpage_label_2->setGeometry(QRect(60, 250, 201, 31));
        Frontpage_label_2->setFont(font4);
        Logout_pushButton_4 = new QPushButton(page7_Deposit);
        Logout_pushButton_4->setObjectName(QString::fromUtf8("Logout_pushButton_4"));
        Logout_pushButton_4->setGeometry(QRect(670, 30, 83, 29));
        BackToMenu_pushButton_3 = new QPushButton(page7_Deposit);
        BackToMenu_pushButton_3->setObjectName(QString::fromUtf8("BackToMenu_pushButton_3"));
        BackToMenu_pushButton_3->setGeometry(QRect(30, 30, 111, 29));
        verticalLayoutWidget = new QWidget(page7_Deposit);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(290, 140, 451, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        AddFrontpage_pushButton = new QPushButton(verticalLayoutWidget);
        AddFrontpage_pushButton->setObjectName(QString::fromUtf8("AddFrontpage_pushButton"));
        AddFrontpage_pushButton->setFont(font);
        AddFrontpage_pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(200, 200, 200);"));

        verticalLayout->addWidget(AddFrontpage_pushButton);

        AddBackPage_pushButton = new QPushButton(verticalLayoutWidget);
        AddBackPage_pushButton->setObjectName(QString::fromUtf8("AddBackPage_pushButton"));
        AddBackPage_pushButton->setFont(font);
        AddBackPage_pushButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(200, 200, 200);"));

        verticalLayout->addWidget(AddBackPage_pushButton);

        lineEdit = new QLineEdit(page7_Deposit);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(290, 420, 113, 28));
        Frontpage_label_3 = new QLabel(page7_Deposit);
        Frontpage_label_3->setObjectName(QString::fromUtf8("Frontpage_label_3"));
        Frontpage_label_3->setGeometry(QRect(60, 420, 71, 31));
        Frontpage_label_3->setFont(font4);
        Frontpage_label_4 = new QLabel(page7_Deposit);
        Frontpage_label_4->setObjectName(QString::fromUtf8("Frontpage_label_4"));
        Frontpage_label_4->setGeometry(QRect(60, 360, 71, 31));
        Frontpage_label_4->setFont(font4);
        lineEdit_2 = new QLineEdit(page7_Deposit);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(290, 360, 113, 28));
        stackedWidget->addWidget(page7_Deposit);
        page8_AddAcc = new QWidget();
        page8_AddAcc->setObjectName(QString::fromUtf8("page8_AddAcc"));
        page8_AddAcc->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)"));
        AddAcc_label = new QLabel(page8_AddAcc);
        AddAcc_label->setObjectName(QString::fromUtf8("AddAcc_label"));
        AddAcc_label->setGeometry(QRect(220, 50, 331, 41));
        AddAcc_label->setFont(font);
        SavingAcc_checkBox = new QCheckBox(page8_AddAcc);
        SavingAcc_checkBox->setObjectName(QString::fromUtf8("SavingAcc_checkBox"));
        SavingAcc_checkBox->setGeometry(QRect(230, 180, 171, 26));
        SavingAcc_checkBox->setFont(font2);
        InvestingAcc_checkBox = new QCheckBox(page8_AddAcc);
        InvestingAcc_checkBox->setObjectName(QString::fromUtf8("InvestingAcc_checkBox"));
        InvestingAcc_checkBox->setGeometry(QRect(230, 250, 191, 26));
        InvestingAcc_checkBox->setFont(font2);
        Logout_pushButton_5 = new QPushButton(page8_AddAcc);
        Logout_pushButton_5->setObjectName(QString::fromUtf8("Logout_pushButton_5"));
        Logout_pushButton_5->setGeometry(QRect(660, 30, 83, 29));
        BackToMenu_pushButton_4 = new QPushButton(page8_AddAcc);
        BackToMenu_pushButton_4->setObjectName(QString::fromUtf8("BackToMenu_pushButton_4"));
        BackToMenu_pushButton_4->setGeometry(QRect(30, 30, 111, 29));
        stackedWidget->addWidget(page8_AddAcc);
        page9_MyAcc = new QWidget();
        page9_MyAcc->setObjectName(QString::fromUtf8("page9_MyAcc"));
        page9_MyAcc->setStyleSheet(QString::fromUtf8("\n"
"background-color:rgb(47, 47, 47)"));
        MyAcc_label = new QLabel(page9_MyAcc);
        MyAcc_label->setObjectName(QString::fromUtf8("MyAcc_label"));
        MyAcc_label->setGeometry(QRect(280, 60, 211, 41));
        MyAcc_label->setFont(font);
        Logout_pushButton_6 = new QPushButton(page9_MyAcc);
        Logout_pushButton_6->setObjectName(QString::fromUtf8("Logout_pushButton_6"));
        Logout_pushButton_6->setGeometry(QRect(660, 40, 83, 29));
        BackToMenu_pushButton_5 = new QPushButton(page9_MyAcc);
        BackToMenu_pushButton_5->setObjectName(QString::fromUtf8("BackToMenu_pushButton_5"));
        BackToMenu_pushButton_5->setGeometry(QRect(30, 40, 111, 29));
        stackedWidget->addWidget(page9_MyAcc);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);


        retranslateUi(ClientApp);

        QMetaObject::connectSlotsByName(ClientApp);
    } // setupUi

    void retranslateUi(QWidget *ClientApp)
    {
        ClientApp->setWindowTitle(QCoreApplication::translate("ClientApp", "ClientApp", nullptr));
        Login_label->setText(QCoreApplication::translate("ClientApp", "Login", nullptr));
        CarNum_label->setText(QCoreApplication::translate("ClientApp", "Card Number:", nullptr));
        PassWord_label->setText(QCoreApplication::translate("ClientApp", "Password:", nullptr));
        Login_pushButton->setText(QCoreApplication::translate("ClientApp", "Login", nullptr));
        Signin_pushButton->setText(QCoreApplication::translate("ClientApp", "Don't have an account?", nullptr));
        ResetPassword_pushButton->setText(QCoreApplication::translate("ClientApp", "Forgot password?", nullptr));
        Login_label_2->setText(QCoreApplication::translate("ClientApp", "Reset Password", nullptr));
        cardNum_label->setText(QCoreApplication::translate("ClientApp", "Card Number:", nullptr));
        email_label->setText(QCoreApplication::translate("ClientApp", "Email:", nullptr));
        SendResetLink_pushButton->setText(QCoreApplication::translate("ClientApp", "Send reset link", nullptr));
        BackToLogin_pushButton->setText(QCoreApplication::translate("ClientApp", "Back to Login", nullptr));
        SignupMsg_label->setText(QCoreApplication::translate("ClientApp", "Online signing up is currently unavailable. \n"
"Please go to a nearest bank branch to open a new account with our assistants.", nullptr));
        Signup_label->setText(QCoreApplication::translate("ClientApp", "Sign up", nullptr));
        BackToLogin_pushButton_2->setText(QCoreApplication::translate("ClientApp", "Back to Login", nullptr));
        ViewStatement_pushButton->setText(QCoreApplication::translate("ClientApp", "View Statements", nullptr));
        Transfer_pushButton->setText(QCoreApplication::translate("ClientApp", "Transfers", nullptr));
        AddAcc_pushButton->setText(QCoreApplication::translate("ClientApp", "Add account", nullptr));
        Deposit_pushButton->setText(QCoreApplication::translate("ClientApp", "Deposit", nullptr));
        ViewAcc_pushButton->setText(QCoreApplication::translate("ClientApp", "My account", nullptr));
        Menu_label->setText(QCoreApplication::translate("ClientApp", "Menu", nullptr));
        Logout_pushButton->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        ViewStatement_label->setText(QCoreApplication::translate("ClientApp", "Account's Activities", nullptr));
        Logout_pushButton_2->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        labelImage->setText(QString());
        ImageDisplayPushButton->setText(QCoreApplication::translate("ClientApp", "Display Statments", nullptr));
        Transfer_label->setText(QCoreApplication::translate("ClientApp", "Transfer", nullptr));
        ToMyAcc_pushButton->setText(QCoreApplication::translate("ClientApp", "To My Account", nullptr));
        ToOtherPeople_pushButton->setText(QCoreApplication::translate("ClientApp", "To Other People", nullptr));
        From_label->setText(QCoreApplication::translate("ClientApp", "FROM:", nullptr));
        To_label->setText(QCoreApplication::translate("ClientApp", "TO:", nullptr));
        Amount_label->setText(QCoreApplication::translate("ClientApp", "AMOUNT:", nullptr));
        Send_pushButton->setText(QCoreApplication::translate("ClientApp", "Send", nullptr));
        BackToMenu_pushButton_2->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        Logout_pushButton_3->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        Deposit_label->setText(QCoreApplication::translate("ClientApp", "Deposit", nullptr));
        Frontpage_label->setText(QCoreApplication::translate("ClientApp", "Front page of the cheque:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("ClientApp", "Done", nullptr));
        DepositComplete_label->setText(QCoreApplication::translate("ClientApp", "Deposit Completed", nullptr));
        Frontpage_label_2->setText(QCoreApplication::translate("ClientApp", "Back page of the cheque:", nullptr));
        Logout_pushButton_4->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton_3->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        AddFrontpage_pushButton->setText(QCoreApplication::translate("ClientApp", "+", nullptr));
        AddBackPage_pushButton->setText(QCoreApplication::translate("ClientApp", "+", nullptr));
        Frontpage_label_3->setText(QCoreApplication::translate("ClientApp", "Amount:", nullptr));
        Frontpage_label_4->setText(QCoreApplication::translate("ClientApp", "Account:", nullptr));
        AddAcc_label->setText(QCoreApplication::translate("ClientApp", "Add New Accounts", nullptr));
        SavingAcc_checkBox->setText(QCoreApplication::translate("ClientApp", "Saving Account", nullptr));
        InvestingAcc_checkBox->setText(QCoreApplication::translate("ClientApp", "Investing Account", nullptr));
        Logout_pushButton_5->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton_4->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        MyAcc_label->setText(QCoreApplication::translate("ClientApp", "My Account", nullptr));
        Logout_pushButton_6->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton_5->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientApp: public Ui_ClientApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTAPP_H
