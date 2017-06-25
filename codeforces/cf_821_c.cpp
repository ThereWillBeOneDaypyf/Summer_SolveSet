#include<bits/stdc++.h>
#include<stack>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

int main()
{
	int n;
	while(cin >> n )
	{
		set<int>s;
		stack<int>st;
		int ans = 0;
		int flag = 1;
		int cur_size = 0;
		int cur=1;
		for(int i =0;i<2*n;i++)
		{
			string str;
			cin >> str;
			if(str[0] == 'a')
			{
				int x;
				cin >> x;
				st.push(x);
			}
			else if(!st.empty())
			{
				if(st.top() == cur)
					st.pop();
				else
				{
					ans ++;
					while(!st.empty())
						st.pop();
				}
				cur++;
			}
			else
				cur++;
		}
		cout << ans << endl;
	}
	return 0;
}
