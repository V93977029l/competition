#include <bits/stdc++.h>
using namespace std;

struct hush
{
    char c;
    int num;
} t1[101], t2[101];

char str1[101], str2[101];

int main()
{
    cin.getline(str1, 101);
    getchar();
    cin.getline(str2, 101);

    int n;
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 == n2)
    {
        n = n1;
    }

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = i + 1; j < m; j++)
        {
            if (str1[i] == t1[j].c)
            {
                t1[j].num++;
                flag = false;
            }
        }
        if (flag)
        {
            t1[m].c = str1[i];
            t1[m].num++;
            m++;
        }
    }
}