#include<bits/stdc++.h>
using namespace std;

vector<int>v;

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	double a;
	cin >> n >> a;
	string s;
	stringstream ss;
	cin.get();
	while(getline(cin,s))
	{
		int sta = 0;
		int x;
		ss.clear();
		ss << s;
		while(ss >> x)
			sta += (1 << x);
		v.push_back(sta);
	}
	int tar = ceil(1.0 * v.size() * a);
	int ans = 0;
	for(int i = 1;i<=(1 << (n + 1)); i ++)
	{
		int cnt = 0;
		for(int j = 0;j<v.size();j++)
		{
			if((v[j] & i) == i)
				cnt ++;
		}
		if(cnt >= tar)
		{
			ans ++;
		}
	}
	cout << ans << endl;
}
