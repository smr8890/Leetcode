#include<iostream>
using namespace std;
//考察矩阵运算，综合了线性代数知识
int n,d;
int Q[101][11],KT[11][101],V[101][11];//此处，转置这个行为可以在一开始输入的时候就完成
int W[101];
long long temp[101][101],temp2[101][11];//临时变量保存
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
            cin>>Q[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
            cin>>KT[j][i]; //矩阵转置可以在一开始就完成，将列输入成行的形式

    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
            cin>>V[i][j];

    for(int i=1;i<=n;i++)
        cin>>W[i];
    //完成输入

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=d;k++)
                temp[i][j]+=Q[i][k]*KT[k][j];//矩阵乘法的形式，由计算可知为n*n
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            temp[i][j]=temp[i][j]*W[i];//W[i]因为每个都要乘他的数
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=d;j++)
        {
            for(int k=1;k<=n;k++)
                temp2[i][j]+=temp[i][k]*V[k][j];//矩阵乘法的形式，由计算可知为n*d
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=d;j++)
            cout<<temp2[i][j]<<" ";
        cout<<endl;
    }
}