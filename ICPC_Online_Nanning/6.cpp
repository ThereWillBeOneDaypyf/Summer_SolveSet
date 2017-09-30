#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3
const int MAX = 1e4 + 7;
#define LCH(i) ((i)<<1)
#define RCH(i) ((i)<<1 | 1)

struct segment //保存矩形上下边界
{
	long long l,r,h; //左右横坐标，纵坐标
	int f; //-1为下边界，1为上边界
}ss[2*MAX];
struct node //线段树节点
{
	int l,r;
	int cnt; //该节点被覆盖的情况
	int len; //该区间被覆盖的总长度
	int mid()
	{ return (l+r)>>1; }
}tt[2*MAX*4];
double pos[2*MAX];
int nums;

int cmp(struct segment a ,struct segment b)
{
	return a.h<b.h;
}

void build(int a, int b ,int rt)
{
	tt[rt].l=a; tt[rt].r=b; tt[rt].cnt=0; tt[rt].len=0;
	if(a==b) return ;
	int mid=tt[rt].mid();
	build(a,mid,LCH(rt));
	build(mid+1,b,RCH(rt));
}

int binary(int key ,int low, int high)
{
	while(low<=high)
	{
		int mid=(low+high)>>1;
		if(pos[mid] == key) return mid;
		else if(key < pos[mid]) high=mid-1;
		else                    low=mid+1;
	}
	return -1;
}

void get_len(int rt)
{
	if(tt[rt].cnt) //非0，已经被整段覆盖
		tt[rt].len = pos[tt[rt].r+1] - pos[tt[rt].l];
	else if(tt[rt].l == tt[rt].r) //已经不是一条线段
		tt[rt].len = 0;
	else //是一条线段但是又没有整段覆盖，那么只能从左右孩子的信息中获取
		tt[rt].len = tt[LCH(rt)].len + tt[RCH(rt)].len ;
}

void updata(int a, int b ,int val ,int rt)
{
	if(tt[rt].l==a && tt[rt].r==b) //目标区间
	{
		tt[rt].cnt += val; //更新这个区间被覆盖的情况
		get_len(rt);  //更新这个区间被覆盖的总长度
		return ;
	}
	int mid=tt[rt].mid();
	if(b<=mid) //只访问左孩子
		updata(a,b,val,LCH(rt));
	else if(a>mid) //只访问有孩子
		updata(a,b,val,RCH(rt));
	else //左右都要访问
	{
		updata(a,mid,val,LCH(rt));
		updata(mid+1,b,val,RCH(rt));
	}
	get_len(rt); //计算该区间被覆盖的总长度
}

int main()
{
	int Case=0;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
		{
			printf("*\n");
			break;
		}
		nums=0;
		for(int i=0; i<n; i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			ss[nums].l=x1;  ss[nums].r=x2; ss[nums].h=y1; ss[nums].f=1;
			//记录上边界的信息
			ss[nums+1].l=x1; ss[nums+1].r=x2; ss[nums+1].h=y2; ss[nums+1].f=-1;
			//记录下边界的信息
			pos[nums]=x1; pos[nums+1]=x2;
			//记录横坐标
			nums += 2;

		}

		sort(ss,ss+nums,cmp); //横线按纵坐标升序排序
		sort(pos,pos+nums); //横坐标升序排序
		//for(int i=0; i<nums; i++) printf("%.2lf %.2lf  %.2lf\n",ss[i].l,ss[i].r,ss[i].h);
		int m=1;
		for(int i=1; i<nums; i++)
			if(pos[i]!=pos[i-1]) //去重
				pos[m++]=pos[i];

		build(0,m-1,1);  //离散化后的区间就是[0,m-1]，以此建树
		long long ans=0;
		for(int i=0; i<nums; i++) //拿出每条横线并且更新
		{
			int l=binary(ss[i].l,0,m-1);
			int r=binary(ss[i].r,0,m-1)-1;
			updata(l,r,ss[i].f,1); //用这条线段去更新
			ans += 1LL * (ss[i+1].h-ss[i].h)*tt[1].len;
			//printf("%.2lf\n",ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
