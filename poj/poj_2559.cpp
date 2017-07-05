#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

int l[N], r[N], a[N];

int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		stack<pair<int, int> > st;
		for (int i = 1; i <= n; i++)
		{
			while (!st.empty() && st.top().first > a[i])
			{
				pair<int, int> temp = st.top();
				st.pop();
				r[temp.second] = i - 1;
			}
			st.push(make_pair(a[i], i));
		}
		while (!st.empty())
		{
			r[st.top().second] = n;
			st.pop();
		}
		for (int i = n; i >= 1; i--)
		{
			while (!st.empty() && st.top().first > a[i])
			{
				pair<int, int>temp = st.top();
				st.pop();
				l[temp.second] = i + 1;
			}
			st.push(make_pair(a[i], i));
		}
		while (!st.empty())
		{
			l[st.top().second] = 1;
			st.pop();
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, (long long)(r[i] - l[i] + 1) * a[i]);
		cout << ans << endl;
	}
}