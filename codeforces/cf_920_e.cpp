#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 200005
#define Mod 10001
using namespace std;
int n, m, dis[MAXN];
set<int> all, mp[MAXN], tmp;
int vis[MAXN];
int main()
{
    int t;
    while(scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; ++i)
        {
            all.insert(i); //先把所有顶点加入
            mp[i].clear();
        }
        memset(dis, -1, sizeof(dis));
        int u, v, s;
        while (m--)
        {
            scanf("%d%d", &u, &v);
            mp[u].insert(v);
            mp[v].insert(u);
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                int cnt = 0;
                all.erase(i);
                queue<int>q;
                q.push(i);
                while (!q.empty())
                {
                    tmp.clear();
                    u = q.front();
                    q.pop();
                    vis[u] = 1;
                    cnt ++;
                    set<int>::iterator v = all.begin();
                    for (; v != all.end(); v++) //遍历所有顶点
                    {
                        if (mp[u].find(*v) == mp[u].end()) //不在原图中的边说明补图中可以到达
                        {
                            dis[*v] = dis[u] + 1;
                            tmp.insert(*v); //这些点下次就不用考虑
                            q.push(*v);     //以当前距离为起点（第一次距离为1），寻找距离+1的点
                        }
                    }
                    for (v = tmp.begin(); v != tmp.end(); v++) //在所有顶点中删除已经算过的点
                        all.erase(*v);
                }
                ans.push_back(cnt);
            }
        }
        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(int i = 0;i < ans.size();i++)
        {
            if(i)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}