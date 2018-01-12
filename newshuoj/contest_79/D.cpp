#include<bits/stdc++.h>
using namespace std;

unsigned long long C[1005][1005];

void init()
{
	C[0][0] = 1;
	for (int i = 1; i < 1005; i++)
	{
		C[i][0] = 1, C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
}

int main()
{
	int T;
	cin >> T;
	init();
	int w, z, a, b;
	while (T--)
	{
		cin >> w >> z >> a >> b;
		unsigned long long ans = 0;
		for (int i = 0; i <= (w - z) / a; i++)
		{
			long long ret = w - z - i * a;
			if (ret < 0)
				break;
			if (ret % b == 0)
			{
				long long temp = ret / b + i;
				ans += C[temp][i];
			}
		}
		cout << ans << endl;
	}
}