#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;

// 2021 国赛---和与乘积 前缀和

//文字描述看不懂的看例子,表达起来确实有点抽象
//这道题的解就是：原序列长度+拓展后的个数


/**********************************************************************************************
*例如:1 1 3 2 2 1 1 1 
*
*w[N]表示原序列删去非1的序列 w[] = 3 2 2
*sum[N]表示原序列删去非1的序列的前缀和(要包括删去1的值)  sum[] = 5 7 9 (注意最后三个1没有加进去)
*onecnt[N]表示原序列删去非1的序列的1的个数  onecnt[] = 2 0 3   最后一个是特例,是为了记录结尾是1的个数
***********************************************************************************************/
ll w[N], sum[N], onecnt[N];

void sovle() {
    int n;
    cin >> n;
    // i控制输入,j控制存储非一的数
    int j = 1;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            sum[j]++;  // 这一步是为了下面sum+将删去的1值带上
            onecnt[j]++;
        } else {
            sum[j] += sum[j - 1] + num;
            w[j++] = num;
        }
    }
    ll res = sum[j - 1] + onecnt[j];//记录最大的乘积
    ll ans = n;//由题意知 每个数单独成为一种情况

    for (int i = 1; i < j; i++) {
        ll p = w[i];
        for (int k = i + 1; k < j; k++) {
            p *= w[k];
            if (p > res)
                break;
            ll d = p - sum[k] + sum[i - 1] + onecnt[i];
            if (!d)
                ans++;
            else if (onecnt[i] + onecnt[k + 1] >= d && d > 0) {
                ll left = min(d, onecnt[i]);
                ll right = min(d, onecnt[k + 1]);
                ans += left + right - d + 1;

                /*******************************************************
                例子:1 1 1 1 3 2 2 1 1 1 1 1
                sum=3+2+2=7
                mul=3*2*2=12
                d=5
                所有往左边、右边、左边和右边拓展
                    left = min(d, onecnt[i]),则left=4,左边只有4个1
                    right = min(d, onecnt[k + 1]),则right=5,右边有5个1
                首先，向左边和右边拓展
                    1 4  ---  2 3  -- 3 2  --- 4 1   有48种
                其次,向右边拓展   0 5   1种
                    4+1=5
                left+right-d+1=4+5-5+1=5种

                其实都可以看作向左边和右边拓展
                假设左有2右有1 d=3
                l+r-d=3-3=0因为有一种方案所有需要加上1
                *******************************************************/
            }
        }
    }
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    while (T--)
        sovle();

    //system("pause");
    return 0;
}