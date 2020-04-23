#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n == 1)
        {
            cout << 1 << endl << 1 << endl;
        }
        else if(n == 2)
        {
            cout << 2 << endl;
            cout << 0 << endl;
            cout << 11 << endl;
        }
        else 
        {
            cout << n - 1 << endl;
            for(int i = 1; i < n; i ++)
            {
                cout << 1;
                for(int j = 1; j < i; j ++)
                {
                    cout << 0;
                }
                cout << 1 << endl;
            }
        }
    }
}