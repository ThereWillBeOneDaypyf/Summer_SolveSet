#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int a[1000];
int b[1000];

int solve1(string s)
{
	int ans = 0;
	for(int i = 0;i < s.length();i++)
		a[i] = s[i] - '0';
	a[0] = !a[0],a[1]=!a[1];
	ans ++;
	for(int i  = 1 ;i< s.length();i++)
	{
		if(a[i-1]==1)
			a[i-1] = !a[i-1],a[i] = !a[i] ,a[i+1]= !a[i+1],ans++;
	}
	for(int i =0;i<s.length();i++)
		if(a[i] == 1)
			return -1;
	return ans;
}
int solve2(string s)
{
	int ans = 0;
	for(int i = 0;i < s.length();i++)
		a[i] = s[i] - '0';
	for(int i  = 1 ;i< s.length();i++)
	{
		if(a[i-1]==1)
			a[i-1] = !a[i-1],a[i] = !a[i] ,a[i+1]= !a[i+1],ans++;
	}
	for(int i =0;i<s.length();i++)
		if(a[i] == 1)
			return -1;
	return ans;
}
int main()
{
	string s;
	while(cin >> s)
	{
		int ans1 = solve1(s);
		int ans2 = solve2(s);
		if(ans1 == -1 && ans2 == -1)
			cout << "NO" << endl;
		else if(ans1 == -1 || ans2 == -1)
			cout << max(ans1,ans2) << endl;
		else
			cout << min(ans1,ans2) << endl;
	}
}
