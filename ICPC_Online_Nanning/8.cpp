#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	double R;
	scanf("%lf",&R);
	while(T--)
	{
		int k;
		double R1 = R,R2 = R,R3 = R;
		scanf("%d",&k);
		for(int i = 0;i<k;i++)
		{
			R3 = (R1 * R2 * R3) / (R1*R2 + R2*R3 + R1*R3 + 2.0 * sqrt((R1 * R2 * R3) *(R1 + R2 + R3)));
		}
		long long ans = R3;
		printf("%d %lld\n",k , ans);
	}
	int x;
	scanf("%d",&x);
}
