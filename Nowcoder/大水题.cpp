#include<bits/stdc++.h>
using namespace std;

int q[100];

long long solve(long long n)
{
    int a[] = {2,5,11,13};
    int tot = 0;
    q[tot++] = -1;
    for(int i = 0;i < 4;i ++)
    {
        int temp = tot;
        for(int j = 0;j < temp;j++)
            q[tot++] = -1 * a[i] * q[j];
    }
    long long ans = 0;
    for(int i = 1;i < tot;i ++)
        ans += n / q[i];
    return ans;
}

int main()
{
    long long n;
    while(cin >> n)
    {
        cout << n - solve(n) << endl;
    }
}