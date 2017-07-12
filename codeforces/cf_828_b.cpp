#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f

char Map[1005][1005];
int n,m;
int main()
{
	while(cin >> n >> m)
	{
		int minx = INF,miny = INF,maxx = -1,maxy = -1;
		int cnt = 0;
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				cin >> Map[i][j];
				if(Map[i][j] == 'B')
				{
					minx = min(minx,i),miny = min(miny,j);
					maxx = max(maxx,i),maxy = max(maxy,j);
					cnt ++ ;
				}
			}
		}
		if(!cnt)
			cout << 1 << endl;
		else
		{
			if(maxx - minx >= maxy - miny)
			{
				int Max = maxx - minx + 1;
				if(Max > m)
					cout << -1 << endl;
				else
					cout << Max * Max - cnt << endl;
			}
			else 
			{
				int Max = maxy - miny + 1;
				if(Max > n)
					cout << -1 << endl;
				else
					cout << Max * Max - cnt << endl;
			}
		}
	}
}
