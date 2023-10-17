#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e16;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , l , r , k , a[N] , c[3][35];
unordered_map<int , pi> f[35][3][3];
pi ans;

int Bit(ll x , int p) {
	return (x >> p) & 1;
}

pi Getmax(pi a , pi b) {
	if(a.fi == b.fi && a.fi != inf) return {a.fi , a.se + b.se};
	if(a.fi < b.fi) return b;
	return a;
}

pi calc(int id , int ok1 , int ok2 , ll nho) {
	if(id == -1) {
		if(nho == 0) return {0 , 1};
		else return {-inf , 0};
	}
	
	if(f[id][ok1][ok2].find(nho) != f[id][ok1][ok2].end()) return f[id][ok1][ok2][nho];
	
	int Min = (ok1) ? 0 : Bit(l , id);
	int Max = (ok2) ? 1 : Bit(r , id);
	pi best = {-inf , 0};
	if(Min == 0) {
	    ll sum = c[1][id] * (1LL << (id));
		pi x = calc(id - 1, ok1 | (0 != Bit(l , id)) , ok2 | (0 != Bit(r , id)) , nho);
		if(x.fi != -inf) x.fi += sum;
		best = Getmax(best , x);
	}
	
	if(Max == 1) {
	    ll sum = c[0][id] * (1LL << (id));
		pi x = calc(id - 1, ok1 | (1 != Bit(l , id)) , ok2 | (1 != Bit(r , id)) , (nho + (1 << id)) % k);
		if(x.fi != -inf) x.fi += sum;
		best = Getmax(best , x);
	}
//	cout << id << ' ' << ok1 << ' ' << ok2 << ' ' << nho << ' ' << best.fi << ' ' << best.se << ' ' << Max << ' ' << Min << '\n';
	f[id][ok1][ok2][nho] = best;
	return best;
}

pi Buffalo() {
	pi best = {0 , 0};
	l = (l + k - 1) / k * k;
	r = r / k * k;
	for(int i = l ; i <= r ; i += k) {
		ll tmp = 0;
		for(int j = 0 ; j <= 31 ; j++) tmp = tmp + c[1 - Bit(i , j)][j] * (1LL << j);
		best = Getmax(best , {tmp , 1});
	}
	return best;
}
int main() {
	file();
  cin >> n >> l >> r >> k;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  for(int i = 31 ; i >= 0 ; i--) 
  	for(int j = 1 ; j <= n ; j++) c[Bit(a[j] , i)][i]++;
//  for(int i = 4 ; i >= 0 ; i--) cout << c[0][i] << ' ' << c[1][i] << '\n';
 if(k < 1e4) ans = calc(31 , 0 , 0 , 0);
  else ans = Buffalo();
  cout << ans.fi << '\n' << ans.se;
  return 0;
}
