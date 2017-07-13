#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

random_device rd;

struct TreapNode
{
	int key,prio;
	int sz;
	int cnt;
	TreapNode *ch[2];
	TreapNode(int val = 0)
	{
		key = val;
		ch[0] = ch[1] = NULL;
		sz = 1;
		cnt = 1;
		prio = rd();
	}
	void push_up()
	{
		sz = cnt;
		if(ch[0] != NULL)
			sz += ch[0]->sz;
		if(ch[1] != NULL)
			sz += ch[1]->sz;
	}
};

struct Treap
{
	TreapNode *root;
	void Rotate(TreapNode *&r,int k)
	{
		TreapNode *child = r->ch[k];
		r->ch[k] = child->ch[!k];
		child->ch[!k] = r;
		r->push_up();
		r = child;
	}
	void insert(TreapNode *&r,int val)
	{
		if(r == NULL)
		{
			r = new TreapNode(val);
		}
		else if(val == r-> key)
			r->cnt ++;
		else
		{
			int kind = val > r->key;
			insert(r->ch[kind],val);
			if(r->ch[kind]->prio > r->prio)
				Rotate(r,kind);
		}
		r->push_up();
	}
	void del(TreapNode *&r,int key)
	{
		if(r->key == key)
		{
			if(r->ch[0] != NULL && r->ch[1] != NULL)
			{
				int k = r->ch[0]->prio > r->ch[1]->prio;
				Rotate(r,k);
				del(r->ch[!k],key);
			}
			else
			{
				TreapNode *temp = NULL;
				if(r->ch[0] != NULL)
					temp = r->ch[0];
				else if( r->ch[1] != NULL)
					temp = r->ch[1];
				delete r;
				r = temp;
			}
		}
		else
		{
			int k = r->key < key;
			del(r->ch[k] , key);
		}
		r->push_up();
	}
	int get_k(TreapNode *r,int k)
	{
		int tz = r->cnt;
		if(r->ch[0])
			tz += r->ch[0]->sz;
		if(tz == k)
			return r->key;
		if(tz < k)
			return get_k(r->ch[0],k);
		else 
			return get_k(r->ch[1],k - tz);
	}
	int get_Min(TreapNode *r) // wrong
	{
		if(r->ch[0] == NULL)
			return r->key;
		return get_Min( r->ch[0]);
	}
	int get_Max(TreapNode *r) // wrong
	{
		if(r->ch[1] == NULL)
			return r->key;
		return get_Max(r->ch[1]);
	}
	TreapNode *Find_key(TreapNode *r,int key)
	{
		if(r == NULL || r->key == key)
			return r;
		return Find_key(r->ch[key > r->key],key);
	}
	int get_pre(int key) // wrong
	{
		TreapNode *temp = Find_key(root,key);
		return get_Max(temp->ch[0]);
	}
	int get_nxt(int key) // wrong
	{
		TreapNode *temp = Find_key(root,key);
		return get_Min(temp->ch[1]);
	}
	int get_lessK(TreapNode *r,int key)
	{
		int sum = 0;
		if(r == NULL)
			return 0;
		if( key < r->key)
			return get_lessK(r->ch[0],key);
		else if(key >= r->key)
		{
			sum += r->cnt;
			if(r->ch[0] != NULL)
				sum += r->ch[0]->sz;
			if(r->ch[1] != NULL)
				sum += get_lessK(r->ch[1],key);
		}
		return sum;
	}
};

int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		Treap *t;
		t->root = NULL;
		for(int i = 0;i<n;i++)
		{
			int op;
			scanf("%d",&op);
			int x;
			if(op == 1)
			{
				scanf("%d",&x);
				t->insert(t->root,x);
			}
			else if(op == 2)
			{
				scanf("%d",&x);
				t->del(t->root,x);
			}
			else if(op == 3)
			{
				scanf("%d",&x);
				printf("%d\n",t->get_lessK(t->root,x));
			}
			else if(op == 4)
			{
				scanf("%d",&x);
				printf("%d\n",t->get_k(t->root,x));
			}
			else if(op == 5)
			{
				scanf("%d",&x);
				printf("%d\n",t->get_pre(x));
			}
			else 
			{
				scanf("%d",&x);
				printf("%d\n",t->get_nxt(x));
			}
		}
	}
}


