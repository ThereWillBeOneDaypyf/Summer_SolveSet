#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int M = 1e6 + 5;
const int N = 1e3 * 2 + 7;

struct Edge
{
	int u, v, next;
} edge[M], sedge[M];

struct T_SAT
{
	stack<int>st;
	int instack[N], belong[N], dfn[N], low[N];
	int pos[N], deg[N], shead[N], clr[N];
	int head[N];
	int n;
	int Index, block, tot , stot ;
	void init()
	{
		Index = block = tot = stot = 0;
		memset(head, -1, sizeof(head));
		memset(shead, -1, sizeof(shead));
		memset(instack, 0, sizeof(instack));
		memset(belong, 0, sizeof(belong));
		memset(low, 0, sizeof(low));
		memset(dfn, 0, sizeof(dfn));
		while (!st.empty())
			st.pop();
	}
	void add_edge(int u, int v)
	{
		edge[tot] = {u, v, head[u]};
		head[u] = tot ++;
	}
	void tarjan(int u)
	{
		dfn[u] = low[u] = ++ Index;
		st.push(u);
		instack[u] = 1;
		for (int i = head[u]; ~i; i = edge[i].next)
		{
			int v = edge[i].v;
			if (!dfn[v])
			{
				tarjan(v);
				low[u] = min(low[u], low[v]);
			}
			else if (instack[v])
				low[u] = min(low[u], dfn[v]);
		}
		int x;
		if (dfn[u] == low[u])
		{
			block ++;
			do
			{
				x = st.top();
				st.pop();
				belong[x] = block;
				instack[x] = 0;
			}
			while (x != u);
		}
	}
	bool Build_Graph()
	{
		for (int i = 1; i <= 2 * n; i++)
			if (!dfn[i])
				tarjan(i);
		for (int i = 1; i <= n; i++)
		{
			if (belong[i * 2 - 1] == belong[i * 2])
				return false;
			pos[belong[i * 2 - 1]] = belong[i * 2];
			pos[belong[i * 2]] = belong[i * 2 - 1];
		}
		for (int i = 1; i <= n * 2; i++)
		{
			for (int j = head[i]; ~j; j = edge[j].next)
			{
				int v = edge[j].v;
				if (belong[v] != belong[i])
				{
					deg[belong[i]] ++ ;
					sedge[stot] = {belong[v], belong[i], shead[v]};
					shead[belong[v]] = stot ++ ;
				}
			}
		}
		// for (int i = 1; i <= 2 * n ; i++)
		// {
		// 	cout << "**" << i << "--->  ";
		// 	for (int j = head[i]; ~j; j = edge[j].next)
		// 		cout << edge[j].v << " ";
		// 	cout << endl;
		// }
		return true;
	}
	void topu()
	{
		queue<int>q;
		for (int i = 1; i <= block; i++)
			if (!deg[i])
				q.push(i);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (clr[u] == 0)
			{
				clr[u] = 1;
				clr[pos[u]] = 2;
			}
			for (int i = shead[u]; ~i; i = sedge[i].next)
			{
				int v = sedge[i].v;
				deg[v] -- ;
				if (deg[v] == 0)
					q.push(v);
			}
		}
	}
	void OutPut()
	{
		vector<int>part1, part2;
		for (int i = 1; i <= 2 * n; i ++)
		{
			if (clr[belong[i]] == 1)
				part1.push_back(i);
			else  if (clr[belong[i]] == 2)
				part2.push_back(i);
		}
		for (int i = 0; i < part1.size(); i++)
		{
			if (i)
				printf(" ");
			printf("%d", part1[i]);
		}
		printf("\n");
		// for (int i = 0; i < part2.size(); i++)
		// {
		// 	if (i)
		// 		printf(" ");
		// 	printf("%d", part2[i]);
		// }
		// printf("\n");
	}
	int get_id(int u, int type) // (1,2) (3,4)
	{
		if (type == 0)
			return u * 2 - 1;
		else return u * 2;
	}
};
vector<pair<int,int> > tar;
int main()
{
	int n, m;
	T_SAT sat;
	while (scanf("%d%d", &n, &m) == 2)
	{
		sat.n = m;
		sat.init();
		for (int i = 0; i < m; i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(u > v)
				swap(u,v);
			tar.push_back(make_pair(u,v));
		}
		for(int i = 0;i<tar.size();i++)
		{
			int u = tar[i].first, v = tar[i].second;
			for(int j = i + 1;j<tar.size();j++)
			{
				int x = tar[j].first, y = tar[j].second;
				if((u <= x && x <= v && v <= y) || (x <= u && u <= y && y <= v))
				{
					sat.add_edge(sat.get_id(i+1,0),sat.get_id(j+1,1));
					sat.add_edge(sat.get_id(i+1,1),sat.get_id(j+1,0));
					sat.add_edge(sat.get_id(j+1,0),sat.get_id(i+1,1));
					sat.add_edge(sat.get_id(j+1,1),sat.get_id(i+1,0));
				}
			}
		}
		if (sat.Build_Graph())
			printf("panda is telling the truth...\n");
		else
			printf("the evil panda is lying again\n");
	}
}
