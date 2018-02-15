#include<bits/stdc++.h>
using namespace std;


int main()
{
    long double a,b,c;
    int T;
    cin >> T;
    while(T--)
    {
        cin >> a >> b >> c;
        long double ans = a * c / b;
        string s = to_string(ans);
        int pos = find_if(s.begin(),s.end(),[](char x){
            if(x == '.')
                return true;
            return false;
        }) - s.begin();
        if(s[pos + 3] > '5')
            s[pos + 2 ]++;
        else if(s[pos + 3] == '5')
        {
            int flag = 0;
            for(int i = pos + 4;i < s.length();i++)
                if(s[i] != '0')
                {
                    flag = 1;
                    break;
                }
            if(flag)
                s[pos + 2 ]++;
            else if((s[pos + 2] - '0') % 2 == 1)
            {
                s[pos + 2] ++;
            }
        }
        int c = 0;
        for(int i = pos + 2;i >= 0;i --)
        {
            if(s[i] == '.')
                i --;
            int num = s[i] - '0' + c;
            c = 0;
            if(num >= 10)
                c = 1;
            s[i] = num % 10 + '0';
        }
        if(c)
            cout << 1;
        for(int i = 0;i != pos + 3;i ++)
            cout << s[i];
        cout << endl;
    }
}