#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        map<long long,int> cnt;
        long long sum = 0;
        for(int i = 1;i < n;i ++)
        {
            int x;
            cin >> x;
            cnt[x] ++;
            sum += x;
        }
        long long res = (2LL * sum) / (3 * n - 2);
        double pro = 1.0 / (1.0 * (cnt[res] + 1));
        printf("%d %.2lf\n",res,pro);
    }
}
