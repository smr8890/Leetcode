#include <iostream>
using namespace std;

int count = 0;
int chess[8][8] = {0};

bool check(int row, int column)
{
    int i, j;
    for (i = 0; i < 8; ++i)
    {
        if (chess[i][column] == 1)
        {
            return false;
        }
    }

    for (i = row, j = column; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    for (i = row, j = column; i >= 0 && j < 8; i--, j++)
    {
        if (chess[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void Print()
{
    int row, column;
    for (row = 0; row < 8; ++row)
    {
        for (column = 0; column < 8; ++column)
        {
            if (chess[row][column] == 1)
            {
                cout << column + 1;
            }
        }
    }
    cout << endl;
}

void EightQueen(int row, int b)
{
    int column;
    if (row > 7)
    {
        count++;
        if (count == b)
        {
            Print();
        }
        return;
    }

    for (column = 0; column < 8; ++column)
    {
        if (check(row, column))
        {
            chess[row][column] = 1;
            EightQueen(row + 1, b);
            chess[row][column] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int b;
        cin >> b;
        count = 0;
        EightQueen(0, b);
    }
}
