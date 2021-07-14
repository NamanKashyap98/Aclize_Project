#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QLineEdit>
#include "secdialog.h"
#include "thirddialog.h"


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




void MainWindow::on_pushbutton_clicked()
{
    QFile file("C:/Users/isha/Documents/Aclize_social_media_app_Project/DB.txt");
            if(!file.open(QFile::WriteOnly | QFile::Text)){
                QMessageBox::warning(this,"Title","file is not open");
            }
            QTextStream out(&file);
            QString reguser;
             QString  regpass;
             QString Name;
             QString ID;
             QString BDay;
            reguser=ui->reguser->text();
            regpass=ui->regpass->text();
            Name=ui->Name->text();
            ID=ui->ID->text();
            BDay=ui->BDay->text();

            out<<reguser<<"\n"<<regpass<<"\n"<<Name<<"\n"<<ID<<"\n"<<BDay;

            QMessageBox::information(this,"Congratulations","Your Account is Created");


}


void MainWindow::on_pushButton_clicked()
{
    SecDialog secdialog;
    secdialog.setModal(true);
    secdialog.exec();

}

