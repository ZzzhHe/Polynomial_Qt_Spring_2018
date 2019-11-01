#include "widget.h"
#include "ui_widget.h"
#include "faction.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <string>
#include <iostream>
#include <cmath>
#include <ctime>
#include <QProgressBar>
#include <QProgressDialog>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("X");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->a_tableView->setModel(model);
    ui->a_tableView_2->setModel(model);
    model_= new QSqlTableModel(this);
    model_->setTable("Xs");
    model_->select();
    model_->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->a__tableView->setModel(model_);
    ui->a__tableView_2->setModel(model_);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_InputButton_clicked()
{
    ui->StackedWidget->setCurrentIndex(0);
}



void Widget::on_ShowButton_clicked()
{
    ui->StackedWidget->setCurrentIndex(1);
}

void Widget::on_FindButton_clicked()
{
    ui->StackedWidget->setCurrentIndex(2);
}

void Widget::on_CpwdButton_clicked()
{
    ui->StackedWidget->setCurrentIndex(3);
}

void Widget::on_RunButton_clicked()
{
    //进度条
    QProgressDialog connect(this);
    connect.setLabelText(tr("计算中Loading..."));
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
    void Mul(const double A[8][50],const double B[50][8],double C[8][8]);
    void Mul(const double A[8][8], const double B[8][8], double C[8][8]);

for(int n=1;n<=7;n++)
        {//从数据库中获取Xmax和Xmin
        QSqlQuery query;
        query.exec("select 1 from X");
        query.next();

        query.exec(QString("select Xmax from X where n='%1'").arg(n));
        query.next();

        double Xmax=query.value(0).toDouble();

        query.exec(QString("select Xmin from X where n='%1'").arg(n));
        query.next();

        double Xmin=query.value(0).toDouble();

        double X[50];
        double XX;
        double Matrix_X[8][50] = { 0.0 };
        double XT[50][8] = { 0.0 };
        double Matrix_XX[8][8] = { 0.0 };

        //对X均分，存放在数组中

        X[0]=Xmin;
        XX=(Xmax-Xmin)/49;
        for(int i=1;i<50;i++)
        {
            X[i]=X[i-1]+XX;
        }
        //定义X 8*50矩阵，存放7个函数的X数据(X[0]用来存放1，去乘以a0)

            for(int j=0;j<50;j++){
                for(int i=1;i<8;i++)
                {
                    Matrix_X[i][j]=pow(X[j],i);
                    XT[j][i]=Matrix_X[i][j];
                }
            }

                for (int j=0;j<50;j++) {
                    Matrix_X[0][j]=1;
                    XT[j][0]=1;
                }

                //X和X的转置相乘得到XX矩阵

                   // Trs(Matrix_X,XT);

                    Mul(Matrix_X,XT,Matrix_XX);



    //从数据库中读取a，存放在a[8]中
        double a[8];
        query.exec(QString("select a0 from X where n='%1'").arg(n));
        query.next();
        a[0]=query.value(0).toDouble();
        query.exec(QString("select a1 from X where n='%1'").arg(n));
        query.next();
        a[1]=query.value(0).toDouble();
        query.exec(QString("select a2 from X where n='%1'").arg(n));
        query.next();
        a[2]=query.value(0).toDouble();
        query.exec(QString("select a3 from X where n='%1'").arg(n));
        query.next();
        a[3]=query.value(0).toDouble();
        query.exec(QString("select a4 from X where n='%1'").arg(n));
        query.next();
        a[4]=query.value(0).toDouble();\
        query.exec(QString("select a5 from X where n='%1'").arg(n));
        query.next();
        a[5]=query.value(0).toDouble();
        query.exec(QString("select a6 from X where n='%1'").arg(n));
        query.next();
        a[6]=query.value(0).toDouble();
        query.exec(QString("select a7 from X where n='%1'").arg(n));
        query.next();
        a[7]=query.value(0).toDouble();

    //定义Y1*50矩阵，存放计算出的Y数据
        double Y[1][50]={0.0};
        for(int i=0;i<50;i++)
        {
            Y[0][i]=a[0]+a[1]*X[i]+a[2]*pow(X[i],2)+a[3]*pow(X[i],3)+a[4]*pow(X[i],4)+a[5]*pow(X[i],5)+a[6]*pow(X[i],6)+a[7]*pow(X[i],7);
        }

    //定义Y_1*50矩阵，存放拟合出的Y_数据
    //并引入随机数，增加波动
        double Y_[1][50] = { 0.0 };
        for (int i = 0; i < 50; i++)
        {
            srand((unsigned)time(NULL));
            Y_[0][i] = Y[0][i] + rand()/double(RAND_MAX);
        }

    //定义新的A的矩阵
        double A[1][8]={0.0};
        for(int i=0;i<8;i++)
            A[0][i]=a[i];


    //把XX矩阵添加一个E
        double Matrix_XXE[8][16];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++)
            {
                Matrix_XXE[i][j]=Matrix_XX[i][j];
            }
            for(int j=8;j<16;j++)
            {
                if(j!=i+8)
                        Matrix_XXE[i][j]=0;
                else {
                        Matrix_XXE[i][j]=1;
            }
            }

    }
     //对XXE进行行变换得到上三角矩阵
        for(int i=0;i<8;i++)
        {
            double m=Matrix_XXE[i][i];
            for(int j=0;j<16;j++)
            {
             Matrix_XXE[i][j]=Matrix_XXE[i][j]/m;
       }
           for(int k=i+1;k<8;k++)
            {
                double l=Matrix_XXE[k][i]/Matrix_XXE[i][i];
                for(int g=0;g<16;g++)
                {
                    Matrix_XXE[k][g]=Matrix_XXE[k][g]-l*Matrix_XXE[i][g];
                }
           }
  }
       //把XXE这个上三角矩阵转化为单位阵
        for(int i=7;i>=0;i--)
        {
            double m=Matrix_XXE[i][i];
            for(int j=0;j<16;j++)
            {
             Matrix_XXE[i][j]=Matrix_XXE[i][j]/m;
            }
            for(int j=i-1;j>=0;j--)
            {
                double m_=Matrix_XXE[j][i];
                for(int k=0;k<16;k++)
                {
                    Matrix_XXE[j][k]=Matrix_XXE[j][k]-m_*Matrix_XXE[i][k];
                }
            }
        }

        //得到逆矩阵
        double IMatrix[8][8];
        for(int i=0;i<8;i++)
        {
            for(int j=0;j<8;j++)
            {
                IMatrix[i][j]=Matrix_XXE[i][j+8];
            }
        }

        double temp[1][8]={0.0};
        Mul(Y,XT,temp);//1*50 50*8
        double A_[1][8]={0.0};
        Mul(temp,IMatrix,A_);//1*8 8*8

        bool s =query.exec(QString("update Xs set a0_='%1',a1_='%2',a2_='%3',a3_='%4',a4_='%5',a5_='%6',a6_='%7',a7_='%8' where n_='%9'")
                   .arg(A_[0][0]).arg(A_[0][1]).arg(A_[0][2]).arg(A_[0][3]).arg(A_[0][4]).arg(A_[0][5]).arg(A_[0][6]).arg(A_[0][7]).arg(n));

    }

}

void Widget::on_EvaluateButton_clicked()
{
    double Rand(int i,double Xmax,double Xmin);
   for(int n=1;n<8;n++){
        //计算Y的标准差和Y‘的标准差
        //把原a和拟合a的数据传入函数中
        QSqlQuery query;
        query.exec("select 1 from X");
        query.next();
        double a[8];
        query.exec(QString("select a0 from X where n='%1'").arg(n));
        query.next();
        a[0]=query.value(0).toDouble();
        query.exec(QString("select a1 from X where n='%1'").arg(n));
        query.next();
        a[1]=query.value(0).toDouble();
        query.exec(QString("select a2 from X where n='%1'").arg(n));
        query.next();
        a[2]=query.value(0).toDouble();
        query.exec(QString("select a3 from X where n='%1'").arg(n));
        query.next();
        a[3]=query.value(0).toDouble();
        query.exec(QString("select a4 from X where n='%1'").arg(n));
        query.next();
        a[4]=query.value(0).toDouble();
        query.exec(QString("select a5 from X where n='%1'").arg(n));
        query.next();
        a[5]=query.value(0).toDouble();
        query.exec(QString("select a6 from X where n='%1'").arg(n));
        query.next();
        a[6]=query.value(0).toDouble();
        query.exec(QString("select a7 from X where n='%1'").arg(n));
        query.next();
        a[7]=query.value(0).toDouble();

        double a_[8];
        query.exec(QString("select a0_ from Xs where n='%1'").arg(n));
        query.next();
        a_[0]=query.value(0).toDouble();
        query.exec(QString("select a1_ from Xs where n='%1'").arg(n));
        query.next();
        a_[1]=query.value(0).toDouble();
        query.exec(QString("select a2_ from Xs where n='%1'").arg(n));
        query.next();
        a_[2]=query.value(0).toDouble();
        query.exec(QString("select a3_ from Xs where n='%1'").arg(n));
        query.next();
        a_[3]=query.value(0).toDouble();
        query.exec(QString("select a4_ from Xs where n='%1'").arg(n));
        query.next();
        a_[4]=query.value(0).toDouble();
        query.exec(QString("select a5_ from Xs where n='%1'").arg(n));
        query.next();
        a_[5]=query.value(0).toDouble();
        query.exec(QString("select a6_ from Xs where n='%1'").arg(n));
        query.next();
        a_[6]=query.value(0).toDouble();
        query.exec(QString("select a7_ from Xs where n='%1'").arg(n));
        query.next();
        a_[7]=query.value(0).toDouble();


        //从数据库中读取Xmin和Xmax
        query.exec(QString("select Xmax from X where n='%1'").arg(n));
        query.next();
        double Xmax=query.value(0).toDouble();

        query.exec(QString("select Xmin from X where n='%1'").arg(n));
        query.next();
        double Xmin=query.value(0).toDouble();

        //随机生成五十个X数据
        double X[50]={0.0};
        for(int i=0;i<50;i++)
        {
            X[i]=Rand(i,Xmax,Xmin);
        }
        //利用50个X数据得到50个Y数据
        double Y[50],Y_[50];
        for(int i=0;i<50;i++)
        {
            Y[i]=a[0]+a[1]*X[i]+a[2]*pow(X[i],2)+a[3]*pow(X[i],3)+a[4]*pow(X[i],4)+a[5]*pow(X[i],5)+a[6]*pow(X[i],6)+a[7]*pow(X[i],7);
        }
        for(int i=0;i<50;i++)
        {
            Y_[i]=a_[0]+a_[1]*X[i]+a_[2]*pow(X[i],2)+a_[3]*pow(X[i],3)+a_[4]*pow(X[i],4)+a_[5]*pow(X[i],5)+a_[6]*pow(X[i],6)+a_[7]*pow(X[i],7);
        }
        //计算Y的均方差
        double Ys=0.00;
        for(int i=0;i<50;i++)
        {
            Ys+=Y[i];
        }
        for(int i=0;i<50;i++)
        {
            Ys+=Y_[i];
        }
        double Yp=0.0;
        Yp=Ys/100.0;
        double Yss=0.00;
        for(int i=0;i<50;i++)
        {
            Yss+=(Y[i]-Yp)*(Y[i]-Yp);
        }
        for(int i=0;i<50;i++)
        {
            Yss+=(Y_[i]-Yp)*(Y_[i]-Yp);
        }
        double Yb=sqrt(Yss/100.0);
        QMessageBox::information(this,tr("评估结果"),tr("Y的均方差为%1").arg(Yb),
                                QMessageBox::Ok);
    }
}

void Widget::on_submitButton_clicked()
{
    if (ui->oldpwdlineEdit->text().isEmpty() ||
    ui->newpwdlineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, tr("警告"), tr("请将信息填写完整！ "),
        QMessageBox::Ok);
    } else{
        QSqlQuery query;
        query.exec("select pwd from password");
        query.next();
        if (query.value(0).toString() == ui->oldpwdlineEdit->text())
        {
            bool temp = query.exec(QString("update password set pwd='%1' where id='01'")
            .arg(ui->newpwdlineEdit->text()));
            if (temp){
                QMessageBox::information(this, tr("提示"), tr("密码修改成功！ "),
                QMessageBox::Ok);
                ui->oldpwdlineEdit->clear();
                ui->newpwdlineEdit->clear();
            } else {
                QMessageBox::information(this, tr("提示"),
                tr("密码修改失败， 无法访问数据库！ "),
                QMessageBox::Ok);
            }
        } else{
            QMessageBox::warning(this, tr("警告"), tr("原密码错误， 请重新填写！ "),

                                 QMessageBox::Ok);
        ui->oldpwdlineEdit->clear();
        ui->newpwdlineEdit->clear();
        ui->oldpwdlineEdit->setFocus();
        }
    }
}

void Widget::on_pushButton_clicked()
{

    QString name=ui->nameline->text();
    int n =ui->nspinBox->text().toInt();
    double Xmax=ui->XmaxdoubleSpinBox->text().toDouble();
    double Xmin=ui->XmindoubleSpinBox->text().toDouble();
    double a0=ui->a0SpinBox->text().toDouble();
    double a1=ui->a1SpinBox->text().toDouble();
    double a2=ui->a2SpinBox->text().toDouble();
    double a3=ui->a3SpinBox->text().toDouble();
    double a4=ui->a4SpinBox->text().toDouble();
    double a5=ui->a5SpinBox->text().toDouble();
    double a6=ui->a6SpinBox->text().toDouble();
    double a7=ui->a7SpinBox->text().toDouble();

    QSqlQuery query;
    query.exec("select 1 from X");
    query.next();

    bool t,s,t_,s_;
    switch (ui->nspinBox->text().toInt()) {

        case 1: {t=query.exec(QString("update X set name='%1',Xmax='%2',Xmin='%3' where n='01'")
                                         .arg(name).arg(Xmax).arg(Xmin));
                s=query.exec(QString("update X set a0='%1',a1='%2',a2='%3' where n='01'")
                                    .arg(a0).arg(a1));
                t_=query.exec(QString("update Xs set name_='%1',Xmax_='%2',Xmin_='%3' where n_='01'")
                                                         .arg(name).arg(Xmax).arg(Xmin));
                break;}
        case 2: {t=query.exec(QString("update X set name='%1',Xmax='%2',Xmin='%3' where n='02'")
                              .arg(name).arg(Xmax).arg(Xmin));
                 s=query.exec(QString("update X set a0='%1',a1='%2',a2='%3' where n='02'")
                            .arg(a0).arg(a1).arg(a2));
                 t_=query.exec(QString("update Xs set name_='%1',Xmax_='%2',Xmin_='%3' where n_='02'")
                                               .arg(name).arg(Xmax).arg(Xmin));
                 break;}
        case 3: {t=query.exec(QString("update X set name='%1',Xmax='%2',Xmin='%3' where n='03'")
                              .arg(name).arg(Xmax).arg(Xmin));
                 s=query.exec(QString("update X set a0='%1',a1='%2',a2='%3',a3='%4' where n='03'")
                     .arg(a0).arg(a1).arg(a2).arg(a3));
                 t_=query.exec(QString("update Xs set name_='%1',Xmax_='%2',Xmin_='%3' where n_='03'")
                                               .arg(name).arg(Xmax).arg(Xmin));
                break;}
        case 4: {t=query.exec(QString("update X set name='%1',Xmax='%2',Xmin='%3' where n='04'")
                              .arg(name).arg(Xmax).arg(Xmin));
                s=query.exec(QString("update X set a0='%1',a1='%2',a2='%3',a3='%4',a4='%5' where n='04'")
                       .arg(a0).arg(a1).arg(a2).arg(a3).arg(a4));
                t_=query.exec(QString("update Xs set name_='%1',Xmax_='%2',Xmin_='%3' where n_='04'")
                                              .arg(name).arg(Xmax).arg(Xmin));

                break;}
        case 5: {t=query.exec(QString("update X set name='%1',Xmax='%2',Xmin='%3' where n='05'")
                              .arg(name).arg(Xmax).arg(Xmin));
                s=query.exec(QString("update X set a0='%1',a1='%2',a2='%3',a3='%4',a4='%5',a5='%6' where n='05'")
                       .arg(a0).arg(a1).arg(a2).arg(a3).arg(a4).arg(a5));
                t_=query.exec(QString("update Xs set name_='%1',Xmax_='%2',Xmin_='%3'  where n_='05'")
                                              .arg(name).arg(Xmax).arg(Xmin));
                break;}
        case 6: {t=query.exec(QString("update X set name='%1',Xmax='%2',Xmin='%3' where n='06'")
                              .arg(name).arg(Xmax).arg(Xmin));
                s=query.exec(QString("update X set a0='%1',a1='%2',a2='%3',a3='%4',a4='%5',a5='%6',a6='%7' where n='06'")
                      .arg(a0).arg(a1).arg(a2).arg(a3).arg(a4).arg(a5).arg(a6));
                t_=query.exec(QString("update Xs set name_='%1',Xmax_='%2',Xmin_='%3' where n_='06'")
                                              .arg(name).arg(Xmax).arg(Xmin));
                break;}
        case 7: {t=query.exec(QString("update X set name='%1',Xmax='%2',Xmin='%3' where n='07'")
                              .arg(name).arg(Xmax).arg(Xmin));
                s=query.exec(QString("update X set a0='%1',a1='%2',a2='%3',a3='%4',a4='%5',a5='%6',a6='%7',a7='%8' where n='07'")
                      .arg(a0).arg(a1).arg(a2).arg(a3).arg(a4).arg(a5).arg(a6).arg(a7));
                t_=query.exec(QString("update Xs set name_='%1',Xmax_='%2',Xmin_='%3' where n_='07'")
                                              .arg(name).arg(Xmax).arg(Xmin));
                break;}
        default:{
                    t=s=t_=s_=false;
            QMessageBox::information(this,tr("提示"),
                                     tr("输入函数次数错误，请重新输入"),
                                     QMessageBox::Ok);
            break;
        }
    }


    if ( t&&s ) {
        QMessageBox::information(this, tr("提示"), tr("数据提交成功！ "),
        QMessageBox::Ok);
        ui->oldpwdlineEdit->clear();
        ui->newpwdlineEdit->clear();
    } else {
        QMessageBox::information(this, tr("提示"),
        tr("提交数据失败， 无法访问数据库！ "),
        QMessageBox::Ok);
    }
}

void Widget::on_pushButton_2_clicked()
{
    ui->nameline->clear();
    ui->nspinBox->setValue(0);
    ui->XmaxdoubleSpinBox->setValue(0);
    ui->XmindoubleSpinBox->setValue(0);
    ui->a0SpinBox->setValue(0);
    ui->a1SpinBox->setValue(0);
    ui->a2SpinBox->setValue(0);
    ui->a3SpinBox->setValue(0);
    ui->a4SpinBox->setValue(0);
    ui->a5SpinBox->setValue(0);
    ui->a6SpinBox->setValue(0);
    ui->a7SpinBox->setValue(0);
}

void Widget::on_showButton_clicked()
{
    model->setTable("X");
    model->select();
    model_->setTable("Xs");
    model_->select();
}

void Widget::on_FindnameButton_clicked()
{

    if(ui->comboBox->isEnabled()){
        QString n=ui->comboBox->currentText();
        model->setFilter(QString("n='%1'").arg(n.toInt()));
        model_->setFilter(QString("n_='%1'").arg(n.toInt()));
    }
    model->select();
    model_->select();
}

