#include<bits/stdc++.h>
using namespace std;

pair<int,int> p[100000];
int pre[10000];
bool cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first < b.first || (a.first == b.first && a.second > b.second);
}
int main()
{
	int T;
	cin >> T;
	int m;
	cin >> m;
	memset(pre,0,sizeof(pre));
	while(T--)
	{
		for(int i = 1;i<=m;i++)
		{
			p[i].first = -1;
			p[i].second = i;
		}
		int dijia;
		cin >> dijia;
		int ren,qian;
		while(cin >> ren)
		{
			if(ren == -1)
				break;
			cin >> qian;
			if(qian >= dijia)
				p[ren].first = max(p[ren].first,qian);
		}
		sort(p+1,p+1+m,cmp);
		double temp;
		if(p[m].first == -1)
			continue;
		if(p[m-1].first == -1)
			temp = 1.0 * 1.1 * dijia;
		else 
			temp = 1.0 * 1.1 * p[m-1].first;
		pre[p[m].second] += min(p[m].first, (int) temp);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		cout << pre[x] << endl;
	}
}
