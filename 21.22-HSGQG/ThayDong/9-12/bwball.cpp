#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll , ll>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

ll m , n;
pi ans;

pi Reduce(pi a) {
	ll g = __gcd(abs(a.fi) , abs(a.se));
	return make_pair(a.fi / g , a.se / g);
}

pi Plus(pi a , pi b) {
	return Reduce({a.fi * b.se + b.fi * a.se , a.se * b.se});
}

pi Product(pi a , pi b) {
	return Reduce({a.fi * b.fi , a.se * b.se});
}

int main() {
	while(cin >> m >> n) {
		ans = {0 , 1};
		for(int i = 1 ; i <= m + 1 ; i++) {
		pi res = {5 * i * n , n + m + 1 - i};
		res = Reduce(res);
		if(i % 2) res.fi = -res.fi;
		for(int j = 0 ; j <= i - 2 ; j++)
			res = Product(res , {m - j , n + m - j});
		ans = Plus(ans , res);
	}
	cout << ans.fi << "/" << ans.se << '\n';
	}
//	cin >> m >> n;
	
	return 0;
}

