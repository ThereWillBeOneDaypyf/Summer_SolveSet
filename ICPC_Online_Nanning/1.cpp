#include<bits/stdc++.h>
using namespace std;

double Map[5][5];
vector<int>s1;
vector<int>s2;
int main()
{
	for(int i = 1;i<=4;i++)
		for(int j = 1;j<=4;j++)
			scanf("%lf",&Map[i][j]);
	char op;
	int x;
	while(scanf("%d%c",&x,&op) == 2)
	{
		s1.push_back(x);
		if(op == '\n')
			break;
	}
	while(scanf("%d%c",&x,&op) == 2)
	{
		s2.push_back(x);
		if(op == '\n')
			break;
	}
	double ans1 = 1;
	for(int i =1;i<s1.size();i++)
		ans1 *= Map[s1[i-1]][s1[i]];
	double ans2 = 1;
	for(int i =1;i<s2.size();i++)
		ans2 *= Map[s2[i-1]][s2[i]];
	double ans3 = 0,ans4 = 0;
	double a,b;
	scanf("%lf%lf",&a,&b);
	a = Map[(int)a][(int)a];
	b = Map[(int)b][(int)b];
	double temp = 1;
	for(int i = 1;i<=200;i++)
	{
		ans3 += (i *(1-a))*temp;
		temp *= a;
	}
	temp = 1;
	for(int i = 1;i<=200;i++)
	{
		ans4 += (i*(1-b))*temp;
		temp *= b;
	}
	printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n",ans1,ans2,ans3,ans4);
}
