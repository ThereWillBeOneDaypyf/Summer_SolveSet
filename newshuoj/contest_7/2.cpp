#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Node
{
	char str[33];
	int id;
	int sorted;
}a[300005];
bool cmp_id(Node a,Node b)
{
	return a.id < b.id;
}
bool cmp(Node a,Node b)
{
	if(strcmp(a.str,b.str) < 0)
		return true;
	else
		return false;
}
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		for(int i = 0 ;i<n;i++)
		{
			scanf("%s",a[i].str);
			a[i].id = i;
		}
		sort(a,a+n,cmp);
		for(int i = 0;i<n;i++)
		{
			a[i].sorted = i + 1;
		}
		sort(a,a+n,cmp_id);
		for(int i = 0 ;i<n;i++)
			printf("%d\n",a[i].sorted);
	}
}
