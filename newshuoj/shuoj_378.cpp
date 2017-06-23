#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int n;
	while(cin >> n )
	{
		int cnt = 0;
		int ans = -1;
		for(int i = 0;i<n;i++)
		{
			int x;
			cin >> x;
			if( x != ans)
			{
				if(!cnt)
				{
					ans = x;
					cnt ++;
				}
				else
					cnt --;
			}
			else
				cnt ++;
		}
		cout << ans << endl;
	}
}
