#include "two.h"
#include "ui_two.h"
#include "QApplication"
#include "Two2.h"

Two::Two(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Two)
{
    ui->setupUi(this);
}

Two::~Two()
{
    delete ui;
}

void Two::on_exit_clicked()
{
     QApplication::exit();
}



void Two::on_pushButton_clicked()
{
    Two2 *t=new Two2();
    t->show();
}


