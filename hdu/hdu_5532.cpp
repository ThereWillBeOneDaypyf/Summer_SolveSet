#include<bits/stdc++.h>
using namespace std;


vector<int>v;
vector<int> len;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		v.clear();
		for(int i = 0;i < n;i++)
		{
			int x;
			scanf("%d",&x);
			v.push_back(x);
		}
		len.clear();
		len.push_back(v[0]);
		for(int i = 1;i<v.size();i++)
		{
			if(*len.rbegin() <= v[i])
				len.push_back(v[i]);
			else
			{
				auto pos = upper_bound(len.begin(),len.end(),v[i]);
				if(pos != len.end())
				{
					int id = pos - len.begin();
					len[id] = v[i];
				}
			}
		}
		int cnt1 = len.size();
		len.clear();
		reverse(v.begin(),v.end());
		len.push_back(v[0]);
		for(int i = 1;i<v.size();i++)
		{
			if(*len.rbegin() <= v[i])
				len.push_back(v[i]);
			else
			{
				auto pos = upper_bound(len.begin(),len.end(),v[i]);
				if(pos != len.end())
				{
					int id = pos - len.begin();
					len[id] = v[i];
				}
			}
		}
		int cnt2 = len.size();
		int ans = max(cnt1,cnt2);
		int need = n - ans;
		if(need <= 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
