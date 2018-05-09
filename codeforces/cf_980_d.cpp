#include<bits/stdc++.h>
using namespace std;

const int N = 5e3;

vector<long long> s[N];
int ans[N + 1];
int sum[N];
int pos[N];
void init()
{
    for(int i = 0;i < N;i ++)
        s[i].clear();
    memset(ans,0,sizeof(ans));
}

bool judge(int val,int id)
{
    for(auto ele : s[id])
    {
        long long res = 1LL * val * ele;
        if(res < 0)
            return false;
        long long half = sqrt(1.0 * res);
        if(half * half != res)
            return false;
    }
    return true;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1)
    {
        init();
        vector<int> v;
        for(int i = 0;i < n;i ++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        int cnt = 0;
        for(int i = 0;i < n;i ++)
        {
            if(v[i])
            {
                if(!cnt)
                {
                    s[cnt++].push_back(v[i]);
                    pos[i] = cnt - 1;
                }
                else 
                {
                    int flag = 0;
                    for(int j = 0;j < cnt;j++)
                    {
                        if(judge(v[i],j))
                        {
                            s[j].push_back(v[i]);
                            pos[i] = j;
                            flag = 1;
                            break;
                        }
                    }
                    if(!flag)
                    {
                        s[cnt ++].push_back(v[i]);
                        pos[i] = cnt - 1;
                    }
                }
            }
            ans[max(cnt,1)] ++;
            for(int j = 0;j < cnt;j ++)
                sum[j] = s[j].size();
            int all = cnt;
            for(int j = 0;j < i;j ++)
            {
                if(v[j])
                {
                    int id = pos[j];
                    sum[id] --;
                    if(!sum[id])
                        all --;
                }
                ans[max(all,1)] ++;
            }
        }
        for(int i = 1;i <= n;i ++)
        {
            if(i != 1)
                printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
}
