#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;
//需要初始化点数 init函数
#define N 1000
#define INF 100000000

struct Edge
{
    int from, to, cap, flow, cost;
    Edge(int u, int v, int ca, int f, int co): from(u), to(v), cap(ca), flow(f), cost(co) {};
};

struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    int inq[N];//是否在队列中
    int d[N];//距离
    int p[N];//上一条弧
    int a[N];//可改进量

    void init(int n)//初始化
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }

    void add_edge(int from, int to, int cap, int cost) //加边
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool SPFA(int s, int t, int &flow, int &cost) //寻找最小费用的增广路，使用引用同时修改原flow,cost
    {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inq[u]--;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) //满足可增广且可变短
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to])
                    {
                        inq[e.to]++;
                        Q.push(e.to);
                    }
                }
            }
        }
        if (d[t] == INF) return false; //汇点不可达则退出
        flow += a[t];
        cost += d[t] * a[t];
        int u = t;
        while (u != s) //更新正向边和反向边
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int MincotMaxflow(int s, int t)
    {
        int flow = 0, cost = 0;
        while (SPFA(s, t, flow, cost));
        return cost;
    }
};

vector<pair<int, int> > home;
vector<pair<int, int> > people;
int dis(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
    ios :: sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        MCMF ans;
        int s = 0;
        home.clear(), people.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char x;
                cin >> x;
                if (x == 'm')
                    people.push_back(make_pair(i, j));
                else if (x == 'H')
                    home.push_back(make_pair(i, j));
            }
        }
        int t = home.size() + people.size() + 1;
        ans.init(t + 1);
        for (int i = 0; i < home.size(); i++)
            ans.add_edge(i + people.size() + 1, t, 1, 0);
        for (int i = 0; i < people.size(); i++)
            ans.add_edge(s, i + 1, 1, 0);
        for (int i = 0; i < people.size(); i++)
            for (int j = 0; j < home.size(); j++)
                ans.add_edge(i + 1, j + people.size() + 1, 1, dis(people[i], home[j]));
        cout << ans.MincotMaxflow(s, t) << endl;
    }
    return 0;
}