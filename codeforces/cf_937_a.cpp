#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v;
        for(int i = 0;i < n;i ++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        auto none_zero_pos = find_if(v.begin(),v.end(),[](int x){return x > 0;});
        cout << v.size() - (none_zero_pos - v.begin()) << endl;
    }
}