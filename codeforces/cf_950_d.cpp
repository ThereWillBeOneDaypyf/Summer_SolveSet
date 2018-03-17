#include<bits/stdc++.h>
using namespace std;

long long dfs(long long cur_n,long long cur)
{
	if(cur % 2 == 1)
		return cur / 2 + 1;
	else
	{
		if(cur_n % 2 == 0)
			return dfs(cur_n / 2,cur / 2) + cur_n / 2;
		else 
		{
			if(cur == 2)
				return dfs(cur_n - 1,cur_n - 1) + 1;
			else return dfs(cur_n - 1,cur - 2) + 1;
		}
	}
}


int main()
{
	ios :: sync_with_stdio(false);
	long long n;
	int q;
	while(cin >> n >> q)
	{
		for(int i = 0;i < q;i ++)
		{
			long long temp;
			cin >> temp;
			cout << dfs(n,temp) << endl;
		}
	}
}
