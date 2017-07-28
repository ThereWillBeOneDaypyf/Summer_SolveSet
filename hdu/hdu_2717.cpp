#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5+10;

int vis[N];
int n,k;
struct Node
{
	int pos,step;
	Node(int _pos,int _step):pos(_pos),step(_step){}
};
int bfs()
{
	queue<Node>q;
	q.push(Node(n,0));
	memset(vis,0,sizeof(vis));
	while(!q.empty())
	{
		Node temp = q.front();
		q.pop();
		if(temp.pos == k)
			return temp.step;
		vis[temp.pos] = 1;
		for(int i = 0;i<3;i++)
		{
			int cur = temp.pos;
			if(i==0)
				cur ++;
			else if(i == 1)
				cur --;
			else
				cur *= 2;
			if(cur < 0 || cur > 1e5 || vis[cur])
				continue;
			q.push(Node(cur,temp.step+1));
		}
	}
}

int main()
{
	while(cin >> n >> k)
	{
		cout << bfs() << endl;
	}
}
