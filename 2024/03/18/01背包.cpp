#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define DEBUG_LOCAL

int knapsackDP(const vector<int>& weights, const vector<int>& values, int W)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            if (weights[i - 1] <= w)    // 如果当前物品可以加入背包
            {                
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
            else    // 如果当前物品不可以加入背包
            {                
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main()
{
    #ifdef DEBUG_LOCAL
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    vector<int> weights = {10, 3, 4, 5, 4}; // 物品重量
    vector<int> values = {24, 3, 9, 10, 9}; // 物品价值
    int W = 13; // 背包最大容量

    auto max_value = knapsackDP(weights, values, W);
    cout << "最大价值为: " << max_value << endl;

    #ifdef DEBUG_LOCAL
    fclose(stdin);
    fclose(stdout);
    #endif

    return 0;
}

