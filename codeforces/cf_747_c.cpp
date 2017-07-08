#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

struct Query
{
	int st,sev_need,t_need;
	int ed;
	bool operator < (const Query &rhs) const
	{
		return ed < rhs.ed;
	}
}Q[N];
int ans[N];
int vis[N];
int n,q;
int get_ans(int need,int st,int ed)
{
	int ans = 0;
	int cnt = 0;
	for(int i = 1;i<=n;i++)
	{
		if(st > vis[i])
		{
			cnt ++;
			ans += i;
		}
		if(need == cnt) break;
	}	
	if(cnt < need)
		return -1;
	else
	{
		for(int i = 1;i<=n;i++)
		{
			if(st > vis[i])
			{
				cnt -- ;
				vis[i] = ed;
			}
			if(!cnt)
				return ans;
		}
		return ans;
	}
}
int main()
{
	while(cin >> n >> q)
	{
		for(int i = 0;i<q;i++)
		{
			cin >> Q[i].st >> Q[i].sev_need >> Q[i].t_need;
			Q[i].ed = Q[i].st + Q[i].t_need - 1;
		}
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<q;i++)
		{
			cout << get_ans(Q[i].sev_need,Q[i].st,Q[i].ed) << endl;		
		}
	}
}

