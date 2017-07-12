#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6;

int v[N];

int main()
{
	int a,b;
	int n;
	while(cin >> n >> a >> b)
	{
		memset(v,0,sizeof(v));
		for(int i = 0;i<n;i++)
			cin >> v[i];
		int __b = 0;
		int ans = 0;
		for(int i = 0;i<n;i++)
		{
			if(v[i] == 1)
			{
				if(a)
					a--;
				else if(b)
				{
					b--;
					__b ++;
				}
				else if(__b)
					__b--;
				else
					ans ++;
			}
			else
			{
				if(b)
					b --;
				else
					ans +=2;
			}
		}
		cout << ans << endl;
	}
}
