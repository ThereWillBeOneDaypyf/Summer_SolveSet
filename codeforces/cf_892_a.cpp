#include<iostream>
using namespace std;
int Fun(int);
int main()
{
	int n, res;
	cout << "input a number:" << endl;
	cin >> n;
	res = Fun(n);
	cout << "There are " << res << " cases." << endl;
	return 0;
}
int Fun(int n)
{
	if (n == 1)  return 0;
	if (n == 2)  return 1;
	return (n - 1) * (Fun(n - 1) + Fun(n - 2));
}