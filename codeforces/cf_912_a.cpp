#include<bits/stdc++.h>
using namespace std;

int pos[3] = {0, 1, 2};
long long a[3];
int main()
{
	long long aa, bb;
	while (cin >> aa >> bb)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> a[i];
			pos[i] = i;
		}
		long long need = 1e18;
		//do
		{
			long long tempa = 2 * a[pos[0]] + a[pos[1]];
			long long tempb = 3 * a[pos[2]] + a[pos[1]];
			long long sum = max(0LL , tempa - aa) + max(0LL, tempb - bb);
			need = min(need, sum);
		}
		//while (next_permutation(pos, pos + 3));
		cout << need << endl;
	}
}