#include <bits/stdc++.h>
using namespace std;

int a[4];

bool dfs(int pos, int left, int right)
{
	if(pos >= 4)
	{
		if(left == right)
			return true;
		return false;
	}
	return dfs(pos + 1, left + a[pos], right) | dfs(pos + 1, left, right + a[pos]);

}

int main()
{
	while(cin >> a[0])
	{
		for(int i = 1; i < 4; i ++)
			cin >> a[i];
		int left = 0, right = 0;
		bool flag = dfs(0, left, right);
		if(flag)
			cout << "yes" << endl;
		else cout << "no" << endl;
	}
}
