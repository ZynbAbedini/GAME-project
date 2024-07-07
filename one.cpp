#include "one.h"
#include "ui_one.h"
#include "QApplication"

one::one(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::one)
{
    ui->setupUi(this);
}

one::~one()
{
    delete ui;
}

void one::on_exit_clicked()
{
     QApplication::exit();
}

