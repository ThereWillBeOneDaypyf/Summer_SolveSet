#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5 + 7;

int opt_ch[N][2], tar_ch[N][2];
int hash_opt[N], hash_tar[N];
map<pair<int, int> , int>hash_val;
map<int, int>ans;
int hash_key = 0;
void init()
{
	hash_key = 0;
	hash_val.clear();
	ans.clear();
}
void dfs_opt(int u)
{
	int l = opt_ch[u][0], r = opt_ch[u][1];
	if (l == -1)
		hash_opt[l] = -1;
	else
		dfs_opt(l);
	if (r == -1)
		hash_opt[r] = -1;
	else
		dfs_opt(r);
	if (!hash_val.count(make_pair(hash_opt[l], hash_opt[r])))
		hash_val[make_pair(hash_opt[l], hash_opt[r])] =  ++ hash_key;
	hash_opt[u] = hash_val[make_pair(hash_opt[l], hash_opt[r])];
}
void dfs_tar(int u)
{
	int l = tar_ch[u][0], r = tar_ch[u][1];
	if (l == -1)
		hash_tar[l] = -1;
	else
		dfs_tar(l);
	if (r == -1)
		hash_tar[r] = -1;
	else
		dfs_tar(r);
	if (!hash_val.count(make_pair(hash_tar[l], hash_tar[r])))
		hash_val[make_pair(hash_tar[l], hash_tar[r])] = ++ hash_key;
	hash_tar[u] = hash_val[make_pair(hash_tar[l], hash_tar[r])];
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		init();
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &opt_ch[i][0], &opt_ch[i][1]);
		for (int i = 1; i <= m; i++)
			scanf("%d%d", &tar_ch[i][0], &tar_ch[i][1]);
		dfs_tar(1);
		dfs_opt(1);
		long long sum = 0;
		for (int i = 1; i <= m; i++)
			ans[hash_tar[i]] ++;
		for (int i = 1; i <= n; i++)
			if (ans.count(hash_opt[i]))
				sum += (long long) ans[hash_opt[i]];
		printf("%lld\n", sum);
	}
}