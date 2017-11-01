#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int val;
	char x;
	bool operator < (Node rhs) const
	{
		return (val < rhs.val || (val == rhs.val && x > rhs.x));
	}
};

int main()
{
	map<char,int>cnt;
	int n,m;
	vector<Node> v;
	while(scanf("%d%d",&n,&m) == 2)
	{
		if(n == 0 && m == 0)
			break;
		char x[100];
		cnt.clear();
		v.clear();
		for(int i = 0;i<n;i++)
		{
			scanf("%s",x);
			for(int j = 0;j<m;j++)
			{
				cnt[x[j]] ++;
			}
		}
		for(auto temp : cnt)
			v.push_back({temp.second,temp.first});
		sort(v.begin(),v.end());
		for(int i = v.size() - 1;i >= 0;i--)
		{
			if(i != v.size() - 1)
				printf(" ");
			printf("%c %d",v[i].x,v[i].val);
		}
		printf("\n");
	}
}
