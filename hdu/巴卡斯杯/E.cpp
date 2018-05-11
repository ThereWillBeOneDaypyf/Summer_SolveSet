#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

int n,m;

int xdir[4] = {0,1,0,-1};
int ydir[4] = {1,0,-1,0};

char Map[N][N];

int girl = 0,cat = 0;

void init()
{
    girl = 0;
    cat = 0;
}

void dfs(int x,int y,int pos,const string& tar)
{
    if(pos == tar.size() - 1)
    {
        if(tar == "girl")
            girl ++;
        else
        {
            cat ++;
        }
        return;
    }
    for(int i = 0;i < 4;i ++)
    {
        int tx = x + xdir[i];
        int ty = y + ydir[i];
        if(tx < 0 || ty < 0 || tx >= n || ty >= m)
            continue;
        if(Map[tx][ty] != tar[pos + 1])
            continue;
        dfs(tx,ty,pos + 1,tar);
    }
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        init();
        cin >> n >> m;
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                cin >> Map[i][j];
            }
        }
        string g = "girl";
        string c = "cat";
        for(int i = 0;i < n;i ++)
        {
            for(int j = 0;j < m;j ++)
            {
                if(Map[i][j] == 'g')
                    dfs(i,j,0,g);
                else if(Map[i][j] == 'c')
                {
                    dfs(i,j,0,c);
                }
            }
        }
        cout << girl << " " << cat << endl;
    }
}
