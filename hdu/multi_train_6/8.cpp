#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		int m;
		cin >> m;
		string s;
		cin >> s;
		int ans = 0;
		for(int i = 0;i<s.length();i++)
		{
			int l = i,r = i,lt = i+1,rt = i+1;
			int cur = 0;
			while(l >= 0 && l <= r && lt < s.length())
			{
				if(cur <= m)
				{
					cur += abs(s[l] - s[lt]);
					if(cur <= m)
						ans = max(ans,r - l + 1);
					l -- ,lt ++;
				}
				else
				{
					cur -= abs(s[r] - s[rt]);
					r --, rt ++;
				}
			}	
			l = i ,r = i,lt = i+2,rt = i + 2;
			cur = 0;
			while(l >= 0 && l <= r && lt < s.length())
			{
				if(cur <= m)
				{
					cur += abs(s[l] - s[lt]);
					if(cur <= m)
						ans = max(ans,r - l + 1);
					l--,lt ++;
				}
				else
				{
					cur -= abs(s[r] - s[rt]);
					r -- ,rt ++;
				}
			}
		}
		cout << ans << endl;
	}
}
