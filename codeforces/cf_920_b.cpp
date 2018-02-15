#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int l,r,id,vaild;
};
int main()
{
    ios :: sync_with_stdio(false);
    int T;
    while(cin >> T)
    {
        while(T--)
        {
            int n;
            cin >> n;
            vector<Node> v;
            for(int i = 0;i < n;i ++)
            {
                int l,r;
                cin >> l >> r;
                v.emplace_back((Node){l,r,i,1});
            }
            vector<int> ans;
            ans.assign(n,0);
            sort(v.begin(),v.end(),[](Node a,Node b){
                if(a.l != b.l)
                    return a.l < b.l;
                else return a.id < b.id;
            });
            ans[v[0].id] = v[0].l;
            for(int i = 1;i < n;i ++)
            {
                int cur = 0;
                for(int j = 0;j < i;j ++)
                {
                    if(!v[j].vaild)
                        continue;
                    cur = max(cur,v[j].l);
                    cur ++;
                }
                if(cur <= v[i].r)
                    ans[v[i].id] = max(cur,v[i].l);
                else
                    v[i].vaild = 0;
            }
            for(int i = 0;i < n;i ++)
            {
                if(i)
                    cout << " ";
                cout << ans[i];
            }
            cout << endl;
        }
    }
}