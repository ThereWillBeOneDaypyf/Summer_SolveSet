#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

int ch[N][2], sz[N];
int fa[N];
int tot = 0;
int key[N];
int root;
void push_up(int r)
{
	sz[r] = sz[ch[r][0]] + sz[ch[r][1]];
}
void NewNode(int val, int Fa)
{
	if (tot == 0)
		root = 0;
	ch[tot][0] = ch[tot][1] = -1;
	key[tot] = val;
	fa[tot] = Fa;
	sz[tot++] = 1;
}
void insert(int r, int val, int Fa)
{
	if (tot == 0)
	{
		NewNode(val, Fa);
		return;
	}
	if (r == -1)
	{
		NewNode(val, Fa);
		return;
	}
	else insert(ch[r][key[r] > val], val, r);
	update(r);
}
void Rotate(int r, int kind) // left 0 right 1
{
	fa[ch[r][kind]] = fa[r];
	ch[fa[r]][!kind] = ch[r][kind];
	ch[r][kind] = fa[r];
	if (fa[fa[r]] != -1)
		ch[fa[fa[r]]][ch[fa[fa[r]]][1] == fa[r]] = r;
	fa[r] = fa[fa[r]];
	fa[ch[r][kind]] = r;
	push_up(r);
}
void splay(int r, int goal)
{
	while (fa[r] != goal)
	{
		if (fa[fa[r]] == goal)
			Rotate(r, !(ch[fa[r]][1] == r));
		else
		{
			int y =  fa[r];
			int x = fa[fa[r]];
			int kind_xy = ch[x][1] == x;
			int kind_yr = ch[y][1] == r;
			if (kind_xy == kind_yr)
			{
				Rotate(y, !kind_xy);
				Rotate(r, !kind_xy);
			}
			else
			{
				Rotate(r, !kind_yr);
				Rotate(r, !kind_xy);
			}
		}
	}
	if (goal == -1)
		root = r;
	push_up(r);
}
int main()
{

}