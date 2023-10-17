#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("cover.inp" , "r" , stdin);
	freopen("cover.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , a , b , r , ans , d[N];

int main() {
	file();
	cin >> n >> a >> b;
	for(int i = 1 , l , r ; i <= n ; i++) 
		cin >> l >> r , d[l] = max(d[l] , r);
	for(int i = 1 ; i <= b ; i++) d[i] = max(d[i] , d[i - 1]);
	r = a;
	if(a == b) {
		cout << ((d[a] >= b) ? 1 : -1);
		return 0;
	}
	while(r < b) {
		if(d[r] <= r) {
			cout << -1;
			return 0;
		}
		r = d[r];
		ans++;
	}
	cout << ans;
	return 0;
}

