#include<bits/stdc++.h>
using namespace std;

int fa[30];

void init()
{
    for(int i = 0;i < 30; i++)
        fa[i] = i;
}

int find(int x)
{
    if(fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int a,int b)
{
    a = find(a), b = find(b);
    if(fa[a] != fa[b])
        fa[a] = fa[b];
}

int main()
{
    int n;
    string s1,s2;
    while(cin >> n >> s1 >> s2)
    {
        init();
        for(int i = 0;i < n;i ++)
            if(s1[i] != s2[i])
                merge(s1[i] - 'a', s2[i] - 'a');
        vector<pair<char,char> > v;
        for(int i = 0;i < 26;i ++)
            if(find(i) != i)
                v.push_back(make_pair('a' + find(i),'a' + i));
        cout << v.size() << endl;
        for(auto temp : v)
            cout << temp.first << " " << temp.second << endl;
    }
}