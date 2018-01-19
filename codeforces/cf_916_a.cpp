#include<bits/stdc++.h>
using namespace std;

bool judge(int a,int b)
{
    if(a / 10 == 7 || a % 10 == 7 || b / 10 == 7 || b % 10 == 7)
        return true;
    return false;
}

int main()
{
    int k,a,b;
    while(cin >> k >> a >> b)
    {
        int cnt = 0;
        while(!judge(a,b))
        {
            cnt ++;
            b -= k;
            if(b < 0)
            {
                a --;
                b += 60;
            }
        }
        cout << cnt << endl;
    }
}