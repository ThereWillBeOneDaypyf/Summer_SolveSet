#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

struct Node
{
	int x,step;
};
int vis[N+5];
int bfs(int n,int k)
{
	queue<Node>q;
	q.push({n,0});
	memset(vis,0,sizeof(vis));
	while(!q.empty())
	{
		int cur = q.front().x;
		int step = q.front().step;
		q.pop();
		vis[cur] = 1;
		if(cur == k)
			return step;
		for(int i = 0;i<3;i++)
		{
			int next;
			if(i == 0)
				next = cur + 1;
			if(i == 1)
				next = cur * 2;
			if(i == 2)
				next = cur - 1;
			if(next > N || vis[next])
				continue;
			q.push({next,step+1});
		}
	}
}
int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		cout << bfs(n,k) << endl;
	}
}
