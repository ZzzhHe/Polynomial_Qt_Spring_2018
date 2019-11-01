#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QProgressBar>
#include <QProgressDialog>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(700,400);
    setWindowTitle(tr("登陆"));
    ui->loginpwd->setFocus();
    ui->loginBtn->setDefault(true);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginBtn_clicked()
{

    //进行登陆操作
    if (ui->loginpwd->text().isEmpty())
    {
        QMessageBox::information(this, tr("请输入密码"),
        tr("请先输入密码再登录！ "), QMessageBox::Ok);
        ui->loginpwd->setFocus();
    }
    else
    {
        QSqlQuery query;

        query.exec("select pwd from password");
        query.next();
        //从数据库中读取密码，和登陆密码进行比较
        if (query.value(0).toString() == ui->loginpwd->text())
        {
        QDialog::accept();
        //进度条
        QProgressDialog connect(this);
        connect.setLabelText(tr("连接MySQL数据库..."));
        connect.setMinimumDuration(0);
        connect.setRange(0,50000);
        connect.setModal(true);
        connect.setCancelButtonText(tr("cancel"));
        connect.show();
       for(int i=0;i<50000;i++)
        {
          for(int j=0;j<20000;j++);
            connect.setValue(i);
          if(connect.wasCanceled())
            break;
        }
        }
        else
        {
            QMessageBox::warning(this, tr("密码错误"),
            tr("请输入正确的密码再登录！ "), QMessageBox::Ok);

            ui->loginpwd->clear();
            ui->loginpwd->setFocus();
        }
    }
}

void LoginDialog::on_quitBtn_clicked()
{
    QDialog::reject();
}

void LoginDialog::on_pushButton_clicked()
{
    //显示进度条
    QProgressDialog connect(this);
    connect.setLabelText(tr("连接MySQL数据库..."));
    connect.setRange(0,50000);
    connect.setModal(true);
    connect.setCancelButtonText(tr("cancel"));
    connect.show();
   for(int i=0;i<50000;i++)
    {
      for(int j=0;j<20000;j++);
        connect.setValue(i);
      if(connect.wasCanceled())
        break;
    }

}
