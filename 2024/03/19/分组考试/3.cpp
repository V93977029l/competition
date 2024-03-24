#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    char x, y, z;
    cin >> x >> y >> z;

    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    if (y > z)
    {
        int temp = y;
        y = z;
        z = temp;
    }
    if (x > z)
    {
        int temp = x;
        x = z;
        z = temp;
    }
    
    cout << x << y << z << endl;
    
    return 0;
}