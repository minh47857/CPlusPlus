#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

const int N = 35 , M = 1e5 + 5 , inf = 1e9;

void file() {
    freopen("DOWRY.inp" , "r" , stdin);
	freopen("DOWRY.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , m , L , R , w[N] , v[N] , Log[M] , ans = 0 , Pos1 = 0, Pos;
pi P[M][25];
vector<ll> Q , H , Pos2;
map<ll , pi> f;

int count(int a) {
	return __builtin_popcount(a);
}

void Rmq() {
	Q.pb(0);
	sort(Q.begin() , Q.end());
	m = Q.size() - 1;
	Log[1] = 0;
	P[1][0] = {f[Q[1]].fi , 1};
	for(int i = 2 ; i <= m ; i++) Log[i] = Log[i / 2] + 1 , P[i][0] = {f[Q[i]].fi , i};
	//cout << m <<  "non" << Log[m] << '\n';
	for(int j = 1 ; j <= Log[m] ; j++)
	for(int i = 1 ; i <= m ; i++)
	 if(i + (1 << j) - 1 <= m)  P[i][j] = max(P[i][j - 1] , P[i + (1 << (j - 1))][j - 1]);// , cout << "id" << i << ' ' << j << ' ' << P[i][j] << '\n';
}

pi Get(int l , int r) {
	int len = Log[r - l + 1];
//	cout << len << ' '  << P[l][len] << ' ' << P[r - (1 << len) + 1][len] << endl;
	return max(P[l][len] , P[r - (1 << len) + 1][len]);
}

pi Max(pi a , pi b) {
	if(a.fi > b.fi) return a;
	if(a.fi == b.fi) return {a.fi , min(a.se , b.se)};
	return b;
}

void Gen(int t) {
	for(int i = 0 ; i <= 1 ; i++) {
        Pos += (i * (1 << t));
		if(t == n / 2) {
			ll s1 = 0 , s2 = 0;
			for(int j = 1 ; j <= n / 2 ; j++) if(Bit(Pos , j)) s1 += w[j] , s2 += v[j];
		//	cout << "Gen" << Pos << ' ' << s1 << ' ' << s2 << '\n';
			if(f[s1].fi == 0) Q.pb(s1);
			f[s1] = Max(f[s1] , {s2 , Pos});
		}
		else Gen(t + 1);
		Pos -= (i * (1 << t));
	}
}

int Binary1(ll x) {
	int d = 1 , c = m , g , res = -1;
	while(d <= c) {
		g = (d + c) / 2;
		if(Q[g] >= x) res = g , c = g - 1;
		else d = g + 1;
	}
	return res;
}

int Binary2(ll x) {
	int d = 1 , c = m , g , res = -1;
	while(d <= c) {
		g = (d + c) / 2;
		if(Q[g] <= x) res = g , d = g + 1;
		else c = g - 1;
	}
	return res;
}

void Check() {
	ll s1 = 0 , s2 = 0;
	for(auto x : H)	s1 += w[x] , s2 += v[x];
//	for(auto x : H) cout << x << ' ';
	//cout << "|";
	int d = Binary1(L - s1);
	int c = Binary2(R - s1);
//	cout << s1 << ' ' << s2 << ' ' << L - s1 << ' ' << R - s1 << ' ' << d <<  ' ' << c << ' ';
	if(d == -1 || c == -1 || d > c) return;
	pi tmp = Get(d , c);
	ll res = tmp.fi + s2;
//	cout << tmp.fi << ' ' << res << ' ' << ans << '\n';
	//cout << res << '\n';
//	cout << f[Q[tmp.se]].se << ' ' << res << '\n';
	if(res == ans) {
		if(count(Pos1) < count(f[Q[tmp.se]].se)) {
			ans = res;
			Pos1 = f[Q[tmp.se]].se;
			Pos2 = H;
		}
		else if(count(Pos1) == count(f[Q[tmp.se]].se) && Pos1 >= f[Q[tmp.se]].se) {
			ans = res;
			Pos1 = f[Q[tmp.se]].se;
			Pos2 = H;
		}
	}
	
	else if(res > ans) {
		ans = res;
		Pos1 = f[Q[tmp.se]].se;
		Pos2 = H;
	}
}

void Solve(int t) {
	for(int i = 0 ; i <= 1 ; i++) {
		if(i) H.pb(t);
		if(t == n) Check();
		else Solve(t + 1);
		if(i) H.pop_back();
	}
}

int main() {
	file();
	cin >> n >> L >> R;
	for(int i = 1 ; i <= n ; i++) cin >> w[i] >> v[i];
	Gen(1);
	Rmq();
//	cout << m << '\n';
//	for(auto x : Q) cout << x << " " << f[x].fi << ' ' << f[x].se << '\n';
//	cout << endl;
//	cout << Q[1] << ' ' << Q[2] << ' ' << P[1][1] << ' ' << P[2][1] << '\n';
//	cout << Get(1 , 2) << '\n';
	Solve(n / 2 + 1);
//	cout << ans << '\n';
	cout << __builtin_popcount(Pos1) + Pos2.size() << '\n';
	for(int i = 1 ; i <= n / 2 ; i++) if(Bit(Pos1 , i)) cout << i << ' ';
	for(auto x : Pos2) cout << x << ' ';
	return 0;
}



