#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int n = 1e5 + 7;

int a[n];

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	int t;
	while (cin >> n >> t)
	{
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int ret = t, cnt = 0;
		int l = 0, r = 0;
		int ans = 0;
		while (r < n)
		{
			if (a[r] > t)
			{
				r ++;
				l = r;
				ret = t;
				cnt = 0;
			}
			else if (ret >= a[r]) // 从这里到那个else
				//是比较标准的尺取 一个if判断是不是可以拓展
				//然后可以拓展怎么走，不能扩展怎么走
			{
				ret -= a[r];
				cnt ++;
				r ++;
				ans = max(ans, cnt);
			}
			else
			{
				ret += a[l];
				cnt --;
				l ++ ;
			}
		}
		cout << ans << endl;
	}
}