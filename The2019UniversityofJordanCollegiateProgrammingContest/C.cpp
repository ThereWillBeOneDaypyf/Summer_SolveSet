#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long s,x;
    while(cin >> s >> x)
    {
        int cnt = 0;
        long long base = 1;
        while(base <= s)
        {
            cnt ++;
            base *= x;
        }
        cout << cnt << endl;
    }
}