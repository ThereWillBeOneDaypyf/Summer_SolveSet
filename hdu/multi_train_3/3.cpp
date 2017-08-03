#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

struct LinkList
{
	int l, r;
} link[N];
int n, k;
int pos[N];
void init()
{
	memset(link, 0, sizeof(link));
	link[1].l = 0, link[1].r = 2;
	link[n].r = n + 1, link[n].l = n - 1;
	for (int i = 2; i < n; i++)
		link[i].l = i - 1, link[i].r = i + 1;
}
int all = 0;
vector<int>tar;
void getleft(int p, int cnt)
{
	for (int i = link[p].l; cnt; i = link[i].l)
	{
		cnt --;
		tar.push_back(i);
		if (i == 0)
			break;
	}
}
void getright(int p, int cnt)
{
	for (int i = link[p].r; cnt; i = link[i].r)
	{
		cnt --;
		tar.push_back(i);
		if (i == n + 1)
			break;;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		init();
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			pos[x] = i;
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			tar.clear();
			getleft(pos[i], k);
			sort(tar.begin(), tar.end());
			tar.push_back(pos[i]);
			getright(pos[i], k);
			int cnt = 0;
			for (int i = 0; i < (int)tar.size() - k - 1; i++)
				cnt += (tar[i + 1] - tar[i]) * (tar[i + k + 1] - tar[i + k]);
			ans += 1LL * cnt * i;
			link[link[pos[i]].l].r = link[pos[i]].r;
			link[link[pos[i]].r].l = link[pos[i]].l;
		}
		printf("%lld\n", ans);
	}
}