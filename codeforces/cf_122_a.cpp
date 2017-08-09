#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int f[1000];
int cnt = 0;
bool judge(int x)
{
	while(x)
	{
		int temp = x % 10;
		if(temp != 7 && temp != 4)
			return false;
		x /= 10;
	}
	return true;
}
void get()
{
	for(int i = 1;i<=1000;i++)
	{
		if(judge(i))
			f[cnt++] = i;
	}
}

int main()
{
	int n;
	get();
	while(cin >> n)
	{
		int flag = 0 ;
		for(int i = 0;i<cnt;i++)
			if(n % f[i] == 0)
			{
				flag = 1;
				break;
			}
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
