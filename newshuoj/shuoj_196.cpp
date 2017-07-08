#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int n,s;
int a[1005];
bool judge(int l,int r,int tar)
{
	int mid ;
	while(l <= r)
	{
		mid = (l + r) / 2;
		int sum = a[mid]+tar;
		if(sum == s)
			return true;
		if(sum < s)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return false;
}
int main()
{
	while(cin >> n >> s)
	{
		for(int i = 0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		int flag = 0;
		for(int i = 0;i<n;i++)
		{
			if(flag)
				break;
			for(int j = i+1;j<n;j++)
			{
				int sum = a[i] + a[j];
				if(sum >= s)
					continue;
				else if(judge(j+1,n-1,sum))
					flag = 1;
				if(flag)
					break;
			}
		}			
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}	
	return 0;
}

