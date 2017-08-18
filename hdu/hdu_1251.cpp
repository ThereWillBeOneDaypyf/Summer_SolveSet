#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


struct Tire
{
	Tire *next[26];
	int val;
};

Tire *root;
void init_node(Tire *r)
{
	r -> val = 0;
	for (int i = 0; i < 26; i++)
		r -> next[i] = NULL;
}
void init_tree()
{
	root = new Tire;
	init_node(root);
}
void Insert(char s[])
{
	Tire *r;
	r = root;
	int l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		int id = s[i] - 'a';
		r -> val ++;
		if (r -> next[id] == NULL)
		{
			Tire *q;
			q = new Tire;
			init_node(q);
			r -> next[id] = q;
		}
		r = r -> next[id];
	}
	r -> val ++;
}
int find(char s[])
{
	Tire *r;
	r = root;
	int l = strlen(s);
	for (int i = 0; i < l; i++)
	{
		int id = s[i] - 'a';
		if (r -> next[id] == NULL)
			return 0;
		r = r -> next[id];
	}
	return r -> val;
}
void del_node(Tire *r)
{
	if (r == NULL)
		return;
	for (int i = 0; i < 26; i++)
	{
		if (r -> next[i] != NULL)
			del_node(r -> next[i]);
	}
	delete [] r;
}
int main()
{
	char s[20];
	init_tree();
	while (gets(s) && s[0] != '\0')
		Insert(s);
	while (gets(s))
		cout << find(s) << endl;
	del_node(root);
}