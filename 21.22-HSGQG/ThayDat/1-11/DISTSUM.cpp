#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , x[N] , y[N] , ans;

ll solve(ll a[]) {
	ll res = 0;
	for(int i = 1 ; i < n ; i++) res = res + (a[i + 1] - a[i]) * i * (n - i);
	return res;
}

int main() {
	file();
        cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> x[i] >> y[i];
		sort(x + 1 , x + n + 1);
		sort(y + 1 , y + n + 1);
		ans = solve(x) + solve(y);
		cout << ans;
		return 0;
}

