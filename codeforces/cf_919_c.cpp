#include<bits/stdc++.h>
using namespace std;

constexpr int N = 2e3 + 8;

char Map[N][N];

int main()
{
    int n,m,k;
    while(cin >> n >> m >> k)
    {
        for(int i = 0;i < n;i ++)
            for(int j = 0 ;j < m;j ++)
                cin >> Map[i][j];
        long long ans = 0;
        for(int i = 0;i < n;i ++)
        {
            int continue_cnt = 0;
            for(int j = 0;j < m;j ++)
            {
                if(Map[i][j] == '*')
                    continue_cnt = 0;
                else if(Map[i][j] == '.')
                {
                    continue_cnt ++;
                    if(continue_cnt >= k)
                        ans ++;
                }
            }
        }
        if(k == 1)
        {
            cout << ans << endl;
            continue;
        }
        for(int j = 0;j < m; j++)
        {
            int continue_cnt = 0;
            for(int i = 0;i < n;i ++)
            {
                if(Map[i][j] == '*')
                    continue_cnt = 0;
                else if(Map[i][j] == '.')
                {
                    continue_cnt ++;
                    if(continue_cnt >= k)
                        ans ++;
                }
            }
        }
        cout << ans << endl;
    }
}