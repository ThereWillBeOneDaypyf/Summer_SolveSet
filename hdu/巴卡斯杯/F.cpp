#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 7;

bool dp[N][N];
char a[N],b[N],c[N];

int main()
{
    while(scanf("%s%s%s",a + 1,b + 1,c + 1) == 3)
    {
        int len_a = strlen(a + 1);
        int len_b = strlen(b + 1);
        int len_c = strlen(c + 1);
        if(len_a + len_b != len_c)
        {
            cout << "No" << endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0;i <= len_a;i ++)
        {
            for(int j = 0;j <= len_b;j ++)
            {
                if(i == 0 && j == 0)
                    continue;
                if(c[i + j] == a[i])
                    dp[i][j] |= dp[i - 1][j];
                if(c[i + j] == b[j])
                    dp[i][j] |= dp[i][j - 1];
            }
        }
        if(dp[len_a][len_b])
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
