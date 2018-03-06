#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,a,b;
    while(cin >> n >> k >> a >> b)
    {
        long long ans = 0;
        if(k == 1)
        {
            cout << (n - 1) * a << endl;
            continue;
        }
        while(n != 1)
        {
            if(n % k != 0)
            {
                if(n < k)
                {
                    ans += a * (n - 1);
                    n = 1;
                }
                else
                {
                    ans += a * (n - (n / k) * k);
                    n = (n / k) * k;
                }
            }
            else
            {
                long long ratio = n / k;
                if(ratio == 1)
                    ans += min(a * (n - 1), b);
                else
                    ans += min(a * (n - ratio), b);
                n = ratio;
            }
        }
        cout << ans << endl;
    }
}