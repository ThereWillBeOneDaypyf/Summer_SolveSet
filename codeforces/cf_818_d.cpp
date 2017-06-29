#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

map<int,int> m;

struct cmp
{
	bool operator () (int a,int b) const
	{
		return m[a] > m[b];
	}
};
int clr[1000000];

int main()
{
	int n,tar;
	while(cin >> n >> tar)
	{
		m.clear();
		int pos = -1;
		for(int i = 0 ;i<n;i++)
		{
			cin >> clr[i];
			if(tar == clr[i] && pos == -1)
				pos = i;
		}
		if(pos == -1)
		{
			cout << clr[0] << endl;
			continue;
		}
		priority_queue<int,vector<int>,cmp>q;
		int flag = 1;
		for(int i = 0;i<=pos;i++)
		{
			if(!m.count(clr[i]))
			{
				q.push(clr[i]);
			}
			m[clr[i]]++;
		}
		for(int i = pos+1 ;i<n;i++)
		{
			int x = clr[i];
			if(!m.count(x) || m[x] == -1)
				continue;
			m[x] ++;
			if(x == tar)
			{
				while(m[q.top()] < m[x])
				{
					m[q.top()] = -1;
					q.pop();
				}
				if(q.size() == 1)
					flag = 0;
			}
		}
		if(!flag)
			cout << -1 << endl;
		else if(pos == -1 || q.size() > 1)
		{
			while(q.top() == tar)
				q.pop();
			cout << q.top() << endl;
		}
		else 
			cout << - 1 << endl;
	}	
}
