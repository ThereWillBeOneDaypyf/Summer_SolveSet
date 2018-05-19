#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 8;

bool vis[N];

int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        memset(vis,0,sizeof(vis));
        int ans = 0;
        for(int i = 0;i < s1.size();i ++)
        {
            int Min = 100;
            int pos = -1;
            for(int j = 0;j < s2.size();j ++)
            {
                if(vis[j])
                    continue;
                int tar = (s2[j] - s1[i]);
                if(tar < 0)
                    tar += 26;
                if(pos == -1 || tar < Min)
                {
                    Min = tar;
                    pos = j;
                }
            } 
            ans += Min;
            vis[pos] = 1;
        }
        cout << ans << endl;
    }
}
