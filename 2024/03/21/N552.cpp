#include <iostream>
using namespace std;
typedef long long LL;

int *x;         //数列
int n;          //皇后的个数
int num = 0;    //解的个数

//判断该位置是否可以摆放
bool constraion(int k)
{
    for(int i = 0; i < k; i++)
    {
        if((x[i] == x[k]) || (i = k) || ((abs(x[i] - x[k]) == k - i) && (k - i < 3)))
        {
            return false;
        }
    }
    return true;
}

//输出解
void output()
{
    cout << num << endl;
}

//遍历所有可能
int function()
{
    //第一行的第i个的位置
    for(int i = 0; i < n; i++)
    {
        x[1] = i;
        for(int j =0; j < n; j++)
        {
            if(!constraion(j))
            {
                
            }
        }
    }
}

int main()
{
    cin >> n;

    x = new int[n + 1];

    return 0;
}