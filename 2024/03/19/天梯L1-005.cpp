#include <bits/stdc++.h>
using namespace std;

int N, M;
struct student
{
    string ID;
    int tempNum;
    int realNum;
};

int main()
{
    cin >> N;
    vector<student> dataList(N);
    for (int i = 0; i < N; i++)
    {
        cin >> dataList[i].ID >> dataList[i].tempNum >> dataList[i].realNum;
    }
    
    cin >> M;
    vector<int> indexNum(M);
    for (int i = 0; i < M; i++)
    {
        cin >> indexNum[i];
    }

    for (int i = 0; i < M; i++)
    {
        int thisIndex = indexNum[i];
        for (int j = 0; j < N; j++)
        {
            if (dataList[j].tempNum == thisIndex)
            {
                cout << dataList[j].ID << " " << dataList[j].realNum << endl;
                continue;
            }
        }
    }
    return 0;
}