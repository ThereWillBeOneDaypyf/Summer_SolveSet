#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

struct Edge
{
    int u,v,d;
    Edge(int _u,int _v,int _d) : u(_u), v(_v), d(_d) {}
};

int fa[N];
vector<Edge> v;
int n,m;
void init()
{
    for(int i = 0;i < N;i++)
        fa[i] = i;
    v.clear();
}
int find(int x)
{
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}
void merge(int a,int b)
{
    a = find(a), b = find(b);
    if(fa[a] != fa[b])
        fa[a] = fa[b];
}
long long kruskal()
{
    sort(v.begin(),v.end(),[](Edge a,Edge b){return a.d < b.d;});
    long long ans = 0;
    for(auto temp : v)
    {
        int u = temp.u;
        int vv = temp.v;
        int d = temp.d;
        if(find(u) != find(vv))
        {
            merge(u,vv);
            ans += d;
        }
    }
    for(int i = 1;i <= n;i ++)
        if(find(i) != find(1))
            return -1;
    return ans;
}

int main()
{
    long long sum = 0;
    while(cin >> sum >> m >> n)
    {
        init();
        for(int i = 0;i < m;i ++)
        {
            int u,vv,d;
            cin >> u >> vv >> d;
            v.push_back({u,vv,d});
        }
        long long res = kruskal();
        if(res == -1 || res > sum)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}