#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios :: sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        vector<int> v; 
        for(int i = 0;i < 5;i++)
        {
            int _;
            cin >> _;
            v.push_back(_);
            cout << _ << " ";
        }
        int flag = 1;
        for(decltype(v.size()) i = 0;i < v.size() - 2;i ++)
        {
            if(v[i] + v[i + 2] != 2 * v[i + 1])
                flag = 0;
        }
        if(!flag)
        {
            cout << *v.rbegin() * v[1] / v[0] << endl;
        }
        else
        {
            cout << *v.rbegin() + v[1] - v[0] << endl;
        }
    }
}