#include<bits/stdc++.h>
using namespace std;

string s;
int judge(int x,int y)
{
	map<char,int> cnt;
	for(int i = x;i <= y;i++)
	{
		if(isupper(s[i]))
			return 0;
		cnt[s[i]]++;
	}
	return cnt.size();
}
int main()
{
	int n;
	while(cin >> n >> s)
	{
		int ans = 0;
		for(int i = 0;i<s.length();i++)
		{
			for(int j = i;j<s.length();j++)
			{
				int res = judge(i,j);
				ans = max(ans,res);
			}
		}
		cout << ans << endl;
	}
}
