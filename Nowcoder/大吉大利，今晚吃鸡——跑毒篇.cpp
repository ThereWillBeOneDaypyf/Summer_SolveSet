#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int life = 100;
        int flag = 1;
        for(int i = 1;i < b;i++)
        {
            if(life > 6 * a && life <= 7 * a)
            {
                if(c)
                {
                    c--;
                    life = 80;
                }
            }
            life -= a;
        }
        if(life <= 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}