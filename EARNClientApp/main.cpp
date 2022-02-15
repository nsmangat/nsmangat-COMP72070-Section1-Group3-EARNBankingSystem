#include "clientapp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClientApp w;
    w.show();
    return a.exec();
}
