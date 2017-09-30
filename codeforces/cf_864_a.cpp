#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int vis[1000];

int main()
{
	int n;
	while(cin >> n)
	{
		memset(vis,0,sizeof(vis));
		for(int i =0 ;i<n;i++)
		{
			int x;
			cin >> x;
			vis[x] ++;
		}
		int flag = 0;
		int ans1 = 0, ans2 = 0;
		for(int i = 1;i<=100;i++)
		{
			if(!vis[i])
				continue;
			for(int j = 1;j<=100;j++)
			{
				if(i == j || !vis[j])
					continue;
				if(vis[i] == vis[j])
				{
					ans1 = i,ans2 = j;
					flag = 1;
					break;
				}
			}
		}
		if(vis[ans1] + vis[ans2] != n)
			flag = 0;
		if(flag)
		{
			cout << "YES" << endl;
			cout << ans1 << " " << ans2 << endl;
		}
		else 
			cout << "NO" << endl;
	}	
}
