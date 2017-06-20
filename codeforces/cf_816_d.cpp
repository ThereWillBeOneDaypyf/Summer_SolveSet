#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int N = 1e6 + 7;

int a[N];
int l[N];
int r[N];
int lt[N];
int rt[N];

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i =0  ;i< n;i++)
			scanf("%d", a+i);
		for(int i = 0 ;i < n;i ++ )
			lt[i] = rt[i] = l[i] = r[i] = i;
		long long ans = 0;
		for(int i = 0;i < n;i ++)
		{
			int cur = i;
			while(cur >0 && a[i] >= a[cur-1])
				cur = l[cur-1];
			l[i] = cur;
		}
		for(int i = n-2;i >= 0 ;i--)
		{
			int cur = i;
			while(cur < n - 1 && a[i] > a[cur+1])
				cur = r[cur +1];
			r[i] = cur;
		}
		//for(int i = 0;i<n;i++)
		//	cout << "i :" << i << " " << l[i] << " " << r[i] << endl;
		//for(int i = 0 ;i < n ;i++)
		//	ans += (ll) (r[i] - i + 1) * (i - l[i] + 1) * a[i];
		//for(int i = 0;i < n ; i++)
		//	l[i] = r[i] = i;
		for(int i = 0;i<n ;i++)
		{
			int cur = i;
			while(cur > 0 && a[i] <= a[cur-1])
				cur = lt[cur-1];
			lt[i] = cur;
		}
		for(int i = n-2;i>=0;i--)
		{
			int cur = i;
			while(cur < n - 1 && a[i] < a[cur+1])
				cur = rt[cur+1];
			rt[i] = cur;
		}
		//for(int i =0 ;i<n;i++)
		//	cout << i << " " << l[i] << " " << r[i] << endl;
		for(int i =0 ;i<n;i++)
		{
			ans += (ll)(r[i] - i + 1 )  * (i - l[i] + 1) * a[i];
			ans -= (ll)(rt[i] - i + 1 ) * (i - lt[i] + 1 ) * a[i];
		}
		printf("%lld\n",ans);
	}
}	
