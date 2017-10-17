#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	int n,k;
	while(cin >> n >> k)
	{
		int Min = (1e9 + 7);
		int Max = -(1e9 + 7); 
		vector<int> v;
		for(int i = 0;i<n;i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
			Min = min(Min,x);
			Max = max(Max,x);
		}
		if(k == 1)
			cout << Min << endl;
		else if(k == 2)
			cout << max(*v.begin(),*v.rbegin()) << endl;	
		else
			cout << Max << endl;
	}
}
