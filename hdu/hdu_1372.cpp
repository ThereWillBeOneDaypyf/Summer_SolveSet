#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...
int xdir[8] = {-2,-2,2,2,-1,-1,1,1};
int ydir[8] = {1,-1,-1,1,2,-2,-2,2}; 
int vis[100][100];
struct Node
{
	int x,y,step;
	Node(int _x,int _y,int _step) : x(_x),y(_y),step(_step){}
};
int bfs(int sx,int sy,int ex,int ey)
{
	queue<Node>q;
	q.push(Node(sx,sy,0));
	memset(vis,0,sizeof(vis));
	vis[sx][sy] = 1;
	while(!q.empty())
	{
		Node temp = q.front();
		q.pop();
		if(temp.x == ex && temp.y == ey)
			return temp.step;
		for(int i = 0;i<8;i++)
		{
			int tx = temp.x + xdir[i];
			int ty = temp.y + ydir[i];
			if(tx <0 || tx >= 8 || ty < 0 || ty >= 8 || vis[tx][ty])
				continue;
			q.push(Node(tx,ty,temp.step+1));
			vis[tx][ty] = 1;
		}
	}
}
int main()
{
	string s1,s2;
	while(cin >> s1 >> s2)
	{
		int sx = s1[0] - 'a';
		int sy = s1[1] - '1';
		int ex = s2[0] - 'a';
		int ey = s2[1] - '1';
		cout << "To get from " << s1 << " to " << s2 << " takes ";
		cout << bfs(sx,sy,ex,ey) ;
		cout << " knight moves." << endl;
	}
}
