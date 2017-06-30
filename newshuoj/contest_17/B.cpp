#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
char g[maxn + 5][maxn + 5];
int n, m;
const int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
inline bool inside(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return false;
	return true;
}
void dfs(int x, int y) {
	g[x][y] = '*';
	for (int i = 0; i < 8; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (inside(tx, ty) && g[tx][ty] == '@') dfs(tx, ty);
	}	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n >> m) {
		if ((n + m) == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> g[i][j];

		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (g[i][j] == '@') {
					cnt++;
					dfs(i, j);
				}

		cout << cnt << endl;
	}
	return 0;
}
