#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<char> G[N];

void init()
{
    for(int i = 0;i < N;i ++)
        G[i].clear();
}

int main()
{
    string s;
    int T;
    cin >> T;
    int n;
    while(T--)
    {
        cin >> n >> s;
        init();
        if(n == 1)
        {
            cout << s << endl;
            continue;
        }
        for(int i = 0;i < s.length();i++)
        {
            int id = i % (2 * n - 2);
            if(id > n - 1)
                id = (2 * n - 2 - id);
            G[id].push_back(s[i]);
        }
        for(int i = 0;i < n;i ++)
            for(auto temp : G[i])
                cout << temp;
        cout << endl;
    }
}