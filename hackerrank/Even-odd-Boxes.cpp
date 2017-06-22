#include <bits/stdc++.h>

using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

int a[N];

int main()
{
	int  T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		cin >> n;
		set<int> evenposzero;
		set<int> needchange;
		for(int i = 0;i<n;i++)
		{
			cin >> a[i];
			if(i%2 == 0 && a[i] == 1)
				evenposzero.insert(i);
			else if(i%2 != a[i] %2)
				needchange.insert(i);
		}
		int ans = 0;	
		int flag = 1;
		while(evenposzero.size() && needchange.size())
		{
			int zero_index = *(evenposzero.begin());
			int change_index = *(needchange.begin());
			a[zero_index] ++;
			a[change_index] --;
			evenposzero.erase(evenposzero.begin());
			needchange.erase(needchange.begin());
			ans ++;
		}
		if(evenposzero.size())
		{
			int cnt = evenposzero.size();
			if(cnt % 2 == 0)
			{
				for(int i = n-1 ;i>=0&&cnt>1;i--)
				{
					while(a[i] > 2 && cnt > 1)
					{
						a[i] -= 2;
						evenposzero.erase(evenposzero.begin());
						evenposzero.erase(evenposzero.begin());	
						ans+=2;
						cnt-=2;
					}
				}		
				if(cnt)
					flag = 0;
			}
			else
				flag = 0;
		}
		else
		{
			if(needchange.size() % 2)
				flag = 0;
			else
				ans += (needchange.size() / 2);
		}
		if(flag)
			cout << ans << endl;
		else
			cout << -1 << endl;
	}
}

/*
4
4
1 1 1 1
5
3 1 1 1 2
*/
