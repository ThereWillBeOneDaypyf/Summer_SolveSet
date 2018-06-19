#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

struct Node
{
    int pos;
    int step;
};

int val[N];
int clst[N];
int last_clr[N];
int vis[N];

void debug(queue<Node> q)
{
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        cout <<temp.pos << " " <<temp.step << endl; 
    }
    cout << "*********" << endl;
}

int bfs(int n)
{
    queue<Node> q;
    memset(vis,0,sizeof(vis));
    q.push({n,0});
    int ans = 1e9 + 7;
    if(n == 1)
        return 0;
    while(!q.empty())
    {
        auto temp = q.front();
        q.pop();
        int nxt = temp.pos - 1;
        if(nxt == 1)
            return temp.step + 1;
        else
        {
            if(!vis[nxt])
            {
                vis[nxt] = 1;
                q.push({nxt,temp.step + 1});
            }
        }
        if(clst[temp.pos] != -1)
        {
            nxt = clst[temp.pos];
            if(nxt == 1)
            {
                return temp.step + 1;
            }
            if(!vis[nxt])
            {
                vis[nxt] = 1;
                q.push({nxt,temp.step + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        memset(last_clr,-1,sizeof(last_clr));
        scanf("%d",&n);
        for(int i = 1;i <= n;i ++)
        {
            scanf("%d",val + i);
            clst[i] = last_clr[val[i]];
            last_clr[val[i]] = i;
        }
        printf("%d\n",bfs(n));
    }
}
