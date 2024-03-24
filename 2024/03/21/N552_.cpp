#include <iostream>
using namespace std;
int a[10] = {0};    //用来存储第i行存储在第几列
int count, n;

//判断row行的y列是否可用
bool valid(int row, int y)
{
    //判断前row-1行中有无与y冲突的列
    for (int i = 1; i < row; i++)
    {
        if (a[i] == y)                              //前row-1行中有行存在第y列不可用
            return false;
        if ((a[i] + i == row + y) && (row - i) < 3) //前row-1行中有列存在和第y列在反对角线上不可用
            return false;
        if ((row - i == y - a[i]) && (row - i) < 3) //前row-1行中有列存在和第y列在正对角线上不可用
            return false;
    }

    return true;
}

void dfs(int row)
{
    //前row行均以排完，方案数加一
    if (row == n + 1)
    {
        count++;
        return;
    }

    //依次判断1到n列有无可用
    for (int i = 1; i <= n; i++)
    {
        if (valid(row, i))  //row行i列可用
        {
            a[row] = i;     //row行存在第i列
            dfs(row + 1);   //处理下一行
            a[row] = 0;     //重置便与尝试新方案
        }
    }
}

int main()
{
    cin >> n;

    dfs(1);

    cout << count;

    return 0;
}