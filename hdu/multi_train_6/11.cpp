#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int a,b,c,ab,bc,ac,abc;
	int n;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int ans = 0;
		for(int i =0 ;i<n;i++)
		{
			scanf("%d%d%d%d%d%d%d",&a,&b,&c,&ab,&bc,&ac,&abc);	
			ab -= abc, bc -= abc , ac -= abc;
			a -= (ab + ac + abc) , b -= (ab + bc + abc) , c -= (ac + bc + abc);
			if(a < 0 || b < 0 || c < 0 || ab < 0 || ac < 0 || bc < 0 || abc < 0)
				continue;
			else
				ans = max(ans ,a + b + c + ab + ac + bc + abc);
		}
		printf("%d\n",ans);
	}
}
