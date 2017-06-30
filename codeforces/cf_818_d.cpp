#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


struct Node
{
	int c,n;
};

struct cmp
{
	bool operator () (Node a,Node b) const
	{
		return a.n > b.n ;
	}
};
int clr[1000000];
int cnt[1000005];
int vis[1000005];
int main()
{
	int n,tar;
	while(cin >> n >> tar)
	{
		memset(cnt,0,sizeof(cnt));
		memset(clr,0,sizeof(clr));
		int pos = -1;
		for(int i = 0 ;i<n;i++)
		{
			cin >> clr[i];
			if(tar == clr[i] && pos == -1)
				pos = i;
		}
		if(pos == -1)
		{
			cout << clr[0] << endl;
			continue;
		}
		priority_queue<Node,vector<Node>,cmp>q;
		int flag = 1;
		for(int i = 0;i<=pos;i++)
		{
			if(!cnt[clr[i]])
			{
				Node temp = {clr[i],++cnt[clr[i]]};
				q.push(temp);
			}
			else
				cnt[clr[i]]++;
		}
		for(int i = pos+1;i<n;i++)
		{
			int x = clr[i];
			if(!cnt[x])
				continue;
			cnt[clr[i]]++;
			if(x == tar)
			{
				while( cnt[q.top().c] <= cnt[tar])
				{
					int temp = q.top().c;
					q.pop();
					if(cnt[temp] >= cnt[tar])
					{
						Node temp_node = {temp,cnt[temp]};
						q.push(temp_node);
					}
					else
						cnt[temp] = 0;
					if(tar == temp)
						break;
				}
			}
		}
		while(!q.empty() && q.top().c == tar)
			q.pop();
		if(!q.empty())
			cout << q.top().c << endl;
		else
			cout << -1 << endl;
	}	
}
