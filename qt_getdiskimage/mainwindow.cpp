#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <QFileDialog>
#include <QDateTime>
QString filebrowse;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Get Devices");
    ui->textEdit->hide();
    //connect(button, SIGNAL(clicked()), this, SLOT(buttonPressed()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(doldur()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(getfiledialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inspect(void)
{
    unsigned char device[100][50];
    return;
}
void MainWindow::getfiledialog()
{
    QFileDialog * fd = new QFileDialog;
    filebrowse = fd->getOpenFileName(this);
    filebrowse +="/image_"+ QDate::currentDate().toString("dd.MM.yyyy_hh.mm");
    //ui->comboBox->addItem(filebrowse);
    //QFile * file = new QFile; Here error starts...
    //txt->setPlainText(file->read(fd->FileName)); this doesn't work.
    ui->label_savepath->setText(filebrowse);
}


QString exec_cmd(char* cmd)
{
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    QString result = "";
    while(!feof(pipe))
    {
        if(fgets(buffer, 128, pipe) != NULL) result += buffer;
    }
    pclose(pipe);
    return result;
}


void MainWindow::doldur()
{
    QString str = exec_cmd("ls -l /dev/sd*");
    QStringList pieces = str.split( "\n", QString::SkipEmptyParts);
    QString item,str2;
    for(int i=0;i<pieces.length();i++)
    {
        item = pieces.value(i);
        item.remove(0,42);
        ui->comboBox->addItem(item);
        str2 +=item+"\n";

    }
    ui->textEdit->setText(str2);
    //ui->comboBox->addItem("halil");
    //ui->comboBox->addItem("caglar");
    //ui->comboBox->addItem("UEKAE");
}
