#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> in_queue;
	deque<int> q;
	int n, k;
	while(cin >> n >> k) 
	{
		in_queue.clear();
		q.clear();
		for(int i = 0;i < n; i ++)
		{
			int id;
			cin >> id;
			if(in_queue.size() == k)
			{
				if(in_queue.find(id) != in_queue.end())
					continue;
				else 
				{
					auto back_id = q.back();
					q.pop_back();
					in_queue.erase(in_queue.find(back_id));
					in_queue.insert(id);
					q.push_front(id);
				}
			}
			else 
			{
				if(in_queue.find(id) != in_queue.end())
					continue;
				in_queue.insert(id);
				q.push_front(id);
			}
		}
		cout << q.size() << endl;
		for(int i = 0; i < q.size(); i ++)
		{
			if(i)
				cout << " ";
			cout << q.at(i);
		}
		cout << endl;
	}
}
