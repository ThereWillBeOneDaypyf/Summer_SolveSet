#include <bits/stdc++.h>
using namespace std;
int xdir[4] = {1, 0, -1, 0};
int ydir[4] = {0, 1, 0, -1};
char d[4] = {'D', 'R', 'U', 'L'};
int vis[12][12];
int m[12][12];

void init()
{
    memset(vis, 0, sizeof(vis));
    memset(m, -1, sizeof(m));
    vis[2][2] = 1;
    vis[2][9] = 1;
    vis[9][2] = 1;
    vis[9][2] = 1;
    vis[5][5] = 2;
    vis[5][6] = 2;
    vis[6][5] = 2;
    vis[6][6] = 2;
    vis[8][1] = 2;
    vis[8][2] = 2;
    vis[9][1] = 2;
    vis[9][10] = 2;
    vis[8][9] = 2;
    vis[8][10] = 2;
}

struct Node
{
    int x, y, step;
};

pair<int, pair<int, int> >bfs(int x, int y)
{
    if(vis[x][y] == 1)
        return make_pair(0, make_pair(x, y));
    memset(m, -1, sizeof(m));
    queue<Node> q;
    q.push({x, y, 0});
    while(!q.empty())
    {
        auto n = q.front();
        q.pop();
        int x = n.x;
        int y = n.y;
        int step = n.step;
        for(int i = 0; i < 4; i ++)
        {
            int tx = x + xdir[i];
            int ty = y + ydir[i];
            if(tx < 0 || tx >= 12 || ty < 0 || ty >= 12)
                continue;
            if(vis[tx][ty] == 2 || m[tx][ty] != -1)
                continue;
            m[tx][ty] = i;
            if(vis[tx][ty] == 1)
            {
                return make_pair(step + 1, make_pair(tx, ty));
            }
            q.push({tx, ty, step + 1});
        }
    }
    return make_pair(0, make_pair(0, 0));
}

void outpath(int x, int y, int tx, int ty) 
{
    if(x == tx && y == ty)
        return;
    int dir = m[x][y];
    int rev_dir = (dir + 2) % 4;
    outpath(x + xdir[rev_dir], y + ydir[rev_dir], tx, ty);
    cout << d[dir];
}

void debug()
{
    for(int i = 0; i < 12; i ++)
    {
        for(int j = 0; j < 12; j ++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    init();
    while(cin >> n)
    {
        for(int i = 0; i < n; i ++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            auto res = bfs(x, y);
            cout << res.first << endl;
            // debug();
            outpath(res.second.first, res.second.second, x, y);
            cout << endl;
        }
    }
}