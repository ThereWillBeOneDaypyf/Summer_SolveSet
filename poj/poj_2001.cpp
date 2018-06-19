//#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 1e5 + 7;

struct Trie
{
    int val;
    int next[26];
}t[N];

int tot = 0;

void init()
{
    tot = 0;
    for(int i = 0;i < 26;i++)
        t[tot].next[i] = -1;
    t[tot].val = 0;
}

int new_node()
{
    tot ++;
    for(int i = 0;i < 26;i ++)
        t[tot].next[i] = -1;
    t[tot].val = 0;
    return tot;
}

void insert(const string &s)
{
    int cur = 0; 
    for(int i = 0;i < s.size();i ++)
    {
        int id = s[i] - 'a';
        t[cur].val ++;
        if(t[cur].next[id] == -1)
            t[cur].next[id] = new_node();
        cur = t[cur].next[id];
    } 
    t[cur].val++;
}

string query(const string &s)
{
    int cur = 0;
    int pos = s.size();
    for(int i = 0;i < s.size();i ++)
    {
        int id = s[i] - 'a';
        if(t[cur].val == 1)
        {
            pos = i;
            break;
        }
        cur = t[cur].next[id];
    }
    return string(s.begin(),s.begin() + pos);
}




int main()
{
    //freopen("poj_2001_1.in","r",stdin);
    string s;
    init();
    vector<string> v;
    while(cin >> s)
    {
        v.push_back(s);
        insert(s);
    }
    for(int i = 0;i < v.size();i ++)
        cout << v[i] << " " << query(v[i]) << endl;
}
