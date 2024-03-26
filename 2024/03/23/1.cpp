#include <iostream>
using namespace std;

using ll = long long;

struct unity
{
    ll a;
    ll b;
} obj[N];   // 寻找最小的A和最大的B

int n;
const int N = 1e4 + 10;
int index_a = 0, index_b = 0;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> obj[i].a >> obj[i].b;
        ll a = obj[i].a / (obj[i].b + 1) + 1;
        ll b = obj[i].a / obj[i].b;
        obj[i].a = a;
        obj[i].b = b;
    }

    for (int i = 1; i < n; i++)
    {
        if (obj[i].a > obj[index_a].a)
        {
            index_a = i;
        }
        if (obj[i].b < obj[index_b].b)
        {
            index_b = i;
        }
    }

    cout << obj[index_a].a << ' ' << obj[index_b].b << endl;

    return 0;
}