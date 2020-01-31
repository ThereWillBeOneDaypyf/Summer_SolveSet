#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

int n, a, b;
int v[N];

bool judge(int all)
{
    long long cur_damage = 1LL * b * all;
    long long need = 0;
    for(int i = 0; i < n; i ++)
    {
        if(cur_damage >= v[i])
            continue;
        long long dif = a - b;
        long long ret = v[i] - cur_damage;
        need += (ret + dif - 1) / dif;
    }
    return need <= all;
}


int main()
{
    while(cin >> n >> a >> b)
    {
        int l = 1, r = 1e9;
        for(int i = 0;i < n; i ++)
            cin >> v[i];
        int res = r + 1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(judge(mid))
            {
                res = min(res, mid);
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }
        cout << res << endl;
    }
}