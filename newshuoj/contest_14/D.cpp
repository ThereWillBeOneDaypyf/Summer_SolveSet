#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

typedef long long LL;  
typedef double DB;  

LL e_gcd(LL a,LL b,LL &x,LL &y)  
{  
	if(b==0)  
	{  
		x=1;  
		y=0;  
		return a;  
	}  
	LL ans=e_gcd(b,a%b,x,y);  
	LL temp=x;  
	x=y;  
	y=temp-a/b*y;  
	return ans;  
}  

LL cal(LL a,LL b,LL c)  
{  
	LL x,y;  
	LL gcd=e_gcd(a,b,x,y);  
	if(c%gcd!=0) return -1;  
	x*=c/gcd;  
	b/=gcd;  
	if(b<0) b=-b;  
	LL ans=x%b;  
	if(ans<=0) ans+=b;  
	return ans;  
}  
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long a,b,c;
		cin >> a >> b >> c;
		if(cal(a,b,c) == -1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}
