#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct point
{
	int x,y;
};
point list[1005];
int stack[1005];
int top;
int cross(point p0,point p1,point p2)
{
	return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}
double dis(point p1,point p2)
{
	return sqrt((double) (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
bool cmp(point p1,point p2)
{
	int temp = cross(list[0],p1,p2);
	if(temp > 0)
		return true;
	else if(temp == 0 && dis(list[0],p1) < dis(list[0],p2))
		return true;
	else 
		return false;
}
void init(int n)
{
	int i,k;
	point p0;
	scanf("%d%d",&list[0].x,&list[0].y);
	p0.x = list[0].x;
	p0.y = list[0].y;
	k = 0;
	for(i = 1;i<n;i++)
	{
		scanf("%d%d",&list[i].x, &list[i].y);
		if((p0.y > list[i].y) || ((p0.y == list[i].y) && (p0.x > list[i].x)))
		{
			p0.x = list[i].x;
			p0.y = list[i].y;
			k = i;
		}
	}
	list[k] = list[0];
	list[0] = p0;
	sort(list+1,list+n,cmp);
}
void graham(int n)
{
	int i;
	if(n == 1)
	{
		top = 0;
		stack[0] = 0;
	}
	if(n == 2)
	{
		top = 1;
		stack[0] = 0;
		stack[1] = 1;
	}
	if(n > 2)
	{
		for(i = 0;i<=1;i++)
			stack[i] = i;
		top = 1;
		for(i = 2;i<n;i++)
		{
			while(top > 0 && cross(list[stack[top -1]],list[stack[top]],list[i]) <= 0)
				top --;
			top ++;
			stack[top] = i;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		init(n);
		graham(n);
		if(top + 1 != n)
			printf("NO\n");
		else
		{
			double D = dis(list[stack[0]],list[stack[top]]);
			int flag = 1;
			for(int i = 0;i<top;i++)
			{
					if(D != dis(list[stack[i]],list[stack[i+1]]))
					{
						flag = 0;
						break;
					}
			}
			bool ok = false;
			list[++top].x = list[0].x;
			list[top].y = list[0].y;
			list[++top].x = list[1].x;
			list[++top].y = list[1].y;
			long long tar;
			for(int i = 0;i<top-1;i++)
			{
				if(!ok)
				{
					int xx = list[stack[i]].x - list[stack[i+1]].x;
					int xy = list[stack[i]].y - list[stack[i+1]].y;
					int yx = list[stack[i+1]].x - list[stack[i+2]].x;
					int yy = list[stack[i+1]].y - list[stack[i+2]].y;
					if(!ok)
					{
						ok = 1;
						tar = xx * yx + xy * yy;
					}
					else
					{
						long long cur = xx * yx + xy * yy;
						if(cur != tar)
						{
							flag = 0;
							break;
						}
					}
				}
			}
			if(flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}
