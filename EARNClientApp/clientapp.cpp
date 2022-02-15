#include "clientapp.h"
#include "ui_clientapp.h"

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

