#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int INF = 100000;
int n,m;
string s,t;
int judge(int pos)
{
	int sp,tp;
	int res = 0;
	for(int i = 0; i <n;i++)
	{
		if(s[i] != t[i+pos])
			res ++;
	}
	return res;
}
vector<int>tar;
int main()
{
	while(cin >> n >> m)
	{
		cin >> s >> t;
		int ans = INF;
		int pos = 0;
		for(int i =0 ;i<=m-n;i++)
		{
			int res = judge(i);
			if(ans > res)
				pos = i,ans = res; 
		}
		cout << ans << endl;
		tar.clear();
		for(int i = 0;i<n;i++)
		{
			if(s[i] != t[i+pos])
			{
				tar.push_back(i + 1);
			}
		}
		for(int i = 0;i<tar.size();i++)
		{
			if(i)
				cout << " ";
			cout << tar[i];
		}
		cout << endl;
	}
}
