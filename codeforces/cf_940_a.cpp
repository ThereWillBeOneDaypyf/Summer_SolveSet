#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int d;
    while(cin >> n >> d)  
    {
        vector<int> v;
        for(int i = 0;i < n;i ++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int ans = n;
        for(int i = 0;i < n;i ++)
        {
            for(int j = i;j < n;j ++)
            {
                if(v[j] - v[i] <= d)
                {
                    ans = min(ans, i + (n - j - 1));
                }
            }
        }
        cout << ans << endl;
    }
}