#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 2e5 + 5 , MOD = 1e9 + 7;
const ll inf = 1e15;

using namespace std;

int n , a[N] , x;
ll bit[N] , l[N] , r[N] , ans = inf , sum;

void update(int u) {
	for(int i = u ; i <= n ; i += (i & (-i)))
		bit[i]++;
}

ll get(int u) {
	ll res = 0;
	for(int i = u ; i >= 1 ; i -= (i & (-i)))
		res += bit[i];
	return res;
}

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		l[a[i]] = get(n - a[i]);
		update(n - a[i] + 1);
		sum += l[a[i]];
	}
	memset(bit , 0 , sizeof(bit));
	for(int i = n ; i >= 1 ; i--) {
		r[a[i]] = get(a[i] - 1);
		update(a[i]);
	}
	for(int i = 1 ; i <= n ; i++) r[i] += r[i - 1];
	for(int i = n ; i >= 1 ; i--) l[i] += l[i + 1];
	for(int i = 1 ; i <= n ; i++) {
		ll tmp = l[i + 1] + r[i - 1];
		if(tmp < ans) {
			ans = tmp;
			x = i;
		}
	}
	cout << x << ' ' << sum - ans;
	return 0;
}

