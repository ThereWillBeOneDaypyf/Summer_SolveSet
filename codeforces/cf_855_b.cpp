//#include<bits/stdc++.h>
//using namespace std;
//
//const long long INF = 1e19 + 7; 
//const int N = 1e5 + 7;
//
//long long a[N];
//long long dp[N];
//
//int main()
//{
//	long long n,p,q,r;
//	while(cin >> n >> p >> q >> r)
//	{
//		for(int i = 1;i<=n;i++)
//			cin >> a[i];
//		vector<long long>v{p,q,r};
//		memset(dp,0,sizeof(dp));
//		dp[0] = - INF;
//		for(int i = 0;i<3;i++)
//		{
//			for(int j = 1;j<=n;j++)
//			{
//				dp[j] = max(dp[j-1],dp[j] + v[i] * a[j]);
//			}
//		}
//		cout << dp[n] << endl;
//	}
//}
//
