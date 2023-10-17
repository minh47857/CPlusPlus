#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 3e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("mickey.inp" , "r" , stdin);
	freopen("mickey.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node {
	int u , v , h;
	bool operator > (const node&s) const {return h > s.h;}
};

int n , x , y , MaxH , f[N];
vector<node> s;
vector<pi> adj[N];

bool In(int u , int x1 , int x2) {
	if(min(x1 , x2) > u || max(x1 , x2) < u) return false;
	return true;
}

int dis(node a , node b) {
	if(a.h - b.h > MaxH || a.h == b.h || (!In(a.u , b.u , b.v) && !In(a.u , b.u , b.v))) return -1;
	int res = inf;
	if(b.h == 0) return a.h;
	if(In(a.u , b.u , b.v)) res = min(res , a.h - b.h + abs(a.u - b.u));
	if(In(a.v , b.u , b.v)) res = min(res , a.h - b.h + abs(a.v - b.u) + abs(a.v - a.u));
	return res;
}

int Dfs(int u) {
	cout << "PATH " << u << '\n';
	if(u == s.size() - 1) {
		f[u] = 0;
		return 0;
	}
	if(f[u] != -1) return f[u];
	int res = inf;
	for(auto x : adj[u]) 
		res = min(res , Dfs(x.fi) + x.se);
//	cout << u << ' ' << res << '\n';
cout << "RES " << u << ' ' << res << '\n';
	f[u] = res;
	return res;
}

void solve() {
	s.clear();
	cin >> n >> x >> y >> MaxH;
	s.pb({x , x , y});
	for(int i = 1 , u1 , u2 , y; i <= n ; i++) {
		cin >> u1 >> u2 >> y;
		s.pb({u1 , u2 , y});
		s.pb({u2 , u1 , y});
	}
	for(int i = 0 ; i < s.size() ; i++) adj[i].clear();
	s.pb({-inf , inf , 0});
	sort(s.begin() , s.end() , greater<node>());
	//for(auto x : s) cout << "in" << ' ' << x.u << ' ' << x.v << ' ' << x.h << '\n';
	for(int i = 0 ; i < s.size() ; i++) 
	 for(int j = i + 1 ; j < s.size() ; j++) {
			int D = dis(s[i] , s[j]);
			if(D != -1) {
				cout << i << ' ' << j << ' ' << D << '\n';
				adj[i].pb({j , D});
				if(j == s.size() - 1 || s[j].h != s[j + 1].h) break;
			}
	 }
	 cout << s.size() << '\n';
	memset(f , -1 , sizeof(f));
	cout << Dfs(0) << '\n';
	int u = 0;
	while(u != s.size() - 1) {
		cout << u << ' ';
		for(auto x : adj[u]) {
			if(f[u] == f[x.fi] + x.se) {
				u = x.fi;
				break;
			}
		}
	}
	//cout << Dfs(0) << '\n';
}

int main() {
	file();
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}



