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
        string s;
        cin >> s;
        bool change_l = false, change_r = false;
        int l_l,l_r,r_l,r_r;
        for(int i = 4;i < n;i ++)
        {
            int Max = -1e9;
            int Min = 1e9;
            for(int j = i - 4;j <= i;j ++)
                Max = max(Max,v[j]), Min = min(Min, v[j]);
            int dif = s[i - 4] - '0';
            for(int j = i - 4;j < i;j ++)
                if(s[j] - '0' != dif)
                {
                    dif = -1;
                    break;
                }
            if(dif == -1)
                continue;
            else if(dif == 0)
            {
                if(s[i] == '0')
                {
                    if(!change_l)
                    {
                        change_l = true;
                        l_l = Min,l_r = Max;
                    }
                    else
                    {
                        l_l = max(Min,l_l);
                        l_r = min(Max,l_r);
                    }
                }
                else
                {
                    if(!change_l)
                    {
                        change_l = true;
                        l_l = l_r = Max + 1;
                    }
                    else
                        l_l = max(l_l, Max + 1),l_r = max(l_r,Max + 1);
                }
            }
            else if(dif == 1)
            {
                if(s[i] == '0')
                {
                    if(!change_r)
                    {
                        change_r = true;
                        r_l = r_r = Min - 1;
                    }
                    else r_l = min(r_l, Min - 1),r_r = min(r_r,Min - 1);
                }
                else
                {
                    if(!change_r)
                    {
                        change_r = true;
                        r_l = Min,r_r = Max;
                    }
                    else r_l = max(r_l, Min),r_r = min(r_r,Max);
                }
            }
        }
        if(!change_l && !change_r)
            cout << 0 << " " << 0 << endl;
        else if(!change_l)
            cout << r_l << " " << r_l << endl;
        else if(!change_r)
            cout << l_l << " " << l_l << endl;
        else
            cout << l_l << " " << r_r << endl;
    }
}