#include<bits/stdc++.h>
using namespace std;

const  int N = 1e6 + 7;

int a[N];
int pre_sum[N];
bool judge(int n)
{
	for (int i = 0; i < n; i++)
		if (a[i] > 1 && a[i + 1] > 1)
			return true;
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i <= n; i++)
			cin >> a[i];
		if (judge(n))
		{
			cout << "ambiguous" << endl;
			pre_sum[0] = a[0];
			for (int i = 1; i <= n; i++)
				pre_sum[i] = pre_sum[i - 1] + a[i];
			cout << 0;
			for (int i = 1; i <= n; i++)
				for (int j = 0; j < a[i]; j ++)
					cout << " " << pre_sum[i - 1];
			cout << endl;
			int flag = 0;
			cout << 0;
			for (int i = 1; i <= n; i++)
			{
				if (!flag && a[i - 1] > 1 && a[i] > 1)
				{
					for (int j = 0; j < a[i] - 1; j ++)
						cout << " " << pre_sum[i - 1];
					cout << " " << pre_sum[i - 1] - 1;
					flag = 1;
				}
				else
				{
					for (int j = 0; j < a[i]; j ++)
						cout << " " << pre_sum[i - 1];
				}
			}
			cout << endl;
		}
		else
			cout << "perfect" << endl;
	}
}