#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...


multiset<int>s1,s2;

int main()
{
	int n;
	while(scanf("%d",&n) == 1)
	{
		s1.clear();
		s2.clear();
		for(int i = 0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			s2.insert(x);
		}
		int temp = *(s2.begin());
		s1.insert(temp);
		s2.erase(s2.begin());
		for(multiset <int> :: iterator it2 = s2.begin();it2 != s2.end();it2++)
		{
			for(multiset<int> :: iterator it1 = s1.begin();it1 != s1.end(); it1 ++)
			{
				int val = *it1 + *it2;
				s2.erase(s2.find(val));
			}
			s1.insert(*it2);
		}
		printf("%d\n",s1.size());
		int cnt = 0;
		for(auto val : s1)
		{
			if(cnt)
				printf(" ");
			cnt ++;
			printf("%d",val);
		}
		printf("\n");
	}
}
