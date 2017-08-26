// #include<bits/stdc++.h>
// using namespace std;

// //thanks to pyf ...
// //thanks to qhl ...

// const int N = 1e5 + 7;

// struct node
// {
// 	int l , r;
// 	bool operator < (const node & rhs) const
// 	{
// 		return l < rhs.l;
// 	}
// } a[N];

// multiset<long long>ed;
// int main()
// {
// 	int t;
// 	scanf("%d", &t);
// 	int n;
// 	while (t--)
// 	{
// 		scanf("%d", &n);
// 		for (int i = 0; i < n; i++)
// 			scanf("%d%d", &a[i].l, &a[i].r);
// 		ed.clear();
// 		sort(a, a + n);
// 		int tot = 0;
// 		long long ans = 0;
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (ed.empty())
// 			{
// 				tot ++;
// 				ed.insert(a[i].r);
// 				ans += a[i].r - a[i].l;
// 			}
// 			else
// 			{
// 				auto temp_it = ed.upper_bound(a[i].l);
// 				if (temp_it == ed.begin())
// 				{
// 					tot ++;
// 					ed.insert(a[i].r);
// 					ans += a[i].r - a[i].l;
// 				}
// 				else
// 				{
// 					temp_it--;
// 					ans += a[i].r - *temp_it;
// 					ed.erase(temp_it);
// 					ed.insert(a[i].r);
// 				}
// 			}
// 		}
// 		printf("%d %lld\n", tot, ans);
// 	}
// }
#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct node
{
	int l , r;
	bool operator < (const node & rhs) const
	{
		return l < rhs.l || (l == rhs.l && r > rhs.r);
	}
} a[N];

multiset<long long>ed;
multiset<long long>st;
int main()
{
	int t;
	scanf("%d", &t);
	int n;
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].l, &a[i].r);
		st.clear(), ed.clear();
		sort(a, a + n);
		int tot = 0;
		for (int i = 0; i < n; i++)
		{
			if (st.empty())
			{
				tot ++;
				st.insert(a[i].l);
				ed.insert(a[i].r);
			}
			else
			{
				auto temp_it = ed.upper_bound(a[i].l);
				if (temp_it == ed.begin())
				{
					tot ++;
					st.insert(a[i].l);
					ed.insert(a[i].r);
				}
				else
				{
					temp_it--; ed.erase(temp_it);
					ed.insert(a[i].r);
				}
			}
		}
		long long ans = 0;
		for (auto temp : st)
			ans -= 1LL * temp;
		for (auto temp : ed)
			ans += 1LL * temp;
		printf("%d %lld\n", tot, ans);
	}
}