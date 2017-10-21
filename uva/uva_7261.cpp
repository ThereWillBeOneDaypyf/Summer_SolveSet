#include<bits/stdc++.h>
using namespace std;
int n;
struct Node
{
	int x1,y1;
	int x2,y2;
};
vector<Node>v;
bool judge(int tar,long long sum)
{
	long long cur = 0;
	for(auto temp : v)
	{
		if(temp.x2 <= tar)
			cur += abs(1LL * (temp.x2 - temp.x1) * (temp.y1 - temp.y2));
		else if(temp.x1 < tar && temp.x2 > tar)
			cur += abs(1LL * (tar - temp.x1) * (temp.y2 - temp.y1));
	}
	if(cur * 2 >= sum)
		return true;
	else
		return false;
}
long long Get(int tar)
{
	long long cur = 0;
	for(auto temp : v)
	{
		if(temp.x2 <= tar)
			cur += abs(1LL * (temp.x2 - temp.x1) * (temp.y1 - temp.y2));
		else if(temp.x1 < tar && temp.x2 > tar)
			cur += abs(1LL * (tar - temp.x1) * (temp.y2 - temp.y1));
	}
	return cur;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int R;
		scanf("%d",&R);
		long long sum = 0;
		scanf("%d",&n);
		v.clear();
		for(int i = 0;i < n;i++)
		{
			int l,t,w,h;
			scanf("%d%d%d%d",&l,&t,&w,&h);
			int lt = l + w;
			int rt = t - h;
			lt = max(0,lt);
			rt = min(rt,R);
			v.push_back({l,t,lt,rt});
		}
		for(auto temp : v)
			sum += abs(1LL * (temp.x1 - temp.x2) * (temp.y2 - temp.y1));
		int l = 0,r = R;
		int ans = 0;
		long long ansS = 0;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(judge(mid,sum))
			{
				if(!judge(mid - 1,sum))
				{
					ans = mid;
					ansS = Get(mid);
					break;
				}
				else
					r = mid - 1;			
			}
			else 
				l = mid + 1;
		}
		l = ans,r = R;
		int ac = 0;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(Get(mid) > ansS)
				r = mid - 1;
			else 
			{
				ac = max(ac,mid);
				l = mid + 1;
			}
		}
		printf("%d\n",ac);
	}
}
