#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int n;
    int num[6] = {0};
    for (int i = 0; i < 6; i++)
    {
        cin >> num [i];
    }
    cin >> n;
    
    // <=n输出n+1,否则输出n
    for (int i = 0; i < 6; i++)
    {
        if (num[i] <= n)
        {
            cout << n + 1;
        }
        else
        {
            cout << n;
        }
        cout << " ";
    }
    
    return 0;
}