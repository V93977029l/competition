#include <iostream>
using namespace std;

const int N = 1e5 + 1;
int h[N], w[N];
int n, k;

bool check(int x) // 边长为x的正方形
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (h[i] / x) * (w[i] / x);
    }

    if (sum >= k)
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
    }

    // 二分法判断边长
    int l = 1;
    int r = 100000;
    int max = 0;
    while (l <= r)  // 注意判断条件包括=
    {
        int mid = (l + r) / 2;
        if (check(mid)) // mid边长是满足的
        {
            max = mid;
            l = mid + 1;    // 要求最大边长，还需要继续判断
        }
        else
        {
            r = mid - 1;    // 说明不满足，需要缩减边长
        }
    }
    cout << max;
    return 0;
}
