#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    while(cin >> n)
    {
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = i;j <= n;j ++)
            {
                int need = i ^ j;
                if(need >= j && need <= n && i + j > need)
                    ans ++;
            }
        }
        cout << ans << endl;
    }
}