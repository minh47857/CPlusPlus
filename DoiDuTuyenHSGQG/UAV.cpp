#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 5e5 + 5 , MOD = 1e9 +7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll l , n , a[N] , f[N] , U , V;

void Find_U() {
	f[1] = 1;
	for(int i = 2 ; i <= n ; i++) f[i] = inf;
	for(int i = 1 ; i < n ; i++) {
		if(f[i] == inf) continue;
		for(int j = i + 1 ; j <= i + l ; j++) {
			if(a[j] % 2) f[j] = min(f[j] , f[i] + 1);
		}
	}
	U = f[n];
}

void Find_V() {
	memset(f , 0 , sizeof(f));
	ll Max = 1001;
	f[n] = Max;
	for(int i = n - 1; i >= 1 ; i--) {
		if(a[i] % 2) continue;
		f[i] = Max - a[i];
		if(i + l <= n && a[i + l] % 2 == 0) f[i] = max(f[i + l] + a[i] , f[i]);
		Max = max(Max , f[i]);
	}
	V = f[1];
}

int main() {
  cin >> l >> n;
  a[1] = 1000 , a[n] = 1001;
  for(int i = 2 ; i <= n - 1 ; i++) cin >> a[i];
  Find_U();
  Find_V();
  cout << U << '\n' << V;
  return 0;
}

