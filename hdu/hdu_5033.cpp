#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thansk to qhl ...
const int N = 1e6 + 7;
const double PI = acos(-1.0);

vector<int>q;

struct Point
{
	int x,y;
	bool operator < (const Point &p) const
	{
		return x < p.x;
	}
};
vector<Point>v;
Point sta[N];
double ans[N];
int top = 0;
void init()
{
	top = 0;
	v.clear();
}
bool check(Point a,Point b,Point c)
{
	if(c.y <= 0)
		c.y = 0;
	double ka = 1.0 * (a.y - b.y) / (a.x - b.x);
	double kb = 1.0 * (b.y - c.y) / (b.x - c.x);
	return kb  <= ka;
}
double getangle(Point a,Point b)
{
	return 180.0000 * atan(1.0 * abs((b.x - a.x)) / (a.y))/ PI;
}	
void solve()
{
	top = 0;
	//top from 1
	for(int i = 0;i != v.size(); i ++)
	{
		if(v[i].y <= 0)
		{
			while(top > 1 && !check(sta[top-1],sta[top],v[i]))
					top --;
			ans[-v[i].y] += getangle(sta[top],v[i]);
		}	
		else
		{
			if(top == 0 || top == 1)
				sta[++ top] = v[i];
			else
			{
				while(top > 1 && !check(sta[top-1],sta[top],v[i]))
					top --;
				sta[++top] = v[i];
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		init();
		for(int i = 0;i<n;i++)
		{
			Point temp;
			scanf("%d%d",&temp.x,&temp.y);
			v.push_back(temp);
		}
		int q;
		scanf("%d",&q);
		for(int i = 0;i<q;i++)
		{
			int x;
			scanf("%d",&x);
			v.push_back({x,-i});
		}
		memset(ans,0,sizeof(ans));
		sort(v.begin(),v.end());		
		solve();
		reverse(v.begin(),v.end());
		for(auto & temp : v)
			temp.x = 1000000 - temp.x;
		solve();
		printf("Case #%d:\n",++ka);
		for(int i = 0;i<q;i++)
			printf("%.9lf\n",ans[i]);
	}
}
