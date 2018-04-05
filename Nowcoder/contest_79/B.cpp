#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    vector<long long>va,vb;
    int n,m;
    while(cin >> n >> m)
    {
        va.clear(),vb.clear();
        long long ans = 0;
        for(int i = 0;i < n;i ++)
        {
            long long x;
            cin >> x;
            va.push_back(x);
        }
        for(int i = 0;i < n;i ++)
        {
            long long x;
            cin >> x;
            vb.push_back(x);
        }
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end(),[](const long long a,const long long b) { return a > b;});
        int i = 0;
        int cnt = 0;
        while(i < n && va[i] <= vb[i])
        {
            ans += (vb[i] - va[i]);
            cnt ++;
            if(cnt % 3 == 0)
                ans += m;
            i ++;
        }
        long long cost = 0;
        long long get_v = 0;
        for(int j = i;j < n;j ++)
        {
            cost += va[j];
            get_v += vb[j];
            cnt ++;
            if(cnt % 3 == 0)
            {
                if(get_v + m - cost > 0)
                {
                    ans += get_v + m - cost;
                    cost = 0;
                    get_v = 0;
                }
                else break;
            }
        }
        cout << ans << endl;
    } 
}