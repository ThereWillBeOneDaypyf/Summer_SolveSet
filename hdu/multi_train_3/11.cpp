nclude<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	vector<int>a;
	int t;
	while(cin >> t)
	{
		int ans = 0;
		for(int i = 0;i<t;i++)
		{
			int x;
			cin >> x;
			if(x <= 35)
				ans ++;
		}
		cout << ans << endl;
	}
}

