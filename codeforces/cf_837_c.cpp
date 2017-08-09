#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e3 + 8;

struct Node
{
	int x,y;
}c[N];

int main()
{
	int n,a,b;
	while(cin >> n >> a >> b)
	{
		for(int i = 0;i<n;i++)
			cin >> c[i].x >> c[i].y;
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0 ;j<n;j++)
			{
				if(i == j)
					continue;
				swap(a,b);
				if((c[i].x + c[j].x <= a && max(c[i].y,c[j].y) <=b)
					|| (c[i].x + c[j].y <= a && max(c[i].y,c[j].x) <= b)
					|| (c[i].y + c[j].y <= a && max(c[i].x,c[j].x) <= b)
					|| (c[i].y + c[j].x <= a && max(c[i].x,c[j].y) <= b))
				{
					ans = max(ans,c[i].x * c[i].y + c[j].x * c[j].y);
				}
				swap(a,b);
				if((c[i].x + c[j].x <= a && max(c[i].y,c[j].y) <=b)
					|| (c[i].x + c[j].y <= a && max(c[i].y,c[j].x) <= b)
					|| (c[i].y + c[j].y <= a && max(c[i].x,c[j].x) <= b)
					|| (c[i].y + c[j].x <= a && max(c[i].x,c[j].y) <= b))
				{
					ans = max(ans,c[i].x * c[i].y + c[j].x * c[j].y);
				}
			}
		}
		cout << ans << endl;
	}
}
