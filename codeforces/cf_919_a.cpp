#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    int n,m;
    while(cin >> n >> m)
    {
        vector<double> v;
        for(int i = 0;i < n;i ++)
        {
            double a,b;
            cin >> a >> b;
            v.emplace_back(a / b);
        }
        auto pos = min_element(v.begin(),v.end());
        cout << fixed << setprecision(6) << 1.0 * m * (*pos) << endl;
    }
}