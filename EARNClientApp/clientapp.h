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

private:
    Ui::ClientApp *ui;
};
#endif // CLIENTAPP_H
