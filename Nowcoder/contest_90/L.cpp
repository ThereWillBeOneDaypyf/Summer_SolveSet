#include<bits/stdc++.h>
using namespace std;

#define eps 1e-6


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        long long x,a,y,b;
        cin >> x >> a >> y >> b;
        double res_x = 1.0 * a * log10(1.0 * x);
        double res_y = 1.0 * b * log10(1.0 * y);
        if(abs(res_x - res_y) <= eps)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}