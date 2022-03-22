#include "clientapp.h"
#include "ui_clientapp.h"
#include <QMessageBox>
#include <Q

ClientApp::ClientApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientApp)
{
    ui->setupUi(this);
}

ClientApp::~ClientApp()
{
    delete ui;
}


void ClientApp::on_BackToMenu_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void ClientApp::on_Login_pushButton_clicked()
{
    QString userName = ui->CardNum_lineEdit->text();
    QString password = ui->Password_lineEdit->text();

    if(userName == "admin" && password =="admin")
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else {
       QMessageBox::warning(this, "Login", "Card number or password is incorrect.");
    }
}

void ClientApp::on_SendResetLink_pushButton_clicked()
{
    QString cardNum = ui->cardNum_lineEdit_1->text();
    QString email = ui->email_lineEdit->text();

    if(cardNum == "0123456789" && email == "admin@gamil.com")
    {
     QMessageBox::information(this, "Reset Password", "A reset link is sent to your email.");
    }else{
        QMessageBox::warning(this, "Reset Password", "Card Number or Email is incorrect.");
    }
}


void ClientApp::on_BackToLogin_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void ClientApp::on_BackToLogin_pushButton_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
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
    ui->stackedWidget->setCurrentIndex(0);
}

//Menu page
void ClientApp::on_ViewStatement_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void ClientApp::on_Transfer_pushButton_clicked()
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
    ui->stackedWidget->setCurrentIndex(8);
}

void ClientApp::on_pushButton_4_clicked()
{
    ///
}
//Add Account Page
void ClientApp::on_BackToMenu_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void ClientApp::on_Logout_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void ClientApp::on_ImageDisplayPushButton_clicked()
{
    QPixmap pic("C:/Users/letra/Downloads/TransactionActivities.png");
    ui->labelImage->setPixmap(pic);
}


void ClientApp::on_BackToMenu_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void ClientApp::on_Logout_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}




void ClientApp::on_ToOtherPeople_pushButton_clicked()
{
    ui->ToMyAcc_pushButton->setStyleSheet(QString("#%1 { background-color: grey; }"));
    QPushButton* target = qobject_cast<QPushButton*>(sender());
    
        if (target != nullptr)
        {
            target->setStyleSheet(QString("#%1 { background-color: green; }").arg(target->objectName()));
            
        }
}


void ClientApp::on_ToMyAcc_pushButton_pressed()
{
    ui->ToOtherPeople_pushButton->setStyleSheet(QString("#%1 { background-color: grey; }"));
    QPushButton* target = qobject_cast<QPushButton*>(sender());
        if (target != nullptr)
        {
            target->setStyleSheet(QString("#%1 { background-color: red; }").arg(target->objectName()));
        }
}

void ClientApp::setupUI()
{
   int index = ui->To_comboBox->findText("Saving Account", QtCore.Qt);
}


