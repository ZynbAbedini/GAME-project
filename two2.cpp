#include "two2.h"
#include "ui_two2.h"
#include "QApplication"

Two2::Two2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Two2)
{
    ui->setupUi(this);
}

Two2::~Two2()
{
    delete ui;
}

void Two2::on_exit_clicked()
{
      QApplication::exit();
}

