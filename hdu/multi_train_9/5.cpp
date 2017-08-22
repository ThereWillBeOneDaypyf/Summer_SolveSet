#include <iostream>  
#include <stdio.h>  
#include <algorithm>  
#include <string.h>  
#include <stdlib.h>  
#include <cmath>  
#include <iomanip>  
#include <vector>  
#include <set>  
#include <map>  
#include <stack>  
#include <queue>  
#include <cctype>  
#define rd(x) scanf("%d",&x)  
#define rd2(x,y)  scanf("%d%d",&x,&y)  
#define rd3(x,y,z) scanf("%d%d%d",&x,&y,&z)  
using namespace std;  
const int maxn=2010;  
vector<int>g[maxn];  
bool has[maxn][maxn];  
bool vis[maxn];  
int n,m;  
bool ok;  

void bfs(int s)  
{  
	memset(vis,0,sizeof(vis));  
	vis[s]=1;  
	queue<int>q;  
	q.push(s);  
	while(!q.empty())  
	{  
		int first=q.front();  
		// cout<<"fist"<<first<<endl;  
		q.pop();  
		int len=g[first].size();  
		for(int i=0;i<len;i++)  
		{  
			int v=g[first][i];  
			if(vis[v])  
				continue;  
			has[s][v]=1;  
			q.push(v);  
			vis[v]=1;  
		}  
	}  
}  


int main()  
{  
	int t,c=1;  
	rd(t);  
	while(t--)  
	{  
		ok=1;  
		rd2(n,m);  
		memset(has,0,sizeof(has));  
		for(int i=0;i<maxn;i++)  
			g[i].clear();  
		int u,v;  
		while(m--)  
		{  
			rd2(u,v);  
			g[u].push_back(v);  
		}  
		for(int i=1;i<=n;i++)  
		{  
			bfs(i);  
		}/* 
			for(int i=1;i<=n;i++) 
			{ 
			for(int j=1;j<=n;j++) 
			cout<<has[i][j]<<" "; 
			cout<<endl; 
			}*/  
		for(int i=1;i<=n;i++)  
		{  
			for(int j=i+1;j<=n;j++)  
			{  
				if(!has[i][j]&&!has[j][i])  
				{  
					ok=0;  
					break;  
				}  
			}  
			if(ok==0)  
				break;  
		}  
		if(ok)  
			printf("I love you my love and our love save us!\n",c++);  
		else  
			printf("Light my fire!\n",c++);  
	}  
	return 0;  
}  
