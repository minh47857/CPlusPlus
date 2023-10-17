#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("CLIMBE.inp" , "r" , stdin);
	freopen("CLIMBE.ans" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , l = 0 , r = 0;
pi a[N];

bool cmp(pi a , pi b) {
	return a.fi + max(a.se , b.fi) + b.se < b.fi + max(b.se , a.fi) + a.se;
}

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].se;
	sort(a + 1 , a + n + 1 , cmp);
	for(int i = 1 ; i <= n ; i++) {
		l += a[i].fi;
		r = max(r , l) + a[i].se;
	}
	cout << r ;
	return 0;
}


