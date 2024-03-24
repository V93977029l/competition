#include <iostream>
int count = 0;

int main()
{
    int n;
    scanf("%d",&n);
    count = n;

    for (int i = 2; i <= n; i++)
    {
        int x = i;
        while (x)
        {
            if (x % 10 == 2)
            {
                count--;
                break;
            }
            x /= 10;
        }
    }

    printf("%d",count);

    return 0;
}