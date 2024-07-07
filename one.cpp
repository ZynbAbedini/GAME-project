#include "one.h"
#include "ui_one.h"
#include "QApplication"
#include "one2.h""
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


void one::on_pushButton_clicked()
{
    One2 *t=new One2();
    t->show();
}

