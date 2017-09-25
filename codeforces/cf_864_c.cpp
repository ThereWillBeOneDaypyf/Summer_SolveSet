#include<bits/stdc++.h>
using namespace std;


int main()
{
	long long a,b,f,k;
	while(cin >> a >> b >> f >> k)
	{
		long long s = 0,t = f;
		int flag = 0;
		int cur = b;
		int cnt = 0;
		if(k == 1)
		{
			if(b < f || b < (a - f))
			//if(b < f)
				cout << -1 << endl;
			else if(b < a)
				cout << 1 << endl;
			else cout << 0 << endl;
			continue;
		}
		if(b < 2 * f || b < 2 * (a - f))
		{
			cout << -1 << endl;
			continue;
		}
		for(int i = 0;i < k;i++)
		{
			if(t - s > cur)
			{
				cur = b;
				cnt ++;
			}
			cur -= (t - s);
			if(!flag)
			{
				s = t;
				t = t + 2 * (a - f);	
			}
			else
			{
				s = t;
				t = t + 2 * f;
			}
			flag ^= 1;
		}
		if(flag)
		{
			if(cur < (a - f))
				cnt ++;
		}
		else 
		{
			if(cur < f)
				cnt ++;
		}
		cout << cnt << endl;
	}

}
