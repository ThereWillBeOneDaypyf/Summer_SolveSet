#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

int a[N];
int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0;i<n;i++)
			cin >> a[i];
		int i = 0;
		int flag =0;
		for(i = 1;i<n;i++)
			if(a[i-1] >= a[i])
				break;			
		if(i == n)
			flag = 1;
		for(;i<n;i++)
			if(a[i-1] != a[i])
				break;
		for(;i<n;i++)
			if(a[i-1] <= a[i])
				break;
		if(flag)
		{
			int cnt = 0;
			for(int i = 1;i<n;i++)
			{
				if(a[i-1] == a[i])
					cnt ++;
			}
			if(cnt == n-1)
				flag = 0;
		}
		if(i<n || flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}	
}
