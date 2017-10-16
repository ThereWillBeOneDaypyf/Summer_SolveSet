#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
	int ans = 0;
	while(n)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> ans;
		for(int i = max(0,n - 81);i <= n; i++)
		{
			int sum = solve(i);
			sum += i;
			if(sum == n)
				ans.push_back(i);
		}
		cout << ans.size() << endl;
		for(int i = 0;i != ans.size();i++)
		{
			if(i)
				cout << " ";
			cout << ans[i];
		}
		if(ans.size())
			cout << endl;
	}
}
