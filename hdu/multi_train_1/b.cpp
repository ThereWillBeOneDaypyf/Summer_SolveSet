#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


const int MOD = 1e9 + 7;
const int N = 1e5 +8;

int Max = 0;

struct Node
{
	int id;
	int vis;
	int a[N];
	bool operator < (const Node & rhs) const
	{
		for(int i = Max-1;i>=0;i--)
		{
			if(a[i] == rhs.a[i])
				continue;
			else
				return a[i] < rhs.a[i];
		}
	}
}res[26];
int val[26];
vector<string>s;
void get_val(string x)
{
	int base = x.length()-1;
	for(int i = 0;i<x.length();i++,base--)
		res[x[i]-'a'].a[base] ++;

}
void cal()
{
	for(int i =0 ;i<26;i++)
	{
		for(int j = 0;j<Max;j++)
		{
			if(res[i].a[j]>=26)
			{
				res[i].a[j+1] += (res[i].a[j] / 26);
				res[i].a[j] %= 26;
			}
		}
	}
}
void init()
{
	memset(res,0,sizeof(res));
	for(int i = 0;i<26;i++)
		res[i].id = i;
	s.clear();
}
int main()
{
	int n;
	int ka = 0;
	while(scanf("%d",&n) == 1)
	{
		cout << "Case #" << ++ka << ": ";
		init();
		set<int>x;
		Max = 0;
		for(int i = 0;i<n;i++)
		{
			string tar;
			cin >> tar;
			get_val(tar);
			s.push_back(tar);
			if(Max < tar.length())
				Max = tar.length();
			x.insert(tar[0]-'a');
		}
		cal();
		Max ++;
		sort(res,res+26);
		int cur =0 ;
		if(x.count(res[0].id))
		{
			for(int i = 0;i<26;i++)
			{
				if(!x.count(res[i].id))
				{
					val[res[i].id] = cur++;
					res[i].vis = 1;
					break;
				}
			}	
		}
		for(int i = 0;i<26;i++)
			if(!res[i].vis)
				val[res[i].id] = cur ++;
		long long sum = 0;
		for(int i = 0;i<n;i++)
		{
			long long base = 1;
			for(int j = s[i].length() - 1;j>=0;j--)
			{
				sum = sum + (val[s[i][j] - 'a'] * base) % MOD;
				sum %= MOD;
				base = base * 26 % MOD;	
			}
		}
		cout << sum << endl;
	}
}
