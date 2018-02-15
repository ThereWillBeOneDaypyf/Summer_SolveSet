#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e6;

int BIT[N];
int a[N];
int n;
int lowbit(int x)
{
    return x & (- x);
}
void update(int x)
{
    while(x <= n)
    {
        BIT[x] ++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += BIT[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    ios :: sync_with_stdio(false);
    while(cin >> n)
    {
        memset(BIT,0,sizeof(BIT));
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        string s;
        cin >> s;
        update(a[n]);
        int flag = 1;
        for(int i = n - 1; i >= 1;i --)
        {
            if(query(a[i]) && s[i - 1] == '0')
            {
                flag = 0;
                break;
            }
            update(a[i]);
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}