#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1e5 , MOD = 1e9 + 7 , inf = 1e11;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll f[100][2 * N + 5] , n , a[100] , s1[30] , s2[30] , dem = 0 , ans , m , sum;
map<ll , ll> d;

ll gen(int i , ll s1 , ll s2) {
	if(i == n) {
		if(s1 == s2) return 0;
		return inf;
	}
	return min({gen(i + 1 , a[i + 1] + s1 , s2) , gen(i + 1 , s1 , a[i + 1] + s2) , gen(i + 1 , s1 , s2) + a[i + 1]});
}

void sub1() {
	cout <<  gen(0 , 0 , 0) << '\n';
}

void gen1(int t) {
	for(int i = 0 ; i <= 2 ; i++) {
		s1[t] = s1[t - 1];
		s2[t] = s2[t - 1];
		if(i == 1) s1[t] += a[t];
		if(i == 2) s2[t] += a[t];
		if(t == m) {
		   if(d.count(s1[t] - s2[t]) > 0) d[s1[t] - s2[t]] = min(d[s1[t] - s2[t]] , sum - s1[t] - s2[t]);
		   else d[s1[t] - s2[t]] = sum - s1[t] - s2[t];
	    }
		else gen1(t + 1);
	}
}

void gen2(int t) {
	for(int i = 0 ; i <= 2 ; i++) {
		s1[t] = s1[t - 1];
		s2[t] = s2[t - 1];
		if(i == 1) s1[t] += a[t];
		if(i == 2) s2[t] += a[t];
		if(t == m) {
			 if(d.count(s2[t] - s1[t]) > 0)
		                      ans = min(ans , sum - s1[t] - s2[t] + d[s2[t] - s1[t]]);
	     }
		else gen2(t + 1);
	}
}

void sub2() {
	d.clear();
	ans = inf;
	m = n / 2 , sum = 0;
	for(int i = 1 ; i <= m ; i++) sum += a[i];
	gen1(1);
	m = n - n / 2 , sum = 0;
	for(int i = 1 ; i <= m ; i++) a[i] = a[i + n / 2];
	for(int i = 1 ; i <= m ; i++) sum += a[i];
	gen2(1);
	cout << ans << '\n';
}

void sub34() {
    for(int i = 0 ; i <= n ; i++)
	  for(int j = -N ; j <= N ; j++)
		f[i][j + N] = inf;
	f[0][N] = 0;
	for(int i = 0 ; i < n ; i++)	
		for(int j = -N ; j <= N ; j++) {
			if(f[i][j + N] == inf) continue;
			f[i + 1][j + N] = min(f[i + 1][j + N] , f[i][j + N] + a[i + 1]);
		if(j + a[i + 1] <= N)	f[i + 1][j + a[i + 1] + N] = min(f[i + 1][j + a[i + 1] + N] , f[i][j + N]);
		if(j - a[i + 1] >= -N)	f[i + 1][j - a[i + 1] + N] = min(f[i + 1][j - a[i + 1] + N] , f[i][j + N]);
		}
	cout << f[n][N] << '\n';
}

int main() {
	file();
   while(cin >> n) {
   	//cout << dem ;
   //	assert(dem <= 100);
   	for(int i = 1 ; i <= n ; i++) cin >> a[i];
  // 	if(n <= 24) sub1();
   	if(n <= 24) sub2();
    else sub34();
   }
}
