#include<iostream>
using namespace std;


int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    if(n == 1)
    {
      printf("Yes\n");
      continue;
    }
    else if(m == 1)
    {
      printf("No\n");
      continue;
    }
    else 
    {
      (n - 1) % (m - 1) ? printf("No\n") : printf("Yes\n");
    }
  }
}