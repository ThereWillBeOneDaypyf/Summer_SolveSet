#include <bits/stdc++.h>

using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 5;

int a[N];

int main()
{
	int  T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i =0 ;i<n;i++)
			scanf("%d",a+i);
		int evenpos_odd = 0,oddpos_even = 0;
		int cnt_zero = 0;
		for(int i = 0;i<n;i++)
		{
			if( i % 2 == 0 && a[i] % 2 == 1)
			{
				evenpos_odd ++;
				if(a[i] == 1)
					cnt_zero ++;
			}
			else if( i % 2 == 1 && a[i] % 2 == 0)
				oddpos_even ++;
		}
		int flag = 1;
		int ans = min(oddpos_even,evenpos_odd);
		int ret = max(oddpos_even,evenpos_odd) - min(oddpos_even,evenpos_odd);
		if(ret % 2)
			flag = 0;
		else
		{
			if(evenpos_odd > oddpos_even)
			{
				evenpos_odd -= oddpos_even;
				if(evenpos_odd % 2 == 1)
					flag = 0;
				if(cnt_zero > oddpos_even)
				{
					cnt_zero -= oddpos_even;
					if(cnt_zero > evenpos_odd /2)
					{
						int cnt =0 ;
						for(int i =0 ;i<n;i++)
						{
							if(a[i] >= 4)
								cnt ++ ;
						}
						if(cnt > (cnt_zero - evenpos_odd / 2) /2)
							ans += cnt_zero - evenpos_odd / 2;
					}
					else
						ans += evenpos_odd / 2;
				}
				else
				{
					ans += evenpos_odd /2;
				}
			}
			else
			{
				ans += (oddpos_even - evenpos_odd) / 2;
			}
		}
		if(!flag)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
}

/*
4
4
1 1 1 1
5
3 1 1 1 2
*/
