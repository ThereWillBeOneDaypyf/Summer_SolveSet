#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
long long ans = 0;

long long BIT[N][3];
int l;

char s[N];

int lowbit(int x)
{
  return x & (-x);
}

void add(int pos, int ty, long long val)
{
  while (pos <= l)
  {
    BIT[pos][ty] += val;
    BIT[pos][ty] %= MOD;
    pos += lowbit(pos);
  }
}

long long query(int pos, int ty)
{
  long long sum = 0;
  while (pos > 0)
  {
    sum += BIT[pos][ty];
    sum %= MOD;
    pos -= lowbit(pos);
  }
  return sum;
}

int main()
{
  int T;
  scanf("%d",&T);
  while (T--)
  {
    scanf("%s",s);
    ans = 0;
    l = strlen(s);
    for (int i = 0; i <= l; i++)
      for (int j = 0; j < 3; j++)
        BIT[i][j] = 0;
    for (int i = 0; i < l; i++)
    {
      for (int k = 0; k < 3; k++)
      {
        int cur = k + s[i] - '0';
        cur %= 3;
        add(i + 1, cur, query(i, k));
      }
      if (s[i] != '0')
        add(i + 1, (s[i] - '0') % 3, 1);
    }
    ans = query(l, 0);
    printf("%lld\n",ans);
  }
}