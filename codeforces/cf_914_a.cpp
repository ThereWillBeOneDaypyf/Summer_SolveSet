#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    int n;
    while(cin >> n)
    {
        vector<long long > v;
        for(int i = 0;i < n;i++)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(auto it = v.rbegin();it != v.rend();it ++)
        {
            int flag = 0;
            for(long long i = 0;;i++)
            {
                long long tar = i * i;
                if(tar > *it)
                    break;
                if(tar == *it)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                cout << *it << endl;
                break;
            }
        }
    }
}