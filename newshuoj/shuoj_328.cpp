#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long ll;

const int N = 1e5 + 5;

int t[N];

int judge()
{
	for(int i = 0;i<N;i++)
		if(t[i]==2)
			return i;
	return -1;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		memset(t,0,sizeof(t));
		int cur_a = b;
		int cur_c = d;
		while(cur_a < N || cur_c < N)
		{
			if(cur_a < N)
			{
				t[cur_a] ++;
				cur_a += a;
			}
			if(cur_c < N)
			{
				t[cur_c] ++;
				cur_c += c;
			}
		}
		cout << judge() << endl;
	}
	return 0;
}

