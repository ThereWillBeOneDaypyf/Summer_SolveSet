#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

struct Point
{
	int x,y;
}a[N];
struct Edge
{
	int u,v;
	double l;
	int x,y;
	void get_xy()
	{
		x = a[u].x - a[v].x;
		y = a[u].y - a[v].y;
	}
	Edge(int _u,int _v,double _l) : u(_u),v(_v),l(_l) {}
};
vector<Edge>G[N];
double cal(int i,int j)
{
	return sqrt(1.0 * ((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y -a[j].y)));
}
int judge(Edge x,Edge y)
{
	int tar = 0;
	if(x.u == y.u || x.u == y.v || x.v == y.u || x.v == y.v)
	{
		if(x.u == y.u)
			tar = x.u;
		if(x.u == y.v)
			tar = x.u;
		if(x.v == y.u)
			tar = x.v;
		if(x.v == y.v)
			tar = x.v;
	}
	else
		return -1;
	if(x.x * y.x + x.y * y.y == 0)
		return tar;
	else
		return -1;
}
vector<pair<int,int> >ans;
int main()
{
	int n;
	while(cin >> n)
	{
		int cnt = 0;
		map<double,int>m;
		for(int i = 0;i<N;i++)
			G[i].clear();
		for(int i = 0;i<n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		for(int i = 0;i<n;i++)
		{
			for(int j = i+1;j<n;j++)
			{
				if(i != j)
				{
					double len = cal(i,j);
					if(!m.count(len))
					{
						m[len] = cnt ++;
					}
					G[m[len]].push_back(Edge(i,j,len));
				}
			}
		}	
		for(int i = 0;i<cnt;i++)
		{
			for(int j = 0;j<G[i].size();j++)
			{
				G[i][j].get_xy();
			}
		}
		int sum = 0;
		for(int i = 0;i<cnt;i++)
		{
			ans.clear();
			for(int j = 0;j<G[i].size();j++)
			{
				for(int k = j+1;k<G[i].size();k++)
				{
					int p = judge(G[i][j],G[i][k]);	
					//cout << G[i][j].u << " " << G[i][j].v << " " << G[i][k].u << " " << G[i][k].v << " " << p << endl;  
					if(p != -1)
					{
						int first,second;
						if(G[i][j].u != p)
							first = G[i][j].u;
						else
							first = G[i][j].v;
						if(G[i][k].u != p)
							second = G[i][k].u;
						else
							second = G[i][k].v;	
						ans.push_back(make_pair(min(first,second),max(first,second)));
					}

				}	
			}
			for(int z = 0;z<ans.size();z++)
			{
				//cout << "*" << i << " " << ans[z].first << " " << ans[z].second << endl;
				for(int j = z +1;j<ans.size();j++)
				{
					if(ans[z].first == ans[j].first && ans[j].second == ans[z].second)
						sum ++;
				}
			}
		}
		cout << sum/2 << endl;
	}
}
