#include <iostream>
using namespace std;

long long num = 0;

long long n, m, r, c, w;

enum direction {
	up_d,
	right_d,
	down_d,
	left_d
} d;

int main()
{
	cin >> n >> m >> r >> c;

	long long temp_1 = n - r;
	long long temp_2 = m - c;

	r--;
	c--;

	w = r;
	d = up_d;
	if (temp_2 < w)
	{
		w = temp_2;
		d = right_d;
	}
	if (temp_1 < w)
	{
		w = temp_1;
		d = down_d;
	}
	if (c < w)
	{
		w = c;
		d = left_d;
	}

	// 求出外圈的数量w,朝向d
	num += 4 * w * w + 2 * (n - 2 * w + m - 2 * w) * w;
	if (d == up_d)
		num += c - w + 1;
	else if (d == right_d)
		num += m - 2 * w + r - w;
	else if (d == down_d)
		num += m - 2 * w + n - 2 * w + (m - c - 1) - w - 1;
	else
		num += 2 * (m - 2 * w) + n - 2 * w + (n - r - 1) - w - 2;

	cout << num;

	return 0;
}
