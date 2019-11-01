#include "widget.h"
#include <QApplication>
#include "connection.h"
#include "logindialog.h"
#include <QProcess>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 这里使用代码来运行 MySQL 数据库
    QProcess process;
    process.start("C:/Program Files/MySQL/MySQL Server 8.0/bin/mysqld.exe");

    if(!createConnection()) return 0;

    Widget w;
    LoginDialog dlg;

    if (dlg.exec() == QDialog::Accepted)
    {
        w.show();
        return a.exec();
    }
    else
    {
        return 0;
     }
}
