#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

struct Node
{
	int w,v;
	bool operator < (const Node &rhs) const 
	{
		return w < rhs.w;
	}
}a[N];
int n,m;
bool judge(int tar,int need)
{
	int get_cnt = 0;
	int get_w = 0;
	for(int i = 0;i<n;i++)
	{
		if(a[i].v < tar)
			continue;
		if(a[i].v >= tar && get_w + a[i].w <= m)
		{
			get_cnt ++;
			get_w += a[i].w;
		}
		else
			break;
	}
	return get_cnt >= need;
}
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		for(int i = 0;i<n;i++)
			cin >> a[i].v >> a[i].w;
		sort(a,a+n);
		int ans_cnt = 0;
		int cur = 0;
		for(int i = 0;i<n;i++)
		{
			if(cur+a[i].w <= m)
			{
				ans_cnt ++;
				cur += a[i].w;
			}
			else
				break;
		}
		int l = 0,r = 1e9+8,mid;
		int ans_v = 0;
		while(l <= r)
		{
			mid = (l + r) / 2;
			if(judge(mid,ans_cnt))
			{
				ans_v = max(ans_v,mid);
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		cout << ans_cnt << " " << ans_v << endl;
	}
}
