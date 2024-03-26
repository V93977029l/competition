#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int mi = INT_MIN, mx = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;

        int r = a / b, l = a / (b + 1) + 1;
        mi = max(mi, l), mx = min(mx, r);
    }
    
    cout << mi << ' ' << mx << endl;

    return 0;
}
