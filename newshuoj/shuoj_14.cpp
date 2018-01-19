#include<bits/stdc++.h>
using namespace std;

const int N = 1e3;

int Map[N][N];
int vis[N];
int flag = 0;
void dfs(int pos,int col)
{
    if(vis[Map[pos][col]])
        return ;
    if(pos >= 9)
    {
        flag = 1;
        return;
    }
    vis[Map[pos][col]] = 1;
    dfs(pos + 1,col);
    dfs(pos + 1,col + 1);
    vis[Map[pos][col]] = 0;
}
int main()
{
    int T;
    cin >> T;
    int ka = 0;
    while(T--)
    {
        memset(Map,0,sizeof(Map));
        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j <= i;j++)
            {
                cin >> Map[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        flag = 0;
        dfs(0,0);
        cout << "Case " << ++ ka << ":" << endl;
        if(flag)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
}