#include<iostream>
#include<stdio.h>
using namespace std;

int A[501][501];
enum  Choice
{
    rightTowards,    //向右移动
    rightUp,         //向右上移动
    down,            //向下移动
    leftDown         //向左下移动
};

void zigzagScan(int n)
{
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        cin >> A[i][j];
    int row = 0, col = 0;
    Choice choice = rightTowards;
    //row = n-1&&col = n-1的情况在while循环结束后处理，防止出现越界的情况
    while (row != n - 1 || col != n - 1)
    {
        cout << A[row][col] << ' ';
        switch (choice)
        {
        case rightTowards:
            col++;
            if (row == 0)
                choice = leftDown;
            else
                choice = rightUp;
            break;
        case rightUp:
            row--;
            col++;
            if (row == 0 && col != n - 1)
                choice = rightTowards;
            else if (col == n - 1)
                choice = down;
            else
                choice = rightUp;
            break;
        case down:
            row++;
            if (col == 0)
                choice = rightUp;
            else
                choice = leftDown;
            break;
        case leftDown:
            row++;
            col--;
            if (col == 0 && row != n - 1)
                choice = down;
            else if (row == n - 1)
                choice = rightTowards;
            else
                choice = leftDown;
            break;
        }
    }
    cout << A[n - 1][n - 1];
}

int main()
{
    int n;
    scanf("%d",&n);
    zigzagScan(n);
    
return 0;
}
