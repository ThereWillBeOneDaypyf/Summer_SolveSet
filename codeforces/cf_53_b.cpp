#include<iostream>
#include<set>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

set<long long>s;

void get_S()
{
	for (int i = 0; i < 31; i++)
		s.insert((1 << i));
}
vector<pair<long long, long long> > tar;
bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
	long long area1 = a.first * a.second, area2 = b.first * b.second;
	return area1 > area2 || (area1 == area2 && a.first > b.first);
}
int main()
{
	get_S();
	int h , w;
	while (cin >> h >> w)
	{
		set<long long> :: iterator it;
		for (it = s.begin(); it != s.end(); it++)
		{
			if (*it <= h)
				tar.push_back(make_pair(*it, min(w, (int)floor((1.0 * (*it) / 0.8)))));
			if (*it <= w)
				tar.push_back(make_pair(min(h, (int)floor(*it * 1.25)), *it));
		}
		sort(tar.begin(), tar.end(), cmp);
		for (int i = 0; i < tar.size(); i++)
		{
			double ratio = 1.0 * tar[i].first / tar[i].second;
			if (ratio <= 1.25 && ratio >= 0.8)
			{
				cout << tar[i].first << " " << tar[i].second << endl;
				break;
			}
		}
	}
}