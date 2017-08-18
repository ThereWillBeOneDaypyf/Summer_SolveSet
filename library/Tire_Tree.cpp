#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Tire
{
	Tire *next[10];
	int val;
};

Tire *root;
void init_node(Tire *r)
{
	r -> val = 0;
	for (int i = 0; i < 10; i++)
		r -> next[i] = NULL;
}
void init_tree()
{
	root = new Tire;
	init_node(root);
}
void insert(string s)
{
	Tire *r;
	r = root;
	for (int i = 0; i < s.length(); i++)
	{
		int id = s[i] - '0';
		r -> val ++;
		if (r -> next[id] == NULL)
		{
			Tire *temp;
			temp = new Tire;
			init_node(temp);
			r -> next[id] = temp;
		}
		r = r-> next[id];
	}
	r -> val ++;
}
int find(string s)
{
	Tire *r;
	r = root;
	for (int i = 0; i < s.length(); i++)
	{
		int id = s[i] - '0';
		if (r -> next[id] == NULL)
			return 0;
		else
			r = r -> next[id];
	}
	return r -> val;
}
void del_node(Tire *r)
{
	for (int i = 0; i < 10; i++)
	{
		if (r -> next[i] != NULL)
			del_node(r -> next[i]);
	}
	delete r;
}
vector<string> tar;
bool judge()
{
	for (int i = 0; i < tar.size(); i++)
		if (find(tar[i]) != 1)
			return false;
	return true;
}
int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		init_tree();
		tar.clear();
		for (int i = 0 ; i < n; i++)
		{
			string s;
			cin >> s;
			tar.push_back(s);
			insert(s);
		}
		if (judge())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		del_node(root);
	}
}