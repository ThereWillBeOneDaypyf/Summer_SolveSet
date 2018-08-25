#include <bits/stdc++.h>
using namespace std;

const int N = 100;

char Map[N][N];

void init()
{
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      Map[i][j] = '.';
}

void put_ret(int row, int st, bool item_type, int ed, bool end_type = false)
{
  bool flag = end_type;
  for (int i = ed - 1; i >= st; i--)
  {
    if (item_type)
    {
      if (!flag)
      {
        Map[row][i] = '|';
      }
      else
      {
        Map[row][i] = '/';
      }
    }
    else
    {
      if (!(flag ^ end_type))
      {
        Map[row][i] = '+';
      }
    }
    flag ^= 1;
  }
}

void put_xie(int row, int st, bool item_type, int width, int ed, bool end_type = false)
{
  for (int i = st; i < st + 2 * width; i += 2)
  {
    if (item_type)
    {
      Map[row][i] = '/';
    }
    else
    {
      Map[row][i] = '+';
      Map[row][i + 1] = '-';
    }
  }
  put_ret(row, st + 2 * width, item_type, ed, end_type);
}

void put_zhi(int row, int st, bool item_type, int width, int ed, bool end_type = false)
{
  for (int i = st; i < st + 2 * width; i += 2)
  {
    if (item_type)
    {
      Map[row][i] = '|';
    }
    else
    {
      Map[row][i] = '+';
      Map[row][i + 1] = '-';
    }
  }
  put_ret(row, st + 2 * width, item_type, ed, end_type);
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
  {
    int a, b, c;
    init();
    scanf("%d%d%d", &a, &b, &c);
    if (b > c)
    {
      for (int i = 0; i < 2 * c; i++)
      {
        put_xie(i, (2 * b - i), i % 2, a, 2 * (a + b) + 1);
      }
      for(int i = 2 * c;i < 2 * b;i ++)
      {
        put_xie(i,(2 * b - i), i % 2, a, 2 * (a + b) + 1 - (i - 2 * c),true);
      }
      for (int i = 2 * b; i < 2 * (b + c); i++)
      {
        put_zhi(i, 0, i % 2, a, (a + b) * 2 + 1 - (i - 2 * c), true);
      }
    }
    else
    {
      for (int i = 0; i < 2 * b; i++)
      {
        put_xie(i, (2 * b - i), i % 2, a, 2 * (a + b) + 1);
      }
      for (int i = 2 * b; i < 2 * c; i++)
      {
        put_zhi(i, 0, i % 2, a, 2 * (a + b) + 1);
      }
      for (int i = 2 * c; i < (b + c) * 2; i++)
      {
        put_zhi(i, 0, i % 2, a, (a + b) * 2 + 1 - (i - 2 * c), true);
      }
    }
    for (int i = 0; i < (b + c) * 2; i++)
    {
      for (int j = 0; j < (a + b) * 2 + 1; j++)
      {
        printf("%c", Map[i][j]);
      }
      printf("\n");
    }
    for (int j = 0; j < (a)*2 + 1; j++)
    {
      printf("%c", j % 2 ? '-' : '+');
    }
    for (int j = a * 2 + 1; j < (a + b) * 2 + 1; j++)
      printf(".");
    printf("\n");
  }
}