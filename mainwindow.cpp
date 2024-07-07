#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "one.h"
#include "QApplication"
#include "Two.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    one *f=new one();
    f->show();
}


void MainWindow::on_exit_clicked()
{
    QApplication::exit();
}


void MainWindow::on_pushButton_2_clicked()
{
    Two *t=new Two();
    t->show();
}


