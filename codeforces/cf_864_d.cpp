#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

int a[N];
int vis[N];
int last_pos[N];
int main()
{
	int n;
	while(cin >> n )
	{
		memset(vis,0,sizeof(vis));
		memset(last_pos,0,sizeof(last_pos));
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i];
			vis[a[i]] ++ ;
		}
		int l = 1;
		int cnt = 0;	
		for(int i = 1;i<=n;i++)
		{
			if(vis[a[i]] > 1)
			{
				for(;l <= n;l++)
				{
					if(!vis[l])
					{
						if(a[i] < l && !last_pos[a[i]])
						{
							last_pos[a[i]] = 1;
							break;
						}
						vis[a[i]] --;
						vis[l] ++;
						cnt ++;
						a[i] = l;
						break;
					}
				}
			}
		}
		cout << cnt << endl;
		for(int i = 1;i<=n;i++)
		{
			if(i!=1)
				cout << " ";
			cout << a[i];
		}
		cout << endl;
	}
}
