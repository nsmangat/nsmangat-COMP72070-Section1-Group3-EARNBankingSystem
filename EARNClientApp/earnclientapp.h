#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_earnclientapp.h"

class EARNClientApp : public QMainWindow
{
    Q_OBJECT

public:
    EARNClientApp(QWidget *parent = Q_NULLPTR);

private:
    Ui::EARNClientAppClass ui;
};
