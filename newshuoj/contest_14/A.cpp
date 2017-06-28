#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e4;

int p[N];
int pre_sum[N];
int main()
{
	int n;
	while(cin >> n)
	{
		for(int i =1;i<=n;i++)
			cin >> p[i];
		sort(p+1,p+n+1);
		memset(pre_sum,0,sizeof(pre_sum));
		int i;
		for(i = 1;i<=n;i++)
		{
			if(p[i] > pre_sum[i-1] + 1)
				break;
			pre_sum[i] = pre_sum[i-1] + p[i];
		}
		cout << pre_sum[i-1] + 1 << endl;
	}
}
