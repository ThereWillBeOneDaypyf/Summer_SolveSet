#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

const int N = 105;

int n,m;
int Map[N][N];

void del_row(int row)
{
	for(int i = 0;i<m;i++)
		Map[row][i] --;
}
void del_col(int col)
{
	for(int i =0 ;i<n;i++)
		Map[i][col] --;
}
bool judge_row(int row)
{
	for(int i = 0;i<m;i++)
		if(!Map[row][i])
			return false;
	return true;
}
bool judge_col(int col)
{
	for(int i=0;i<n;i++)
		if(!Map[i][col])
			return false;
	return true;
}
int main()
{
	while(cin >> n >> m)
	{
		for(int i =0 ;i<n;i++)
		{
			for(int j =0 ;j<m;j++)
			{
				cin >> Map[i][j];
			}
		}
		int flag = 0;
		vector<pair<int,int> > ans;
		for(int i = 0 ; i< n ;i++)
		{
			for(int j = 0 ;j<m;j++)
			{
				if(Map[i][j])
				{
					if(n < m) // row first
					{
						while(judge_row(i))
						{
							del_row(i);
							ans.push_back(make_pair(0,i+1));
						}
						while(judge_col(j))
						{
							del_col(j);
							ans.push_back(make_pair(1,j+1));
						}
						if(Map[i][j])
							flag = 1;
					}
					else // col first
					{
						while(judge_col(j))
						{
							del_col(j);
							ans.push_back(make_pair(1,j+1));
						}
						while(judge_row(i))
						{
							del_row(i);
							ans.push_back(make_pair(0,i+1));
						}
						if(Map[i][j])
							flag =  1;
					}
				}
			}
		}
		if(flag)
			cout << -1 << endl;
		else
		{
			cout << ans.size() << endl;
			for(int i =0 ;i<ans.size();i++)
			{
				int tar = ans[i].first;
				int val = ans[i].second;
				if(tar == 0)
					cout << "row ";
				else
					cout << "col ";
				cout << val << endl;
			}
		}
	}
}
