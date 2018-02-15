#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    while(cin >> n >> k)
    {
        if(k > 100)
            cout << "No" << endl;
        else 
        {
            int flag = 1;
            for(int i = 1;i <= k;i ++)
           {
                if((n + 1) % i)
                    flag = 0;
           } 
           flag ? cout << "Yes" : cout << "No";
           cout << endl;
        } 
    }
}