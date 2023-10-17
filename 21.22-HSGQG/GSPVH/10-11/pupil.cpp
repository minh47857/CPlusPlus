#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll , ll>
#define fi first
#define se second
#define pb push_back

const int N = 4e5 + 5 , inf = 1e9;

void file() {
    freopen("pupil.inp" , "r" , stdin);
	freopen("pupil.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct store {
	int pos , price , id;
	bool operator < (const store&s) const {return pos < s.pos;}
};

int d , m , n , C , f[N][25] , LOG[N];
ll ans[N];
bool check = true;
store a[N];

ll Min(int x , int y) {
	if (a[x].price < a[y].price) return x;
	return y; 
}

int Get(int x , int y) {
	int L = LOG[y - x + 1];
	return Min(f[x][L] , f[y - (1 << L) + 1][L]);
}

void RMQ() {
	LOG[1] = 0;
	for(int i = 2 ; i <= m ; i++) LOG[i] = LOG[i / 2] + 1;
	for(int j = 1 ; j <= LOG[m] ; j++) 
	   for(int i = 1 ; i <= m ; i++)
	    if(i + (1 << (j - 1)) <= m) f[i][j] = Min(f[i][j - 1] , f[i + (1 << (j - 1))][j - 1]) ;
}

pair<ll , int> solve(int l , int r , int s) {
	if(l == r) 	return {0 , s};
	if(l == r - 1) return {0 , s - a[r].pos + a[l].pos};
	int m , buy;
	pi x , y;
	m = Get(l + 1 , r - 1);
	x = solve(l , m , s);
	buy = max(0LL , min(n - x.se , a[r].pos - a[m].pos - x.se));
	ans[a[m].id] = buy;
	y = solve(m , r , x.se + buy);
	return {x.fi + y.fi + 1LL * buy * a[m].price, y.se};
}

int main() {
	file();
	cin >> d >> n >> m >> C;
	for(int i = 1 ; i <= m ; i++) {
		cin >> a[i].pos >> a[i].price;
		a[i].id = i;
		f[i][0] = i;
	}
	sort(a + 1 , a + m + 1);
	a[0] = {0 , inf , 0} , a[m + 1] = {d , inf  , 0};
	for(int i = 1 ; i <= m + 1 ; i++) if(a[i].pos - a[i - 1].pos > n) check = false;
	if(a[1].pos - a[0].pos > C) check = false;
	RMQ();
	if(!check) {
		cout << -1;
		return 0;
	}
	else cout << solve(0 , m + 1 , C).fi << '\n';
	for(int i = 1 ; i <= m ; i++) cout << ans[i] << ' ';
	return 0;
}
