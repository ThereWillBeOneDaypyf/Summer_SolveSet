#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
#define INF 0x3f3f3f3f
typedef long long ll;
const int N = 1e4+5;

struct Node
{
	int s,w;
	bool operator < (const Node &rhs) const
	{
		return w - rhs.s < rhs.w - s;
	}
}a[N];

int main()
{
	int n;
	while(cin >> n)
	{
		for(int i =0 ;i<n;i++)
		{
			cin >> a[i].w >> a[i].s;
		}
		sort(a,a+n);
		ll sum = 0;
		ll Max = -INF;
		for(int i = 0;i<n;i++)
		{
			Max = max(Max,sum - a[i].s);
			sum += a[i].w;
		}
		cout << Max << endl;
	}
}
