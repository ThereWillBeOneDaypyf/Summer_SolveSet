#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

struct Node
{
	int ed, p;
	bool operator < (const Node & rhs) const
	{
		return ed < rhs.ed || (ed == rhs.ed && p > rhs.p);
	}
} a[N];
struct cmp
{
	bool operator()(const Node a, const Node b) const
	{
		return a.p > b.p;
	}
};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		priority_queue<Node, vector<Node> , cmp>q;
		vector<int>ans;
		for (int i = 0; i < n; i++)
			cin >> a[i].ed;
		for (int i = 0; i < n; i++)
			cin >> a[i].p;
		sort(a, a + n);
		int cur = 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i].ed < cur)
			{
				Node temp = q.top();
				if (temp.p < a[i].p)
				{
					q.pop();
					q.push(a[i]);
					ans.push_back(temp.p);
				}
				else
					ans.push_back(a[i].p);
			}
			else
				cur ++, q.push(a[i]);
		}
		int sum = 0;
		for (auto x : ans)
			sum += x;
		cout << sum << endl;
	}
}