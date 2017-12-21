#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

const int N = 1e5 + 7;

int fa[N];
int val[N];
int sz[N];
void init()
{
	for(int i = 0; i < N;i ++)
		sz[i] = 1,fa[i] = i, val[i] = 0;
}

int find(int x)
{
	if(fa[x] == x)
		return fa[x];
	int temp = fa[x];
	fa[x] = find(fa[x]);
	val[x] += val[temp];
	return fa[x];
}

int main()
{
	ios :: sync_with_stdio(false);
	int n;
	while(cin >> n)
	{
		init();
		string s;
		for(int i = 0;i < n; i ++)
		{
			cin >> s;
			if(s == "M")
			{
				int x,y;
				cin >> x >> y;
				int xr = find(x), yr = find(y);
				if(xr != yr)
				{
					val[xr] = sz[yr];
					sz[yr] += sz[xr];
					fa[xr] = yr;
				}			
			}
			else
			{
				int x;
				cin >> x;
				find(x);
				cout << val[x] << endl;
			}
		}

	}	
}

