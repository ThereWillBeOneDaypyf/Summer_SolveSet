#include<bits/stdc++.h>
using namespace std;

//thanks to pyf ...
//thanks to qhl ...

char x[4] = {'^', '>', 'v', '<'};
int main()
{
	char a, b;
	while (cin >> a >> b)
	{
		int s, e;
		int n;
		cin >> n;
		for (s = 0; s < 4; s++)
			if (x[s] == a)
				break;
		for (e = 0; e < 4; e++)
			if (x[e] == b)
				break;
		int flag1 = 0, flag2 = 0;
		if ((s + n) % 4 == e)
			flag1 = 1;
		if (((s - n) % 4 + 4) % 4 == e)
			flag2 = 1;
		if ((flag1 && flag2) || (!flag1 && !flag2))
			cout << "undefined" << endl;
		else if (flag1)
			cout << "cw" << endl;
		else
			cout << "ccw" << endl;
	}
}