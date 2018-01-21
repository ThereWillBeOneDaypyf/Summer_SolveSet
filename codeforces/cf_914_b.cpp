#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        map<int,int> cnt;
        for(int i = 0;i < n;i++)
        {
            int x;
            cin >> x;
            cnt[x] ++;
        }
        int flag = 0;
        for(auto temp : cnt)
        {
            if(temp.second % 2) 
            {
                flag = 1;
                break;
            }
        }
        if(flag % 2)
            cout << "Conan" << endl;
        else
            cout << "Agasa" << endl;
    }
}