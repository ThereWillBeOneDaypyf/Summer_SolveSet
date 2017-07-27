#include<bits/stdc++.h>
using namespace std;
//thanks to pyf ...
//thanks to qhl ...


const int N = 3e5;
const int MOD = 1e9 + 7;
struct Node
{
	int val,id;
	int dif = val - id;
	bool operator < (const Node &rhs) const
	{
		return dif < rhs.dif || (val < rhs.val && id > rhs.id);
	}
}a[N];
int b[N];
int main()
{
	priority_queue<Node> q;
	int n;
	while(scanf("%d",&n) == 1)
	{
		while(!q.empty())
			q.pop();
		for(int i =1 ;i<=n;i++)
		{//correct
			scanf("%d",&a[i].val);
			a[i].id = i;
			a[i].dif = a[i].val - a[i].id;
			q.push(a[i]);
		}
		long long ans = 0;
		for(int i =1 ;i<=n;i++)
			scanf("%d",b+i);
		sort(b+1,b+n+1);
		for(int i = 1;i<=n;i++)
		{
			while(1)
			{
				Node temp = q.top();
				if(temp.id >= b[i])
				{
					ans=((ans+temp.dif)%MOD+MOD)%MOD;
					Node tar;
					tar.id = n + i;
		//			cout << tar.id << endl;
					tar.val = temp.dif;
					tar.dif = tar.val - tar.id;
		//			cout << tar.dif << endl;
					q.push(tar);
					break;
				}
				else
					q.pop();
			}
		}
		printf("%lld\n",ans);
	}
}
