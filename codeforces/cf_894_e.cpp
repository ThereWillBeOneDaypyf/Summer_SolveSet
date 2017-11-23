#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

vector<pair<int,int> > G[N];
int Index = 0;
int cnt = 0;
int dfn[N],low[N];
stack<int> st;
int instack[N];
long long dp[N];
int belong[N];
long long pw[N];
int n;
vector<pair<int,int> > edge[N];
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
void init()
{
	memset(dfn,0,sizeof(dfn));
	memset(pw,0,sizeof(pw));
	while(!st.empty())
		st.pop();
	memset(instack,0,sizeof(instack));
	for(int i = 0;i<N;i++)
		G[i].clear(),edge[i].clear();
}
void add_edge(int u,int v,int w)
{
	G[u].push_back(make_pair(v,w));
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++ Index;
	st.push(u);
	instack[u] = 1;
	for(auto temp : G[u])
	{
		int v = temp.first;
		int w = temp.second;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(instack[v])
			low[u] = min(low[u],dfn[v]);
	}
	int x;
	if(dfn[u] == low[u])
	{
		cnt ++;
		do{
			x = st.top();
			st.pop();
			instack[x] = 0;
			belong[x] = cnt;
		}while(x != u);
	}
}
void link()
{
	for(int i = 1;i<=n;i++)
	{
		for(auto temp : G[i])
		{
			int v = temp.first;
			int w = temp.second;
			int cnt = (-1.0 + sqrt(1.0 + 8.0 * w)) / 2;
			if(cnt * cnt + cnt == 2 * w)
				cnt --;
			//int cnt = serch(w);
			long long curw = - 1LL * cnt * (cnt + 1) * (2 * cnt + 1) / 6;
			curw += 1LL * (cnt + 1) * (1 + cnt) * cnt / 2;
			curw = 1LL * (cnt + 1) * w - curw;
			if(belong[i] == belong[v])
				pw[belong[i]] += curw;
			else
			{
				edge[belong[i]].push_back(make_pair(belong[v],w));
			}
		}
	}
}
void dfs(int u)
{
	dp[u] = pw[u];
	for(auto temp : edge[u])
	{
		int v = temp.first;
		long long w = temp.second;
		if(!dp[v])
			dfs(v);
		dp[u] = max(dp[u],1LL * dp[v] + w + pw[u]);
	}
}
long long solve(int s)
{
	tarjan(s);
	link();
	dfs(belong[s]);
	return dp[belong[s]];
}
int main()
{
	int m;
	in(n),in(m);
	init();
	for(int i = 0;i<m;i++)
	{
		int u,v;
		int w;
		in(u),in(v),in(w);
		add_edge(u,v,w);
	}	
	int s;
	in(s);
	out_int(solve(s));
	write();
}
