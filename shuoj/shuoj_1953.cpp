#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
#include<map>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

#define INF 0x3f3f3f3f
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
typedef pair<int,int> PII;
typedef long long ll;

const int N = 1e6+5;


struct Query
{
	int l,r;
	int id;
	int ans;
}Q[N];

int block;
int pos[N];
int cnt[N];
int cnt_odd = 0;
int a[N];
int ans = 0;
void init()
{
	CLR(a,0);
	CLR(pos,0);
	CLR(cnt,0);
	CLR(Q,0);
	cnt_odd = 0;
}
bool cmp1(Query a,Query b)
{
	return pos[a.l] < pos[b.l] || (pos[a.l]==pos[b.l] && pos[a.r] < pos[b.r]);
}
bool cmp_id(Query a,Query b)
{
	return a.id < b.id;
}

void update(int i,int flag)
{
	cnt[a[i]] += flag;
	if(cnt[a[i]]%2==0)
		cnt_odd --;
	else
		cnt_odd ++;
}

int main()
{
	int T;
	scanf("%d",&T);
	int ka = 0;
	int n,q;
	while(T--)
	{
		init();
		scanf("%d%d",&n,&q);
		block = ceil(sqrt(1.0*n));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			pos[i] = i/block;
		}
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&Q[i].l,&Q[i].r);
			Q[i].id = i;
		}
		ans = 1;
		int l =1,r=0;
		cnt_odd = 0;
		sort(Q,Q+q,cmp1);
		for(int i=0;i<q;i++)
		{
			while(l>Q[i].l) update(--l,1);
			while(r<Q[i].r) update(++r,1);
			while(Q[i].l>l) update(l++,-1);
			while(Q[i].r<r) update(r--,-1);
			Q[i].ans = cnt_odd;
		}
		sort(Q,Q+q,cmp_id);
		printf("Case %d:\n",++ka);
		for(int i=0;i<q;i++)
		{
			if(Q[i].ans<=1)
				printf("YES\n");
			else
				printf("NO\n");
		}		
	}
	return 0;
}

