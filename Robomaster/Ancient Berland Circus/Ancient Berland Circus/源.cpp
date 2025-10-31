#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-4;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double a1 = 2 * (x2 - x1);
    double b1 = 2 * (y2 - y1);
    double c1 = x2 * x2 - x1 * x1 + y2 * y2 - y1 * y1;
    double a2 = 2 * (x3 - x1);
    double b2 = 2 * (y3 - y1);
    double c2 = x3 * x3 - x1 * x1 + y3 * y3 - y1 * y1;

    double det = a1 * b2 - a2 * b1;
    double x = (c1 * b2 - c2 * b1) / det;
    double y = (a1 * c2 - a2 * c1) / det;

    double r = sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));

    double dx1 = x1 - x, dy1 = y1 - y;
    double dx2 = x2 - x, dy2 = y2 - y;
    double dx3 = x3 - x, dy3 = y3 - y;

    double len1 = sqrt(dx1 * dx1 + dy1 * dy1);
    double len2 = sqrt(dx2 * dx2 + dy2 * dy2);
    double len3 = sqrt(dx3 * dx3 + dy3 * dy3);

    double dot1 = (dx1 * dx2 + dy1 * dy2) / (len1 * len2);
    if (dot1 > 1.0) dot1 = 1.0;
    if (dot1 < -1.0) dot1 = -1.0;
    double alpha1 = acos(dot1);

    double dot2 = (dx2 * dx3 + dy2 * dy3) / (len2 * len3);
    if (dot2 > 1.0) dot2 = 1.0;
    if (dot2 < -1.0) dot2 = -1.0;
    double alpha2 = acos(dot2);

    double dot3 = (dx3 * dx1 + dy3 * dy1) / (len3 * len1);
    if (dot3 > 1.0) dot3 = 1.0;
    if (dot3 < -1.0) dot3 = -1.0;
    double alpha3 = acos(dot3);

    for (int n = 3; n <= 100; n++) 
    {
        double theta = 2 * PI / n;
        for (int i1 = 0; i1 < 2; i1++) 
        {
            double a1_val = (i1 == 0) ? alpha1 : 2 * PI - alpha1;
            for (int i2 = 0; i2 < 2; i2++) 
            {
                double a2_val = (i2 == 0) ? alpha2 : 2 * PI - alpha2;
                if (a1_val + a2_val > 2 * PI + eps) continue;
                double a3_val = 2 * PI - a1_val - a2_val;
                if (a3_val < -eps || a3_val > 2 * PI + eps) continue;
                if (fabs(a3_val - alpha3) < eps || fabs(a3_val - (2 * PI - alpha3)) < eps) 
                {
                    double k1 = a1_val / theta;
                    double k2 = a2_val / theta;
                    double k3 = a3_val / theta;
                    int k1_int = round(k1);
                    int k2_int = round(k2);
                    int k3_int = round(k3);
                    if (fabs(k1 - k1_int) < eps && fabs(k2 - k2_int) < eps && fabs(k3 - k3_int) < eps)
                    {
                        if (k1_int + k2_int + k3_int == n) 
                        {
                            double area = 0.5 * n * r * r * sin(2 * PI / n);
                            printf("%.8lf\n", area);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}