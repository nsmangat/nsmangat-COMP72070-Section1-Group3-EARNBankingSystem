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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
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
    QLabel *email_label;
    QLineEdit *email_lineEdit;
    QPushButton *SendResetLink_pushButton;
    QPushButton *BackToLogin_pushButton;
    QWidget *page3_Signup;
    QLabel *Signup_label;
    QPushButton *BackToLogin_pushButton_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_4;
    QLabel *NewPassword_label;
    QLabel *Phone_label;
    QLabel *PostalCode_label;
    QLabel *Email_label_2;
    QLabel *City_label;
    QLabel *LastName_label;
    QLabel *Street_label;
    QLabel *UserName_label;
    QLabel *FirstName_label;
    QLabel *ConfirmPassword_label;
    QLabel *Province_label;
    QLineEdit *FirstName_lineEdit;
    QLineEdit *LastName_lineEdit;
    QLineEdit *UserName_lineEdit;
    QLineEdit *NewPassword_lineEdit;
    QLineEdit *ConfirmPassword_lineEdit;
    QLineEdit *Email_lineEdit;
    QLineEdit *Phone_lineEdit;
    QLineEdit *Street_lineEdit;
    QLineEdit *City_lineEdit;
    QLineEdit *Province_lineEdit;
    QLineEdit *PostalCode_lineEdit;
    QPushButton *Signup_pushButton;
    QWidget *page4_Menu;
    QPushButton *ViewStatement_pushButton;
    QPushButton *E_Transfer_pushButton;
    QPushButton *AddAcc_pushButton;
    QPushButton *Deposit_pushButton;
    QPushButton *ViewAcc_pushButton;
    QLabel *Menu_label;
    QPushButton *Logout_pushButton;
    QPushButton *Transfer_pushButton;
    QPushButton *ViewBalance_pushButton;
    QWidget *page5_Statments;
    QLabel *ViewStatement_label;
    QPushButton *Logout_pushButton_2;
    QPushButton *BackToMenu_pushButton;
    QLabel *labelImage;
    QPushButton *ImageDisplayPushButton;
    QWidget *page6_ETransfer;
    QLabel *Transfer_label;
    QLabel *From_label;
    QLabel *To_label;
    QLabel *Amount_label;
    QPushButton *Send_pushButton;
    QPushButton *BackToMenu_pushButton_2;
    QPushButton *Logout_pushButton_3;
    QComboBox *From_comboBox;
    QLineEdit *Amount_lineEdit;
    QLineEdit *To_lineEdit;
    QWidget *page7_Deposit;
    QLabel *Deposit_label;
    QLabel *Frontpage_label;
    QPushButton *DepositComplete_pushButton;
    QLabel *Backpage_label_2;
    QPushButton *Logout_pushButton_4;
    QPushButton *BackToMenu_pushButton_3;
    QLineEdit *Amount_lineEdit_2;
    QLabel *Amount_label_3;
    QLabel *AccType_label;
    QComboBox *AccType_comboBox;
    QLabel *FrontpageImage_label;
    QPushButton *AddFrontpage_pushButton;
    QLabel *BackpageImage_label;
    QPushButton *AddBackpage_pushButton;
    QWidget *page8_AddAcc;
    QLabel *AddAcc_label;
    QCheckBox *InvestingAcc_checkBox;
    QPushButton *Logout_pushButton_5;
    QPushButton *BackToMenu_pushButton_4;
    QWidget *page9_MyAcc;
    QLabel *MyAcc_label;
    QPushButton *Logout_pushButton_6;
    QPushButton *BackToMenu_pushButton_5;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *Address_label;
    QLabel *Name_label;
    QLabel *label_2;
    QLabel *PostalCode_label_2;
    QLabel *Email_label;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label;
    QLabel *PhoneNum_label;
    QWidget *page10_Transfer;
    QPushButton *BackToMenu_pushButton_6;
    QPushButton *Logout_pushButton_7;
    QLabel *Transfer_label_2;
    QLabel *From_label_2;
    QComboBox *From_comboBox_2;
    QLabel *To_label_2;
    QComboBox *To_comboBox;
    QLineEdit *Amount_lineEdit_3;
    QLabel *Amount_label_2;
    QPushButton *Send_pushButton_2;
    QWidget *page11_ViewBalance;
    QLabel *CurrentBalance_label_2;
    QPushButton *BackToMenu_pushButton_7;
    QPushButton *Logout_pushButton_8;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_5;
    QLabel *SavingBalance_label;
    QLabel *ChequingBalance_label;
    QLabel *label_12;
    QLabel *label_11;

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
"								background-color:rgb(47, 47, 47)\n"
"							"));
        Login_label = new QLabel(page2_Login);
        Login_label->setObjectName(QString::fromUtf8("Login_label"));
        Login_label->setGeometry(QRect(330, 40, 101, 51));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        Login_label->setFont(font);
        CarNum_label = new QLabel(page2_Login);
        CarNum_label->setObjectName(QString::fromUtf8("CarNum_label"));
        CarNum_label->setGeometry(QRect(170, 160, 281, 31));
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
"								background-color:rgb(47, 47, 47)\n"
"							"));
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
        email_label = new QLabel(gridLayoutWidget);
        email_label->setObjectName(QString::fromUtf8("email_label"));

        gridLayout_2->addWidget(email_label, 0, 0, 1, 1);

        email_lineEdit = new QLineEdit(gridLayoutWidget);
        email_lineEdit->setObjectName(QString::fromUtf8("email_lineEdit"));

        gridLayout_2->addWidget(email_lineEdit, 0, 1, 1, 1);

        SendResetLink_pushButton = new QPushButton(Reset_page);
        SendResetLink_pushButton->setObjectName(QString::fromUtf8("SendResetLink_pushButton"));
        SendResetLink_pushButton->setGeometry(QRect(280, 400, 201, 51));
        BackToLogin_pushButton = new QPushButton(Reset_page);
        BackToLogin_pushButton->setObjectName(QString::fromUtf8("BackToLogin_pushButton"));
        BackToLogin_pushButton->setGeometry(QRect(50, 30, 111, 29));
        stackedWidget->addWidget(Reset_page);
        page3_Signup = new QWidget();
        page3_Signup->setObjectName(QString::fromUtf8("page3_Signup"));
        page3_Signup->setStyleSheet(QString::fromUtf8("\n"
"								background-color:rgb(47, 47, 47)\n"
"							"));
        Signup_label = new QLabel(page3_Signup);
        Signup_label->setObjectName(QString::fromUtf8("Signup_label"));
        Signup_label->setGeometry(QRect(330, 40, 141, 71));
        Signup_label->setFont(font);
        Signup_label->setAlignment(Qt::AlignCenter);
        BackToLogin_pushButton_2 = new QPushButton(page3_Signup);
        BackToLogin_pushButton_2->setObjectName(QString::fromUtf8("BackToLogin_pushButton_2"));
        BackToLogin_pushButton_2->setGeometry(QRect(40, 30, 111, 29));
        gridLayoutWidget_3 = new QWidget(page3_Signup);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(120, 120, 551, 380));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        NewPassword_label = new QLabel(gridLayoutWidget_3);
        NewPassword_label->setObjectName(QString::fromUtf8("NewPassword_label"));

        gridLayout_4->addWidget(NewPassword_label, 3, 0, 1, 1);

        Phone_label = new QLabel(gridLayoutWidget_3);
        Phone_label->setObjectName(QString::fromUtf8("Phone_label"));

        gridLayout_4->addWidget(Phone_label, 6, 0, 1, 1);

        PostalCode_label = new QLabel(gridLayoutWidget_3);
        PostalCode_label->setObjectName(QString::fromUtf8("PostalCode_label"));

        gridLayout_4->addWidget(PostalCode_label, 10, 0, 1, 1);

        Email_label_2 = new QLabel(gridLayoutWidget_3);
        Email_label_2->setObjectName(QString::fromUtf8("Email_label_2"));

        gridLayout_4->addWidget(Email_label_2, 5, 0, 1, 1);

        City_label = new QLabel(gridLayoutWidget_3);
        City_label->setObjectName(QString::fromUtf8("City_label"));

        gridLayout_4->addWidget(City_label, 8, 0, 1, 1);

        LastName_label = new QLabel(gridLayoutWidget_3);
        LastName_label->setObjectName(QString::fromUtf8("LastName_label"));

        gridLayout_4->addWidget(LastName_label, 1, 0, 1, 1);

        Street_label = new QLabel(gridLayoutWidget_3);
        Street_label->setObjectName(QString::fromUtf8("Street_label"));

        gridLayout_4->addWidget(Street_label, 7, 0, 1, 1);

        UserName_label = new QLabel(gridLayoutWidget_3);
        UserName_label->setObjectName(QString::fromUtf8("UserName_label"));

        gridLayout_4->addWidget(UserName_label, 2, 0, 1, 1);

        FirstName_label = new QLabel(gridLayoutWidget_3);
        FirstName_label->setObjectName(QString::fromUtf8("FirstName_label"));

        gridLayout_4->addWidget(FirstName_label, 0, 0, 1, 1);

        ConfirmPassword_label = new QLabel(gridLayoutWidget_3);
        ConfirmPassword_label->setObjectName(QString::fromUtf8("ConfirmPassword_label"));

        gridLayout_4->addWidget(ConfirmPassword_label, 4, 0, 1, 1);

        Province_label = new QLabel(gridLayoutWidget_3);
        Province_label->setObjectName(QString::fromUtf8("Province_label"));

        gridLayout_4->addWidget(Province_label, 9, 0, 1, 1);

        FirstName_lineEdit = new QLineEdit(gridLayoutWidget_3);
        FirstName_lineEdit->setObjectName(QString::fromUtf8("FirstName_lineEdit"));
        FirstName_lineEdit->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));

        gridLayout_4->addWidget(FirstName_lineEdit, 0, 2, 1, 1);

        LastName_lineEdit = new QLineEdit(gridLayoutWidget_3);
        LastName_lineEdit->setObjectName(QString::fromUtf8("LastName_lineEdit"));

        gridLayout_4->addWidget(LastName_lineEdit, 1, 2, 1, 1);

        UserName_lineEdit = new QLineEdit(gridLayoutWidget_3);
        UserName_lineEdit->setObjectName(QString::fromUtf8("UserName_lineEdit"));

        gridLayout_4->addWidget(UserName_lineEdit, 2, 2, 1, 1);

        NewPassword_lineEdit = new QLineEdit(gridLayoutWidget_3);
        NewPassword_lineEdit->setObjectName(QString::fromUtf8("NewPassword_lineEdit"));

        gridLayout_4->addWidget(NewPassword_lineEdit, 3, 2, 1, 1);

        ConfirmPassword_lineEdit = new QLineEdit(gridLayoutWidget_3);
        ConfirmPassword_lineEdit->setObjectName(QString::fromUtf8("ConfirmPassword_lineEdit"));

        gridLayout_4->addWidget(ConfirmPassword_lineEdit, 4, 2, 1, 1);

        Email_lineEdit = new QLineEdit(gridLayoutWidget_3);
        Email_lineEdit->setObjectName(QString::fromUtf8("Email_lineEdit"));

        gridLayout_4->addWidget(Email_lineEdit, 5, 2, 1, 1);

        Phone_lineEdit = new QLineEdit(gridLayoutWidget_3);
        Phone_lineEdit->setObjectName(QString::fromUtf8("Phone_lineEdit"));

        gridLayout_4->addWidget(Phone_lineEdit, 6, 2, 1, 1);

        Street_lineEdit = new QLineEdit(gridLayoutWidget_3);
        Street_lineEdit->setObjectName(QString::fromUtf8("Street_lineEdit"));

        gridLayout_4->addWidget(Street_lineEdit, 7, 2, 1, 1);

        City_lineEdit = new QLineEdit(gridLayoutWidget_3);
        City_lineEdit->setObjectName(QString::fromUtf8("City_lineEdit"));

        gridLayout_4->addWidget(City_lineEdit, 8, 2, 1, 1);

        Province_lineEdit = new QLineEdit(gridLayoutWidget_3);
        Province_lineEdit->setObjectName(QString::fromUtf8("Province_lineEdit"));

        gridLayout_4->addWidget(Province_lineEdit, 9, 2, 1, 1);

        PostalCode_lineEdit = new QLineEdit(gridLayoutWidget_3);
        PostalCode_lineEdit->setObjectName(QString::fromUtf8("PostalCode_lineEdit"));

        gridLayout_4->addWidget(PostalCode_lineEdit, 10, 2, 1, 1);

        Signup_pushButton = new QPushButton(page3_Signup);
        Signup_pushButton->setObjectName(QString::fromUtf8("Signup_pushButton"));
        Signup_pushButton->setGeometry(QRect(660, 520, 83, 29));
        stackedWidget->addWidget(page3_Signup);
        page4_Menu = new QWidget();
        page4_Menu->setObjectName(QString::fromUtf8("page4_Menu"));
        page4_Menu->setStyleSheet(QString::fromUtf8("\n"
"								background-color:rgb(47, 47, 47)\n"
"							"));
        ViewStatement_pushButton = new QPushButton(page4_Menu);
        ViewStatement_pushButton->setObjectName(QString::fromUtf8("ViewStatement_pushButton"));
        ViewStatement_pushButton->setGeometry(QRect(190, 170, 171, 61));
        ViewStatement_pushButton->setFont(font2);
        E_Transfer_pushButton = new QPushButton(page4_Menu);
        E_Transfer_pushButton->setObjectName(QString::fromUtf8("E_Transfer_pushButton"));
        E_Transfer_pushButton->setGeometry(QRect(420, 170, 171, 61));
        E_Transfer_pushButton->setFont(font2);
        AddAcc_pushButton = new QPushButton(page4_Menu);
        AddAcc_pushButton->setObjectName(QString::fromUtf8("AddAcc_pushButton"));
        AddAcc_pushButton->setGeometry(QRect(190, 330, 171, 61));
        AddAcc_pushButton->setFont(font2);
        Deposit_pushButton = new QPushButton(page4_Menu);
        Deposit_pushButton->setObjectName(QString::fromUtf8("Deposit_pushButton"));
        Deposit_pushButton->setGeometry(QRect(190, 250, 171, 61));
        Deposit_pushButton->setFont(font2);
        ViewAcc_pushButton = new QPushButton(page4_Menu);
        ViewAcc_pushButton->setObjectName(QString::fromUtf8("ViewAcc_pushButton"));
        ViewAcc_pushButton->setGeometry(QRect(420, 330, 171, 61));
        ViewAcc_pushButton->setFont(font2);
        Menu_label = new QLabel(page4_Menu);
        Menu_label->setObjectName(QString::fromUtf8("Menu_label"));
        Menu_label->setGeometry(QRect(350, 70, 101, 51));
        Menu_label->setFont(font);
        Logout_pushButton = new QPushButton(page4_Menu);
        Logout_pushButton->setObjectName(QString::fromUtf8("Logout_pushButton"));
        Logout_pushButton->setGeometry(QRect(670, 30, 83, 29));
        Transfer_pushButton = new QPushButton(page4_Menu);
        Transfer_pushButton->setObjectName(QString::fromUtf8("Transfer_pushButton"));
        Transfer_pushButton->setGeometry(QRect(420, 250, 171, 61));
        Transfer_pushButton->setFont(font2);
        ViewBalance_pushButton = new QPushButton(page4_Menu);
        ViewBalance_pushButton->setObjectName(QString::fromUtf8("ViewBalance_pushButton"));
        ViewBalance_pushButton->setGeometry(QRect(300, 420, 171, 61));
        ViewBalance_pushButton->setFont(font2);
        stackedWidget->addWidget(page4_Menu);
        page5_Statments = new QWidget();
        page5_Statments->setObjectName(QString::fromUtf8("page5_Statments"));
        page5_Statments->setStyleSheet(QString::fromUtf8("\n"
"								background-color:rgb(47, 47, 47)\n"
"							"));
        ViewStatement_label = new QLabel(page5_Statments);
        ViewStatement_label->setObjectName(QString::fromUtf8("ViewStatement_label"));
        ViewStatement_label->setGeometry(QRect(240, 40, 351, 61));
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
        page6_ETransfer = new QWidget();
        page6_ETransfer->setObjectName(QString::fromUtf8("page6_ETransfer"));
        page6_ETransfer->setStyleSheet(QString::fromUtf8("\n"
"								background-color:rgb(47, 47, 47)\n"
"							"));
        Transfer_label = new QLabel(page6_ETransfer);
        Transfer_label->setObjectName(QString::fromUtf8("Transfer_label"));
        Transfer_label->setGeometry(QRect(310, 60, 181, 41));
        Transfer_label->setFont(font);
        From_label = new QLabel(page6_ETransfer);
        From_label->setObjectName(QString::fromUtf8("From_label"));
        From_label->setGeometry(QRect(160, 140, 63, 20));
        To_label = new QLabel(page6_ETransfer);
        To_label->setObjectName(QString::fromUtf8("To_label"));
        To_label->setGeometry(QRect(160, 250, 63, 20));
        Amount_label = new QLabel(page6_ETransfer);
        Amount_label->setObjectName(QString::fromUtf8("Amount_label"));
        Amount_label->setGeometry(QRect(160, 360, 71, 20));
        Send_pushButton = new QPushButton(page6_ETransfer);
        Send_pushButton->setObjectName(QString::fromUtf8("Send_pushButton"));
        Send_pushButton->setGeometry(QRect(600, 490, 101, 31));
        Send_pushButton->setFont(font2);
        Send_pushButton->setLayoutDirection(Qt::LeftToRight);
        BackToMenu_pushButton_2 = new QPushButton(page6_ETransfer);
        BackToMenu_pushButton_2->setObjectName(QString::fromUtf8("BackToMenu_pushButton_2"));
        BackToMenu_pushButton_2->setGeometry(QRect(30, 30, 111, 29));
        Logout_pushButton_3 = new QPushButton(page6_ETransfer);
        Logout_pushButton_3->setObjectName(QString::fromUtf8("Logout_pushButton_3"));
        Logout_pushButton_3->setGeometry(QRect(670, 30, 83, 29));
        From_comboBox = new QComboBox(page6_ETransfer);
        From_comboBox->addItem(QString());
        From_comboBox->addItem(QString());
        From_comboBox->setObjectName(QString::fromUtf8("From_comboBox"));
        From_comboBox->setGeometry(QRect(160, 170, 451, 51));
        Amount_lineEdit = new QLineEdit(page6_ETransfer);
        Amount_lineEdit->setObjectName(QString::fromUtf8("Amount_lineEdit"));
        Amount_lineEdit->setGeometry(QRect(160, 390, 451, 51));
        To_lineEdit = new QLineEdit(page6_ETransfer);
        To_lineEdit->setObjectName(QString::fromUtf8("To_lineEdit"));
        To_lineEdit->setGeometry(QRect(160, 280, 451, 51));
        stackedWidget->addWidget(page6_ETransfer);
        page7_Deposit = new QWidget();
        page7_Deposit->setObjectName(QString::fromUtf8("page7_Deposit"));
        page7_Deposit->setStyleSheet(QString::fromUtf8("\n"
"								background-color:rgb(47, 47, 47)\n"
"							"));
        Deposit_label = new QLabel(page7_Deposit);
        Deposit_label->setObjectName(QString::fromUtf8("Deposit_label"));
        Deposit_label->setGeometry(QRect(320, 50, 141, 41));
        Deposit_label->setFont(font);
        Frontpage_label = new QLabel(page7_Deposit);
        Frontpage_label->setObjectName(QString::fromUtf8("Frontpage_label"));
        Frontpage_label->setGeometry(QRect(60, 150, 231, 31));
        QFont font4;
        font4.setPointSize(10);
        Frontpage_label->setFont(font4);
        DepositComplete_pushButton = new QPushButton(page7_Deposit);
        DepositComplete_pushButton->setObjectName(QString::fromUtf8("DepositComplete_pushButton"));
        DepositComplete_pushButton->setGeometry(QRect(650, 490, 91, 41));
        QFont font5;
        font5.setPointSize(11);
        DepositComplete_pushButton->setFont(font5);
        Backpage_label_2 = new QLabel(page7_Deposit);
        Backpage_label_2->setObjectName(QString::fromUtf8("Backpage_label_2"));
        Backpage_label_2->setGeometry(QRect(60, 260, 201, 31));
        Backpage_label_2->setFont(font4);
        Logout_pushButton_4 = new QPushButton(page7_Deposit);
        Logout_pushButton_4->setObjectName(QString::fromUtf8("Logout_pushButton_4"));
        Logout_pushButton_4->setGeometry(QRect(660, 40, 83, 29));
        BackToMenu_pushButton_3 = new QPushButton(page7_Deposit);
        BackToMenu_pushButton_3->setObjectName(QString::fromUtf8("BackToMenu_pushButton_3"));
        BackToMenu_pushButton_3->setGeometry(QRect(30, 30, 111, 29));
        Amount_lineEdit_2 = new QLineEdit(page7_Deposit);
        Amount_lineEdit_2->setObjectName(QString::fromUtf8("Amount_lineEdit_2"));
        Amount_lineEdit_2->setGeometry(QRect(310, 450, 171, 31));
        Amount_label_3 = new QLabel(page7_Deposit);
        Amount_label_3->setObjectName(QString::fromUtf8("Amount_label_3"));
        Amount_label_3->setGeometry(QRect(60, 450, 71, 31));
        Amount_label_3->setFont(font4);
        AccType_label = new QLabel(page7_Deposit);
        AccType_label->setObjectName(QString::fromUtf8("AccType_label"));
        AccType_label->setGeometry(QRect(60, 390, 71, 31));
        AccType_label->setFont(font4);
        AccType_comboBox = new QComboBox(page7_Deposit);
        AccType_comboBox->addItem(QString());
        AccType_comboBox->addItem(QString());
        AccType_comboBox->setObjectName(QString::fromUtf8("AccType_comboBox"));
        AccType_comboBox->setGeometry(QRect(310, 400, 171, 31));
        FrontpageImage_label = new QLabel(page7_Deposit);
        FrontpageImage_label->setObjectName(QString::fromUtf8("FrontpageImage_label"));
        FrontpageImage_label->setGeometry(QRect(310, 150, 241, 91));
        FrontpageImage_label->setStyleSheet(QString::fromUtf8("\n"
"									border:bold 3px ;\n"
"									border-color: rgb(255, 255, 255);\n"
"									background-color: rgb(157, 157, 157);\n"
"								"));
        AddFrontpage_pushButton = new QPushButton(page7_Deposit);
        AddFrontpage_pushButton->setObjectName(QString::fromUtf8("AddFrontpage_pushButton"));
        AddFrontpage_pushButton->setGeometry(QRect(600, 180, 151, 31));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(false);
        AddFrontpage_pushButton->setFont(font6);
        AddFrontpage_pushButton->setStyleSheet(QString::fromUtf8("\n"
"									color: rgb(0, 0, 0);\n"
"									background-color: rgb(200, 200, 200);\n"
"								"));
        BackpageImage_label = new QLabel(page7_Deposit);
        BackpageImage_label->setObjectName(QString::fromUtf8("BackpageImage_label"));
        BackpageImage_label->setGeometry(QRect(310, 260, 241, 91));
        BackpageImage_label->setStyleSheet(QString::fromUtf8("\n"
"									border:bold 3px ;\n"
"									border-color: rgb(255, 255, 255);\n"
"									background-color: rgb(157, 157, 157);\n"
"								"));
        AddBackpage_pushButton = new QPushButton(page7_Deposit);
        AddBackpage_pushButton->setObjectName(QString::fromUtf8("AddBackpage_pushButton"));
        AddBackpage_pushButton->setGeometry(QRect(600, 290, 151, 31));
        AddBackpage_pushButton->setFont(font6);
        AddBackpage_pushButton->setStyleSheet(QString::fromUtf8("\n"
"									color: rgb(0, 0, 0);\n"
"									background-color: rgb(200, 200, 200);\n"
"								"));
        stackedWidget->addWidget(page7_Deposit);
        page8_AddAcc = new QWidget();
        page8_AddAcc->setObjectName(QString::fromUtf8("page8_AddAcc"));
        page8_AddAcc->setStyleSheet(QString::fromUtf8("\n"
"								background-color:rgb(47, 47, 47)\n"
"							"));
        AddAcc_label = new QLabel(page8_AddAcc);
        AddAcc_label->setObjectName(QString::fromUtf8("AddAcc_label"));
        AddAcc_label->setGeometry(QRect(220, 70, 331, 41));
        AddAcc_label->setFont(font);
        InvestingAcc_checkBox = new QCheckBox(page8_AddAcc);
        InvestingAcc_checkBox->setObjectName(QString::fromUtf8("InvestingAcc_checkBox"));
        InvestingAcc_checkBox->setGeometry(QRect(260, 190, 191, 26));
        InvestingAcc_checkBox->setFont(font2);
        Logout_pushButton_5 = new QPushButton(page8_AddAcc);
        Logout_pushButton_5->setObjectName(QString::fromUtf8("Logout_pushButton_5"));
        Logout_pushButton_5->setGeometry(QRect(660, 40, 83, 29));
        BackToMenu_pushButton_4 = new QPushButton(page8_AddAcc);
        BackToMenu_pushButton_4->setObjectName(QString::fromUtf8("BackToMenu_pushButton_4"));
        BackToMenu_pushButton_4->setGeometry(QRect(30, 30, 111, 29));
        stackedWidget->addWidget(page8_AddAcc);
        page9_MyAcc = new QWidget();
        page9_MyAcc->setObjectName(QString::fromUtf8("page9_MyAcc"));
        page9_MyAcc->setStyleSheet(QString::fromUtf8("\n"
"								background-color:rgb(47, 47, 47)\n"
"							"));
        MyAcc_label = new QLabel(page9_MyAcc);
        MyAcc_label->setObjectName(QString::fromUtf8("MyAcc_label"));
        MyAcc_label->setGeometry(QRect(280, 60, 221, 51));
        MyAcc_label->setFont(font);
        Logout_pushButton_6 = new QPushButton(page9_MyAcc);
        Logout_pushButton_6->setObjectName(QString::fromUtf8("Logout_pushButton_6"));
        Logout_pushButton_6->setGeometry(QRect(640, 40, 83, 29));
        BackToMenu_pushButton_5 = new QPushButton(page9_MyAcc);
        BackToMenu_pushButton_5->setObjectName(QString::fromUtf8("BackToMenu_pushButton_5"));
        BackToMenu_pushButton_5->setGeometry(QRect(30, 40, 111, 29));
        gridLayoutWidget_2 = new QWidget(page9_MyAcc);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(150, 160, 521, 351));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        Address_label = new QLabel(gridLayoutWidget_2);
        Address_label->setObjectName(QString::fromUtf8("Address_label"));
        Address_label->setFont(font2);

        gridLayout_3->addWidget(Address_label, 5, 1, 1, 1);

        Name_label = new QLabel(gridLayoutWidget_2);
        Name_label->setObjectName(QString::fromUtf8("Name_label"));
        Name_label->setFont(font2);

        gridLayout_3->addWidget(Name_label, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font7;
        font7.setPointSize(12);
        font7.setBold(true);
        label_2->setFont(font7);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        PostalCode_label_2 = new QLabel(gridLayoutWidget_2);
        PostalCode_label_2->setObjectName(QString::fromUtf8("PostalCode_label_2"));

        gridLayout_3->addWidget(PostalCode_label_2, 6, 1, 1, 1);

        Email_label = new QLabel(gridLayoutWidget_2);
        Email_label->setObjectName(QString::fromUtf8("Email_label"));
        Email_label->setFont(font2);

        gridLayout_3->addWidget(Email_label, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font7);

        gridLayout_3->addWidget(label_4, 5, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font7);

        gridLayout_3->addWidget(label_3, 4, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font7);

        gridLayout_3->addWidget(label_5, 6, 0, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font7);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        PhoneNum_label = new QLabel(gridLayoutWidget_2);
        PhoneNum_label->setObjectName(QString::fromUtf8("PhoneNum_label"));
        PhoneNum_label->setFont(font2);

        gridLayout_3->addWidget(PhoneNum_label, 4, 1, 1, 1);

        stackedWidget->addWidget(page9_MyAcc);
        page10_Transfer = new QWidget();
        page10_Transfer->setObjectName(QString::fromUtf8("page10_Transfer"));
        page10_Transfer->setStyleSheet(QString::fromUtf8("background-color:rgb(47, 47, 47)\n"
"							"));
        BackToMenu_pushButton_6 = new QPushButton(page10_Transfer);
        BackToMenu_pushButton_6->setObjectName(QString::fromUtf8("BackToMenu_pushButton_6"));
        BackToMenu_pushButton_6->setGeometry(QRect(30, 40, 111, 29));
        Logout_pushButton_7 = new QPushButton(page10_Transfer);
        Logout_pushButton_7->setObjectName(QString::fromUtf8("Logout_pushButton_7"));
        Logout_pushButton_7->setGeometry(QRect(650, 50, 83, 29));
        Transfer_label_2 = new QLabel(page10_Transfer);
        Transfer_label_2->setObjectName(QString::fromUtf8("Transfer_label_2"));
        Transfer_label_2->setGeometry(QRect(310, 80, 151, 41));
        Transfer_label_2->setFont(font);
        From_label_2 = new QLabel(page10_Transfer);
        From_label_2->setObjectName(QString::fromUtf8("From_label_2"));
        From_label_2->setGeometry(QRect(150, 150, 63, 20));
        From_comboBox_2 = new QComboBox(page10_Transfer);
        From_comboBox_2->addItem(QString());
        From_comboBox_2->addItem(QString());
        From_comboBox_2->setObjectName(QString::fromUtf8("From_comboBox_2"));
        From_comboBox_2->setGeometry(QRect(150, 180, 451, 51));
        To_label_2 = new QLabel(page10_Transfer);
        To_label_2->setObjectName(QString::fromUtf8("To_label_2"));
        To_label_2->setGeometry(QRect(150, 260, 63, 20));
        To_comboBox = new QComboBox(page10_Transfer);
        To_comboBox->addItem(QString());
        To_comboBox->addItem(QString());
        To_comboBox->setObjectName(QString::fromUtf8("To_comboBox"));
        To_comboBox->setGeometry(QRect(150, 290, 451, 51));
        Amount_lineEdit_3 = new QLineEdit(page10_Transfer);
        Amount_lineEdit_3->setObjectName(QString::fromUtf8("Amount_lineEdit_3"));
        Amount_lineEdit_3->setGeometry(QRect(150, 400, 451, 51));
        Amount_label_2 = new QLabel(page10_Transfer);
        Amount_label_2->setObjectName(QString::fromUtf8("Amount_label_2"));
        Amount_label_2->setGeometry(QRect(150, 370, 81, 20));
        Send_pushButton_2 = new QPushButton(page10_Transfer);
        Send_pushButton_2->setObjectName(QString::fromUtf8("Send_pushButton_2"));
        Send_pushButton_2->setGeometry(QRect(600, 500, 101, 31));
        Send_pushButton_2->setFont(font2);
        stackedWidget->addWidget(page10_Transfer);
        page11_ViewBalance = new QWidget();
        page11_ViewBalance->setObjectName(QString::fromUtf8("page11_ViewBalance"));
        page11_ViewBalance->setStyleSheet(QString::fromUtf8("background-color:rgb(47, 47, 47)"));
        CurrentBalance_label_2 = new QLabel(page11_ViewBalance);
        CurrentBalance_label_2->setObjectName(QString::fromUtf8("CurrentBalance_label_2"));
        CurrentBalance_label_2->setGeometry(QRect(260, 80, 281, 41));
        CurrentBalance_label_2->setFont(font);
        BackToMenu_pushButton_7 = new QPushButton(page11_ViewBalance);
        BackToMenu_pushButton_7->setObjectName(QString::fromUtf8("BackToMenu_pushButton_7"));
        BackToMenu_pushButton_7->setGeometry(QRect(60, 40, 111, 29));
        Logout_pushButton_8 = new QPushButton(page11_ViewBalance);
        Logout_pushButton_8->setObjectName(QString::fromUtf8("Logout_pushButton_8"));
        Logout_pushButton_8->setGeometry(QRect(640, 40, 83, 29));
        gridLayoutWidget_4 = new QWidget(page11_ViewBalance);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(140, 170, 501, 211));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        SavingBalance_label = new QLabel(gridLayoutWidget_4);
        SavingBalance_label->setObjectName(QString::fromUtf8("SavingBalance_label"));
        SavingBalance_label->setFont(font2);

        gridLayout_5->addWidget(SavingBalance_label, 1, 1, 1, 1);

        ChequingBalance_label = new QLabel(gridLayoutWidget_4);
        ChequingBalance_label->setObjectName(QString::fromUtf8("ChequingBalance_label"));
        ChequingBalance_label->setFont(font2);

        gridLayout_5->addWidget(ChequingBalance_label, 0, 1, 1, 1);

        label_12 = new QLabel(gridLayoutWidget_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font7);

        gridLayout_5->addWidget(label_12, 0, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font7);

        gridLayout_5->addWidget(label_11, 1, 0, 1, 1);

        stackedWidget->addWidget(page11_ViewBalance);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(ClientApp);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientApp);
    } // setupUi

    void retranslateUi(QWidget *ClientApp)
    {
        ClientApp->setWindowTitle(QCoreApplication::translate("ClientApp", "ClientApp", nullptr));
        Login_label->setText(QCoreApplication::translate("ClientApp", "Login", nullptr));
        CarNum_label->setText(QCoreApplication::translate("ClientApp", "Card Number/User Name:", nullptr));
        PassWord_label->setText(QCoreApplication::translate("ClientApp", "Password:", nullptr));
        Login_pushButton->setText(QCoreApplication::translate("ClientApp", "Login", nullptr));
        Signin_pushButton->setText(QCoreApplication::translate("ClientApp", "Don't have an account?", nullptr));
        ResetPassword_pushButton->setText(QCoreApplication::translate("ClientApp", "Forgot password?", nullptr));
        Login_label_2->setText(QCoreApplication::translate("ClientApp", "Reset Password", nullptr));
        email_label->setText(QCoreApplication::translate("ClientApp", "Email:", nullptr));
        SendResetLink_pushButton->setText(QCoreApplication::translate("ClientApp", "Send reset link", nullptr));
        BackToLogin_pushButton->setText(QCoreApplication::translate("ClientApp", "Back to Login", nullptr));
        Signup_label->setText(QCoreApplication::translate("ClientApp", "Sign up", nullptr));
        BackToLogin_pushButton_2->setText(QCoreApplication::translate("ClientApp", "Back to Login", nullptr));
        NewPassword_label->setText(QCoreApplication::translate("ClientApp", "Password:", nullptr));
        Phone_label->setText(QCoreApplication::translate("ClientApp", "Phone Number:", nullptr));
        PostalCode_label->setText(QCoreApplication::translate("ClientApp", "Postal Code:", nullptr));
        Email_label_2->setText(QCoreApplication::translate("ClientApp", "Email:", nullptr));
        City_label->setText(QCoreApplication::translate("ClientApp", "City:", nullptr));
        LastName_label->setText(QCoreApplication::translate("ClientApp", "Last Name:", nullptr));
        Street_label->setText(QCoreApplication::translate("ClientApp", "Street:", nullptr));
        UserName_label->setText(QCoreApplication::translate("ClientApp", "User Name:", nullptr));
        FirstName_label->setText(QCoreApplication::translate("ClientApp", "First Name:", nullptr));
        ConfirmPassword_label->setText(QCoreApplication::translate("ClientApp", "Confirm Password:", nullptr));
        Province_label->setText(QCoreApplication::translate("ClientApp", "Province:", nullptr));
        Signup_pushButton->setText(QCoreApplication::translate("ClientApp", "Sign up", nullptr));
        ViewStatement_pushButton->setText(QCoreApplication::translate("ClientApp", "View Statements", nullptr));
        E_Transfer_pushButton->setText(QCoreApplication::translate("ClientApp", "E-transfers", nullptr));
        AddAcc_pushButton->setText(QCoreApplication::translate("ClientApp", "Add account", nullptr));
        Deposit_pushButton->setText(QCoreApplication::translate("ClientApp", "Deposit", nullptr));
        ViewAcc_pushButton->setText(QCoreApplication::translate("ClientApp", "My account", nullptr));
        Menu_label->setText(QCoreApplication::translate("ClientApp", "Menu", nullptr));
        Logout_pushButton->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        Transfer_pushButton->setText(QCoreApplication::translate("ClientApp", "Transfer", nullptr));
        ViewBalance_pushButton->setText(QCoreApplication::translate("ClientApp", "View Balance", nullptr));
        ViewStatement_label->setText(QCoreApplication::translate("ClientApp", "Account's Activities", nullptr));
        Logout_pushButton_2->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        labelImage->setText(QString());
        ImageDisplayPushButton->setText(QCoreApplication::translate("ClientApp", "Display Statments", nullptr));
        Transfer_label->setText(QCoreApplication::translate("ClientApp", "E-transfer", nullptr));
        From_label->setText(QCoreApplication::translate("ClientApp", "FROM:", nullptr));
        To_label->setText(QCoreApplication::translate("ClientApp", "TO:", nullptr));
        Amount_label->setText(QCoreApplication::translate("ClientApp", "AMOUNT:", nullptr));
        Send_pushButton->setText(QCoreApplication::translate("ClientApp", "Send", nullptr));
        BackToMenu_pushButton_2->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        Logout_pushButton_3->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        From_comboBox->setItemText(0, QCoreApplication::translate("ClientApp", "Chequing Account", nullptr));
        From_comboBox->setItemText(1, QCoreApplication::translate("ClientApp", "Saving Account", nullptr));

        Deposit_label->setText(QCoreApplication::translate("ClientApp", "Deposit", nullptr));
        Frontpage_label->setText(QCoreApplication::translate("ClientApp", "Front page of the cheque:", nullptr));
        DepositComplete_pushButton->setText(QCoreApplication::translate("ClientApp", "Done", nullptr));
        Backpage_label_2->setText(QCoreApplication::translate("ClientApp", "Back page of the cheque:", nullptr));
        Logout_pushButton_4->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton_3->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        Amount_label_3->setText(QCoreApplication::translate("ClientApp", "Amount:", nullptr));
        AccType_label->setText(QCoreApplication::translate("ClientApp", "Account:", nullptr));
        AccType_comboBox->setItemText(0, QCoreApplication::translate("ClientApp", "Chequing Account", nullptr));
        AccType_comboBox->setItemText(1, QCoreApplication::translate("ClientApp", "Saving Account", nullptr));

        FrontpageImage_label->setText(QString());
        AddFrontpage_pushButton->setText(QCoreApplication::translate("ClientApp", "Choose an image", nullptr));
        BackpageImage_label->setText(QString());
        AddBackpage_pushButton->setText(QCoreApplication::translate("ClientApp", "Choose an image", nullptr));
        AddAcc_label->setText(QCoreApplication::translate("ClientApp", "Add New Accounts", nullptr));
        InvestingAcc_checkBox->setText(QCoreApplication::translate("ClientApp", "Investing Account", nullptr));
        Logout_pushButton_5->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton_4->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        MyAcc_label->setText(QCoreApplication::translate("ClientApp", "My Account", nullptr));
        Logout_pushButton_6->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        BackToMenu_pushButton_5->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        Address_label->setText(QString());
        Name_label->setText(QString());
        label_2->setText(QCoreApplication::translate("ClientApp", "Email:", nullptr));
        PostalCode_label_2->setText(QString());
        Email_label->setText(QString());
        label_4->setText(QCoreApplication::translate("ClientApp", "Address:", nullptr));
        label_3->setText(QCoreApplication::translate("ClientApp", "Phone Number:", nullptr));
        label_5->setText(QCoreApplication::translate("ClientApp", "Postal Code:", nullptr));
        label->setText(QCoreApplication::translate("ClientApp", "Full Name:", nullptr));
        PhoneNum_label->setText(QString());
        BackToMenu_pushButton_6->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        Logout_pushButton_7->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        Transfer_label_2->setText(QCoreApplication::translate("ClientApp", "Transfer", nullptr));
        From_label_2->setText(QCoreApplication::translate("ClientApp", "FROM:", nullptr));
        From_comboBox_2->setItemText(0, QCoreApplication::translate("ClientApp", "Chequing Account", nullptr));
        From_comboBox_2->setItemText(1, QCoreApplication::translate("ClientApp", "Saving Account", nullptr));

        To_label_2->setText(QCoreApplication::translate("ClientApp", "TO:", nullptr));
        To_comboBox->setItemText(0, QCoreApplication::translate("ClientApp", "Chequing Account", nullptr));
        To_comboBox->setItemText(1, QCoreApplication::translate("ClientApp", "Saving Account", nullptr));

        Amount_label_2->setText(QCoreApplication::translate("ClientApp", "AMOUNT:", nullptr));
        Send_pushButton_2->setText(QCoreApplication::translate("ClientApp", "Send", nullptr));
        CurrentBalance_label_2->setText(QCoreApplication::translate("ClientApp", "Current Balance", nullptr));
        BackToMenu_pushButton_7->setText(QCoreApplication::translate("ClientApp", "Back to Menu", nullptr));
        Logout_pushButton_8->setText(QCoreApplication::translate("ClientApp", "Logout", nullptr));
        SavingBalance_label->setText(QString());
        ChequingBalance_label->setText(QString());
        label_12->setText(QCoreApplication::translate("ClientApp", "Chequing:", nullptr));
        label_11->setText(QCoreApplication::translate("ClientApp", "Saving:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientApp: public Ui_ClientApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTAPP_H
