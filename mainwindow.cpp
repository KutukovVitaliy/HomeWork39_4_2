#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->lineEdit, &QLineEdit::textEdited, this, [this](QString currentText){
        QRegularExpression exp("^(\\+)([0-9]{11})$");
        if(exp.match(currentText).hasMatch())
            this->setOkLabel();
        else this->setNotOkLabel();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("OK!");
    ui->label->setStyleSheet("QLabel {color : green;}");
}

void MainWindow::setNotOkLabel()
{
    ui->label->setText("Not OK!");
    ui->label->setStyleSheet("QLabel {color : red;}");
}

