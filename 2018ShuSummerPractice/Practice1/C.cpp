#include<bits/stdc++.h>
using namespace std;

const  int TAR = 1e9 + 6;
const int MOD = 1e9 + 7;

vector<int> tar;

int go(int t,int v,vector<int>::iterator bg,vector<int>::iterator ed);


int solve(int t,int v)
{
    auto p = lower_bound(tar.begin(),tar.end(),v);
    int ans = go(t,v,tar.begin(),p);
    if(p != tar.end())
        ans = max(ans,go(t,v,p + 1,tar.end()));
    return ans;
}

int go(int t,int v,vector<int>::iterator bg,vector<int>::iterator ed)
{
    auto pos = lower_bound(bg,ed,t);
    int ans = 0;
    if(pos != ed)
    {
        ans = max(ans,(*pos + v) % MOD);
    }
    if(pos != bg)
    {
        pos --;
        ans = max(ans,(*pos + v) % MOD);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v;
        tar.clear();
        for(int i =0;i < n;i ++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        tar = v;
        sort(tar.begin(),tar.end());
        for(int i = 0;i < n;i ++)
        {
            printf("%d ",max(solve(TAR - v[i],v[i]),solve(TAR - v[i] + MOD,v[i])));
        }
        printf("\n");
    }
}