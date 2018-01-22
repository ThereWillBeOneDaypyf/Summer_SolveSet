#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
struct point{  
    int x,y;  
}A[10010],result[10010];  
int dist(point a,point b){  
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);  
}  
int cp(point p1,point p2,point p3){  
    return (p3.x-p1.x)*(p2.y-p1.y)-(p3.y-p1.y)*(p2.x-p1.x);  
}  
bool cmp(point a,point b){  
    int ans=cp(A[0],a,b);  
    if(ans==0)  
        return dist(A[0],a)-dist(A[0],b)<=0;  
    else   
        return ans>0;  
}  
int main()  
{  
    int n,i,j;  
    while(scanf("%d",&n)!=EOF){  
        int pos=0;  
        for(i=0;i<n;++i){  
            scanf("%d%d",&A[i].x,&A[i].y);  
            if(A[pos].y>=A[i].y){  
                if(A[pos].y==A[i].y){  
                    if(A[pos].x>A[i].x)pos=i;  
                }  
                else pos=i;  
            }  
        }  
        if(n<3){  
            printf("0\n");  
            continue;  
        }  
        point temp;int top=1;  
        temp=A[0];A[0]=A[pos];A[pos]=temp;  
        sort(A+1,A+n,cmp);  
        result[0]=A[0];result[1]=A[1];  
        for(i=2;i<n;++i){  
            while(cp(result[top-1],result[top],A[i])<0)top--;  
            result[++top]=A[i];  
        }  
        double s=0;  
        for(i=0;i<=top;++i){  
            double area=(result[(i+1)%(top+1)].x*result[i].y-result[(i+1)%(top+1)].y*result[i].x)/2.0;  
            s+=area;  
        }  
        printf("%.1lf\n",s);  
    }  
    return 0;  
}  