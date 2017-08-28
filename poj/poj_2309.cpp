#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
int get_Max(long long n)
{
	for (int i = 31 ; i >= 0; i--)
		if (n & (1 << i))
			return i;
}
int get_low(long long n)
{
	for (int i = 0; i <= 31; i++)
		if (n & (1 << i))
			return i;
}
int main()
{
	long long n;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &n);
		int l = get_Max(n);
		int ll = get_low(n);
		long long Min = n ^ (1 << ll);
		Min ++;
		long long Max = n | ((1 << (ll + 1)) - 1);
		printf("%lld %lld\n", Min , Max);
	}
}