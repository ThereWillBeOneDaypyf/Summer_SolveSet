#include<iostream>
using namespace std;
int a[210];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			a[i+n]=a[i];
		}
		int ans = 0;
		for(int i=1;i<=n;i++)
		{
			int cur = 0;
			for(int j=1;j<=n;j++)
			{
 	//			cout << a[i+j-1] << " " << a[i+j] << endl;
				if(a[i+j-1]>=a[i+j]) break;
				cur++;
			}
	//		cout << cur << endl;
			ans = max(cur,ans);
		}

		for(int i=1;i<=n;i++)
		{
			int cur = 0;
			for(int j=1;j<=n;j++)
			{
 	//			cout << a[i+j-1] << " " << a[i+j] << endl;
				if(a[i+j-1]<=a[i+j]) break;
				cur++;
			}
	//		cout << cur << endl;
			ans = max(cur,ans);
		}
		cout << ans << endl;
	}
}
