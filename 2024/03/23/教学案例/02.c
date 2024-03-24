#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main() {
    double a, b;    //两边
    double angle;   //角度

    scanf("%lf %lf %lf", &a, &b, &angle);

    double radian = angle * PI / 180;                                   //将角度转换为弧度
    double S = a * b * sin(radian) / 2;                                 //面积
    double c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(radian));   //第三条边

    printf("c=%.2f\tarea=%.2f\n", c, S);

    return 0;
}
