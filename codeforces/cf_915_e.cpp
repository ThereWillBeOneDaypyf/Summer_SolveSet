#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 8;

struct Tree
{
    int lt,rt;
    int sum;
    int vis;
}t[N * 50];

int cnt = 0;
int new_node()
{
    cnt ++;
    t[cnt].lt = t[cnt].rt = t[cnt].sum = 0;
    t[cnt].vis = -1;
    return cnt;
}
void init()
{
    cnt = 0;
    new_node();
}


void push_down(int l,int r,int step)
{
    if(t[step].lt == 0)
        t[step].lt = new_node();
    if(t[step].rt == 0)
        t[step].rt = new_node();
    if(t[step].vis == -1)
        return;
    int mid = (l + r) / 2;
    t[t[step].lt].vis = t[step].vis;
    t[t[step].rt].vis = t[step].vis;
    t[t[step].lt].sum = t[step].vis * (mid - l + 1);
    t[t[step].rt].sum = t[step].vis * (r - mid);
    t[step].vis = -1;
}
void push_up(int step)
{
    t[step].sum = t[t[step].lt].sum + t[t[step].rt].sum;
}
void update(int l,int r,int ql,int qr,int val,int step)
{
    if(l == ql && r == qr)
    {
        t[step].vis = val;
        t[step].sum = (qr - ql + 1) * val;
        return;
    }
    push_down(l,r,step);
    int mid = (l + r) / 2;
    if(qr <= mid)
    {
        update(l,mid,ql,qr,val,t[step].lt);
    }
    else if(ql > mid)
        update(mid + 1,r,ql,qr,val,t[step].rt);
    else    update(l,mid,ql,mid,val,t[step].lt), update(mid + 1,r,mid + 1,qr,val,t[step].rt);
    push_up(step);
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q) == 2)
    {
        init();
        update(1,n,1,n,1,1);
        for(int i = 0;i < q;i ++)
        {
            int op,l,r;
            scanf("%d%d%d",&l,&r,&op);
            update(1,n,l,r,op - 1,1);
            printf("%d\n",t[1].sum);
        }
    }
}