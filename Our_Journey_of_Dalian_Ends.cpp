#include<bits/stdc++.h>
using namespace std;
//需要初始化点数 init函数
#define N 10000
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

	bool SPFA(int s, int t, int &flow, long long &cost) //寻找最小费用的增广路，使用引用同时修改原flow,cost
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

	pair<int,long long> MincotMaxflow(int s, int t)
	{
		int flow = 0;
	   	long long cost = 0;
		while (SPFA(s, t, flow, cost));
		return make_pair(flow,cost);
	}
};
map<string,int> p;
struct Node
{
	int u,v,d;
};
vector<Node> edge;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int m ;
		scanf("%d",&m);
		edge.clear();
		p.clear();
		int s = 0;
		MCMF ans;
		int cnt = 0;
		for(int i = 0;i<m;i++)
		{
			char u[100],v[100];
			int d;
			scanf("%s%s%d",u,v,&d);
			if(!p.count(u))
				p[u] = ++ cnt;
			if(!p.count(v))
				p[v] = ++ cnt;
			edge.push_back({p[u],p[v],d});
		}
		int  t = 2 * p.size() + 1;
		ans.init(t + 1);
		ans.add_edge(s,p["Dalian"],1,0);ans.add_edge(s,p["Xian"],1,0);
		ans.add_edge(p["Shanghai"],t,2,0);
		for(int i = 1;i<=p.size();i++)
			ans.add_edge(i,i + p.size(),1,0);
		for(int i = 0; i != edge.size();i++)
		{
			Node temp = edge[i];
			int d = temp.d;
			int u = temp.u,v = temp.v;
			ans.add_edge(u + p.size(),v,1,d);
			ans.add_edge(v + p.size(),u,1,d);
		}
		pair<int,long long> res = ans.MincotMaxflow(s,t);
		if(res.first != 2)
			printf("-1\n");
		else printf("%lld\n",res.second);
	}
	return 0;
}
