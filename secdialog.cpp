#include "secdialog.h"
#include "ui_secdialog.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QLineEdit>
#include "thirddialog.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushbutton_clicked()
{
    QString user;
    QString pass;
    QString u;
    QString p;
    QString N;
    QString I;
    QString B;


    user=ui->loginuser->text();
    pass=ui->loginpass->text();

  QFile file("C:/Users/isha/Documents/Aclize_social_media_app_Project/DB.txt");
         if(!file.open(QFile::ReadOnly | QFile::Text)){
             QMessageBox::warning(this,"Title","file is not open");
         }
         QTextStream in(&file);
         in>>u>>p>>N>>I>>B;




              if(u==user && p==pass)
                {
                  thirdDialog thirddialog;
                  thirddialog.setModal(true);
                  thirddialog.exec();

                }
                else
                {
                    QMessageBox::information(this,"Sorry"," Logged in Failed");
                }
              file.close();
}

