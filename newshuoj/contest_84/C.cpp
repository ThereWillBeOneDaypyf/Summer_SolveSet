#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main()
{
	int n,k;
	while(cin >> n >> k && (n || k ))
	{
		ull fuck[30];
		memset(fuck,0,sizeof(fuck));
		fuck[0] = 1;
		for(int i = 1;i <= n;i++)
			fuck[i] = 1ULL * i * fuck[i - 1];
		//for(int i = 1;i <= k;i++)
		//	fuck[n] /= i;
		cout << fuck[n] / fuck[n - k] << endl;
	}
}
