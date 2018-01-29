#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        vector<int> v(n + 1);
        for(int i = 1;i <= n; i++)
            cin >> v[i];
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i + 1;j <= n;j++)
            {
                int Min = i, Max = j;
                swap(v[i], v[j]);
                for(int k = 1;k <= n;k++)
                    if(v[k] == 1)
                        Min = k;
                    else if(v[k] == n)
                        Max = k;
                ans = max(ans,abs(Max - Min));
                swap(v[i], v[j]);
            }
        }
        cout << ans << endl;
    }
}