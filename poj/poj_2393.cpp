#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

typedef long long ll;
const int N = 10005;

struct Node
{
	int c,y;
}a[N];

int main()
{
	int n,s;
	while(cin >> n >> s)
	{
		for(int  i = 0;i < n ;i ++)
			cin >> 	a[i].c >> a[i].y ;
		int cur_cnt = a[0].y;
		int cur_cost = a[0].c;
		ll ans = a[0].y * a[0].c;
		for(int i = 1;i<n;i++)
		{
			if(cur_cost + s < a[i].c)
			{
				cur_cost += s;
				ans += cur_cost * a[i].y; 
			}	
			else
			{
				cur_cost = a[i].c;
				ans += cur_cost * a[i].y;
			}
		}
		cout << ans << endl;
	}
}
