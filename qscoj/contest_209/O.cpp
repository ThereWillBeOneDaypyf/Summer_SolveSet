#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int BLOCK_CNT = 1e3 + 7;

struct Node
{
    long long val;
    int pos;
    bool operator < (const Node& rhs)const
    {
        return val < rhs.val;
    }
};

int l[BLOCK_CNT];
int r[BLOCK_CNT];
long long add[BLOCK_CNT];
int belong[N];

multiset<Node> s[BLOCK_CNT];

int init(int n)
{
    for(int i = 0;i < BLOCK_CNT;i++)
        s[i].clear();
    memset(add,0,sizeof(add));
    int block = sqrt(n);
    int cnt = n / block;
    if(n % block)
        cnt ++;
    for(int i = 1;i <= n;i ++)
    {
        belong[i] = (i - 1) / block + 1;
        long long val;
        cin >> val;
        s[belong[i]].insert({val,i});
    }
    for(int i = 1;i <= cnt;i ++)
    {
        l[i] = (i - 1) * block + 1;
        r[i] = i * block;
    }
    r[cnt] = n;
    return cnt;
}

void single_add(int ql,int qr,int b,int v)
{
    vector<Node> wait_insert;
    for(auto it = s[b].begin();it != s[b].end();)
    {
        if((*it).pos <= qr && ql <= (*it).pos)
        {
            wait_insert.push_back({(*it).val + v,(*it).pos});
            it = s[b].erase(it);
        }
        else it ++;
    }
    for(auto ele : wait_insert)
        s[b].insert(ele);
}

void block_add(int ql,int qr,int v)
{
    for(int i = ql;i <= qr;i ++)
        add[i] += v;
}

void update(int ql,int qr,int v)
{
    if(belong[ql] == belong[qr])
    {
        single_add(ql,qr,belong[ql],v);
    }
    else
    {
        single_add(ql,r[belong[ql]],belong[ql],v);
        single_add(l[belong[qr]],qr,belong[qr],v);
        block_add(belong[ql] + 1,belong[qr] - 1,v);
    }
}


int query(long long tar,int cnt)
{
    int ansl = -1, ansr = -1;
    for(int i = 1;i <= cnt;i ++)
    {
        auto lpos = s[i].lower_bound({tar - add[i],0});
        auto rpos = s[i].upper_bound({tar - add[i],0});
        if(lpos == s[i].end() || (*lpos).val != tar - add[i])
            continue;
        else
        {
            for(auto it = lpos; it != rpos;it ++)
            {
                if(ansl == -1 || ansl > (*it).pos)
                    ansl = it -> pos;
            }
            break;
        }
    }
    for(int i = cnt;i>= 1;i --)
    {
        auto lpos = s[i].lower_bound({tar - add[i],0});
        auto rpos = s[i].upper_bound({tar - add[i],0});
        if(lpos == s[i].end() || (*lpos).val != tar - add[i])
            continue;
        else 
        {
            for(auto it = lpos; it != rpos;it ++)
            {
                if(ansr == -1 || ansr < (*it).pos)
                    ansr = it -> pos;
            }
            break;
        }
    }
    if(ansl == -1 || ansr == -1)
        return -1;
    else return ansr - ansl;
}




int main()
{
    int n,q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> n >> q)
    {
        int cnt = init(n);
        for(int i = 0;i < q;i ++)
        {
            int op;
            cin >> op;
            if(op == 1)
            {
                int ql,qr,val;
                cin >> ql >> qr >> val;
                update(ql,qr,val);
            }
            else
            {
                long long tar;
                cin >> tar;
                cout << query(tar,cnt) << endl;
            }
        }
    }
}
