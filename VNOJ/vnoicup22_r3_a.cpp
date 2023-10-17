#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , q;

bool inside(int x , int y) {
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int main() {
	file();
	cin >> n >> q;
	while(q--) {
		int i , j , x , y , s , t , p1;
		pi res1 , res2;
		cin >> i >> j >> x >> y;
		s = abs(x - i);
		t = abs(y - j);
		if(i == x && j == y) cout << 0 << '\n';
		else if(s == t) cout << 1 << '\n' << x << ' ' << y << '\n';
		else if((s + t) % 2) cout << -1 << '\n';
		else {
			cout << 2 << '\n';
			p1 = (s + t) / 2;
			if(x > i) res1.fi = x - p1 , res2.fi = i + p1;
			else res1.fi = x + p1 , res2.fi = i - p1;
			if(y > j) res1.se = y - p1 , res2.se = j + p1;
			else res1.se = y + p1 , res2.se = j - p1;
			if(inside(res1.fi , res1.se)) cout << res1.fi << ' ' << res1.se;
			else cout << res2.fi << ' ' << res2.se;
			cout << '\n' << x << ' ' << y << '\n';
		}
	}
}
