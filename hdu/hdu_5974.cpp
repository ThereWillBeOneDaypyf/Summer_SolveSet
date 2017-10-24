#include<bits/stdc++.h>
using namespace std;

const int N = 2e4+7;

using ll = long long;
int main()
{
	// char no[] = "No Solution";
	string no = "No Solution";
	ll a, b, x, y;
	while(cin >> a >> b) {
		ll g = __gcd(a, b);
		ll ac = b * g;
		ll delta = (a * a - 4 * ac);	
		if (delta < 0) {
			cout << no << '\n';
			continue;
		}
		ll q;
		if ((q = sqrt(delta)) * sqrt(delta) != delta) {
			cout << no << '\n';
			continue;
		}
		ll y1, y2;
		y1 = a + q;
		y2 = a - q;
		if (y1 & 1 || y2 & 1) {
			cout << no << '\n';
			continue;
		}
		ll x = min(y1, y2);	
		ll y = max(y1, y2);
		cout << x / 2LL << ' ' << y / 2LL << '\n';
	}
}
