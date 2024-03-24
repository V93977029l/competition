#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k1, k2, num, flag, a[25], b[25], vis[25][25], s[600];
const int v[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

#define DEBUG_LOCAL
struct current
{
    int x, y ,k;
};

stack<current> cs;

void dfs(int x, int y)
{
    current c;
    c.x = x;
    c.y = y;
    c.k = 1;
    cs.push(c);
    while (!cs.empty())
    {
        c = cs.top();
        if(flag == 1)
        {
            cs.pop();
            continue;
        }
        if (c.x == n)
        {
            
        }
        
    }
    
    return ;
}

int main()
{
#ifdef DEBUG_LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "r", stdout);
#endif
    cin >> n;
    k1 = 0;
    k2 = 0;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
        k1 += a[i];
    }
        for (int i = 0; i <= n; i++)
    {
        cin >> b[i];
        k2 += b[i];
    }
    flag = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            vis[i][j] = 0;
        }
    }
    vis[1][1] = 1;
#ifdef DEBUG_LOCAL
    fclose(stdin);
    fclose(stdout);
#endif
}