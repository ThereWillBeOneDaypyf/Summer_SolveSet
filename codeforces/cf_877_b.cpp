#include<bits/stdc++.h>
using namespace std;

int pre_a[5005];
int pre_b[5005];

int main()
{
	string s;
	while(cin >> s)
	{
		int n = s.length();
		memset(pre_a,0,sizeof(pre_a));
		memset(pre_b,0,sizeof(pre_b));
		for(int i = 0;i<s.length();i++)
		{
			if(s[i] == 'a')
				pre_a[i + 1] ++;
			else
				pre_b[i + 1] ++;
		}
		for(int i = 1;i<=n;i++)
			pre_a[i] += pre_a[i-1],pre_b[i] += pre_b[i-1];
		int ans = min(pre_a[s.length()],pre_b[s.length()]);
		for(int i = 1;i<=n;i++)
		{
			for(int j = i;j<=n;j++)
			{
				ans = min(ans,pre_b[i - 1] + pre_a[j] - pre_a[i - 1] + pre_b[n] - pre_b[j]); 	
			}
		}
		cout << n - ans << endl;
	}
}
