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

const int N = 1e5+5;

int v[3] = {1,2,5};
int cnt[3];
int c1[N];
int c2[N];
int main()
{
	while(cin >> cnt[0] >> cnt[1] >> cnt[2] && (cnt[0] || cnt[1] || cnt[2]))
	{
		CLR(c1,0);
		CLR(c2,0);
		int sum = 0;
		for(int i=0;i<3;i++)
			sum += cnt[i] * v[i];
		for(int i = 0;i<=cnt[0]*v[0];i++)
			c1[i] = 1, c2[i] = 0;
		for(int i= 1;i<3;i++)
		{
			for(int j=0;j<=sum;j++)
			{
				for(int k = 0;k<=cnt[i]*v[i];k+=v[i])
				{
					c2[j+k] += c1[j];
				}
			}
			for(int j=0;j<=sum;j++)
				c1[j] = c2[j] , c2[j] = 0;
		}
		int ans = 0;
		for(ans = 0 ;ans <= sum ;ans ++)
			if(c1[ans]==0)
				break;
		cout << ans << endl;
	}
}
