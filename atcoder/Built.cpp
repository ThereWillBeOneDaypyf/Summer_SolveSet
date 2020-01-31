#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int fa[N];
vector<pair<int, pair<int, int> > > v;
vector<pair<int, pair<int, int> > > e;

void init()
{
    v.clear();
    e.clear();
    for(int i = 0;i < N;i ++)
        fa[i] = i;
}

void addEdge(int u, int v, int w)
{
    e.push_back(make_pair(w, make_pair(u, v)));
}

int find(int x)
{
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(fa[a] != fa[b])
        fa[a] = fa[b];
}

int main()
{
    int n;
    while(cin >> n)
    {
        init();
        for(int i = 0;i < n; i ++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back(make_pair(i, make_pair(x, y)));
        }
        sort(v.begin(), v.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            return a.second < b.second;
        });
        for(int i = 1; i < n; i ++)
        {
            auto p1 = v[i - 1].second;
            auto p2 = v[i].second;
            addEdge(v[i].first, v[i - 1].first, min(abs(p1.first - p2.first), abs(p1.second - p2.second)));
        }
        sort(v.begin(), v.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            return a.second.second < b.second.second || (a.second.second == b.second.second && a.second.first < b.second.first);
        });
        for(int i = 1; i < n; i ++)
        {
            auto p1 = v[i - 1].second;
            auto p2 = v[i].second;
            addEdge(v[i].first, v[i - 1].first, min(abs(p1.first - p2.first), abs(p1.second - p2.second)));
        }
        long long sum = 0;
        sort(e.begin(), e.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            return a.first < b.first;
        });
        for(int i = 0;i < e.size(); i ++)
        {
            int u = e[i].second.first;
            int v = e[i].second.second;
            int w = e[i].first;
            if(find(u) == find(v))
                continue;
            sum += w;
            merge(u, v);
        }
        cout << sum << endl;
    }
}