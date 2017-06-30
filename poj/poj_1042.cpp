#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 1000;


struct Node
{
	int used,f;
	int id;
	bool operator < (const Node &rhs) const
	{
		return f < rhs.f || ( f == rhs.f && id > rhs.id);
	}
}a[N];

int f[N];
int d[N];
int t[N];
int pre_t[N];
int ans[N];
int temp_ans[N];
bool judge(int n)
{
	for(int i = 1;i<=n;i++)
	{
		if(ans[i] == temp_ans[i])
			continue;
		else
			return temp_ans[i] > ans[i];
	}
	return false;
}
int main()
{
	int n,h;
	while(cin >> n >> h)
	{
		int Max = 0;
		for(int i = 1;i<=n;i++)
			cin >> f[i];
		for(int i = 1;i<=n;i++)
			cin >> d[i];
		for(int i = 1;i<n;i++)
		{
			cin >> t[i];
		}
		for(int i = 2;i<=n;i++)
			pre_t[i] = pre_t[i-1] + t[i-1];
		for(int i = n;i>=1;i--)
		{
			int res = 0;
			priority_queue<Node>q;
			memset(temp_ans,0,sizeof(temp_ans));
			for(int j = 1;j<=i;j++)
			{
				a[j].id = j,a[j].used = 0,a[j].f = f[j];
				q.push(a[j]);
			}	
			int cur_h = 60 * h - pre_t[i] * 5;
			while(cur_h >= 5&&!q.empty())
			{
				Node temp = q.top();
				cur_h -= 5;
				q.pop();
				res += temp.f;
				temp.f -= d[temp.id];
				temp.used ++;
				temp_ans[temp.id] = temp.used;
				if(temp.f > 0)
					q.push(temp);
				cout << "*" << temp.id << " " << temp.f << " ";
			}
			if(cur_h >= 5)
				temp_ans[1] += cur_h / 5;
			if(res > Max)
			{
				Max = res;
				for(int i = 1;i<=n;i++)
					ans[i] = temp_ans[i];
			}
			else if(res == Max && judge(n))
			{
				for(int i = 1;i<=n;i++)
					ans[i] = temp_ans[i];
			}
			cout << endl;
		}
		for(int i =  1;i<=n;i++)
			i == 1 ? cout << ans[i] * 5 : cout << ", " << ans[i] * 5;
		cout << endl;
		cout << "Number of fish expected: " << Max << endl;
	}
}
