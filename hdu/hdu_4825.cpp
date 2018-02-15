#include<bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *next[2];
};

Trie *root;

void init(Trie *r)
{
    for(int i = 0;i < 2;i++)
        r -> next[i] = nullptr;
}
void init_tree()
{
    root = new Trie;
    init(root);
}

void insert(int tar)
{
    int a[32];
    memset(a,0,sizeof(a));
    for(int i = 0;i < 32;i ++)
        if(tar & (1 << i))
            a[i] = 1;
    Trie *r = root;
    for(int i = 31;i >= 0;i--)
    {
        int id = a[i];
        if(r -> next[id] == nullptr)
        {
            Trie *temp = new Trie;
            init(temp);
            r -> next[id] = temp;
        }
        r = r -> next[id];
    }
}
int query(int tar)
{
    int a[32];
    for(int i = 0;i < 32;i ++)
        a[i] = 1;
    for(int i = 0;i < 32;i ++)
        if(tar & (1 << i))
            a[i] = 0;
    int ans[32];
    Trie *r = root;
    for(int i = 31;i >= 0;i --)
    {
        int need = a[i];
        if(r -> next[need])
        {
            ans[i] = need;
            r = r -> next[need];
        }
        else
        {
            ans[i] = need ^ 1;
            r = r -> next[need ^ 1];
        }
    }
    int res = 0;
    for(int i = 0;i < 32;i++)
        res += ans[i] * (1 << i);
    return res;
}
void del(Trie *r)
{
    if(r == nullptr)
        return;
    for(int i = 0;i < 2;i ++)
        del(r -> next[i]);
    delete(r);
}

int main()
{
    ios :: sync_with_stdio(false);
    int T;
    cin >> T;
    int ka = 0;
    while(T--)
    {
        int n,m;
        cin >> n >> m;
        init_tree();
        for(int i = 0;i < n;i ++)
        {
            int x;
            cin >> x;
            insert(x);
        }
        cout << "Case #" << ++ ka << ":" << endl;
        for(int i = 0;i < m;i ++)
        {
            int x;
            cin >> x;
            cout << query(x) << endl;
        }
    }
}