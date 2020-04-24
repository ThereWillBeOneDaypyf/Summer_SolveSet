#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        for(int i = 0; i < n; i ++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int l = 0;
        int Max = 0;
        int cur = 0;
        for(int i = 1; i < k - 1; i ++)
        {
            // cout << i << endl;
            // cout << v[i - 1] << " " << v[i] << " " << v[i + 1] << endl;
            if(v[i - 1] < v[i] && v[i] > v[i + 1])
                Max ++;
        }
        cur = Max;
        for(int i = 1; i < n - k + 1; i ++)
        {
            // cout << " ===== > l , m, r" << endl;
            // cout << i - 1 <<  " " << i << " " << i + 1 << endl;
            // cout << i + k - 2 << " " << i + k - 1 << " " << i + k << endl;
            if(v[i - 1] < v[i] && v[i] > v[i + 1])
                cur --;
            if(v[i + k - 3] < v[i + k - 2] && v[i + k - 2] > v[i + k - 1])
                cur ++;
            if(cur > Max)
            {
                Max = cur;
                l = i;
            }
        }
        cout << Max + 1 << " " << l + 1 << endl;
    }
}