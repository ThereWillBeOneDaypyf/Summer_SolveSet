#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> value_map;
    set<int> not_zero_index_set;
    int n;
    while(cin >> n)
    {
        getchar();
        for(int i = 0; i < n; i ++)
        {
            string s;
            getline(cin, s);
            int blank_ind = s.find(' ');
            if(blank_ind == -1)
            {
                int val = atoi(s.c_str());
                if(val == -1)
                {
                    if(not_zero_index_set.empty())
                    {
                        cout << "skipped" << endl;
                    }
                    else 
                    {
                        cout  << value_map[*not_zero_index_set.begin()] << endl;
                        value_map[*not_zero_index_set.begin()] = 0;
                        not_zero_index_set.erase(not_zero_index_set.begin());
                    }
                }
                else 
                {
                    cout << value_map[val] << endl;
                }
            }
            else 
            {
                string t_str = string(s, 0, blank_ind),c_str =string(s, blank_ind, s.length());
                int t = atoi(t_str.c_str()), c = atoi(c_str.c_str());
                int low_limit = t - 30;
                auto limit_pos = not_zero_index_set.lower_bound(low_limit);
                if(limit_pos == not_zero_index_set.end() || *limit_pos > t + 30)
                {
                    value_map[t] += c;
                    not_zero_index_set.insert(t);
                }
            }
        }
    }
}