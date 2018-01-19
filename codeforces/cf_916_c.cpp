#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;

int vis[N];
int prime[N];
int cnt = 0;
void init()
{
    cnt = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 2;i < N;i++)
    {
        if(vis[i])
            continue;
        prime[cnt ++] = i;
        for(int j = 2;i * j < N;j++)
            vis[i * j] = 1;
    }
}

int main()
{
    int n,m;
    init();
    while(cin >> n >> m)
    {
        int tar;
        for(int i = 0;i < cnt;i++)
            if(prime[i] >= n - 1)
            {
                tar = prime[i];
                break;
            }
        cout << tar << " " << tar << endl;
        for(int i = 2;i < n;i ++)
        {
            cout << i - 1 << " " << i << " " << 1 << endl;
        }
        cout << n - 1 << " " << n <<  " " << tar - (n - 2) << endl;
        if(m > (n - 1))
        {
            int need = m - (n - 1);
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 2;j <= n;j++)
                {
                    cout << i << " " << j << " " << 1000000000 << endl;
                    need -- ;
                    if(!need)
                        break;
                }
                if(!need)
                    break;
            }
        }
    }
}