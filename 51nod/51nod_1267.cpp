#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

struct Node 
{
	int x,y;
	long long v;
	bool operator < (const Node &rhs) const
	{
		return v < rhs.v;
	}
}a[N+10000];
vector<long long>tar;
int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin >> n)
	{
		tar.clear();
		for(int i = 0;i<n;i++)
		{
			long long x;
			cin >> x;
			tar.push_back(x);
		}
		int tot = 0;
		for(int i = 0;i<tar.size();i++)
			for(int j = 0;j<tar.size();j++)
				if(i != j)
					a[tot++] = {i,j,tar[i] + tar[j]};
		sort(a,a+tot);
		int l = 0,r = tot - 1;
		int flag = 0;
		while(l < r)
		{
			if(a[l].v + a[r].v < 0)
				l ++;
			else if(a[l].v + a[r].v > 0)
				r --;
			else if(a[l].v + a[r].v == 0 && a[l].x != a[r].x && a[l].y != a[r].y && a[l].x != a[r].y && a[l].y != a[r].x)
			{
				flag = 1;
				break;
			}
			else
				l ++ ,r --;

		}
		if(!flag)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}
