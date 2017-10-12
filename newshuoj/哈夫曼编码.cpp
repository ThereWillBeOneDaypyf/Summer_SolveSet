#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


struct Node
{
	int type;
	int lt, rt;
	int val;
	int id;
	string code;
} a[1000];
int cnt = 0;
void init()
{
	a[0].lt = a[0].rt = 0;
	cnt = 0;
}
int NewNode(int val, int type, int id)
{
	cnt ++;
	a[cnt].val = val;
	a[cnt].type = type;
	a[cnt].id = id;
	a[cnt].code = "";
	a[cnt].lt = a[cnt].rt = 0;
	return cnt;
}
struct cmp
{
	bool operator()(const int x, const int y)
	{
		return a[x].val > a[y].val || (a[x].val == a[y].val && a[x].id < a[y].id);
		//return a[x].val > a[y].val;
	}
};
pair<int, string> ans[1000];
void dfs(int pos, string code)
{
	a[pos].code = code;
	if (a[pos].lt)
		dfs(a[pos].lt, code + "0");
	if (a[pos].rt)
		dfs(a[pos].rt, code + "1");
}
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while (T--)
	{
		cout << "Case " << ++ ka << endl;
		init();
		int n;
		cin >> n;
		priority_queue<int, vector<int> , cmp>q;
		for (int i = 0; i < n; i++)
		{
			int val;
			cin >> val;
			q.push(NewNode(val, 1, i));
		}
		int time = n;
		while (q.size() != 1)
		{
			int temp_id1 = q.top();
			Node temp1 = a[temp_id1];
			q.pop();
			int temp_id2 = q.top();
			Node temp2 = a[temp_id2];
			q.pop();
			int x = NewNode(temp1.val + temp2.val , 0, time++);
			a[x].lt = temp_id2;
			a[x].rt = temp_id1;
			q.push(x);
		}
		dfs(q.top(), "");
		for (int i = 1; i <= cnt; i++)
			if (a[i].type == 1)
				ans[a[i].id] = make_pair(a[i].val, a[i].code);
		for (int i = 0; i < n; i++)
			cout << ans[i].first << " " << ans[i].second << endl;
		cout << endl;
	}
}