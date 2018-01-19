#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
struct Edge
{
    int u,v,d;
};

int fa[N];
void init()
{
    for(int i = 0;i < N;i++)
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
    a = find(a), b = find(b);
    if(fa[a] != fa[b])
        fa[a] = fa[b];
}
int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;
        init();
        vector<Edge> v;
        long long sum = 0;
        for(int i = 0;i < m;i++)
        {
            int from,to,d;
            cin >> from >> to >> d;
            sum += d;
            v.push_back({from,to,d});
        }
        sort(v.begin(),v.end(),[](Edge e1,Edge e2){
            return e1.d < e2.d;
        });
        int cnt = 0; 
        long long ans = 0;
        for(auto temp : v)
        {
            int u = temp.u, v = temp.v , d = temp.d;
            if(find(u) != find(v))
            {
                cnt ++;
                merge(u,v);
                ans += d;
            }
            if(cnt == n - 1)
                break;
        }
        cout << sum - ans << endl;
    }
}