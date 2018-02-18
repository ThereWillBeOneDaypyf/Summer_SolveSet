#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;

long long a[N];

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i = 1;i <= n;i ++)
            cin >> a[i];
        for(int i = n + 1;i <= 2 * n;i ++)
            a[i] = a[i - n];
        int s,f;
        cin >> s >> f;
        int dis = f - s;
        long long sum = 0;
        for(int i = 1;i <= dis;i++)
            sum += a[i];
        long long Max  = sum;
        long long cur_st = s;
        for(int i = 2;i <= n;i ++)
        {
            sum -= a[i - 1];
            sum += a[i + dis - 1];
            if(sum > Max)
            {
                Max = sum;
                cur_st = s - (i - 1) + n;
                cur_st %= n;
                if(cur_st == 0)
                    cur_st = n;
            }
            else if(sum == Max)
            {
                long long st = s - (i - 1) + n;
                st %= n;
                if(st == 0)
                    st = n;
                if(st < cur_st)
                    cur_st = st;
            }
        }
        cout << cur_st << endl;
    }
}