#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        for(int i = 0;i < s.length();i ++)
        {
            cout << s[i];
            if(((int)s.length() - i - 1) % 3 == 0 && i != s.length() - 1)
            {
                cout << ',';
            }
        }
    }
}