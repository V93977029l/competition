#include <iostream>
using namespace std;

int n;
long long count,sum = 0;
long long a[200000];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; i++) {
        sum -= a[i];
        count += a[i] * sum;
    }
    
    cout << count;

    return 0;
}