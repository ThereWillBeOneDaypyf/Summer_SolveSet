#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e5 + 10;

long long pre_sum[N];
int n,k;
struct Tree
{
	int l,r;
	pair<long long,int> x;
}t[N*4];
void push_up(int step)
{
	if(t[step*2].x.first >= t[step*2+1].x.first)
		t[step].x = t[step*2].x;
	else
		t[step].x = t[step*2+1].x;
}
void build(int l,int r,int step)
{
	t[step].l = l,t[step].r = r;
	if(l == r)
	{
		t[step].x = make_pair(pre_sum[l+k-1]-pre_sum[l-1],l);
		return;
	}
	int mid = (l + r) / 2;
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
	push_up(step);
}
pair<long long,int> query(int l,int r,int step)
{
	if(l ==  t[step].l && r == t[step].r)
		return t[step].x;
	int mid = (t[step].l + t[step].r) / 2;
	if(r <= mid)
		return query(l,r,step*2);
	else if(l > mid)
		return query(l,r,step*2+1);
	else
	{
		pair<long long,int>temp1,temp2;
		temp1 = query(l,mid,step*2);
		temp2 = query(mid+1,r,step*2+1);
		if(temp1.first >= temp2.first)
			return temp1;
		else
			return temp2;
	}
}
int main()
{
	while(cin >> n >> k)
	{
		for(int i = 1;i<=n;i++)
			cin >> pre_sum[i];
		for(int i = 1;i<=n;i++)
			pre_sum[i] = pre_sum[i-1] + pre_sum[i];
		build(1,n-k+1,1);
		long long ans = 0;
		int ans_id[2];
		for(int i = 1;i<=n-2 * k+1;i++)
		{
			pair<long long ,int> temp = query(i+k,n-k+1,1);
			long long res = pre_sum[i+k-1] - pre_sum[i-1] + temp.first;
			if(res > ans)
				ans_id[0] = i,ans_id[1] = temp.second,ans = res;
		}
		cout << ans_id[0] << " " << ans_id[1] << endl;
	}
}
