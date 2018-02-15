#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int h,m,s;
};

int main()
{
    int n;
    while(cin >> n)
    {
        vector<Node> v;
        for(int i = 0;i < n;i ++)
        {
            int h,m,s;
            cin >> h >> m >> s;
            v.push_back({h,m,s});
        }
        sort(v.begin(),v.end(),[](Node a,Node b){
            if(a.h != b.h)
                return a.h < b.h;
            else if(a.m != b.m)
                return a.m < b.m;
            return a.s < b.s;
        });
        for(auto temp : v)
            cout << temp.h << " " << temp.m << " " << temp.s << endl;
    }   
}