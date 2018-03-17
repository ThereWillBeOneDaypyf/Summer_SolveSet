#include<bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 7;
int cnt = 0;
int a[N];
int dp[N];

int main()
{
    ios :: sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        memset(a,0,sizeof(a));
        memset(dp, -1, sizeof(dp));
        vector<int> v;
        for(int i = 0;i < n; i++)
        {
            long long x;
            cin >> x;
            a[x] ++;
            v.push_back(x);
        }
        long long ans = 0;
        sort(v.begin(),v.end(),[](int a,int b){
            return a > b;
        });
        v.erase(unique(v.begin(),v.end()),v.end());
        for(auto temp : v)
        {
            if(!a[temp])
                continue;
            for(long long j = 2;j * temp <= *v.begin();j ++)
            {
                if(a[j * temp])
                {
                    dp[temp] = 1;
                    break;
                }
            }
        }
        for(auto temp : v)
            if(dp[temp] != -1)
                ans += a[temp];
        cout << ans << endl;
    }
}