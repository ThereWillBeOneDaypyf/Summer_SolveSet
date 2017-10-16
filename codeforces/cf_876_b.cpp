#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int vis[N];
vector<int> v;
int main()
{
	int n,k,m;
	while(cin >> n >> k >> m)
	{
		v.clear();
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<n;i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
			vis[x % m] ++;
		}
		int flag = 0;
		for(int i = 0;i<m;i++)
		{
			if(vis[i] >= k)
			{
				flag = 1;
				int cnt = 0;
				cout << "Yes" << endl;
				for(auto x : v)
				{
					if(x % m == i)
					{
						if(cnt)
							cout << " ";
						cout << x;
						cnt ++;
					}
					if(cnt == k)
						break;
				}
				cout << endl;
			}
		}
		if(!flag)
			cout << "No" << endl;
	}
}
