#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,D,A;
		scanf("%d%d%d",&n,&D,&A);
		string d,a;
		cin >> d >> a;
		int same = 0;
		for(int i =0 ;i<n;i++)
			if(d[i] == a[i])
				same ++;
		int dif = n - same;
		int dec = min(same,min(D,A));
		same -= dec,D -= dec,A -= dec;
		if(D + A <= dif)
			cout << "Not lying" << endl;
		else
			cout << "Lying" << endl;
	}
}
