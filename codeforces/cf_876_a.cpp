#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int a,b,c;
		cin >> a >> b >> c;
		vector<int> v{a,b,c};
		sort(v.begin(),v.end());
		int ans = 0;
		if(n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		n --;
		if(v[0] == a || v[0] == b)
		{
			ans += v[0] * n;	
		}
		else
		{
			ans += min(v[1],v[2]);
			ans += (n-1) * v[0];
		}
		cout << ans << endl;
	}

}
