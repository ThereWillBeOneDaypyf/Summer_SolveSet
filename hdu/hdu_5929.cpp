// #include<bits/stddc++.h>
// using namespace std;

// int main()
// {
// 	int T;
// 	scanf("%d", &T);
// 	while (T--)
// 	{
// 		int q;
// 		scanf("%d", &q);
// 		char op[10];
// 		deque<int>deq;
// 		int flag = 0;
// 		int ans[2];
// 		while (q--)
// 		{
// 			scanf("%s", op);
// 			if (op[0] == 'R')
// 				flag ^= 1;
// 			else if (op[0] == 'Q')
// 			{
// 				if (deq.empty())
// 					printf("Invalid\n");
// 				else
// 					printf("%d\n", ans[flag])
// 				}
// 			else
// 			{
// 				if (op[1] == 'U')
// 				{
// 					int x;
// 					scanf("%d", &x);
// 					if (flag)
// 						deq.push_front(x);
// 					else deq.push_back(x);
// 					if (ans[flag] == 0)
// 						ans[flag] = 1;
// 					else ans[flag] = x ^ 1;
// 					if (x == 0)
// 						ans[flag ^ 1] = 1;
// 					else ans[flag ^ 1] = ans[flag ^ 1] ^ 1;
// 				}
// 				else
// 				{
// 					int x;
// 					if (deq.empty())
// 						continue;
// 					if (flag)
// 					{
// 						x = deq.front();
// 						deq.pop_front();
// 					}
// 					else
// 					{
// 						x = deq.back();
// 						deq.pop_back();
// 					}

// 				}
// 			}
// 		}
// 	}
// }
#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long a, b, f, k;
	while (cin >> a >> b >> f >> k)
	{
		long long s = 0, t = f;
		int flag = 0;
		int cur = b;
		int cnt = 0;
		if (k == 1)
		{
			if (b < f || b < (a - f))
				//if(b < f)
				cout << -1 << endl;
			else if (b < a)
				cout << 1 << endl;
			else cout << 0 << endl;
			continue;
		}
		int ok = 1;
		for (int i = 0; i < k; i++)
		{
			if (t - s > b)
			{
				ok = 0;
				break;
			}
			if (t - s > cur)
			{
				cur = b;
				cnt ++;
			}
			cur -= (t - s);
			if (!flag)
			{
				s = t;
				t = t + 2 * (a - f);
			}
			else
			{
				s = t;
				t = t + 2 * f;
			}
			flag ^= 1;
		}
		if (flag)
		{
			if (cur < (a - f))
				cnt ++;
		}
		else
		{
			if (cur < f)
				cnt ++;
		}
		if (!ok)
			cout << -1 << endl;
		else
			cout << cnt << endl;
	}

}