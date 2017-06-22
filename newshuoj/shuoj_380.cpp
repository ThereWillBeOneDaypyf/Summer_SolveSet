#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 1;



int search(long long tar)
{
	int ans = 0;
	int l = 1 , r = N;
	int mid ;
	while(l <= r)
	{
		mid = (l + r)/2;
		if((long long)mid * mid <= tar)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ans ;
}	
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",search(n));
	}
}
