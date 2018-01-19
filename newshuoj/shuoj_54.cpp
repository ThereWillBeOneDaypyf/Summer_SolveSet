#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int dp[N];

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        memset(dp,0,sizeof(dp));
        vector<int> v,w;
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            w.push_back(x);
        }
        for(int i = 0;i < n; i++)
        {
            for(int j = m;j >= w[i];j--)
            {
                dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[m] << endl;
    }
}