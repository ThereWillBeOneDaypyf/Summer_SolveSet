#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

vector<int>v[N];
queue<int> q0,q1;


int main()
{
	string s;
	ios :: sync_with_stdio(false);
	while(cin >> s)
	{
		for(int i = 0;i < N;i++)
			v[i].clear();
		int tot = 0;
		int flag = 1;
		for(int i = 0;i < s.length();i ++)
		{
			if(s[i] == '0')
			{
				if(!q1.empty())
				{
					int id = q1.front();
					q1.pop();
					v[id].push_back(i);
					q0.push(id);
				}
				else 
				{
					v[tot++].push_back(i);
					q0.push(tot - 1);
				}
			}
			else 
			{
				if(q0.empty())
				{
					flag = 0;
					break;
				}
				else
				{
					int id = q0.front();
					q0.pop();
					v[id].push_back(i);
					q1.push(id);
				}
			}
		}
		if(!flag || !q1.empty())
			cout << -1 << endl;
		else
		{
			cout << q0.size() << endl;
			while(!q0.empty())
			{
				int temp = q0.front();
				q0.pop();
				cout << v[temp].size();
				for(auto ele : v[temp])
					cout << " " << ele + 1;
				cout << endl;
			}
		}
	}
}
