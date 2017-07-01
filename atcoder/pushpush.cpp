#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;

int a[N*2];

int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0 ;i<n;i++)
		{
			cin >> a[i];
		}
		deque<int>q;
		for(int i = 0;i<n;i++)
		{
			if(i % 2 != n % 2)
			{
				q.push_front(a[i]);
			}
			else
			{
				q.push_back(a[i]);
			}
		}
		deque<int> :: iterator it;
		int cnt = 0 ;
		for(it = q.begin();it!=q.end();it++)
		{
			if(cnt++)
				cout << " " ;
			cout << *it;	
		}
		cout << endl;
	}
}
