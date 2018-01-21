#include<bits/stdc++.h>
using namespace std;

constexpr int N = 1e4;

unsigned long long f[N];

void init()
{
    f[1] = 1;
    f[2] = 2;
    for(int i = 3;i <= 80;i++)
        f[i] = f[i - 1] + f[i - 2];
}

int main()
{
    int T;
    cin >> T;
    init();
    while(T--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
}