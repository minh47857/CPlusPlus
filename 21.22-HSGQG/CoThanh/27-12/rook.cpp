#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 2e3 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7 , 
	  row[] = {0 , -1 , 1 , 0},
	  col[] = {1 , 0 , 0 , -1};

using namespace std;

void file() {
	freopen("rook.inp" , "r" , stdin);
	freopen("rook.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

struct rook {
	int u , v , t;
};

int q , m , n , k , d[N][N][3] , c[N][N];
pi s , t , a[N];
map<int , int> posx , posy;
vector<int> X , Y;
queue<rook> Q[1005];

void Bfs() {
	memset(d , -1 , sizeof(d));
	Q[1].push({s.fi , s.se , 0});
	Q[1].push({s.fi , s.se , 1});
	d[s.fi][s.se][0] = d[s.fi][s.se][1] = 1;
	for(int len = 1 ; len <= 1e3 ; len++) {
		while(Q[len].size()) {
			int u = Q[len].front().u , v = Q[len].front().v , t = Q[len].front().t;
			//cout << len << ' ' << u << ' ' << v << ' ' << t << '\n';
			Q[len].pop();
			for(int i = 0 ; i < 4 ; i++) {
				int nx = u + row[i] , ny = v + col[i] , val = 0 , nxt = t;
				if(nx < 1 || ny < 1 || nx > m || ny > n) continue;
			    if(t == 0) if(nx != u) val++ , nxt = 1 - t;
				if(t == 1) if(ny != v) val++ , nxt = 1 - t;
				if(c[nx][ny]) continue;
			//	cout << len << ' ' << u << ' ' << v << ' ' << t << ' ' << nx << ' ' << ny << ' ' << nxt << ' ' << val << '\n';
				if(d[nx][ny][nxt] == -1) 
					d[nx][ny][nxt] = len + val,
					Q[len + val].push({nx , ny , nxt});
			}
		}
	}
	if(max(d[t.fi][t.se][0] , d[t.fi][t.se][1])) cout << -1 << '\n';
	else cout << min(d[t.fi][t.se][0] , d[t.fi][t.se][1]) << '\n';
}

void solve() {
	X.clear() , Y.clear();
	posx.clear() , posy.clear();
	cin >> s.fi >> s.se >> t.fi >> t.se >> k;
	X.pb(s.fi) , X.pb(s.fi - 1) , X.pb(s.fi + 1);
	X.pb(t.fi) , X.pb(t.fi - 1) , X.pb(t.fi + 1);
	Y.pb(s.se) , Y.pb(s.se - 1) , Y.pb(s.se + 1);
	Y.pb(t.se) , Y.pb(t.se - 1) , Y.pb(t.se + 1);
	for(int i = 1 ; i <= k ; i++) 
		cin >> a[i].fi >> a[i].se , X.pb(a[i].fi) , Y.pb(a[i].se) , X.pb(a[i].fi - 1) , X.pb(a[i].fi + 1) , Y.pb(a[i].se - 1) , Y.pb(a[i].se + 1);
	sort(X.begin() , X.end());
	sort(Y.begin() , Y.end());
	X.erase(unique(X.begin() , X.end()) , X.end());
	Y.erase(unique(Y.begin() , Y.end()) , Y.end());
	m = X.size() , n = Y.size();
	for(int i = 0 ; i < X.size() ; i++) posx[X[i]] = i + 1 , cout << X[i] << ' ';
	cout << endl;
	for(int i = 0 ; i < Y.size() ; i++) posy[Y[i]] = i + 1 , cout << Y[i] << ' ';
	cout << endl;
	memset(c , 0 , sizeof(c));
	for(int i = 1 ; i <= k ; i++)
		c[posx[a[i].fi]][posy[a[i].se]] = 1;
	s = {posx[s.fi] , posy[s.se]};
	t = {posx[t.fi] , posy[t.se]};
	Bfs();
}

int main() {
	//file();
	cin >> q;
	while(q--) 
		solve();
	return 0;
}


