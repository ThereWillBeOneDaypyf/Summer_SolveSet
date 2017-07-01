#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

int a[N];

bool judge(int n)
{
	int cnt = 0;
	for(int i =0 ;i<n;i++)
		if(a[i] > 0)
			cnt ++;
	return cnt <= 2;
}

int main()
{
	int n;
	while(cin >> n)
	{
		memset(a,0,sizeof(a));
		if(n == 0)
			break;
		for(int i = 0 ;i<=n;i++)
			cin >> a[i];
		sort(a,a+n);
		int ans = ceil(a[n-1]*1.0/50);
		for(int i = 0;i<n;i++)
		{
			a[i] = ans * 50 - a[i];
		}
		sort(a,a+n);
		while(a[n] > 0)
		{
			if(a[n-3] == 0 && a[n] > 0)
			{
				ans ++;
				for(int i = 0;i<n;i++)
					a[i] += 50;
				sort(a,a+n);
			}
			a[n] --,a[n-1]--,a[n-2]--,a[n-3]--;
			sort(a,a+n);
			cout << ans << endl;
			if(a[n] <= 0)
				break;
		}
		cout << ans << endl;
	}
	return 0;
}
