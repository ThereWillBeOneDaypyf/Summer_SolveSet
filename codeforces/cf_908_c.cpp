#include<bits/stdc++.h>
using namespace std;
int n, r;
double getH(pair<int, double> p1, int x2)
{
	//cout << sqrt(1.0 * (4 * r * r - (p1.first - x2) * (p1.first - x2))) << endl;
	return p1.second + sqrt(1.0 * (4 * r * r - (p1.first - x2) * (p1.first - x2))) ;
}
int main()
{
	while (cin >> n >> r)
	{
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		vector<pair<int, double> > ans;
		ans.push_back(make_pair(v[0], r));
		for (int i = 1; i < n; i++)
		{
			double curh = r;
			for (int j = 0; j < i; j++)
			{
				curh = max(curh, getH(ans[j], v[i]));
			}
			ans.push_back(make_pair(v[i], curh));
		}
		for (int i = 0; i < ans.size(); i++)
		{
			if (i)
				cout << " ";
			printf("%.6lf", ans[i].second);
		}
		cout << endl;
	}
}