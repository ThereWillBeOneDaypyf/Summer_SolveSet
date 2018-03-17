#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l,r,both;
    while(cin >> l >> r >> both)
    {
        int ans = 0;
        for(int i = 0;i <= both;i ++) 
            ans = max(ans,min(i + l, both - i + r));
        cout << ans * 2 << endl;
    }
}
