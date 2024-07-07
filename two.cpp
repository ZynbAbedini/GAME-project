#include "two.h"
#include "ui_two.h"
#include "QApplication"

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

