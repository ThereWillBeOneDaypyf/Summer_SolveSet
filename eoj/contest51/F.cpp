#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x,y,z;
    while(cin >> y >> x >> z)
    {
        double ans = 2 * x - z + y;
        ans /= 2;
        if(ans <= 0 || z <= x || z <= y || ans >= x || ans >= z || ans >= y)
            cout << "Wrong" << endl;
        else
            cout << fixed << setprecision(2) << ans << endl;
    }
}