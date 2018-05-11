#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        vector<pair<int,string> > v;
        int n;
        cin >> n;
        for(int i = 0;i < n;i ++)
        {
            string s;
            int cnt;
            cin >> s >> cnt;
            v.push_back(make_pair(cnt,s));
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        for(int i = 0;i < v.size(); i++)
        {
            if(i)
                cout << " ";
            cout << v[i].second;
        }
        cout << endl;
    }   
}
