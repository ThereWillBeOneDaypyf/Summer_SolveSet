#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;

long long col_sum[N];
long long row_sum[N];
int a[N][N];

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, m;
        cin >> m >> n;
        for(int i = 1; i <= n; i ++) 
        {
            for(int j = 1; j <= m; j ++)
            {
                cin >> a[i][j];
            }
        }
        memset(col_sum, 0, sizeof(col_sum));
        memset(row_sum, 0, sizeof(row_sum));
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                row_sum[i] += a[i][j];
                col_sum[j] += a[i][j];
            }
        }
        long long Min = 1e18;
        for(int i = 1; i<= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                long long sum = 0;
                for(int k = 1; k <= n; k ++)    
                {
                    sum += 1LL * abs(i - k) * col_sum[k];
                }
                for(int k = 1; k <= m; k ++)
                {
                    sum += 1LL * abs(j - k) * row_sum[k];
                }
                Min = min(Min, sum);
            }
        }
        cout << Min << endl;
    }
}