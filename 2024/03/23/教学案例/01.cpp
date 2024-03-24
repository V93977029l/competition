#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)

//把角度化为弧度
double to_radian(double angle)
{
    return angle * PI / 180;
}

int main()
{
    double a, b;    //两边
    double angle;   //角度
    double S;       //面积
    double c;       //第三条边

    cin >> a >> b >> angle;

    double radian = to_radian(angle);
    S = a * b * sin(radian) / 2;
    c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(radian));

    cout << fixed << setprecision(2) << "c=" << c << "\tarea="<< S << endl;

    return 0;
}