#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("dongdang.inp" , "r" , stdin);
	freopen("dongdang.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll a , b , c , d , g1 , g2;

int main() {
	file();
	cin >> a >> b >> c >> d;
	g1 = __gcd(a , b) , g2 = __gcd(c , d);
	a /= g1 , b /= g1;
	c /= g2 , d /= g2;
	if((a == c && b == d) || (a == d && b == c)) cout << "YES";
	else cout << "NO";
	return 0;
}

