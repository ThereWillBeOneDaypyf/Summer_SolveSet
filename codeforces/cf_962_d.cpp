#include<bits/stdc++.h>
using namespace std;

struct Node
{
	long long val;
	int pos;
	bool operator < (const Node& x) const
	{
		if (val == x.val)
			return pos > x.pos;
		return val > x.val;
	}
};

int main()
{
	int n;
	while (cin >> n)
	{
		priority_queue<Node> q;
		for (int i = 0; i < n; i ++)
		{
			long long x;
			cin >> x;
			q.push((Node) {x, i});
		}
		vector<Node> ans;
		while (q.size() >= 2)
		{
			Node temp1 = q.top();
			q.pop();
			Node temp2 = q.top();
			q.pop();
			if (temp1.val != temp2.val)
			{
				ans.push_back(temp1);
				q.push(temp2);
				continue;
			}
			else
			{
				Node new_node;
				new_node.val = temp2.val * 2;
				new_node.pos = temp2.pos;
				q.push(new_node);
			}
		}
		while (!q.empty())
		{
			ans.push_back(q.top());
			q.pop();
		}
		cout << ans.size() << endl;
		sort(ans.begin(), ans.end(), [](Node a, Node b) {return a.pos < b.pos;});
		for (int i = 0; i < ans.size(); i ++)
		{
			if (i)
				cout << " ";
			cout << ans[i].val;
		}
		cout << endl;
	}
}