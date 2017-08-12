#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

#define eps 1e-7


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int r,qx,qy,px,py;
		scanf("%d%d%d%d%d",&r,&px,&py,&qx,&qy);
		if(px == 0 && py == 0)
		{
			printf("%.9Lf\n",(long double)2.0 * r);
			continue;
		}
		long double xa = (1.0 * (r * r * px)) / (1.0 * (px * px + py * py));
		long double ya = (1.0 * (r * r * py)) / (1.0 * (px * px + py * py));
		long double xb = (1.0 * (r * r * qx)) / (1.0 * (qx * qx + qy * qy));
		long double yb = (1.0 * (r * r * qy)) / (1.0 * (qx * qx + qy * qy));
		long double d = ((long double) abs(ya*xb-yb*xa) / (sqrt((long double)(yb-ya) * (yb-ya) + (xb -xa) * (xb - xa))));
		long double ratio = sqrt((long double)(px*px + py*py)) / (long double) r;
		long double ans;
		if(d - r <= eps)
			ans = (long double)sqrt((xa-xb) * (xa - xb) + (ya - yb) * (ya - yb))*sqrt((long double)(px*px + py*py)) / (long double) r;
		else
			ans = (long double)sqrt(4.0 * ( ((long double) abs(ya*xb-yb*xa) / (sqrt((long double)(yb-ya) * (yb-ya) + (xb -xa) * (xb - xa))))- (long double)r) * ( ((long double) abs(ya*xb-yb*xa) / (sqrt((long double)(yb-ya) * (yb-ya) + (xb -xa) * (xb - xa))))
-(long double)r) + (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb))*sqrt((long double)(px*px + py*py)) / (long double) r;
		printf("%.9Lf\n",ans);
		
	}
	return 0;
}
