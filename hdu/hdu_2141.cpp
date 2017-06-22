#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 505;

int a[N],b[N],c[N];
int sum[N*N];
int h = 0;
bool judge(int tar)
{
	int l = 0,r = h-1,mid;
	while(l <= r)
	{
		mid = (l + r ) /2;
		if(tar == sum[mid])
			return true;
		if(tar < sum[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}
	return false;
}

int main()
{
	int l,n,m; // a,b,c
	int ka = 0;
	while(cin >> l >> n>> m)
	{
		for(int i =0 ;i<l;i++)
			cin >> a[i];
		for(int i =0;i<n;i++)
			cin >> b[i];
		for(int i =0;i<m;i++)
			cin >> c[i];
		h = 0;
		for(int i =0;i<l;i++)
			for(int j=0;j<n;j++)
				sum[h++] = a[i] + b[j];
		sort(sum,sum+h);
		int q;
		cin >> q;
		cout << "Case " << ++ka << ":" << endl;
		for(int i = 0;i<q;i++)
		{
			int x;
			cin >> x;
			int flag = 0;
			for(int j=0;j<m;j++)
			{
				int tar = x - c[j];
				if(judge(tar))
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				cout<< "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
