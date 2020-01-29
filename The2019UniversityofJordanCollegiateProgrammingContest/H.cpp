#include <bits/stdc++.h>
using namespace std;

const double pi = 3.1415926535;

int main()
{
    double n, s;
    while(cin >> n >> s)
    {
        double alpha = pi / n;
        double r = s / sin(alpha);
        r /= 2;
        printf("%.6lf\n", pi * r * r);
    }
}