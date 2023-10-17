#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll , int>
#define fi first
#define se second
#define pb push_back

const int N = 5e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("SHOPS.inp" , "r" , stdin);
	freopen("SHOPS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , P , f[N];
ll sum[N] , S;
vector<pi> V;

int binary(ll x) {
	int d = 0 , c = n - 1 , res = -1 , g;
	while(d <= c) {
		g = (d + c) / 2;
		if(V[g].fi <= x) res = g , d = g + 1;
		else c = g - 1;
	}
	return res;
}

int main() {
	file();
	cin >> n >> S;
	for(int i = 1 ,  x ; i <= n ; i++)
		cin >> x , sum[i] = sum[i - 1] + x , V.pb({sum[i] , i});
	sort(V.begin() , V.end());
	for(int i = 0 ; i < n ; i++) 
		f[i] = max(V[i].se , f[i - 1]);
	for(int i = 1 , pos ; i <= n ; i++) {
		pos = binary(S + sum[i - 1]);
		if(pos != -1) 
			if(f[pos] - i + 1 > ans) 
				ans = f[pos] - i + 1 , P = i;
	}
	cout << ans << ' ' << P;
	return 0;
}


