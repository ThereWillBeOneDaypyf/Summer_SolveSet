#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0;i < n;i++)
        {
            int x,y;
            cin >> x >> y;
            v.push_back(y);
        }
        long long ans = 1e18 + 8;
        for(int i = 0;i <= 100;i++)
        {
            long long res = 0;
            for(auto temp : v)
                res += abs(i - temp);
            ans = min(ans,res);
        }
        cout << ans << endl;
    }
}