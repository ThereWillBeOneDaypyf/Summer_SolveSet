#include<bits/stdc++.h>
using namespace std;
int r,k;
int n,m;
struct Node
{
	int x,y;
	long long val;
	bool operator < (const Node &rhs) const
	{
		return val < rhs.val;
	}
};
long long cal(pair<int,int> pos)
{
	return 1LL * (min(n + 1,pos.first + r) - max(pos.first,r))
		*(min(m + 1,pos.second + r) - max(pos.second,r));
}
map<pair<int,int> ,bool> vis;
int xdir[8] = {0,1,0,-1,1,1,-1,-1};
int ydir[8] = {1,0,-1,0,-1,1,-1,1};
int main()
{
	while(cin >> n >> m >> r >> k)
	{
		//for(int i = 1;i <= n;i++)
		//{
		//	for(int j = 1;j <= m;j++)
		//	{
		//		cout << cal(make_pair(i,j)) << '\t' ;
		//	}
		//	cout << endl;
		//}
		vis.clear();
		priority_queue<Node>q;
		long long res = 0;
		q.push({(n + 1) / 2,(m + 1) / 2,
				cal(make_pair((n + 1) / 2,(m + 1) / 2))});
		vis[make_pair((n + 1) / 2,(m + 1) / 2)] = true;
		int cnt = 0;
		while(!q.empty())
		{
			Node temp = q.top();
			q.pop();
			res += temp.val;
			cnt ++;
		//	cout << cnt << " " << temp.val << endl;
			if(cnt == k)
				break;
			for(int i = 0;i < 8;i++)
			{
				int tx = temp.x + xdir[i];
				int ty = temp.y + ydir[i];
				if(tx < 1 || tx > n || ty < 1 || ty > m)
					continue;
				if(vis[make_pair(tx,ty)] == true)
					continue;
				vis[make_pair(tx,ty)] = true;
				q.push({tx,ty,cal(make_pair(tx,ty))});
			}
		}
		//cout << res << endl;
		double ans = 1.0 * res / (1.0 * (1LL * (n - r + 1) * (m - r + 1)));
		printf("%.9lf\n",ans);
	}
}
