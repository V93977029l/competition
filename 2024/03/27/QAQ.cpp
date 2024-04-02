#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        for (int j = 0; j < i; j++)
        {
            if (temp < a[j])
            {
                for (int k = i; k > j; k--)
                {
                    a[k] = a[k - 1];
                }
                a[j] = temp;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }

    delete []a;

    return 0;
}
