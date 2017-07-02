#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 200005;

struct Node
{
	int l,r,c;
	bool operator < (const Node &rhs) const 
	{
		return c < rhs.c;
	}
};
set<Node>s[N];
map<int,int> len;
int vis[N];
int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		for(int i = 0;i<N;i++)
			s[i].clear();
		len.clear();
		for(int i = 0;i<n;i++)
		{
			int l,r,c;
			cin >> l >> r >> c;
			int tar = r - l + 1;
			s[tar].insert({l,r,c});
			len[tar] = 1;
		}
		map<int,int> :: iterator it;
		int ans = -1;
		for(it = len.begin();it != len.end();it++)
		{
			int tar = it->first;
			if(vis[tar])
				continue;
			int next = m - tar;
			vis[tar] = 1;
			if(!len.count(next))
				continue;
			vis[next] = 1;
			set<Node> :: iterator it1;
			set<Node> :: iterator it2;
			for(it1 = s[tar].begin() ; it1 != s[tar].end();it1++)
			{
				for(it2 = s[next].begin() ; it2 != s[next].end();it2++)
				{
					Node temp1 = *it1;
					Node temp2 = *it2;
					if(temp1.r < temp2.l || temp2.r < temp1.l)
					{
						if(ans == -1)
							ans = temp1.c + temp2.c;
						else
							ans = min(ans,temp1.c + temp2.c);
					}
				}
			}
		}	
		cout << ans << endl;
	}
}
