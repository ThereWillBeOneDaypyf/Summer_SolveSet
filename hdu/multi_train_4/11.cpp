#include<bits/stdc++.h>
using namespace std;


//thanks to pyf ...
//thanks to qhl ...

char Map[10][30];
int	num[10][7] =  {
	{1,1,1,1,1,1,0}, 
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}};
int tar[7];
void get_num(int col)
{
	memset(tar,0,sizeof(tar));
	if(Map[0][col+1] == 'X')
		tar[0] = 1;
	if(Map[1][col] == 'X')
		tar[5] = 1;
	if(Map[1][col+3] == 'X')
		tar[1] = 1;
	if(Map[3][col+1] == 'X')
		tar[6] = 1;
	if(Map[4][col] == 'X')
		tar[4] = 1;
	if(Map[4][col+3] == 'X')
		tar[2] = 1;
	if(Map[6][col+1] == 'X')
		tar[3] = 1;
}
int judge()
{
	for(int i = 0 ;i<10;i++)
	{
		int j;
		for(j = 0;j<7;j++)
			if(tar[j] != num[i][j])
				break;
		if(j == 7)
			return i;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i = 0;i<7;i++)
			scanf("%s",Map[i]);
		get_num(0);			
		printf("%d",judge());
		get_num(5);
		printf("%d:",judge());
		get_num(12);
		printf("%d",judge());
		get_num(17);
		printf("%d\n",judge());
	}
}
