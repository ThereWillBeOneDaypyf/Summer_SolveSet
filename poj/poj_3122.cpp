#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

#define esp 1e-6
#define Max_r 1e8 + 2000
#define PI 3.14159265359
const int N = 10005;

double a[N];

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		double Max = 0.0;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			a[i] *= a[i];
			Max = max(Max,a[i]);
		}
		m += 1;
		double l = 0.0,r=1.0 * Max,mid;
		while(  r - l > esp )
		{
			mid = (l + r) /2;
			int cnt = 0;
			for(int i = 0;i<n;i++)
				cnt += floor((a[i]/mid));
			if(cnt < m)
				r = mid;
			else
			{
				l = mid;
			}
		}
		cout << fixed << setprecision(4) << mid  * PI << endl;
	}
}
