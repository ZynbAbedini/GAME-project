#include "one2.h"
#include "ui_one2.h"
#include "QApplication"
One2::One2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::One2)
{
    ui->setupUi(this);
}

One2::~One2()
{
    delete ui;
}


void One2::on_exit_clicked()
{
     QApplication::exit();
}

