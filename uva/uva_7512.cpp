#include<bits/stdc++.h>
using namespace std;

int MaxMap[1005][1005];
int MinMap[1005][1005];
int main()
{
	int T;
	cin >> T;
	int ka = 0;
	while(T--)
	{
		int r,c;
		cin >> r >> c;
		int n;
		cin >> n;
		memset(MaxMap,0,sizeof(MaxMap));
		memset(MinMap,0,sizeof(MinMap));
		for(int i = 0;i<n;i++)
		{
			int u,v;
			cin >> u >> v;
			MaxMap[u][v] = -1;
			MinMap[u][v] = -1;
		}
		int Max = 0;
		for(int i = 0;i<r;i++)
		{
			for(int j = 0;j<c;j+=2)
			{
				while(j < c && MaxMap[i][j] == -1)
					j++;
				if(j < c)
					Max ++;
			}
		}
		int Min = 0;
		for(int i = 0;i < r;i++)
		{
			for(int j = 0;j < c;j+=2)
			{
				while(j < c && MinMap[i][j] == -1)
					j ++;
				if(j < c)
				{
					if(j + 1 < c)
						if(MinMap[i][j + 1] != -1)
							j ++;
					Min ++;
				}
			}
		}
		cout << "Case #" << ++ ka << ": " << Max << " " << Min << endl;
	}
}
