#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int ca = 0;
    while(T--)
    {
        int n;
        cin >> n;
        vector<vector<int> > v;
        long long sum = 0;
        int rep_r = 0;
        for(int i = 0; i < n; i ++)
        {
            vector<int> tmp;
            set<int> s;
            for(int j = 0; j < n; j ++)
            {
                int x;
                cin >> x;
                if(i == j)
                    sum += x;
                tmp.push_back(x);
                s.insert(x);
            }
            if(s.size() != n)
                rep_r ++;
            v.push_back(tmp);
        }
        int rep_c = 0;
        for(int j = 0; j < n; j ++)
        {
            set<int> s;
            for(int i = 0; i < n; i ++)
            {
                s.insert(v[i][j]);
            }
            if(s.size() != n)
                rep_c ++;
        }
        cout << "Case #" << ++ca << ": " << sum << " " << rep_r << " " << rep_c << endl;
    }
}