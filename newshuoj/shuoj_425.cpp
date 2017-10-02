#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Tire
{
	Tire *next[2];
	int val;
};
Tire *root;

void InitNode(Tire *r)
{
	r -> val = 0;
	for (int i = 0; i < 2; i++)
		r -> next[i] = NULL;
}
void InitTree()
{
	root = new Tire;
	InitNode(root);
}
void Insert(int x)
{
	Tire *r;
	r = root;
	for (int i = 20; i >= 0; i--)
	{
		int id = (x >> i) & 1;
		r -> val ++;
		if (r -> next[id] == NULL)
		{
			Tire *temp;
			temp = new Tire;
			InitNode(temp);
			r -> next[id] = temp;
		}
		r = r -> next[id];
	}
	r -> val ++;
}
long long query(int x, int y)
{
	Tire *r;
	r = root;
	long long ans = 0;
	for (int i = 20; i >= 0; i--)
	{
		if (r == NULL)
			return ans;
		int tar = (y >> i) & 1 ;
		int need = ((x >> i) & 1) ^ 1;
		if (!tar)
		{
			if (r -> next[need] != NULL)
				ans += 1LL * r -> next[need] -> val;
			r = r -> next[need ^ 1];
		}
		else
			r = r -> next[need];
	}
	return ans;
}
void DelTree(Tire *r)
{
	for (int i = 0; i < 2; i++)
		if (r -> next[i] != NULL)
			DelTree(r -> next[i]);
	delete r;
}
int main()
{
	ios :: sync_with_stdio(false);
	int n , m;
	while (cin >> n >> m)
	{
		InitTree();
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (i)
				ans += query(x, m);
			Insert(x);
		}
		DelTree(root);
		cout << ans << endl;
	}
}