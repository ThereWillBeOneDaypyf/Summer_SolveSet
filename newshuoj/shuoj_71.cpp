#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 +7;

int a[N];
int main()
{
	int n;
	while(cin >> n)
	{
		priority_queue<int ,vector<int>,greater<int> >q;
		for(int i =0 ;i<n;i++)
		{
			int x;
			cin >> x;
			q.push(x);
		}
		int ans = 0;
		while(q.size() > 1)
		{
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			q.push(x+y);
			ans += (x+y);
		}
		cout << ans << endl;
	}
}

