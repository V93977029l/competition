#include <stdio.h>
#include <math.h>

#define PI acos(-1)

// 将角度转换为弧度
double to_radian(double angle) {
    return angle * PI / 180;
}

int main() {
    double a, b;    // 两边
    double angle;   // 角度
    double S;       // 面积
    double c;       // 第三条边

    scanf("%lf %lf %lf", &a, &b, &angle);

    double radian = to_radian(angle);
    S = a * b * sin(radian) / 2;
    c = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(radian));

    printf("c=%.2f\tarea=%.2f\n", c, S);

    return 0;
}
