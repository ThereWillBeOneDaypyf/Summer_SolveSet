#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios :: sync_with_stdio(false);
    long long f[3000];
    f[1] = f[2] = 1;
    int tot = 2;
    while(f[tot] < 1000)
    {
        int temp = tot;
        f[++ tot] = f[temp] + f[temp - 1];
    }
    int n;
    while(cin >> n)
    {
        int cur = 3;
        cout << "O";
        for(int i = 2;i <= n;i ++)
        {
            if(i == f[cur])
            {
                cout << "O";
                cur ++;
            }
            else
                cout << "o";
        }
        cout << endl;
    }
}