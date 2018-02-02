#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        map<string,string> ip2name;
        for(int i = 0;i < n;i ++)
        {
            string name,ip;
            cin >> name >> ip;
            ip2name[ip] = name;
        }
        for(int i = 0; i < m;i++)
        {
            string name,ip;
            cin >> name >> ip;
            string temp(ip.begin(),ip.end() - 1);
            cout << name << " " << temp << "; #" << ip2name[temp] << endl;
        }
    }
}