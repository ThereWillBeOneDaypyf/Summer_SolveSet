#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<char> >& v)
{
    int n = v[0].size(),m = v.size();
    vector<vector<char> > temp_v;
    for(int i = 0;i < n;i ++)
    {
        temp_v.push_back({});
        for(int j = 0;j < m;j ++)
           temp_v[i].push_back('1');
    }
    for(int i = 0;i < v[0].size();i ++)
    {
        for(int j = 0;j < v.size(); j++)
        {
            temp_v[i][j] = v[v.size() - j - 1][i];
        }
    }
    v = temp_v;
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<char> > v;
        for(int i = 0;i < n;i ++)
        {
            vector<char>temp;
            for(int j = 0;j < m;j ++)
            {
                char x;
                cin >> x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        string s;
        cin >> s;
        int ro = 0;
        for(auto x : s)
        {
            if(x == 'L')
                ro --;
            else ro ++;
            if(ro < 0)
                ro += 4;
            ro %= 4;
        }
        if(ro == 1)
        {
            rotate(v);
            for(auto& temp_v : v)
            {
                for(auto& temp : temp_v)
                {
                    if(temp == '-')
                        temp = '|';
                    else if(temp == '|')
                        temp = '-';
                }
            }
        }
        else if(ro == 2)
        {
            rotate(v), rotate(v);
        }
        else if(ro == 3)
        {
            rotate(v);
            rotate(v);
            rotate(v);
            for(auto& temp_v : v)
            {
                for(auto& temp : temp_v)
                {
                    if(temp == '-')
                        temp = '|';
                    else if(temp == '|')
                        temp = '-';
                }
            }
        }
        cout << v.size() << " " << v[0].size() << endl;
        for(auto temp_v : v)
        {
            for(auto temp : temp_v)
                cout << temp;
            cout << endl;
        }
        cout << endl;
    }
}