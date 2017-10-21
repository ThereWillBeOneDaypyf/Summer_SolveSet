#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

struct Node
{
	int l,r;
}a[4][2];
int pos[3] = {0,1,2};
int main()
{
	ios :: sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		for(int i = 0;i<4;i++)
		{
			int l,r;
			cin >> l >> r;
			a[i][0].l = l,a[i][0].r = r;
			a[i][1].l = r,a[i][1].r = l;
		}
		int flag = 0;
		for(int i = 0;i<4;i++)
		{
			for(int j = 0;j<4;j++)
			{
				for(int k = 0;k<4;k++)
				{
					if(i != j && i != k && j != k)
					{
						for(int sta = 0;sta < 8;sta ++)
						{
							int temp_sta = sta;
							int sta1 = temp_sta % 2;
							temp_sta /= 2;
							int sta2 = temp_sta % 2;
							temp_sta /= 2;
							int sta3 = temp_sta;
							if(a[i][sta1].l == a[j][sta2].l && a[j][sta2].l == a[k][sta3].l)
								flag = 1;
							else if(a[i][sta1].l + a[j][sta2].l == a[k][sta3].l && a[i][sta1].r == a[j][sta2].r)
								flag = 1;
						}
					}
				}
			}
		}
		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
