#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

// struct Node
// {
//     int data;
//     int rank;
//     int parent;
// }Node[MAX];
//
// /***
// 鏌ユ壘闆嗗悎i锛堜竴涓厓绱犳槸涓€涓泦鍚堬級鐨勬簮澶达紙閫掑綊瀹炵幇锛夈€?
// 濡傛灉闆嗗悎i鐨勭埗浜叉槸鑷繁锛岃鏄庤嚜宸卞氨鏄簮澶达紝杩斿洖鑷繁鐨勬爣鍙凤紱
// 鍚﹀垯鏌ユ壘闆嗗悎i鐨勭埗浜茬殑婧愬ご銆?
// ***/
//
// int get_parent(x)
// {
//     if(Node[x].parent==x)
//         return x;
//     return get_parent(Node[x].parent);
// }
//
// void Union(int a,int b)
// {
//     a=get_parent(a);
//     b=get_parent(b);
//     if(Node[a].rank>Node[b].rank)
//         Node[b].parent=a;
//     else
//     {
//         Node[a].parent=b;
//         if(Node[a].rank==Node[b].rank)
//             Node[b].rank++;
//     }
// }







struct UF
{
  int rank;
  int parent;
} UF[MAX];
int vis[MAX];
void init(int n) //寮€鎬诲厓绱犱负n鐨勭偣
{
  for (int i = 0; i <= n; i++)
  {
    UF[i].parent = i; //姣忎釜鐐逛竴寮€濮嬪潎涓鸿嚜宸辩殑绁栧厛
    UF[i].rank = 0;
  }
}

int get_parent(int x)
{
  if (UF[x].parent == x)
    return x;
  return get_parent(UF[x].parent);
}

void Union(int a, int b)
{
  a = get_parent(a);
  b = get_parent(b);
  if (UF[a].rank > UF[b].rank) UF[a].parent = b;
  else
  {
    UF[b].parent = a;
    if (UF[a].rank == UF[b].rank) UF[b].rank++;
  }
}
int main()
{
  int a, b;
  while (cin >> a >> b && a != -1 && b != -1)
  {
    if (a == 0 && b == 0)
    {
      cout << "Yes" << endl;
      continue;
    }
    memset(vis, 0, sizeof(vis));
    int edge = 1;
    int point = 2;
    vis[a] = 1;
    vis[b] = 1;
    int flag = 0;
    init(MAX);
    Union(a, b);
    while (cin >> a >> b && a && b)
    {
      edge++;
      if (!vis[a])
      {
        point++;
        vis[a] = 1;
      }
      if (!vis[b])
      {
        point++;
        vis[b] = 1;
      }
      if (get_parent(a) == get_parent(b))
        flag = 1;
      else Union(a, b);
    }
    if (point != edge + 1) flag = 1;
    flag == 0 ? cout << "Yes" << endl : cout << "No" << endl;
  }
  return 0;
}
// int main()
// {
//   //int debug,debug2;
//   int n, m, a, b, sum = 0;

//   while (scanf("%d", &n) == 1)
//   {
//     if(n == 0)
//       break;
//     init(1000);
//     scanf("%d", &m);
//     while (m--)
//     {
//       scanf("%d%d", &a, &b);
//       Union(a, b);
//     }
//     //scanf("%d",&debug);
//     //debug2=get_parent(debug);
//     //printf("%d\n",debug2);
//     for (int i = 1; i <= n; i++)
//     {
//       //printf("get_parent(%d)=%d\n",i,get_parent(i));
//       if (get_parent(i) == i)
//         sum++;
//     }
//     printf("%d\n", sum - 1);
//     sum = 0;
//   }
//   return 0;
// }