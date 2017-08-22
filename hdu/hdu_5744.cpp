#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		int odd_cnt = 0;
		long long sum = 0;;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x % 2)
				odd_cnt ++, x --;
			sum += x / 2;
		}
		if (odd_cnt == 0)
			printf("%d\n", sum * 2);
		else
			printf("%d\n", 1 + (sum / odd_cnt) * 2);
	}
}