#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        long long sum = 0;
        for(int i = 0;i < n; i ++)
        {
            int a;
            cin >> a;
            sum += a;
        }
        cout << sum - (1LL * (n - 1) * n) / 2 << endl;
    }
}