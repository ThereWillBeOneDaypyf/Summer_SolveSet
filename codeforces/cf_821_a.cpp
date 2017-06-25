#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...
int Map[55][55];
int n;
bool judge_ele(int row,int col)
{
	for(int i =0 ;i<n;i++)
	{
		for(int j = 0;j<n;j++)
		{
			if(i == row && j == col)
				continue;
			if(Map[row][j] + Map[i][col] == Map[row][col])
				return true;		
		}
	}
	return false;
}
bool judge()
{
	for(int i = 0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(Map[i][j]!=1)
			{
				if(!judge_ele(i,j))
					return false;
			}
		}
	}
	return true;
}
int main()
{
	while(cin >> n)
	{
		for(int i =0 ;i<n;i++)
			for(int j =0 ;j<n;j++)
				cin >> Map[i][j];
		if(judge())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
