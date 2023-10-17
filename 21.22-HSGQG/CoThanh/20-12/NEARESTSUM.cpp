#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const ll N = 30 , MOD = 1e9 + 7 , inf = 1e17;

using namespace std;

void file() {
	freopen("NEARESTSUM.in" , "r" , stdin);
	freopen("NEARESTSUM.ok" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , Q , ans = inf , s = 0 , a[N];

void Gen(int t) {
	for(ll i = 0 ; i <= 1 ; i++) {
		s += i * a[t];
		if(t == n) 
			ans = min(ans , abs(Q - s));
		else Gen(t + 1);
		s -= i * a[t];
	}
}

int main() {
	file();
	cin >> n >> Q;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	Gen(1);
	cout << ans;
	return 0;
}



