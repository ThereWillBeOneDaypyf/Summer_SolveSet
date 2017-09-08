#include<algorithm>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
vector<pair<double, double> > v;
vector<int>G[1000];
map<int, int>used_clr[1000];
int clr[1000];
int Max_clr = 0;
void init()
{
	v.clear();
	for (int i = 0; i < 1000; i++)
		G[i].clear(), used_clr[i].clear();
	memset(clr, 0, sizeof(clr));
}
double Get_Dis(pair<double, double>x, pair<double, double>y)
{
	return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
void Create_Graph()
{
	for (int i = 0; i < v.size() ; i ++)
	{
		for (int j = i + 1; j != v.size(); j++)
		{
			if (i == j)
				continue;
			if (Get_Dis(v[i], v[j]) <= 20.01)
			{
				G[i].push_back(j);
				G[j ].push_back(i);
			}
		}
	}
}
void Chage_Clr(int n)
{
	memset(clr, 0, sizeof(clr));
	Max_clr = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j != G[i].size(); j++)
			used_clr[i][clr[G[i][j]]] = 1;
		int flag = 0;
		for (int j = 1; j <= Max_clr; j++)
		{
			if (!used_clr[i].count(j))
			{
				clr[i] = j;
				flag = 1;
				break;
			}
		}
		if (!flag)
			clr[i] = ++Max_clr;
	}
}
int main()
{
	int n;
	int ka = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
			break;
		init();
		for (int i = 0; i < n; i++)
		{
			double x, y;
			scanf("%lf%lf", &x, &y);
			v.push_back(make_pair(x, y));
		}
		Create_Graph(), Chage_Clr(n);
		printf("The towers in case %d can be covered in %d frequencies.\n", ++ka, Max_clr);
	}
}