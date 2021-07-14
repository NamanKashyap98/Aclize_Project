#include "thirddialog.h"
#include "ui_thirddialog.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QLineEdit>

thirdDialog::thirdDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thirdDialog)
{
    ui->setupUi(this);
}

thirdDialog::~thirdDialog()
{
    delete ui;
}

void thirdDialog::on_pushButton_clicked()
{
    QFile file("C:/Users/isha/Documents/Aclize_social_media_app_Project/DB.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Title","file is not open");
    }
    QTextStream in(&file);
    QString user;
    QString pass;
    QString Name;
    QString Email;
    QString BD;
    in>>user>>pass>>Name>>Email>>BD;


    ui->lineEdit->setText(user);
    ui->lineEdit_2->setText(pass);
    ui->lineEdit_3->setText(Name);
    ui->lineEdit_4->setText(Email);
    ui->lineEdit_5->setText(BD);

    file.close();

}

