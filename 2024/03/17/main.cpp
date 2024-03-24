#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, k1, k2, num, flag, a[25], b[25], vis[25][25], s[600];
const int v[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

#define DEBUG_LOCAL
struct current
{
	int x, y, k, i;
};

stack<current> cs;

void dfs_1(int x, int y, int k)
{
	if (x < 1 || x > n || y < 1 || y > n)
		return;
	if (flag == 1)
		return;
	if (b[x] < 0 || a[y] < 0)
		return;
	s[k] = (x - 1) * n + (y - 1);
	if (x == n && y == n && k1 == 1 && k2 == 1)
	{
		flag = 1;
		num = k;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int xx = x + v[i][0];
		int yy = y + v[i][1];
		if (1 == vis[xx][yy])
			continue;
		b[xx]--;
		a[yy]--;
		k1--;
		k2--;
		vis[xx][yy] = 1;
		dfs_1(xx, yy, k + 1);
		b[xx]++;
		a[yy]++;
		k1++;
		k2++;
		vis[xx][yy] = 0;
	}
	return;
}

void dfs_2(int x, int y)
{
	current c;
	c.x = x;
	c.y = y;
	c.k = 1;
	c.i = 0;
	s[c.k] = (c.x - 1) * n + (c.y - 1);
	vis[x][y] = 1;
	cs.push(c);
	while (!cs.empty())
	{
		c = cs.top();
		if (flag == 1)
		{
			cs.pop();
			continue;
		}
		if (b[c.x] < 0 || a[c.y] < 0)
		{
			cs.pop();
			continue;
		}
		s[c.k] = (c.x - 1) * n + (c.y - 1);
		if (c.x == n && c.y == n && k1 == 1 && k2 == 1)
		{
			flag = 1;
			num = c.k;
			cs.pop();
			continue;
		}
		int i = 0;
		for (i = c.i + 1; i < 4; i++)
		{
			int xx = c.x + v[i][0];
			int yy = c.y + v[i][1];
			if (1 == vis[xx][yy])
				continue;
			c.x = xx;
			c.y = yy;
			c.i = i;
			vis[c.x][c.y] = 1;
			b[c.x]--;
			a[c.y]--;
			k1--;
			k2--;
			cs.push(c);
			break;
		}
		if (i == 4)
		{
			c = cs.top();
			cs.pop();
			b[c.x]++;
			a[c.y]++;
			k1++;
			k2++;
			vis[c.x][c.y] = 0;
		}
	}
	return;
}

int main(void)
{
#ifdef DEBUG_LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // DEBUG_LOCAL
	cin >> n;
	k1 = 0;
	k2 = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		k1 += a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		k2 += b[i];
	}
	flag = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			vis[i][j] = 0;
		}
	}
	flag = 0;
	vis[1][1] = 1;
	// dfs1(1, 1, 1);
	dfs_2(1, 1);
	for (int i = 1; i <= num; i++)
	{
		cout << s[i] << " ";
	}
#ifdef DEBUG_LOCAL
	fclose(stdin);
	fclose(stdout);
#endif // DEBUG_LOCAL
	return 0;
}