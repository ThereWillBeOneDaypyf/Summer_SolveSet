#include<bits/stdc++.h>
using namespace std;

long long F[100];
int main()
{
	F[1] = 1;
	F[2] = 2;
	for (int i = 3; i <= 50; i++)
		F[i] = F[i - 1] + F[i - 2];
	int n;
	while (cin >> n)
		cout << F[n] << endl;
}