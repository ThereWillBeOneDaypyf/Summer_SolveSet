#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k;
    while(cin >> n >> k)
    {
        int cnt = 0;
        priority_queue<int> q;
        for(int i = 0;pow(2LL,1LL * i) <= n;i++)
        {
            long long tar = pow(2LL ,1LL * i);
            if((tar & n) != 0)
            {
                cnt ++;
                n -= tar;
                q.push(i);
            }
            if(cnt == k)
                break;
        }
        if(n)
        {
            cout << "No" << endl;
        }
        else
        {
            while(cnt != k)
            {
                auto temp = q.top();
                q.pop();
                q.push(temp - 1), q.push(temp - 1);
                cnt ++;
            }
            cout << "Yes" << endl;
            for(int i = 0;i < k;i++)
            {
                if(i)
                    cout << " ";
                cout << q.top();
                q.pop();
            }
            cout << endl;
        }
    }
}