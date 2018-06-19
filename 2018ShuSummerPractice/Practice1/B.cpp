#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        vector<int> v;
        int pos = -1;
        for(int i = 0;i < n;i ++)
        {
            int x;
            cin >> x;
            if(x != -1)
                pos = i; 
            v.push_back(x);
        }
        int cur = v[pos];
        for(int i = pos;i >= 0;i --)
        {
            if(v[i] == -1)
                v[i] = cur;
            cur --;
        }
        cur = v[pos];
        for(int i = pos;i < n;i ++)
        {
            if(v[i] == -1)
                v[i] = cur;
            cur ++;
        }
        for(auto ele : v)
        {
            ele %= m;
            ele += m;
            ele %= m;
            cout << ele << " ";
        }
        cout << endl;
    }
}