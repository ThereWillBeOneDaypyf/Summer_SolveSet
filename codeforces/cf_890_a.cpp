#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int sum = 0;
vector<int> v;
int flag = 0;
void dfs(int pos, int tot, int p)
{
	if (pos >= 6)
	{
		if (tot == sum / 2 && p == 3)
			flag = 1;
		return;
	}
	dfs(pos + 1, tot, p);
	dfs(pos + 1, tot + v[pos], p + 1);
}

int main()
{
	int a;
	while (cin >> a)
	{
		v.clear();
		sum = 0;
		v.push_back(a);
		sum += a;
		for (int i = 0; i < 5; i++)
		{
			cin >> a;
			v.push_back(a);
			sum += a;
		}
		if (sum % 2)
		{
			cout << "NO" << endl;
			continue;
		}
		flag = 0;
		dfs(0, 0, 0);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}