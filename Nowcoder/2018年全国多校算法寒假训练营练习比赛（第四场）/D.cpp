#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

int in[N],out[N];
char Map[1005][1005];
int vis[1005][1005];
int xdir[] = {0,1};
int ydir[] = {1,0};
int n,m;
void dfs(int x,int y)
{
    if(vis[x][y])
        return;
    vis[x][y] = 1;
    for(int i = 0;i < 2;i ++)
    {
        int tx = x + xdir[i];
        int ty = y + ydir[i];
        if(tx < 0 || tx >= n || ty < 0 || ty >= m || Map[tx][ty] == '#')
            continue;
        dfs(tx,ty);
        break;
    }
}
bool judge()
{
    int cnt = 0;
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < m;j ++)
        {
            if(!vis[i][j] && Map[i][j] != '#')
            {
                dfs(i,j);
                cnt ++;
            }
        }
    }
    return cnt < 2;
}
int main()
{
    while(cin >> n >> m)
    {
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                cin >> Map[i][j];
            }
        }
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i = 0;i < n ;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                if(Map[i][j] == '.')
                {
                    for(int k = 0;k < 2;k ++)
                    {
                        int tx = i + xdir[k];
                        int ty = j + ydir[k];
                        if(tx < 0 || tx >= n || ty < 0 || ty >= m || Map[tx][ty] == '#')
                            continue;
                        in[tx * m + ty] ++;
                        out[i * m + j] ++;
                    }
                }
            }
        }
        int cnt_in = 0, cnt_out = 0;
        for(int i = 0;i < n * m;i ++)
        {
            int x = i / m;
            int y = i % m;
            if(Map[x][y] == '#')
                continue;
            if(!in[i])
                cnt_in ++;
            if(!out[i])
                cnt_out ++;
        }
        if(judge())
            cout << 0 << endl;
        else
            cout << max(cnt_in,cnt_out) << endl;
    }
}