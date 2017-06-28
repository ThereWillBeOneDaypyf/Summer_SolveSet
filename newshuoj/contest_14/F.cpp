#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int vis[105];
struct Node
{
	int val,id;
	Node(int _val,int _id) : val(_val),id(_id){}
};
int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		queue<Node>q;
		while(!q.empty())
			q.pop();
		int cnt = 0;
		for(int i = 1;i<=n;i++)
		{
			int x;
			cin >> x;
			q.push(Node(x,i));
		}
		int cur_call = 1;
		vector<Node>ans;
		ans.clear();
		while(!q.empty())
		{
			Node temp = q.front();
			q.pop();
			if(cur_call++==m)
			{
				ans.push_back(temp);
				cur_call = 1;
				m = temp.val;
			}
			else
			{
				q.push(temp);
			}
		}
		cout << ans[n-1].id << endl;	
	}
	return 0;
}
