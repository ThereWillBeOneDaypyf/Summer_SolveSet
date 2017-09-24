#include<bits/stdc++.h>
using namespace std;

map<char,int>pos;

int Exit[16];
string vis[16];

void init()
{
	pos['1'] = 1,pos['0'] = 0,pos['2'] = 2,pos['3'] = 3;
	pos['4'] = 4,pos['5'] = 5,pos['6'] = 6,pos['7'] = 7;
	pos['8'] = 8,pos['9'] = 9,pos['A'] = 10,pos['B'] = 11;
	pos['C'] = 12,pos['D'] = 13,pos['E'] = 14,pos['F'] = 15;
}
bool judge(string s,int id)
{
	for(int i = 0;i<s.size() - 1;i++)
		if(vis[id][i] != s[i])
			return false;
	return true;
}
int main()
{
	init();
	string add;
	int hit = 0,miss = 0;
	memset(Exit,0,sizeof(Exit));
	while(cin >> add)
	{
		if(add == "END")
			break;
		int id = pos[add[5]];
		if(Exit[id])
		{
			if(judge(add,id))
			{
				cout << "Hit" << endl;
				hit ++;
			}
			else
			{
				cout << "Miss" << endl;
				miss++;
			}
		}
		else
		{
			miss++;
			cout << "Miss" << endl;
		}
		vis[id].clear();
		for(int i = 0;i<add.size() - 1;i++)
				vis[id] += add[i];
		Exit[id] = 1;
	}
	double ans = 1.0 * hit * 100 / (miss + hit);
	cout << "Hit ratio = " << fixed << setprecision(2) << ans << "%" << endl;
}
