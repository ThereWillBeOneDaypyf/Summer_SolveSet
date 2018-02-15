#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long n,q;
    long long a0,an;
    while(cin >> n >> a0 >> an >> q)
    {
        for(int i = 0;i < q;i ++)
        {
            long long l,r;
            cin >> l >> r;
            long long temp = (an - a0) / n * (l + r) * (r - l + 1) / 2;
            temp += (r - l + 1) * a0;
            cout << temp << endl;
        }
    }
}