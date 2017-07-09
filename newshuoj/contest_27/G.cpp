lude<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Node
{
	int v,a;
}a[15],b[15],x[15],my[15];

int pos[15];
int n;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i<n;i++)
		{
			scanf("%d%d",&a[i].v,&a[i].a);
			pos[i] = i;
		}
		for(int i = 0;i<n;i++)
			scanf("%d%d",&b[i].v,&b[i].a);
		int flag = 0;
		int cnt_x,cnt_y,killx_need,killy_need;
		int t = 0;
		do{
			t ++;
			if(t > 100000) break;
			cnt_x = 0,cnt_y = 0;
			for(int i = 0;i<n;i++)
				x[i] = a[i],my[i] = b[i];	
			while(cnt_x < n && cnt_y < n)
			{
				killx_need = ceil( 1.0 * x[cnt_x].v / my[pos[cnt_y]].a);
				killy_need = ceil( 1.0 * my[pos[cnt_y]].v / x[cnt_x].a); 
				if(killx_need < killy_need) // x dead;
				{
					my[pos[cnt_y]].v -= killx_need * x[cnt_x].a;
					++ cnt_x;
				}
				else if(killx_need > killy_need)
				{
					x[cnt_x].v -= killy_need * my[pos[cnt_y]].a;
					++ cnt_y;
				}
				else
				{
					++ cnt_y;
					++ cnt_x;
				}
			}
			if(cnt_x == n && cnt_y != n)
			{
				flag = 1;
				break;
			}
		}while(next_permutation(pos,pos+n));
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
