#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
#define Bit(x , k) ((x >> k) & 1)
using namespace std;

const int N = 1e6 + 5 , M = 1e6 , inf = 1e9 + 7;

void file() {
//	freopen("fc124_coprime.inp" , "r" , stdin);
//	freopen("fc124_coprime.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int q , n , p[N] , cnt[N];
vector<int> v[N];
ll ans;

void sieve() {
	for(int i = 2 ; i <= M ; i++) if(!p[i]) {
		v[i].pb(i);
		for(int j = i * 2 ; j <= M ; j += i) p[j] = 1 , v[j].pb(i);
	}
}

int main() {
	file();
	sieve();
	cin >> q;
	while(q--) {
		int t , x , tmp = 0 ; cin >> t >> x;
		if(t == 2) t = -1;
		for(int mask = 1 ; mask < (1 << int(v[x].size())) ; mask++) {
			int num = 1;
			for(int i = 0 ; i < v[x].size() ; i++) num *= ((Bit(mask , i)) ? v[x][i] : 1);
			if(__builtin_popcount(mask) % 2) tmp += cnt[num];
			else tmp -= cnt[num];
			cnt[num] += t;
		}
		
		ans += t * (n - tmp - (t == -1 && x == 1));
		n += t;
		cout << ans << '\n';
	}
	return 0;
}

