#include<bits/stdc++.h>
using namespace std;
int k;
vector<long long> getN(vector<long long> tar)
{
	map<long long,bool> vis;
	priority_queue<long long,vector<long long>,greater<long long> >q;	
	q.push(1);
	vector<long long> ans;
	while(!q.empty())
	{
		long long temp = q.top();
		q.pop();
		ans.push_back(temp);
		if(ans.size() >= 2e6)
			return ans;
		for(auto x : tar)
		{
			if(1e18 / x < temp)
				continue;
			long long cur = x * temp;
			if(cur > 1e18 || vis.count(cur))
				continue;
			vis[cur] = 1;
			q.push(cur);
		}
	}
	return ans;
}
long long getCnt(long long tar,vector<long long> v1,vector<long long> v2)
{
	long long cnt = 0;
	int p = v2.size() - 1;
	for(int i = 0;i < v1.size();i++)
	{
		while(p >= 0 && tar / v1[i] < v2[p])
			p --;
		cnt += 1LL * (p + 1);
	}
	return cnt;
}
int main()
{
	int n;
	while(cin >> n)
	{
		vector<long long> v1,v2;
		vector<long long> v;
		for(int i = 0;i < n;i++)
		{
			long long x;
			cin >> x;
			v.push_back(x);
		}
		for(int i = 0;i < n;i+=2)
			v1.push_back(v[i]);
		for(int i = 1;i < n;i+=2)
			v2.push_back(v[i]);
		cin >> k;
		v1 = getN(v1);
		v2 = getN(v2);
		//for(auto temp : v1)
		//	cout << temp << " ";
		//cout << endl;
		//for(auto temp : v2)
		//	cout << temp << " ";
		//cout << endl;
		long long l = 0,r = 1e18;
		long long ans = 0;
		while(l <= r)
		{
			long long mid = (l + r) / 2;
			long long tempres = getCnt(mid,v1,v2);
			if(tempres < k)
				l = mid + 1;
			else if(tempres == k)
			{
				ans = mid;
				r = mid - 1;
			}
			else r = mid - 1;
		}
		cout << ans << endl;
	}
}
