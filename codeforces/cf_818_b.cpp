#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int a[1005];
int q[10005];
int n,m;
bool cal()
{
	memset(a,-1,sizeof(a));
	map<int,int> vis;
   	for(int i = 1;i<m;i++)
   	{
	   int pos = q[i];
	   int val;
	   if(q[i+1] <= q[i])
			val = q[i+1] + n - q[i];
	   else
		   val = q[i+1] - q[i] ;
	   if((a[pos] == -1 && !vis.count(val)) || (vis.count(val) && a[pos] == val))
			a[pos] = val,vis[val] = 1;
	   else 
		   return false;
  	}	   
   	for(int i = 1;i<=n;i++)
   	{
		if(a[i] == -1)
	   	{
		   for(int j = 1;j<=n;j++)
		   {
			   if(!vis.count(j))
			   {
				   a[i] = j,vis[j] = 1;
				   break;
			   }
		   }
		}
	}
	return true;
}
int main()
{
	while(cin >> n >> m)
	{
		for(int i = 1;i<=m;i++)
			cin >> q[i];
//		cal();
		if(cal())
		{
			for(int i =  1;i<=n;i++)
				i != n ? cout << a[i] << " ": cout << a[i]  << endl; 
		}
		else
			cout << -1 << endl;
	}
	return 0;
}
