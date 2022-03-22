#include "clientapp.h"
#include "ui_clientapp.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

ClientApp::ClientApp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientApp)
{
    ui->setupUi(this);
    ui->SendLinkMessage_label->hide();
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
    QString cardNum = ui->CardNum_lineEdit->text();
    QString password = ui->Password_lineEdit->text();

    if(cardNum == "123456789" && password =="admin")
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else {
       QMessageBox::warning(this, "Login", "Card number or password is incorrect.");
    }

    ui->CardNum_lineEdit->clear();
    ui->Password_lineEdit->clear();
    /*if(!mydb.isOpen())
     * {
     * qDebug()<<Failed to open the database";
     * return;
     * }
     *
     * QSqlQuery qry;
     * if(qry.exec("select* from <table> where cardNumber='"+cardNum +"' and password='"+password+"'")
     * {
     *  int count = 0;
     *  while(qry.next()){count++;}
     *  if(count == 1)
     *  {
     *     ui->stackedWidget->setCurrentIndex(3);
     *  }
     *  else{
     *      QMessageBox::warning(this, "Login", "Card number or password is incorrect.");
     *  }
     */
}

void ClientApp::on_SendResetLink_pushButton_clicked()
{
    QString cardNum = ui->cardNum_lineEdit_1->text();
    QString email = ui->email_lineEdit->text();

    if(cardNum == "123456789" && email == "admin@gmail.com")
    {
     QMessageBox::information(this, "Reset Password", "A reset link is sent to your email.");
    }else{
        QMessageBox::warning(this, "Reset Password", "Card Number or Email is incorrect.");
    }
    ui->cardNum_lineEdit_1->clear();
    ui->email_lineEdit->clear();
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
    QPushButton* target = qobject_cast<QPushButton*>(sender());

        if (target != nullptr)
        {
            target->setStyleSheet(QString("#%1 { background-color: green; }").arg(target->objectName()));

        }
}


void ClientApp::on_ToMyAcc_pushButton_pressed()
{
    QPushButton* target = qobject_cast<QPushButton*>(sender());
        if (target != nullptr)
        {
            target->setStyleSheet(QString("#%1 { background-color: red; }").arg(target->objectName()));
        }
}

/*void ClientApp::setupUI()
{
   int index = ui->To_comboBox->findText("Saving Account", QtCore.Qt);
}
*/
void ClientApp::on_BackToMenu_pushButton_2_clicked()
{
        ui->stackedWidget->setCurrentIndex(3);
}

void ClientApp::on_Logout_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}


void ClientApp::on_Send_pushButton_clicked()
{
    if(ui->To_lineEdit->isModified() && ui->Amount_lineEdit->isModified())
    {
    QMessageBox::information(
        this,
        tr("Transaction"),
        tr("Transaction Completed") );
}
    /*else if( account.balance < ui->Amount_lineEdit->Text())
            QMessageBox::critical(
            this,
            tr("Transaction"),
            tr("Insufficient balance") );
    */
    else{
        QMessageBox::critical(
            this,
            tr("Transaction"),
            tr("Incorrect input data") );
    }
    ui->To_lineEdit->clear();
    ui->Amount_lineEdit->clear();
}


void ClientApp::on_BackToMenu_pushButton_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}


void ClientApp::on_Logout_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void ClientApp::on_DepositComplete_pushButton_clicked()
{
    //Verify that all required fields are filled
    if(!ui->FrontpageImage_label->pixmap().isNull() && !ui->BackpageImage_label->pixmap().isNull()
            && ui->Amount_lineEdit_2->isModified())
    {
        //Successful message
        QMessageBox::information(
            this,
            tr("Deposit"),
            tr("Deposit submitted.\nSent images will be verifed and balance will officially updated in 3 business days.") );

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
            tr("Insufficient information") );
    }

}

void ClientApp::on_AddFrontpage_pushButton_clicked()
{
    //Ask user to select image from their computer to load to the application
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Image(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(fileName,QString())!=0)
    {
        QImage image;
        bool valid = image.load(fileName);      //verify that image is loaded successfully
        if(valid)
        {
           //Set/Display the selected image to the label to let the user know
            ui->FrontpageImage_label->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::warning(
                this,
                tr("Image Error"),
                tr("Unable to load image.") );
        }
    }
}


void ClientApp::on_AddBackpage_pushButton_clicked()
{
    //Ask user to select image from their computer to load to the application
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose"),"",tr("Image(*.png *.jpg *.jpeg *.bmp *.gif)"));
    if(QString::compare(fileName,QString())!=0)
    {
        QImage image;
        bool valid = image.load(fileName);
        if(valid)
        {

            ui->BackpageImage_label->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::warning(
                this,
                tr("Image Error"),
                tr("Unable to load image.") );
        }
    }
}

