#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        int need = 6 - max(n,m) + 1;
        int tar = max(n,m);
        int gcd = __gcd(need,6);
        cout << need / gcd << "/" << 6 / gcd << endl;
    }
}
