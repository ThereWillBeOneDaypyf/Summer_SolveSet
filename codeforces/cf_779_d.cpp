#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

string p,t;
int pos[N];

bool judge(int tar)
{
	int pd = 0,td = 0;
	//cout << tar << endl;
	for(td = 0;td < t.length();td++)
	{
		if(pos[td] < tar)
			continue;
	//	cout << t[td];
		if(t[td] == p[pd])
		   pd ++;	
		if(pd == p.length())
		{
	//		cout << endl;
			return true;
		}
	}
	//cout << endl;
	return false;
}
void debug()
{
	for(int i = 0;i<t.length();i++)
	{
		judge(i);
		cout << endl;
	}
	cout << endl;
}

int main()
{
	while(cin >> t >> p)
	{
		for(int i = 0; i < t.length();i++)
		{
			int x;
			cin >> x;
			pos[x-1] = i;
		}
		//debug();
		int ans = 0;
		int l = 0,r = t.length(),mid;
		while(l<=r)
		{
			mid = (l + r) /2;
			if(judge(mid))
			{
				ans = max(ans,mid);
				l = mid + 1;
			}
			else
				r = mid - 1;
		}
		cout << ans << endl;
	}	
}
