#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    while(cin >> n >> k)
    {
        long long ans = 0;
        if(n == 1)
        {
            long long base = 1;
            for(int i = 0;i < 60;i ++)
            {
                ans ++;
                if(base * 2 > k)
                    break;
                base *= 2;
            }
        }
        else 
        {
            long long sum = 0;
            long long cur = 1;
            while(cur <= k)
            {
                long long add = n - sum / cur;
                ans += n - sum / cur;
                sum += add  * cur;
                cur = sum / n + 1;
            }
        }
        cout << ans << endl;
    }
}
