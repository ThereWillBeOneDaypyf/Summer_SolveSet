#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<set>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

bool judge(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != s[s.length() - 1 - i])
			return false;
	}
	return true;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string s;
		cin >> s;
		string R_s(s.rbegin(), s.rend());
		if (judge(s))
			cout << "YES" << endl;
		else
		{
			for (int i = 0 ; i < s.length(); i++)
			{
				if (s[i] != R_s[i])
				{
					s.erase(i, 1);
					R_s.erase(i, 1);
					break;
				}
			}
			if (judge(s) || judge(R_s))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}