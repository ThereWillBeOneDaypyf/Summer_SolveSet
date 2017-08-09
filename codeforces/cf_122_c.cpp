#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...


vector<long long>tar;
void f()
{
	queue<long long>q;
	q.push(0);
	while(!q.empty())
	{
		long long temp = q.front();
		q.pop();
		tar.push_back(temp);
		if(temp > 1e11)
			continue;
		q.push(temp * 10 + 4),q.push(temp*10 + 7);
	}
	sort(tar.begin(),tar.end());
}
int search_r(long long x)
{
	int ans = 0;
	int l = 0,r = tar.size() -1,mid;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(tar[mid] >= x)
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	return ans;
}
int search_l(long long x)
{
	int ans = tar.size() -1;
	int l = 0,r = tar.size() - 1,mid;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(tar[mid] <= x)
		{
			ans = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ans;
}
int main()
{
	long long l,r;
	f();
	while(cin >> l >> r)
	{
		long long ans = 0;
		int l_r = search_r(l);
		if(tar[l_r] >= r)
		{
			ans += (r - l + 1) * tar[l_r];
			cout << ans << endl;
			continue;
		}
		ans += 1LL * (tar[l_r] - l + 1) * tar[l_r];
		int r_l = search_l(r),r_r = search_r(r);
		ans += 1LL * (r - tar[r_l]) * tar[r_r];
		for(int i = l_r;i < r_l ;i++)
			ans += 1LL * (tar[i+1] - tar[i]) * tar[i+1];
		cout << ans << endl;
	}
}
