#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 10;

int a[N];
char op[10];
long long sum;
int i, len;
int x;
int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		len = 0;
		while (n--)
		{
			scanf("%s", op);
			if (op[0] == 's')
			{
				sum = 0;
				for (i = 2; i < len; i += 5)
					sum += a[i];
				printf("%lld\n", sum);
			}
			else if (op[0] == 'a')
			{
				scanf("%d", &x);
				for (i = len++; i > 0; i--)
				{
					if (a[i - 1] > x)
						a[i] = a[i - 1];
					else
						break;
				}
				a[i] = x;
			}
			else
			{
				scanf("%d", &x);
				for (i = 0; i < len; i++)
					if (a[i] == x)
						break;
				for (; i < len - 1; i++)
					a[i] = a[i + 1];
				len --;
			}
		}
	}
}