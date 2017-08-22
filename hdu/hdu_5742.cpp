// #include<bits/stdc++.h>
// using namespace std;

// //thanks to pyf ...
// //thanks to qhl ...

// const int N = 1e5 + 8;

// int a[N];
// pair<int, int> tar[N];
// int main()
// {
// 	ios :: sync_with_stdio(false);
// 	int n, m;
// 	int T;
// 	cin >> T;
// 	while (T--)
// 	{
// 		cin >> n >> m;
// 		memset(a, -1, sizeof(a));
// 		memset(tar, 0, sizeof(tar));
// 		for (int i = 1; i <= m; i++)
// 		{
// 			int x, y;
// 			cin >> x >> y;
// 			tar[i] = make_pair(x, y);
// 			a[x] = y;
// 		}
// 		sort(tar + 1, tar + 1 + n);
// 		if (a[1] == -1)
// 			a[1] = 100;
// 		if (a[2] == -1)
// 			a[2] = a[1];
// 		long long up , down;
// 		long long cur = 0;
// 		for (int i = n; i >= 3; i--)
// 		{
// 			if (a[i] == -1)
// 				a[i] = cur;
// 			else
// 				cur = a[i];
// 		}
// 		up = a[1] + a[2];
// 		down = up;
// 		for (int i = 3; i <= n; i++)
// 			down += a[i];
// 		long long G = __gcd(up, down);
// 		cout << up / G << "/" << down / G << endl;
// 	}
// }
#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

int a[N];
pair<int, int> tar[N];
int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		memset(a, -1, sizeof(a));
		memset(tar, 0, sizeof(tar));
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			tar[i] = make_pair(x, y);
			a[x] = y;
		}
		if (a[1] == -1)
			a[1] = 100;
		if (a[2] == -1)
			a[2] = a[1];
		long long up , down;
		if (m == 0)
		{
			up = a[1] + a[2];
			down =  up;
			for (int i = 3; i <= n; i++)
				down += 1;
			long long G = __gcd(up, down);
			cout << up / G << "/" << down / G << endl;
			continue;
		}
		for (int i = 1; i <= m; i++)
			for (int j = tar[i - 1].first + 1; j <= tar[i].first; j++)
				if (a[j] == -1)
					a[j] = tar[i].second;
		for (int i = 3; i < tar[0].first; i++)
			if (a[i] == -1)
				a[i] = tar[0].second;
		for (int j = n; j > tar[m - 1].first; j--)
			if (a[j] == -1)
				a[j] = 0;
		up = a[1] + a[2];
		down = up;
		for (int i = 3; i <= n; i++)
			down += a[i];
		long long G = __gcd(up, down);
		cout << up / G << "/" << down / G << endl;
	}
}