#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[8] ;
    for(int i = 0;i < 8;i ++)
        a[i] = i + 1;
    do{
        for(int i = 0;i < 8;i ++)
        {
            if(i)
                cout << " " ;
            cout << a[i];
        }
        cout << endl;
    }while(next_permutation(a, a + 8));
}