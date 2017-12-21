#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int N = 1e6 + 7;

struct Node
{
	int id,sal,hei;
	Node(){}
	Node(int _id,int _sal,int _hei)
	{
		id = _id, sal = _sal, hei = _hei;
	}
	bool operator < (const Node &rhs) const
	{
		return sal < rhs.sal; 
	}
};

vector<Node> v;
int fa[N];
int sz[N];
vector<int> G[N];
int n,m;
void init()
{
	v.clear();
	for(int i = 0;i < N;i++)
		G[i].clear();
	memset(fa,0,sizeof(fa));
}
int search(int lowbound,int tarhei)
{
	int l = lowbound,r = n - 1;
	int ans = 1e6;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(v[mid].hei >= tarhei)
		{
			r = mid - 1;
			ans = min(ans,mid);
		}
		else
			l = mid + 1;
	}
	if(ans == 1e6)
		return -1;
	else
		return v[ans].id;
}
void dfs(int u)
{
	sz[u] = 1;
	for(int i = 0;i < G[u].size();i++)
	{
		int v = G[u][i];
		dfs(v);
		sz[u] += sz[v];
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 0;i < n;i++)
		{
			int id,sal,hei;
			scanf("%d%d%d",&id,&sal,&hei);
			v.push_back(Node(id,sal,hei));
		}
		sort(v.begin(),v.end());
		for(int i = 0;i < n;i ++)
		{
			//int anc = search(i + 1,v[i].hei);
			//if(anc == -1)
			//	continue;
			//else
			//{
			//	fa[v[i].id] = anc;
			//	G[anc].push_back(v[i].id);
			//}
			for(int j = i + 1;j < n ; j ++)
			{
				if(v[i].hei <= v[j].hei)
				{
					fa[v[i].id] = v[j].id;
					G[v[j].id].push_back(v[i].id);
					break;
				}
			}
		}
		for(int i = 0;i < n;i++)
			if(fa[v[i].id] == 0)
				dfs(v[i].id);
		for(int i = 0;i < m;i ++)
		{
			int qid;
			scanf("%d",&qid);
			printf("%d %d\n",fa[qid] , sz[qid] - 1);
		}
	}
}
