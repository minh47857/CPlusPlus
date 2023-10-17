#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("kite.inp" , "r" , stdin);
	freopen("kite.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N] , bit[N];
vector<int> Q;
map<int , int> pos;

void update(int u) {
	for( ; u >= 1 ; u -= (u & (-u)))
		bit[u]++;
}

int get(int u) {
	int res = 0;
	for( ; u <= n ; u += (u & (-u)))
		res += bit[u];
	return res;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i] , Q.pb(a[i]);
	sort(Q.begin() , Q.end());
	for(int i = 0 ; i < Q.size() ; i++) 
		pos[Q[i]] = i + 1;
	for(int i = 1 ; i <= n ; i++) {
		update(pos[a[i]]);
		cout << get(pos[a[i]] + 1) + 1 << '\n';
	}
	return 0;
}


