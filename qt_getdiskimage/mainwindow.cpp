#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <iostream>
#include <stdio.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(button, SIGNAL(clicked()), this, SLOT(buttonPressed()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(doldur()));
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
    QString str = exec_cmd("ls -l /dev/sda512");
    ui->textEdit->setText(str);
}
