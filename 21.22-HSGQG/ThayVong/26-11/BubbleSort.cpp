#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("BubbleSort.inp" , "r" , stdin);
	freopen("BubbleSort.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n , m , bit[N] , a[N] , ans;

void update(int u) {
	for(int i = u ; i <= m ; i += (i & (-i))) bit[i]++;
}

int get(int u) {
	int res = 0;
	for(int i = u ; i >= 1 ; i -= (i & (-i))) res += bit[i];
	return res;
}

void solve() {
	cin >> n;
	vector<int> S;
	memset(bit , 0 , sizeof(bit));
	map<int , int> pos;
	ans = 0;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , S.pb(-a[i]);
	sort(S.begin() , S.end());
	S.erase(unique(S.begin() , S.end()) , S.end());
	m = S.size();
	for(int i = 0 ; i < S.size() ; i++) pos[-S[i]] = i + 1;
	for(int i = 1 ; i <= n ; i++) {
		update(pos[a[i]]);
		ans = max(ans , get(pos[a[i]] - 1));
	}
	cout << ans << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
}


