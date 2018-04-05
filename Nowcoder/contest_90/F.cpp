#include<bits/stdc++.h>
using namespace std;
#define MAXIMUM 26

int prime[1000000];
bool isprime[1000000];

void get_prime(int listsize)
{
    int primesize=1;
    memset(isprime,1,sizeof(isprime));
    isprime[1] = false;
    for(int i=2;i<=listsize;i++)
    {
        if(isprime[i]) prime[primesize++]=i;
        for(int j=1;i*prime[j]<=listsize&&j<=primesize;j++)
        {
            isprime[i*prime[j]] = false;
            if(i%prime[j]==0) break;
        }
    }
}

struct p
{
    long long value;
    int time;
}p[MAXIMUM];

void prime_factorization(long long n)
{
    memset(p,0,sizeof(p));
    long long psize=0;
    long long a = n;
    for(int t = 1;prime[t]*prime[t]<=n;t++)
    {
        if(a%prime[t]==0) p[++psize].value = prime[t];
        while(a%prime[t]==0)
        {
            p[psize].time += 1;
            a = a / prime[t];
        }
        if(a<=90000)
        if(isprime[a])
        {
            p[++psize].value = a;
            p[psize].time += 1;
            a = 1;
            break;
        }
        if(a==1) break;
    }
    if(a!=1)
    {
        p[++psize].value = a;
        p[psize].time = 1;
    }
    //if(p[1].value==0){
       // p[1].value = a;
        //p[1].time = 1;
    //}
}


int main()
{
    int T;
    cin >> T;
    long long n;
    get_prime(100000);
/*
    while(cin >> n)
    {
        prime_factorization(n);
        int ii=1;
         while(p[ii].value!=0)
        {
            cout << p[ii].value << "******" << p[ii].time << endl;
            ii++;
        }
    }
*/

    while(T--)
    {
        cin >> n;
        prime_factorization(n);
        int i=1;
        int ans=1;
        while(p[i].value!=0)
        {
            ans*=(2*p[i].time+1);
            i++;
        }
        ans+=1;
        ans/=2;
        cout << ans << endl;
    }
}