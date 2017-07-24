#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e6 + 7;

double a[N];
const double PI = 3.1415926535;
void f()
{
	for(int i = 1;i<=1e6;i++)
	{
		a[i] = a[i-1] + (double) (1.0 / i / i);
	}
}
long long get_s(string s)
{
	long long sum = 0;
	long long base = 1;
	for(int i = s.length() - 1;i>=0;i--)
		sum += base * (s[i] - '0'), base *= 10;	
	return sum;
}
int main()
{
	string s;
	f();
	while(cin >> s)
	{
		if(s.length() >= 7)
		{
			printf("%.5lf",a[1000000]);
		}
		else
		{
			long long n = get_s(s);
			printf("%.5lf",a[n]);
		}
		printf("\n");
	}
}
