#include<bits/stdc++.h>
using namespace std;


int dp[21][1 << 20];
vector<int> G[21];
const int MOD = 998244353;
inline int read(){
	int x=0; char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
int main()
{
	int n,m;
	n = read(),m = read();
	{
		for(int i = 0;i<m;i++)
		{
			int u,v;
			u = read(),v = read();
			G[u].push_back(v);
		}
		dp[0][0] = 1;
		for(int i = 1;i <= n;i++)
		{
			for(auto v : G[i])
			{
				for(int j = 0;j < (1 << n);j ++)
				{
					if((j & (1 << (v-1))) == 0)
						continue;
					dp[i][j] = dp[i][j] + dp[i-1][j ^ (1 << (v-1))];
					if(dp[i][j] > MOD)
						dp[i][j] -= MOD;
				}	
			}
		}
		printf("%d\n",dp[n][(1 << n) - 1]);
	}
}
