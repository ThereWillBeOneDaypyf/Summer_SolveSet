#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int all_l = n * (a - b);
        int all_r = n * (a + b);
        if(all_r < c - d || all_l > c + d)
        {
            cout << "No" << endl;
        }
        else 
        {
            cout << "Yes" << endl;
        }
    }
}