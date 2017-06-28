#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int c,v0,v1,a,l;
	while(cin >> c >> v0 >> v1 >> a >> l )
	{
		int cur = v0;
		int ans = 1;
		int v = v0;
		while(cur <  c)
		{
			cur -= l;
			v = min(v+a,v1);
			cur += v;
			ans ++;	
		}
		cout << ans << endl;
	}	
}
