#include<bits/stdc++.h>
using namespace std;

int a[] = {1,0,0,0,1,0,1,0,2,1};

int main()
{
    int Max = 2 * 18;
    int k;
    while(cin >> k)
    {
        if(k > Max)
            cout << -1 << endl;
        else
        {
            for(int i = 0;i < k / 2;i ++)
                cout << 8;
            if(k % 2)
                cout << 6;
            cout << endl;
        }
    }
}