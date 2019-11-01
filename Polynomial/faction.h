#ifndef FACTION_H
#define FACTION_H
#include<cmath>

void Mul(const double A[8][50],const double B[50][8],double C[8][8])

{
    for(int m=0;m<8;m++)
    {
        for(int n=0;n<8;n++)
        {
            for(int k=0;k<50;k++)
                C[m][n]+=A[m][k]*B[k][n];
        }
    }
    for(int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++) {
           if(abs(C[i][j])<pow(6,-6))
             {
                 C[i][j]=0;
             }
       }
   }
}

void Mul(const double A[8][8], const double B[8][8], double C[8][8])
{
    for (int m = 0; m < 8; m++)
    {
        for (int n = 0; n < 8; n++)
        {
            for (int k = 0; k < 8; k++)
                C[m][n] += A[m][k] * B[k][n];
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            if (abs(C[i][j]) < pow(6, -6))
            {
                C[i][j] = 0;
            }
    }
}
double Rand(int i,double Xmax,double Xmin){
    srand(i);
    double x=0.0;
    return x=rand()%((int)Xmax-(int)Xmin+1)+(rand()/(double)RAND_MAX);
    if(x>=Xmin&&x<=Xmax)
        return x;
    else
        Rand(i,Xmax,Xmin);
}
#endif // FACTION_H
