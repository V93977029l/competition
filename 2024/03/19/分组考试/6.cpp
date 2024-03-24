#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct replace_
{
    int fir;
    int sec;
    string str;
};

int main()
{
    int N;
    string str;
    getline(cin, str);
    cin >> N;
    vector<replace_> arr(N);
    for (int i = 0; i < N; i++)
    {
        cout << arr[i].fir << arr[i].sec << arr[i].str;
    }
    
    for (int i = 0; i < N; i++)
    {
        str.erase(arr[i].fir - 1, arr[i].sec - arr[i].fir + 1);
        str.insert(arr[i].fir - 1,arr[i].str);
    }
    
    cout << str << endl;
    
    return 0;
}