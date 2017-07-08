#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3;

int a[N];
int n,k;
int ans = 0;
bool judge(int tar)
{
	if(tar == 1)
		return false;
	for(int i = 2;i<=sqrt(tar);i++)
		if(tar % i == 0)
			return false;
	return true;
}
void dfs(int pos,int step,int sum)
{
	if(pos >= n)
	{
		if(step == k)
		{
			if(judge(sum))
			{
				ans++;
			}
		}
		return;
	}
	if(step > k)
		return;
	dfs(pos+1,step+1,sum+a[pos]);
	dfs(pos+1,step,sum);
}


int main()
{
	while(cin >> n >> k)
	{
		for(int i = 0;i<n;i++)
			cin >> a[i];
		ans = 0;
		dfs(0,0,0);
		cout << ans << endl;
	}
}

