#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

const int N = 1e3+5;
double dp[N][N];
struct Node
{
	double x,y;
	bool operator < (const Node & rhs) const
	{
		return x < rhs.x;
	}
}a[N];

double get_dis(int i,int j)
{
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + 
			(a[i].y - a[j].y) * (a[i].y - a[j].y));
}


int main()
{
	int n;
	while(cin >> n)
	{
		memset(a,0,sizeof(a));
		for(int i = 1;i<=n;i++)
			cin >> a[i].x >> a[i].y;
		for(int i = 0;i<N;i++)
			for(int j = 0;j<N;j++)
				dp[i][j] = 99999999;
		dp[1][1] = 0;
		dp[2][1] = get_dis(1,2);
		for(int i = 1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				dp[i+1][j] = min(dp[i+1][j],dp[i][j] + get_dis(i+1,i));
				dp[i+1][i] = min(dp[i+1][i],dp[i][j] + get_dis(i+1,j));	
			}
		}	
		double ans = 99999999;
		for(int i =1;i<n;i++)
			ans = min(ans,dp[n-1][i]+get_dis(i,n));
		printf("%.2f\n",ans + get_dis(n-1,n));
	}	
}
