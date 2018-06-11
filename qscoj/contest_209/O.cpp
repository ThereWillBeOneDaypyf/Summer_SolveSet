#include<bits/stdc++.h>
using namespace std;
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf + 1;
inline void rnext()
{
    if (++ps == pe)
        pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin);
}

template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if (ps == pe) return false; //EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    }
    while (!isdigit(*ps) && ps != pe);
    if (ps == pe) return false; //EOF
    do
    {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    }
    while (isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}
const int  MAXOUT = 10000;
char bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
inline void write()
{
    fwrite(bufout, sizeof(char), pout - bufout, stdout);
    pout = bufout;
}
inline void out_char(char c) { *(pout++) = c; if (pout == pend) write();}
inline void out_str(char *s)
{
    while (*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
}
template <class T>
inline void out_int(T x)
{
    if (!x)
    {
        out_char('0');
        return;
    }
    if (x < 0) x = -x, out_char('-');
    int len = 0;
    while (x)
    {
        outtmp[len++] = x % 10 + 48;
        x /= 10;
    }
    outtmp[len] = 0;
    for (int i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
    out_str(outtmp);
}

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
    int block = sqrt(n);
    int cnt = n / block;
    if(n % block)
        cnt ++;
    for(int i = 1;i <= cnt;i++)
        s[i].clear(),add[i] = 0;
    for(int i = 1;i <= n;i ++)
    {
        belong[i] = (i - 1) / block + 1;
        int val;
        // scanf("%d",&val);
        // cin >> val;
        in(val);
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

vector<Node> wait_insert;
void single_add(int ql,int qr,int b,int v)
{
    wait_insert.clear();
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


int query(int tar,int cnt)
{
    int ansl = -1, ansr = -1;
    for(int i = 1;i <= cnt;i ++)
    {
        auto lpos = s[i].lower_bound({tar - add[i],0});
        if(lpos == s[i].end() || (*lpos).val != tar - add[i])
            continue;
        else
        {
            auto rpos = s[i].upper_bound({tar - add[i],0});
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
        if(lpos == s[i].end() || (*lpos).val != tar - add[i])
            continue;
        else 
        {
            auto rpos = s[i].upper_bound({tar - add[i],0});
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
    static int n,q;
    // while(cin >> n >> q)
    // while(scanf("%d%d",&n,&q) == 2)
    while(in(n) && in(q))
    {
        static int cnt = init(n);
        for(int i = 0;i < q;i ++)
        {
            static int op;
            // cin >> op;
            in(op);
            if(op == 1)
            {
                static int ql,qr,val;
                // cin >> ql >> qr >> val;
                // scanf("%d%d%d",&ql,&qr,&val);
                in(ql),in(qr),in(val);
                update(ql,qr,val);
            }
            else
            {
                static int tar;
                // cin >> tar;
                // scanf("%lld",&tar);
                in(tar);
                // printf("%d\n",query(tar,cnt));
                out_int(query(tar,cnt));
                out_char('\n');
                // cout << query(tar,cnt) << endl;
            }
        }
    }
    write();
}
