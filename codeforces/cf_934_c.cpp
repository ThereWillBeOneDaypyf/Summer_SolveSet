#include<bits/stdc++.h>
using namespace std;

const int N = 3e3;

int pre_sum_one[N];
int pre_sum_two[N];
int dp[N][N];
int a[N];
int main()
{
    int n;
    while(cin >> n)
    {
        memset(pre_sum_two,0,sizeof(pre_sum_two));
        memset(pre_sum_one,0,sizeof(pre_sum_one));
        for(int i = 1;i <= n;i ++)
        {
            cin >> a[i];
            if(a[i] == 1)
                pre_sum_one[i] = 1;
            else
                pre_sum_two[i] = 1;
        }
        for(int i = 1;i <= n;i ++)
            pre_sum_one[i] += pre_sum_one[i - 1], pre_sum_two[i] += pre_sum_two[i - 1];
        vector<int> len;
        len.push_back(a[1]);
        for(int i = 2;i <= n;i ++)
        {
            if(a[i] >= *len.rbegin())
                len.push_back(a[i]);
            else
            {
                auto pos = upper_bound(len.begin(),len.end(),a[i]) - len.begin();
                len[pos] = a[i];
            }
        }
        int ans = len.size();
        for(int i = n;i >= 1;i --)
        {
            len.clear();
            len.push_back(a[i]);
            for(int j = i - 1;j >= 1;j --)
            {
                if(a[j] >= *len.rbegin())    
                    len.push_back(a[j]);
                else
                {
                    auto pos = upper_bound(len.begin(),len.end(),a[j]) - len.begin();
                    len[pos] = a[j];
                }
                dp[j][i] = len.size(); 
            }
        }
        for(int i = 1;i <= n;i ++)
        {
            for(int j = i + 1;j <= n;j ++)
            {
                int res = pre_sum_one[i - 1] + pre_sum_two[n] - pre_sum_two[j] + dp[i][j];
                ans = max(res,ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}