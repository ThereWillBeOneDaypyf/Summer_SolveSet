#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

struct Node
{
	int x,y;
	int id;
	bool operator < (const Node &rhs) const 
	{
		return x < rhs.x;
	}
}a[1000000];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin >> n)
	{
		for(int i = 1;i<=n;i++)
		{
			cin >> a[i].x >> a[i].y;
			a[i].id = i;
		}
		sort(a+1,a+1+n);
		vector<pair<int,int> > ans ;
	   	ans.push_back(make_pair(1,2));
		double Max_ratio = 1.0 * (a[2].y - a[1].y) / (a[2].x - a[1].x);
		for(int i = 3;i<=n;i++)
		{
			double ratio = 1.0 * (a[i].y - a[i-1].y) / (a[i].x - a[i-1].x);
			if(ratio > Max_ratio)
			{
				ans.clear();
				Max_ratio = ratio;
				ans.push_back(make_pair(i-1,i));
			}
			else if(ratio == Max_ratio)
				ans.push_back(make_pair(i-1,i));
				
		}
		for(int i = 0;i<ans.size();i++)
			cout << a[ans[i].first].id << " " << a[ans[i].second].id << endl;
	}
}

