#include <stdio.h>

int count = 0;
int chess[8][8]={0};

int notDanger( int row, int col )
{
    int i,k;
    // 判断列方向
    for( i=0; i < 8; i++ )
    {
        if( chess[i][col]==1 )
        {
            return 0;
        }
    }
    // 判断左对角线
    for( i=row, k=col; i>=0 && k>=0; i--, k-- )
    {
        if(chess[i][k]==1  )
        {
            return 0;
        }
    }
    // 判断右对角线
    for( i=row, k=col; i>=0 && k<8; i--, k++ )
    {
        if(chess[i][k]==1  )
        {
            return 0;
        }
    }
    return 1;
}

void Print()          //打印结果
{
    int row,col;
    printf("第 %d 种\n", count+1);
    for( row=0; row < 8; row++ )
    {
        for( col=0; col< 8; col++ )
        {
            if(chess[row][col]==1)        //皇后用‘0’表示
            {
                printf("%d",col+1);
            }
        }
    }
    printf("\n");
}

void EightQueen( int row )
{
    int col;
    if( row>7 )                       //如果遍历完八行都找到放置皇后的位置则打印
    {
        Print();                       //打印八皇后的解
        count++;
        return ;

    }

    for( col=0; col < 8; col++ )        //回溯，递归
    {
        if( notDanger( row, col ) )    // 判断是否危险
        {
            chess[row][col]=1;
            EightQueen(row+1);

            chess[row][col]=0;           //清零，以免回溯时出现脏数据
        }
    }
}

int main()
{
    EightQueen(0);
    printf("count %d \n\n", count);
    return 0;
}