#include<bits/stdc++.h>
using namespace std;
bool judge(int a,set<int>s)
{
    vector<int> v;
    while(a)
    {
        v.push_back(a % 10);
        a /= 10;
    }
    for(auto tar : v)
    {
        for(auto temp : s)
            if(tar == temp)
                return false;
    }
    return true;
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a,b;
        cin >> a >> b;
        int ans = 0;
        int tempa = a,tempb = b;
        set<int> s;
        while(tempa)
        {
            s.insert(tempa % 10);
            tempa /= 10;
        }
        while(tempb)
        {
            s.insert(tempb % 10);
            tempb /= 10;
        }
        for(int i = 0;i <= 1000;i++)
        {
            if(i % a == 0 || i % b == 0 || !judge(i,s))
                continue;
            ans ++;
        }
        cout << ans << endl;
    }
}