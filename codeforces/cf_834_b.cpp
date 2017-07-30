// #include<bits/stdc++.h>
// using namespace std;

// //thanks to pyf ...
// //thanks to qhl ...
// struct Node
// {
// 	int l, r;
// 	bool operator < (const Node &rhs) const
// 	{
// 		return r < rhs.r || (r == rhs.r && l < rhs.l);
// 	}
// } a[30];
// int main()
// {
// 	int n, k;
// 	while (cin >> n >> k)
// 	{
// 		string s;
// 		cin >> s;
// 		memset(a, -1, sizeof(a));
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (a[s[i] - 'A'].l == -1)
// 				a[s[i] - 'A'].l = a[s[i] - 'A'].r = i;
// 			else
// 				a[s[i] - 'A'].r = max(i, a[s[i] - 'A'].r);
// 		}
// 		int ans = 0;
// 		sort(a, a + 26);
// 		int st = 0;
// 		while (a[st].l == -1) st++;
// 		ans = 0;
// 		for (int i = st; i < 26; i++)
// 		{
// 			int res = 1;
// 			for (int j = st; j < 26; j++)
// 			{
// 				if (i == j)
// 					continue;
// 				if (a[i].l <= a[j].l && a[i].r >= a[j].r)
// 				{
// 					res++;
// 				}
// 				else if (a[i].l <= a[j].l && a[i].r >= a[j].l && a[j].r >= a[i].r)
// 				{
// 					res ++;
// 				}
// 				else if (a[i].l >= a[j].l && a[i].l <= a[j].r && a[i].r >= a[j].r)
// 				{
// 					res ++;
// 				}
// 			}
// 			ans = max(ans , res);
// 		}
// 		if (ans > k)
// 			cout << "YES" << endl;
// 		else
// 			cout << "NO" << endl;
// 	}
// }
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int fanwei[30];
bool vis[30];
int main()
{
	int n, k;
	string str;
	while (cin >> n >> k >> str)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < str.size(); i++)
		{
			fanwei[str[i] - 'A'] = i;
		}
		int need = 0;
		bool flag = true;
		for (int i = 0; i < str.size(); i++)
		{
			if (!vis[str[i] - 'A'])
			{
				need++;
				vis[str[i] - 'A'] = 1;
			}
//			cout << need << endl;
			if (need > k)
			{
				flag = false;
				break;
			}
			if (i == fanwei[str[i] - 'A'])
			{
				need--;
			}
		}
		if (flag) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
}