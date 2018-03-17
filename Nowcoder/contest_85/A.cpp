#include<bits/stdc++.h>

const double e = 2.718281828459;

int main()
{
    int T;
    std :: cin >> T;
    while(T--)
    {
        int a,b,r;
        std :: cin >> a >> b >> r;
        double cur = pow(M_E ,a) * b;
        std :: cout.precision(r);
        std :: cout << std :: fixed << cur << std :: endl;
    }
}