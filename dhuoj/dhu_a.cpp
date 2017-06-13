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

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int, int> PII;
typedef long long ll;

const int N = 1e6 + 5;

int main()
{
	string s;
	while (cin >> s)
	{
		stack<char>st;
		int flag = 0;
		int Max_deep = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				st.push(s[i]);
			if (st.size() > Max_deep)
				Max_deep = st.size();
			if (st.size() == 0 && s[i] == ')')
			{
				flag = 1;
			}
			if (st.size() && s[i] == ')')
				st.pop();
		}
		if (flag || st.size() != 0)
			cout << "NO" << endl;
		else
			cout << "YES" << " " << Max_deep << endl;
	}
}