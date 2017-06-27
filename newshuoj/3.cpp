#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Node
{
	int x;
	int id;
	Node(int _x,int _id) : x(_x) , id(_id){}
};
struct cmp
{
	bool operator () (const Node &  a,const Node & b)
	{
		return a.x < b.x || (a.x==b.x && a.id > b.id);
	}
};
bool cmp_id(Node a,Node b)
{
	return a.id < b.id;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{	
		priority_queue<Node,vector<Node>,cmp>q;
		vector<Node>ans;
		int x;
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&x);
			q.push(Node(x,i));
			Node temp = q.top();
			q.pop();
			temp.x --;
			q.push(temp);
		}
		for(int i = 1;i<=n;i++)
		{
			ans.push_back(q.top());
			q.pop();
		}
		sort(ans.begin(),ans.end(),cmp_id);
		for(int i = 0;i<n;i++)
			i == n-1 ?printf("%d\n",ans[i].x) : printf("%d ",ans[i].x);
	}
	return 0;
}
