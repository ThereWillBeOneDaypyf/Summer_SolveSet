#include <bits/stdc++.h>

using namespace std;

int n;
int a[22];

void dfs(int pos, long long cur, long long& sum)
{
    if(pos >= n)
    {
        sum += cur;
        return;
    }
    dfs(pos + 1, cur, sum);
    dfs(pos + 1, cur | a[pos], sum);
}

int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        long long sum = 0;
        dfs(0, 0, sum);
        cout << sum << endl;
    }
}