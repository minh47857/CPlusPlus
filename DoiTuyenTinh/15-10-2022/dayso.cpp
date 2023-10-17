#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("dayso.inp" , "r" , stdin);
	freopen("dayso.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , l , x , y;

int main() {
	file();
	cin >> n;
	n *= 2;
	l = sqrt(n);
	l -= l % 2;
	for(int i = l ; i >= 2 ; i--) if(n % i == 0) {
		if(abs(n / i - i) % 2 == 0) continue;
		x = (n / i - i + 1) / 2;
		y = (i + n / i - 1) / 2;
		cout << n / 2 << "=" << x << "+...+" << y;
		return 0;
	}
	cout << n / 2 << "=" << n / 2;
	return 0;
}

