#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int,int> PII;
typedef long long ll;

const int N = 50*50*1000+100;

int cnt[1005];
int v[1005];
int c1[N];
int c2[N];

int main()
{
	int n;
	while(cin >> n)
	{
		if(n<=-1)
			break;
		int sum  = 0;
		for(int i=0;i<n;i++)
			cin >> v[i] >> cnt[i];
		for(int i=0;i<n;i++)
			sum += v[i]*cnt[i];
		CLR(c1,0);
		CLR(c2,0);
//		for(int i=0;i<=cnt[0]*v[0];i+=v[0])
//			c1[i] = 1,c2[i] = 0;
		c1[0] = 1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=sum/2;j++)
			{
				for(int k = 0 ;k<=cnt[i]*v[i];k+=v[i])
				{
					if(j+k <= sum/2&&(c2[j+k]||c1[j]))
						c2[j+k] = 1;
				}
			}
			for(int j=0;j<=sum/2;j++)
				c1[j] = c2[j] ,c2[j] = 0;
		}	
		int ans ;		
		for(ans=sum/2;ans>=0;ans--)
			if(c1[ans])
				break;
		cout << sum-ans << " " << ans << endl;	
	}
	return 0;
}
