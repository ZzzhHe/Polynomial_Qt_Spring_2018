#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>



static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("mydata");
    db.setUserName("root");
    db.setPassword("20000502");
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("无法打开数据库"),
        "无法创建数据库连接！ ", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query;
    // 使数据库支持中文
    query.exec("SET NAMES 'Latin1'");


    // 创建真实多项式信息表X
    query.exec("create table X(n int primary key, name varchar(20),Xmax double,Xmin double,"
               "a0 double, a1 double, a2 double, a3 double, a4 double, a5 double, a6 double, a7 double)");
    query.exec("insert into X values(01, '1st',2.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into X values(02, '2nd',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into X values(03, '3th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into X values(04, '4th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into X values(05, '5th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into X values(06, '6th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into X values(07, '7th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");

    //创建拟合多项式信息表X'
    query.exec("create table Xs(n_ int primary key, name_ varchar(20),Xmax_ double,Xmin_ double,"
               "a0_ double, a1_ double, a2_ double, a3_ double, a4_ double, a5_ double, a6_ double, a7_ double)");
    query.exec("insert into Xs values(01, '1st',2.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into Xs values(02, '2nd',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into Xs values(03, '3th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into Xs values(04, '4th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into Xs values(05, '5th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into Xs values(06, '6th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");
    query.exec("insert into Xs values(07, '7th',0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00)");

    // 创建密码表
    query.exec("create table password(id varchar(20) primary key, pwd varchar(50))");
    query.exec("insert into password values('01', '123456')");
    return true;
}
#endif // CONNECTION_H
