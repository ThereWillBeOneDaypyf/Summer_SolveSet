#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

vector<int> G[N];
int a[N];

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        for(int i = 0;i < N;i ++)
            G[i].clear();
        memset(a,0,sizeof(a));
        for(int i = 1;i <= m;i ++)
            cin >> a[i];
        long long sum = 0;
        for(int i = 1;i <= m;i ++)
        {
            if(i != 1 && a[i] != a[i - 1])
                G[a[i]].push_back(a[i - 1]);
            if(i != m && a[i] != a[i + 1])
                G[a[i]].push_back(a[i + 1]);
            if(i != 1)
                sum += abs(a[i] - a[i - 1]);
        }
        long long ans = sum;
        //cout << sum << endl;
        for(int i = 1;i <= n;i ++)
        {
            if(G[i].empty())
                continue;
            sort(G[i].begin(),G[i].end());
            int good = G[i][G[i].size() / 2];
            long long dif1 = 0;
            long long dif2 = 0;
            for(auto ele : G[i])
            {
                dif1 += abs(ele - good);
                dif2 += abs(ele - i); 
            }
            //cout << i << " " << good << " " << dif1 << " " << dif2 << endl;
            ans = min(ans,sum - dif2 + dif1);
        }
        cout << ans << endl;
    }
}
