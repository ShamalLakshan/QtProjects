#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        QListWidgetItem* item = new QListWidgetItem(in.readLine(), ui -> lstTasks);
        ui -> lstTasks -> addItem(item);
        item -> setFlags(item -> flags() | Qt::ItemIsEditable);
    }
    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;

    QFile file(path);

    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < ui -> lstTasks -> count(); ++i) {
        out << ui -> lstTasks ->item(i) -> text() << "\n";
    }
    file.close();
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
    QListWidgetItem* item = ui -> lstTasks -> takeItem(ui -> lstTasks -> currentRow());
    delete item;
}


void MainWindow::on_btnRemoveAll_clicked()
{
    ui -> lstTasks -> clear();
}

