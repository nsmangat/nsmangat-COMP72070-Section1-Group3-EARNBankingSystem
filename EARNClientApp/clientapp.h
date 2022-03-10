#ifndef CLIENTAPP_H
#define CLIENTAPP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ClientApp; }
QT_END_NAMESPACE

class ClientApp : public QWidget
{
    Q_OBJECT

public:
    ClientApp(QWidget *parent = nullptr);
    ~ClientApp();

private slots:

    void on_BackToMenu_pushButton_6_clicked();

    void on_Login_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_SendResetLink_pushButton_clicked();

    void on_BackToLogin_pushButton_clicked();

    void on_BackToLogin_pushButton_2_clicked();

    void on_ResetPassword_pushButton_clicked();

    void on_Signin_pushButton_clicked();

    void on_Logout_pushButton_clicked();

    void on_ViewStatement_pushButton_clicked();

    void on_Transfer_pushButton_clicked();

    void on_Deposit_pushButton_clicked();

    void on_AddAcc_pushButton_clicked();

    void on_ViewAcc_pushButton_clicked();

    void on_BackToMenu_pushButton_4_clicked();

    void on_Logout_pushButton_5_clicked();

private:
    Ui::ClientApp *ui;
};
#endif // CLIENTAPP_H
