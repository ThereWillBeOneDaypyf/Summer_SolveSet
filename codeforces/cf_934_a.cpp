#include<bits/stdc++.h>
using namespace std;

long long solve(int pos,const vector<long long>& a,const vector<long long>& b)
{
    long long ans = -1e18 - 7;
    for(int i = 0;i < a.size();i ++)
    {
        if(i == pos)
            continue;
        for(auto temp : b)
            ans = max(ans,temp * a[i]);
    }
    return ans;
}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<long long> v1;
        vector<long long> v2;
        for(int i = 0;i < n; i++)
        {
            int x;
            cin >> x;
            v1.push_back(x); 
        }
        for(int i = 0;i < m;i ++)
        {
            int x;
            cin >> x;
            v2.push_back(x);
        }
        long long ans = 1e18 + 7;
        for(int i = 0;i < v1.size();i ++)
            ans = min(ans,solve(i,v1,v2));
        cout << ans << endl;
    }
}