#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x[4];
    while(cin >> x[0] >> x[1] >> x[2] >> x[3])
    {
        int m = 9999;
        for(int a = 0; a < 4; a ++)
        {
            for(int b = 0; b < 4; b ++)
            {
                for (int c = 0; c < 4; c ++)
                {
                    for(int d = 0; d < 4; d ++)
                    {
                        if(a != b && a != c && a != d && b != c && b != d && c != d)
                        {
                            m = min(m, abs(x[a] + x[b] - x[c] - x[d]));
                        }
                    }
                }
            }
        }
        cout << m << endl;
    }
}