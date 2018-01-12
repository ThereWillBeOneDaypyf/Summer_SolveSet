#include<bits/stdc++.h>
using namespace std;


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int cur = m % n;
		if (cur == 0)
			cur = n;
		cout << cur << endl;
	}
}
// #include<cstdio>
// #include<cstring>
// #include<algorithm>

// using namespace std;

// char ans[100];


// int main()
// {
// 	int a, b;
// 	int count = 0; //计数
// 	scanf("%d%d", &a, &b);
// 	sprintf(ans, "%d", a + b);
// 	int len = strlen(ans);
// 	if (ans[0] == '-') printf("-");
// 	else
// 	{
// 		printf("%c", ans[0]);
// 		count++;//加1
// 	}
// 	for (int i = 1; i < len; i++)
// 	{
// 		if (count == 3)
// 		{
// 			printf(",");
// 			count = 0; //归0
// 		}
// 		printf("%c", ans[i]);
// 		count++;
// 	}
// 	return 0;
// }