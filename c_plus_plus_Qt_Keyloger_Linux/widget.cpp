#include "widget.h"
#include "ui_widget.h"

#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFileDialog>
#include<QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //signal and slot to read file.txt periodically.
    connect(timer, SIGNAL(timeout()), this, SLOT(catkeybrd()));
    timer->start(500);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event) //delete file when app close to kill qprocess
{
    system("rm keyloger/data.txt");
}


void Widget::catkeybrd()
{
     QFile file("keyloger/data.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug()<<"File not found !";
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    ui->textEdit->setReadOnly(true);
    file.close();
}
