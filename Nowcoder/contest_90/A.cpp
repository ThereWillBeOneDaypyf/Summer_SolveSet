#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;

long long f[N];

void init()
{
    f[0] = 1;
    for(int i = 1;i <= 30;i ++)
    {
        f[i] = 0;
        for(int j = 0;j < i;j ++)
            f[i] += f[j];
    }
}

int main()
{
    init();
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}