#include "clientapp.h"
#include "ui_clientapp.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

ClientApp::ClientApp(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ClientApp)
{
    ui->setupUi(this);

    display_Account_Info();
}

ClientApp::~ClientApp()
{
    delete ui;
}

void ClientApp::display_Account_Info()
{
    //Display user's data in
    ui->Name_label->setText("Admin Test");
    ui->Email_label->setText("admin@earn.ca");
    ui->PhoneNum_label->setText("012345");
    ui->Address_label->setText("1 Street Blv, Kitchener,ON, Canada");
}

void ClientApp::on_BackToMenu_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void ClientApp::on_Login_pushButton_clicked()
{
    QString cardNum = ui->CardNum_lineEdit->text();
    QString password = ui->Password_lineEdit->text();

    if (cardNum == "123456789" && password == "admin")
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
    QString email = ui->email_lineEdit->text();

    if (email == "admin@gmail.com")
    {
        QMessageBox::information(this, "Reset Password", "A reset link is sent to your email.");
    }
    else {
        QMessageBox::warning(this, "Reset Password", "Card Number or Email is incorrect.");
    }
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
    if (ui->To_lineEdit->text() != "" && ui->Amount_lineEdit->text() != "")
    {
        QMessageBox::information(
            this,
            tr("Transaction"),
            tr("Transaction Completed"));
    }
    /*else if( account.balance < ui->Amount_lineEdit->Text())
            QMessageBox::critical(
            this,
            tr("Transaction"),
            tr("Insufficient balance") );
    */
    else {
        QMessageBox::critical(
            this,
            tr("Transaction"),
            tr("Incorrect input data"));
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
    if (!ui->FrontpageImage_label->pixmap().isNull() && !ui->BackpageImage_label->pixmap().isNull()
        && ui->Amount_lineEdit_2->isModified())
    {
        //Successful message
        QMessageBox::information(
            this,
            tr("Deposit"),
            tr("Deposit submitted.\nSent images will be verifed and balance will officially updated in 3 business days."));

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
    ui->stackedWidget->setCurrentIndex(0);
}


void ClientApp::on_Transfer_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


void ClientApp::on_Logout_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void ClientApp::on_Send_pushButton_2_clicked()
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
        QMessageBox::information(
            this,
            tr("Transaction"),
            tr("Transaction Completed"));
    }
    /*else if( account.balance < ui->Amount_lineEdit->Text())
            QMessageBox::critical(
            this,
            tr("Transaction"),
            tr("Insufficient balance") );
    */
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
        QString firstName = ui->FirstName_lineEdit->text();
        QString lastName = ui->LastName_lineEdit->text();
        QString userName = ui->UserName_lineEdit->text();
        QString newPassword = ui->NewPassword_lineEdit->text();
        QString confirmPassword = ui->ConfirmPassword_lineEdit->text();
        QString email = ui->Email_lineEdit->text();
        QString street = ui->Street_lineEdit->text();
        QString city = ui->City_lineEdit->text();
        QString province = ui->Province_lineEdit->text();
        QString postalCode = ui->PostalCode_lineEdit->text();
        QString phone = ui->Phone_lineEdit->text();

        //Call the constructor CreateAccount

        QMessageBox::information(
            this,
            tr("Sign In"),
            tr("Done."));
    }
    else
    {
        QMessageBox::critical(
            this,
            tr("Error"),
            tr("All fields is not filled."));
    }
}

