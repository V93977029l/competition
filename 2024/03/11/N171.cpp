#include <bits/stdc++.h>
using namespace std;

void printTriangle(int n) {
    int num = 1; // 用于打印的数字
    for (int i = 1; i <= n; ++i) {
        // 打印前导空格
        for (int j = i; j < n; ++j) {
            cout << ".";
        }
        // 打印数字和点
        for (int j = 1; j <= i * 2 - 1; ++j) {
            if (j % 2 == 0) cout << ".";
            else {
                cout << num;
                num++; // 更新数字
                if (num == 10) num = 1; // 如果数字达到10，则重置为1
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n; // 输入三角形的高度
    printTriangle(n); // 打印三角形
    return 0;
}