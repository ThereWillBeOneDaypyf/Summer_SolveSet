#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 8;
int dep[N];
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
	if(++ps == pe)
		pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

	template <class T>
inline bool in(T &ans)
{
	ans = 0;
	T f = 1;
	if(ps == pe) return false;//EOF
	do{
		rnext();
		if('-' == *ps) f = -1;
	}while(!isdigit(*ps) && ps != pe);
	if(ps == pe) return false;//EOF
	do
	{
		ans = (ans<<1)+(ans<<3)+*ps-48;
		rnext();
	}while(isdigit(*ps) && ps != pe);
	ans *= f;
	return true;
}
const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
	fwrite(bufout,sizeof(char),pout-bufout,stdout);
	pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
	while(*s)
	{
		*(pout++) = *(s++);
		if(pout == pend) write();
	}
}
template <class T>
inline void out_int(T x) {
	if(!x)
	{
		out_char('0');
		return;
	}
	if(x < 0) x = -x,out_char('-');
	int len = 0;
	while(x)
	{
		outtmp[len++] = x%10+48;
		x /= 10;
	}
	outtmp[len] = 0;
	for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
	out_str(outtmp);
}
struct Edge
{
	int u,v;
	int next;
	bool operator < (const Edge & rhs) const
	{
		return max(dep[u],dep[v]) > max(dep[rhs.u],dep[rhs.v]);
	}
}edge[N*2];
int tot = 0,head[N];
int ans = 0;
int cur = 0;
int k;
int vis[N];
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
}
void dfs(int u,int fa)
{
	int cnt = 0;
	for(int i = head[u] ; ~i;i=edge[i].next)
	{
		int v = edge[i].v;
		if(v == fa)
			continue;
		cnt ++;
		dfs(v,u);
		if(cur >= k)
			return;
		if(!vis[v] && !vis[u])
		{
			vis[v] = 1,vis[u] = 1;
			cur += 2;
			ans += 1;
		}
	}
}
void add_edge(int u,int v)
{
	edge[tot] = {u,v,head[u]};
	head[u] = tot ++;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int T;
	in(T);
	int n;
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		init();
		in(n),in(k);
		for(int i = 2;i<=n;i++)
		{
			int x;
			in(x);
			add_edge(x,i),add_edge(i,x);
		}
		ans = 0;
		cur = 0;
		dfs(1,1);
		if(cur >= k)
			out_int(ans);
		else
			out_int(ans + (k-cur));
		out_char('\n');
	}
	write();
	return 0;
}
