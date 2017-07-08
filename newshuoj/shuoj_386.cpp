#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

long long ans[N];
void f()
{
	memset(ans,0,sizeof(ans));
	ans[0] = 1;
	ans[1] = 1;
	for(int i = 2 ;i<N;i++)
		ans[i] = (ans[i-1] * i)%MOD;
}
int main()
{
	f();
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
}
