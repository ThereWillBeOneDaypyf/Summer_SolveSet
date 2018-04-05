#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<int>v;
        for(int i = 0;i < n;i ++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        int cnt = 0;
        for(int i = 1;i < v.size();i++)
            cnt += v[i] - v[0];
        cout << cnt << " " << v[0] + cnt << endl;
    }
}