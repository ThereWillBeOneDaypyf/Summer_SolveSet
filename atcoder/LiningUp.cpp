#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long pow_mod(int a, int n)
{
    if(!n)
        return 1;
    long long res = pow_mod(a, n / 2);
    res = res * res;
    res %= MOD;
    if(n % 2) 
        res *= a;
    res %= MOD;
    return res;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v(n + 1), cnt(n + 1);
        for(int i = 1; i <= n; i ++)
        {
            cin >> v[i];
            cnt[abs((i - 1) - (n - i))] ++;
        }
        bool ok = true;
        for(int i = 1; i <= n;i ++)
        {
            if(!cnt[v[i]])
            {
                ok = false;
                break;
            }
            cnt[v[i]] --;
        }
        if(!ok)
            cout << 0 << endl;
        else
        cout << pow_mod(2, n / 2) << endl;
    }
}