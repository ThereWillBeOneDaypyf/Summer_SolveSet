#include<iostream>
using namespace std;
const int mxn=31;
int ms[mxn],mv[mxn];
int n,m;
int ans;
void dfs(int smm,int v,int dep,int h,int r)
{
	if(v>n) return ;
	if(!dep) 
	{
		if(v==n && smm<ans) ans=smm;
		return ;
	}
	if(v+mv[dep-1]>n || smm+ms[dep-1]>ans || (n-v)/r*2+smm>=ans) return;
	for(int i=r-1;i>=dep;i--)
	{
		if(dep==m) smm=i*i;
		int mxh=min((n-v-mv[dep-1])/(i*i),h-1);
		for(int j=mxh;j>=dep;j--)
		{
			dfs(smm+2*i*j,v+i*i*j,dep-1,j,i);
		}
	}
	return ;
}
void init()
{
	for(int i=1;i<=20;i++)
	{
		ms[i]=ms[i-1]+i*i*2;
		mv[i]=mv[i-1]+i*i*i;
	}
	return ;
}
int main()
{
	init();
	int i,j;

	while(cin >> n >> m)
	{
		ans=0x3f3f3f3f;
		dfs(0,0,m,n+1,n+1);
		if(ans==0x3f3f3f3f)
			ans=0;
		cout << ans << endl;        
	}

}
