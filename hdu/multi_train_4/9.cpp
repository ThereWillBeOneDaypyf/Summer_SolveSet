#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thansk to qhl ...

const int N = 1e6;

int a[N];
int vis[2];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		for(int i =0 ;i<n;i++)
		{
			scanf("%d",a+i);
			vis[a[i] % 2] ++;
		}
		int k ;
		if(vis[0] > vis[1])
			k = 0;
		else
			k = 1;
		cout << 2 << " " << k << endl;
	}
}
