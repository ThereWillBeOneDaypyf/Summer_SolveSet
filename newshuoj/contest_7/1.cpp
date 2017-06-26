#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

vector<int>v[500005];
void init()
{
	for(int i = 0 ;i<500005 ; i++)
		v[i].clear();
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		init();
		map<pair<int,int> , int> tran;
		int tot = 0;
		for(int i = 0 ;i<n;i++)
		{
			int x ,y,id;
			scanf("%d%d%d",&id,&x,&y);
			pair<int,int> temp = make_pair(x,y);
			if(!tran.count(temp))
				tran[temp] = tot ++;
			v[tran[temp]].push_back(id);
		}
	//	for(int i =0 ;i<tot;i++)
	//		sort(v[i].begin(),v[i].end());
		int q;
		scanf("%d",&q);
		for(int i = 0 ;i<q;i++)
		{
			int x,y,k;
			scanf("%d%d%d",&x,&y,&k);
			cout << v[tran[make_pair(x,y)]][k-1] << endl;
		}
	}
	return 0;
}
