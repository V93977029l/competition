#include <iostream>
using namespace std;
int main()
{
	int a[6][2] = { {0, 0}, {24, 10}, {2, 3}, {9, 4}, {10, 5}, {9, 4} }, b[6][14] = { 0 };
	for (int i = 1; i <6 ; i++)
	{
		for (int j = 1; j <=13 ; j++)
		{
			if (j >= a[i][1]) {
				if (a[i][0]+ b[i - 1][j - a[i][1]] >b[i - 1][j])
				{
					b[i][j] = a[i][0]+b[i - 1][j - a[i][1]];
				}
			}
		}
	}
	cout << b[5][13];
}