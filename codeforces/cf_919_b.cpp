#include<bits/stdc++.h>
using namespace std;

bool judge(long long i)
{
    int sum = 0;
    while(i)
    {
        sum += i % 10;
        i /= 10;
    }
    if(sum == 10)
        return true;
    return false;
}

vector<long long> init()
{
    vector<long long> v;
    for(long long i = 19;; i ++)
    {
        if(v.size() > 10000)
            break;
        if(judge(i))
            v.push_back(i);
    }
    return v;
}

int main()
{
    vector<long long> res = init();
    int k;
    while(cin >> k)
    {
        cout << res[k - 1] << endl;
    }
}