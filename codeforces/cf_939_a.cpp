#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N];

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        int flag = 0;
        for(int i = 1;i <= n;i ++)
        {
            if(a[a[a[i]]] == i && i != a[i] && i != a[a[i]])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}