#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QSqlTableModel;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_InputButton_clicked();

    void on_ShowButton_clicked();

    void on_FindButton_clicked();

    void on_CpwdButton_clicked();

    void on_RunButton_clicked();

    void on_EvaluateButton_clicked();

    void on_submitButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_showButton_clicked();

    void on_FindnameButton_clicked();

private:
        Ui::Widget *ui;

        QSqlTableModel *model;
        QSqlTableModel *model_;
};

#endif // WIDGET_H
