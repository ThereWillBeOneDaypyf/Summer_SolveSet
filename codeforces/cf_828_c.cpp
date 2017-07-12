#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 2e6 + 8;

char x[N];
string s[N];
vector<pair<int,int> > tar;
int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		int Max = 0;
		memset(x,0,sizeof(x));
		for(int i = 0 ;i<n;i++)
		{
			int cnt ;
			cin >> s[i] >> cnt;
			for(int j = 0;j<cnt;j++)
			{
				int pos;
				scanf("%d",&pos);
				tar.push_back(make_pair(pos,i));
			}
		}
		sort(tar.begin(),tar.end());
		string ans;
		int id = 1;
		for(int i = 0;i<tar.size();i++)
		{
			int cur = tar[i].first;
			int string_id = tar[i].second;
			while(id < cur)
			{
				id ++;
				ans += 'a';
			}	
			for(int j = id - cur; j < s[string_id].length();j++)
			{
				ans += s[string_id][j];
				id ++;
			}
		}
		cout << ans << endl;
	}
}
