#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    while(cin >> a >> b)
    {
        if(b == 0)
        {
            cout << "No" << endl;
        }
        else if(b == 1)
        {
            if(a != 0)
                cout << "No" << endl;
            else
                cout<< "Yes" << endl;
        }
        else
        {
            int origin_need = b - 1;
            if(a < origin_need)
                cout << "No" << endl;
            else
            {
                int copy = a - origin_need;
                if(copy % 2)
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            }
        }
    }
}