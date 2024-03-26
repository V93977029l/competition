#include <bits/stdc++.h>
using namespace std;

string line_;

void identify()
{
    int b = line_.length();
    for (int i = 0; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
        {
            if (line_[i] == line_[j])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }

    cout << "YES" << endl;
}

int main()
{
    getline(cin, line_);

    identify();

    return 0;
}