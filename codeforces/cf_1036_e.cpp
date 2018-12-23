#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a1, b1, a2, b2;

 
ll gcd(ll a, ll b){
    return b==0?a:gcd(b, a%b);
}

#define Max(a,b) a>b?a:b
#define Min(a,b) a>b?b:a
#define mem(a,b) memset(a,b,sizeof(a))
int dir[4][2]= {{0,-1},{-1,0},{0,1},{1,0}};
#define N 105
const double eps = 1e-6;
const double Pi = acos(-1.0);
struct Point
{
    Point() {}
    Point(double x,double y):x(x),y(y) {}
    double x,y;
};
 
struct Seg
{
    Point p1,p2;
};
 
int sgn(double x)
{
    return x<-eps ? -1 : (x>eps);
}
 
double Cross(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{
    return (p2.x-p1.x)*(p4.y-p3.y) - (p2.y-p1.y)*(p4.x-p3.x);
}
 
double Area(const Point& p1,const Point& p2,const Point& p3)
{
    return Cross(p1,p2,p1,p3);
}
 
double fArea(const Point& p1,const Point& p2,const Point& p3)
{
    return fabs(Area(p1,p2,p3));
}
 
bool Meet(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{
    return max(min(p1.x,p2.x),min(p3.x,p4.x)) <= min(max(p1.x,p2.x),max(p3.x,p4.x))
           && max(min(p1.y,p2.y),min(p3.y,p4.y)) <= min(max(p1.y,p2.y),max(p3.y,p4.y))
           && sgn(Cross(p3,p2,p3,p4) * Cross(p3,p4,p3,p1)) >= 0
           && sgn(Cross(p1,p4,p1,p2) * Cross(p1,p2,p1,p3)) >= 0;
}
 
Point Inter(const Point& p1,const Point& p2,const Point& p3,const Point& p4)
{
    double k = fArea(p1,p2,p3) / fArea(p1,p2,p4);
    return Point((p3.x + k*p4.x)/(1+k),(p3.y + k*p4.y)/(1+k));
}
int get_line_intersection(double p0_x, double p0_y, double p1_x, double p1_y, 
    double p2_x, double p2_y, double p3_x, double p3_y, double *i_x, double *i_y)
{
    double s02_x, s02_y, s10_x, s10_y, s32_x, s32_y, s_numer, t_numer, denom, t;
    s10_x = p1_x - p0_x;
    s10_y = p1_y - p0_y;
    s32_x = p3_x - p2_x;
    s32_y = p3_y - p2_y;

    denom = s10_x * s32_y - s32_x * s10_y;
    if (denom == 0)//平行或共线
        return 0; // Collinear
    bool denomPositive = denom > 0;

    s02_x = p0_x - p2_x;
    s02_y = p0_y - p2_y;
    s_numer = s10_x * s02_y - s10_y * s02_x;
    if ((s_numer < 0) == denomPositive)//参数是大于等于0且小于等于1的，分子分母必须同号且分子小于等于分母
        return 0; // No collision

    t_numer = s32_x * s02_y - s32_y * s02_x;
    if ((t_numer < 0) == denomPositive)
        return 0; // No collision

    if (((s_numer > denom) == denomPositive) || ((t_numer > denom) == denomPositive))
        return 0; // No collision
    // Collision detected
    t = t_numer / denom;
    if (i_x != NULL)
        *i_x = p0_x + (t * s10_x);
    if (i_y != NULL)
        *i_y = p0_y + (t * s10_y);

    return 1;
} 

bool judge(double n)
{
  if(n >= 0)
  if( (n-(int)n) < 1e-15 || (n-(int)n) < -0.999999999999999 )
	//单精度对应1e-6和6个9，双精度对应1e-15和15个9
    return true;
	else
    return false;
  
  else
	if( -(n-(int)n) < 1e-15 || -(n-(int)n) < -0.999999999999999 )
    return true;
	else
    return false;
}
 
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    while(cin >> n)
    {
      long long sum = 0;
      vector<Point> v1,v2;
      for(int i = 0;i < n;i ++)
      {
        long long a1,b1,a2,b2;
        cin >> a1 >> b1 >> a2 >> b2;
        ll f1 = abs(a1-a2);
        ll f2 = abs(b1-b2);
        ll g = gcd(f1, f2);
        v1.push_back({1.0 * a1,1.0 * b1});
        v2.push_back({1.0 * a2,1.0 * b2});
        sum += g + 1;
      }
      set<pair<long long,long long> > s;
      for(int i = 0;i < n;i ++)
      {
        for(int j = i + 1;j < n;j ++)
        {
          // Point temp = Inter(v1[i],v2[i],v1[j],v2[j]);
          Point temp;
          get_line_intersection(v1[i].x,v1[i].y,v2[i].x,v2[i].y,v1[j].x,v1[j].y,v2[j].x,v2[j].y,&temp.x,&temp.y);
          if(judge(temp.x) && judge(temp.y))
            s.insert(make_pair((long long)temp.x,(long long)temp.y));
        }
      }
      cout << sum - s.size() << endl;
    }
    return 0;
}