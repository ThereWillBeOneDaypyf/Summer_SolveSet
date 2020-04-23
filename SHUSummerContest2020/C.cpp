#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        if(a != b)
            cout << max(a.size(), b.size()) << endl;
        else
            cout << -1 << endl;
    }
}