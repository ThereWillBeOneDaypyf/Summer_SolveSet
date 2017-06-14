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

int c1[N];
int c2[N];
int Max_N = 17;
int Max_M = 310;
void f()
{
	for(int i = 0; i <= Max_M;i++)
		c1[i] = 1,c2[i] = 0;
	for(int i = 2 ; i <=  Max_N;i++)
	{
		for(int j = 0; j <= Max_M; j++)
		{
			for(int k=0;k<=Max_M;k+=pow(i,2))
			{
				if(j+k <= Max_M);
					c2[j+k] += c1[j];
			}
		}
		for(int j=0;j<=Max_M;j++)
			c1[j] = c2[j],c2[j] = 0;
	}
}
int main()
{
	int n;
	f();
	while(cin >> n && n)
	{
		cout << c1[n] << endl;
	}
}
