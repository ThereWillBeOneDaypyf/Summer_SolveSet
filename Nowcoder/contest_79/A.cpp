#include <bits/stdc++.h>

double ans = 1.0;
int n;
double r1, r2, r3, r5;

void dfs(double cur, int n)
{
    if (n == 0)
    {
        ans = std::max(cur, ans);
        return;
    }
    if (n >= 5)
        dfs(std::pow((double)1.0 + r5,(double)5.0) * cur,n - 5);
    if(n >= 3)
        dfs(std::pow((double)1.0 + (double)r3,3.0) * cur,n - 3);
    if(n >= 2)
        dfs(std::pow((double)1.0 + (double)r2,2.0) * cur,n - 2);
    dfs(std::pow((double)1.0 + (double)r1,1.0) * cur,n - 1);
}

int main()
{
    while (std::cin >> n >> r1 >> r2 >> r3 >> r5)
    {
        ans = 1.0;
        dfs(1.0, n);
        std::cout << ans << std::endl;
    }
}