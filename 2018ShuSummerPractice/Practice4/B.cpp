#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

int fa[N];

void init()
{
    for(int i = 0;i < N;i ++)
        fa[i] = i;
}

int find(int x)
{
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a,int b)
{
    a = find(a);
    b = find(b);
    if(fa[a] != fa[b])
        fa[a] = fa[b];
}

bool judge(pair<int,int> x,pair<int,int> y)
{
    if(x.first == y.first || x.second == y.second)
        return true;
    return false;
}

int main()
{
    int n;
    while(cin >> n)
    {
        init();
        vector<pair<int,int> > v;
        for(int i = 0;i < n;i ++)
        {
            int x,y;
            cin >> x >> y;
            v.push_back(make_pair(x,y));
        }
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < n;j ++)
            {
                if(judge(v[i],v[j]))
                {
                    merge(i,j);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n;i ++)
            if(i == find(i))
                ans ++;
        cout << ans - 1 << endl;
    }
}