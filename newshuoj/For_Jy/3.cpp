#include<bits/stdc++.h>
using namespace std;

double a, b, c, d;
inline double sol(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
double query(double l, double r, bool f)
{
	double mid;
	while (l + 0.0001 < r)
	{
		mid = (l + r) / 2;
		bool b = sol(mid) > 0;
		if (f ? (!b) : b)r = mid;
		else l = mid;
	}
	return mid;
}
int main()
{

	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	if (a > 0)
	{
		double i;
		for (i = -100; i <= 100 && sol(i) < 0; i++);
		i += 0.00001; //精度问题 得加这一句 不然判断时可能sol(i)<0==1或==0
		printf("%.2lf ", query(i - 1, i, false)); //up
		for (; i <= 100 && sol(i) >= 0; i++);
		i += 0.00001;
		printf("%.2lf ", query(i - 1, i, true)); //down
		for (; i <= 100 && sol(i) < 0; i++);
		i += 0.00001;
		printf("%.2lf\n", query(i - 1, i, false)); //up
	}
	else
	{
		double i;
		for (i = -100; i <= 100 && sol(i) >= 0; i++);
		i += 0.00001;
		printf("%.2lf ", query(i - 1, i, true)); //down
		for (; i <= 100 && sol(i) < 0; i++);
		i += 0.00001;
		printf("%.2lf ", query(i - 1, i, false)); //up
		for (; i <= 100 && sol(i) >= 0; i++);
		i += 0.00001;
		printf("%.2lf\n", query(i - 1, i, true)); //down
	}

}