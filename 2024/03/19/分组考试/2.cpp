#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int m, n;
    cin >> m >> n;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}