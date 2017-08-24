#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define N 100000+10  
#define INF 1e18  
typedef pair<long long, int>P;  
int n,r;  
struct Edge{ int to;
   			long long cost; };  
vector<Edge>G[N];  
long long dist[N], dist2[N];  
void addedge(int u, int v,long long w)  
{  
	G[u].push_back(Edge{ v, w });  
	G[v].push_back(Edge{ u, w });  
}  
void solve()  
{  
	priority_queue<P, vector<P>, greater<P> >q;  
	fill(dist, dist + n, INF);  
	fill(dist2, dist2 + n, INF);  
	dist[0] = 0;  
	q.push(P(0, 0));  
	while (!q.empty())  
	{  
		P u = q.top(); q.pop();  
		int v = u.second;
	   	long long d = u.first;  
		if (dist2[v] < d)continue;//取出的不是次短距离，抛弃  
		for (int i = 0; i < G[v].size(); i++)  
		{  
			Edge&e = G[v][i];  
			long long d2 = d + e.cost;  
			if (dist[e.to]>d2)//更新最短距离  
			{  
				swap(dist[e.to], d2);  
				q.push(P(dist[e.to], e.to));  
			}  
			if (dist2[e.to] >= d2&&dist[e.to] <= d2)//更新次短距离  
			{  
				dist2[e.to] = d2;  
				q.push(P(dist2[e.to], e.to));  
			}  
		}  
	}  
	printf("%lld\n", dist2[n - 1]);  
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int m;
		scanf("%d%d",&n,&m);
		for(int i = 0;i<N;i++)
			G[i].clear();
		for(int i = 0;i<m;i++)
		{
			int u,v;
			long long w;
			scanf("%d%d%lld",&u,&v,&w);
			u -- ,v --;
			addedge(u,v,w);
		}
		solve();	
	}	
}

