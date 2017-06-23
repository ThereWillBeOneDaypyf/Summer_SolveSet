#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int LN,RN;//L,R数目  
int g[MAXN][MAXN], linker[MAXN];  
bool used[MAXN];  
int dfs(int L)//从左边开始找增广路径  
{  
	int R;  
	for(R = 1; R <= RN; R++)  
	{  
		if(g[L][R]!=0 && !used[R])  
		{  
			//找增广路，反向  
			used[R]=true;  
			if(linker[R] == -1 || dfs(linker[R]))  
			{  
				linker[R]=L;  
				return 1;  
			}  
		}  
	}  
	return 0;//这个不要忘了，经常忘记这句  
}  
int hungary()  
{  
	int res = 0 ;  
	int L;  
	memset(linker,-1,sizeof(linker));  
	for( L = 1; L <= LN; L++)  
	{  
		memset(used,0,sizeof(used));  
		if(dfs(L) != 0)  
			res++;  
	}  
	return res;  
} 
int a[MAXN],b[MAXN];
int main()
{
	int T;
	int ka = 0;
	cin >> T;
	while(T--)
	{
		memset(g,0,sizeof(g));
		cin >> LN;
		for(int i = 1;i<=LN;i++)
			cin >> a[i];
		cin >> RN;
		for(int i = 1;i<=RN;i++)
			cin >> b[i];
		for(int i = 1;i<=LN;i++)
		{
			for(int j = 1;j<=RN;j++)
			{
				if(b[j] % a[i] == 0)
					g[i][j] = 1;
			}
		}
		int ans = hungary();
		cout << "Case " << ++ ka << ": " << ans << endl;
	}
}
