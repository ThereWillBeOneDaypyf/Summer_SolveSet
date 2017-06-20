#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 50000 +5;

struct Node
{
	int l,r;
	int id;
	bool operator < (const Node  &rhs) const
	{
		return l < rhs.l || (l ==rhs.l && r < rhs.r);
	}
}a[N];
struct cmp
{
	bool operator () (Node x,Node y)
	{
		return x.r > y.r;
	}
};
int ans[N];
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a[i].l ,&a[i].r);
			a[i].id = i;
		}
		memset(ans,0,sizeof(ans));
		priority_queue<Node,vector<Node>,cmp >q;
		sort(a,a+n);
		q.push(a[0]);
		int cur_cnt = 0;
		ans[a[0].id] = ++cur_cnt;
		for(int i = 1;i<n;i++)
		{
			Node temp = q.top();
			if(temp.r < a[i].l)
			{
				q.pop();
				ans[a[i].id] = ans[temp.id];
			}	
			else
				ans[a[i].id] = ++ cur_cnt;
			q.push(a[i]);
		}
		cout << cur_cnt << endl;
		for(int i=0;i<n;i++)
			cout << ans[i] << endl;
	}
}
