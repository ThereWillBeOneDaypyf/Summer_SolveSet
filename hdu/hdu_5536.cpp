#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
	if(++ps == pe)
		pe = (ps = buf) + fread(buf,sizeof(char),sizeof(buf) / sizeof(char),stdin);
}
template <class T>
inline bool in(T &ans)
{
	ans = 0;
	T f = 1;
	if(ps == pe)
		return false;
	do
	{
		rnext();
		if('-' == *ps) f = -1;
	}
	while(!isdigit(*ps) && ps != pe);
	if(ps == pe)
		return false;
	do
	{
		ans = (ans << 1) + (ans << 3) + *ps - 48;
		rnext();
	}
	while(isdigit(*ps) && ps != pe);
	ans *= f;
	return true;
}
const int MAXOUT = 1e5;
char bufout[MAXOUT],outtmp[50],*pout = bufout,*pend = bufout + MAXOUT;
inline void write()
{
	fwrite(bufout,sizeof(char),pout - bufout,stdout);
	pout = bufout;
}
inline void out_char(char c){*(pout++) = c; if(pout == pend) write();}
inline void out_str(char *s)
{
	while(*s)
	{
		*(pout++) = *(s++);
		if(pout == pend)
			write();
	}
}
template <class T>
inline void out_int(T x)
{
	if(!x)
	{
		out_char('0');
		return;
	}
	if(x < 0)
		x = -x, out_char('-');
	int len = 0;
	while(x)
	{
		outtmp[len++] = x % 10 + 48;
		x /= 10;
	}
	outtmp[len] = 0;
	for(int i = 0,j = len-1;i < j;i++,j--)
		swap(outtmp[i],outtmp[j]);
	out_str(outtmp);
}
struct Tire
{
	int next[2];
	int val;
};

Tire t[10000000];
int tot = 0;
int root = 0;
int init_node()
{
	tot ++;
	for(int i = 0;i < 2;i++)
		t[tot].next[i] = 0;
	t[tot].val = 0;
	return tot;
}
void init_tree()
{
	tot = 0;
	root = init_node();
}
void insert(int x)
{
	int a[32];
	for(int i = 0;i<32;i++)
	{
		a[i] = x % 2;
		x /= 2;
	}
	int r;
	r = root;
	for(int i = 31;i>= 0;i--)
	{
		int id = a[i];
		t[r].val ++;
		if(t[r].next[id] == 0)
		//if(r -> next[id] == NULL)
		{
			int temp = init_node();
			t[r].next[id] = temp;
		}
		r = t[r].next[id];
	}
	t[r].val ++;
}
void del(int x)
{
	int a[32];
	for(int i = 0;i<32;i++)
	{
		a[i] = x % 2;
		x /= 2;
	}
	int r;
	r = root;
	for(int i =31;i>=0;i--)
	{
		int id = a[i];
		t[r].val --;
		r = t[r].next[id];
	}
	t[r].val --;
}
long long find(int x)
{
	int b[32];
	for(int i = 0;i<32;i++)
	{
		b[i] = x % 2;
		x /= 2;
	}
	int r;
	r = root;
	long long res = 0;
	for(int i = 31;i>=0;i--)
	{
		res *= 2;
		int need = b[i] ^ 1;
		//if(r -> next[need] != NULL && r -> next[need] -> val != 0)
		if(t[r].next[need] != 0 && t[t[r].next[need]].val != 0)
		{
			res ++;
			r = t[r].next[need];
		}
		else
			r = t[r].next[b[i]];
	}
	return res;
}
vector<int>v;
int main()
{
	//freopen("hdu_5536.in","r",stdin);
	int T;
	in(T);
	//scanf("%d",&T);
	while(T--)
	{
		int n;
		//scanf("%d",&n);
		in(n);
		v.clear();
		for(int i = 0;i<n;i++)
		{
			int x;
			//scanf("%d",&x);
			in(x);
			v.push_back(x);
		}
		init_tree();
		for(int i = 0;i<n;i++)
		{
			for(int j = i+1;j<n;j++)
			{
				insert(v[i] + v[j]);
			}
		}
		long long ans = -1;
		for(int k = 0;k<n;k++)
		{
			for(int i = 0;i<n;i++)
			{
				if(i == k)
					continue;
				del(v[i] + v[k]);
			}
		//	cout << ans << " " << find(v[k]) << endl;
			ans = max(ans,find(v[k]));
			for(int i = 0;i<n;i++)
			{
				if(i == k)
					continue;
				insert(v[i] + v[k]);
			}
		}
		//printf("%lld\n",ans);
		out_int(ans);
		out_char('\n');
	}
	write();
}
