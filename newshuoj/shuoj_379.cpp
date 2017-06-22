#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

typedef long long LL; 

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
	LL x,y,m,n,l;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)==5)
	{
		LL ans = cal(m - n, l,y - x) ;
		if(ans == -1)
			printf("Impossible\n");
		else
			printf("%lld\n",ans);
	}
}
