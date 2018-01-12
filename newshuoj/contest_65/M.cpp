#include<bits/stdc++.h>
using namespace std;

int sum = 0;
vector<pair<int, int> > match;
vector<int> tar;
void init()
{
	match.clear();
	for (int i = 0; i < 4; i ++)
		for (int j = i + 1; j < 4; j++)
			match.push_back(make_pair(i, j));
}
bool judge(vector<int> cur)
{
	for (int i = 0; i < 4; i++)
		if (tar[i] != cur[i])
			return false;
	return true;
}
void dfs(int pos, vector<int> cur)
{
	if (pos >= 6)
	{
		if (judge(cur))
			sum ++;
		return;
	}
	cur[match[pos].first] += 3;
	dfs(pos + 1, cur);
	cur[match[pos].first] -= 3;
	cur[match[pos].second] += 3;
	dfs(pos + 1, cur);
	cur[match[pos].second] -= 2;
	cur[match[pos].first] ++;
	dfs(pos + 1, cur);
	cur[match[pos].second] --;
	cur[match[pos].first] --;
}

int main()
{
	int T;
	cin >> T;
	init();
	int ka = 0;
	while (T--)
	{
		sum = 0;
		tar.clear();
		for (int i = 0; i < 4; i++)
		{
			int x;
			cin >> x;
			tar.push_back(x);
		}
		vector<int> cur(4, 0);
		dfs(0, cur);
		cout << "Case #" << ++ ka << ": " ;
		if (sum == 1)
			cout << "Yes" << endl;
		else if (sum == 0)
			cout << "Wrong Scoreboard" << endl;
		else cout << "No" << endl;
	}
}