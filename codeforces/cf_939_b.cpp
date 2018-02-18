#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

long long a[N];

int main()
{
    long long n,k;
    while(cin >> n >> k)
    {
        long long ret = n;
        int id;
        for(int i = 1;i <= k; i++)
        {
            long long x;
            cin >> x;
            a[i] = x;
            long long res = n % x;
            if(res <= ret)
            {
                ret = res;
                id = i;
            }
        }
        cout << id << " " << n / a[id] << endl;
    }
}