#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define INF (1ll<<40)

int N;
int x[300010];
char c[300010];

vector <int> G;
vector <int> R[300010], B[300010];

ll func(ll L, ll R, vector <int> &r, vector <int> &b)
{
    ll ans = 0;
    int i;

    if (L == -INF && R == INF)
    {
        if (!r.empty()) ans += r[r.size() - 1] - r[0];
        if (!b.empty()) ans += b[b.size() - 1] - b[0];
        return ans;
    }

    if (L == -INF)
    {
        if (!r.empty()) ans += R - r[0];
        if (!b.empty()) ans += R - b[0];
        return ans;
    }

    if (R == INF)
    {
        if (!r.empty()) ans += r[r.size() - 1] - L;
        if (!b.empty()) ans += b[b.size() - 1] - L;
        return ans;
    }

    ll rgap = 0, bgap = 0;

    int sz = r.size();
    if (sz == 0)
    {
        rgap = R - L;
    }
    else
    {
        rgap = max(r[0] - L, R - r[sz - 1]);
        REP(i, sz - 1) rgap = max(rgap, (ll)r[i + 1] - r[i]);
    }

    sz = b.size();
    if (sz == 0)
    {
        bgap = R - L;
    }
    else
    {
        bgap = max(b[0] - L, R - b[sz - 1]);
        REP(i, sz - 1) bgap = max(bgap, (ll)b[i + 1] - b[i]);
    }

    return min(2 * (R - L), 3 * (R - L) - rgap - bgap);
}

int main(void)
{
    int i;

    cin >> N;
    REP(i, N) scanf("%d %c", &x[i], &c[i]);

    int cnt = 0;

    REP(i, N) if (c[i] == 'P')
    {
        G.push_back(x[i]);
        cnt++;
    }
    else if (c[i] == 'R')
    {
        R[cnt].push_back(x[i]);
    }
    else
    {
        B[cnt].push_back(x[i]);
    }

    ll ans = 0;

    int sz = G.size();
    REP(i, sz + 1) ans += func(((i == 0) ? -INF : G[i - 1]), ((i == sz) ? INF : G[i]), R[i], B[i]);
    cout << ans << endl;

    return 0;
}