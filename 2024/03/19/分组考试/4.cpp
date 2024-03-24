#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main()
{
    int n, count = 0;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (array[i] / 3 == 0)
            count++;
    }
    
    cout << count << endl;
    
    return 0;
}