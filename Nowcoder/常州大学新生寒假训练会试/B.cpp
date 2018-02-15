#include<bits/stdc++.h>
using namespace std;

long long solve(int n,int m)
{
    if(n  % 2 == 0 || m % 2 == 0)
       return 0;
    if(n == 1 || m == 1)
        return 1;
    return 4 * solve(n / 2, m / 2) + 1;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        cout << solve(n,m) << endl;
    }
}