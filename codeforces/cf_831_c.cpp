#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

const int N = 1e5;

int n,k;
int a[N];
int b[N];
int pre_sum[N];
int main()
{
	while(cin >> k >> n)
	{
		memset(pre_sum,0,sizeof(pre_sum));
		for(int i = 1 ;i<=k;i++)
			cin >> a[i];
		for(int j = 1 ;j<=n;j++)
			cin >> b[j];
		for(int i = 1;i<=k;i++)
			pre_sum[i] = pre_sum[i-1] + a[i];
		set<int>s;
		for(int i = 1;i<=k;i++)
		{
			s.insert(b[1] -pre_sum[i]);
		}
		for(int i = 2;i<=n;i++)
		{
			set<int>temp;
			set<int>ans;
			for(int j = 1;j<=k;j++)
				temp.insert(b[i] - pre_sum[j]);
			set<int> :: iterator it;
			for(it = s.begin();it != s.end();it++)
			{
				if(temp.count(*it))
					ans.insert(*it);
			}
			s = ans;
		}
		cout << s.size() << endl;
	}
}

