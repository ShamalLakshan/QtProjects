#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_btnAdd_clicked()
{
    QListWidgetItem* item = new QListWidgetItem(ui-> txtTask -> text(), ui-> lstTasks);
    ui-> lstTasks->addItem(item);
    item->setFlags(item -> flags() | Qt::ItemIsEditable);
    ui->txtTask->clear();
    ui->txtTask->setFocus();
}


void MainWindow::on_btnRemove_clicked()
{

}


void MainWindow::on_btnRemoveAll_clicked()
{

}

