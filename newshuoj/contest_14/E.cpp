#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

bool judge(int a,int b,int c,int &x,int &y,int &z)
{
	for( x = 100; x >= 1  ; x--)
	{
		for(y = 100;y >=1 ;y--)
		{
			for(z = 99;z >= 3;z-=3)
			{
				if(a && b && c &&(x+y+z) == 100&&(a * x + b * y + z * c / 3 == 100))
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int a,b,c;
	int ka =0 ;
	while(cin >> a >> b >> c)
	{
		cout << "Case " << ++ka << ":" << endl;
		int x,y,z;
		if(judge(a,b,c,x,y,z))
			cout << x << " " << y << " " << z << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}
