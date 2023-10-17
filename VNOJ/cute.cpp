#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int t , a[20];
bool IsPrime[1505];
ll f[20][165][1505];

ll calc(int id , int sum1 , int sum2) {
	if(id == 0) 
		return (IsPrime[sum1] && IsPrime[sum2]);
	if(f[id][sum1][sum2] != -1) return f[id][sum1][sum2];
	f[id][sum1][sum2] = 0;
	for(int i = 0 ; i <= 9 ; i++) 
		f[id][sum1][sum2] += calc(id - 1 , sum1 + i , sum2 + i * i);
	return f[id][sum1][sum2];
}

ll solve(ll x) {
	ll ans = 0 , sum1 = 0 , sum2 = 0;
	for(int i = 1 ; i <= 19 ; i++ , x /= 10)
		a[i] = x % 10;
	for(int i = 19 ; i >= 1 ; i--) {
		for(int j = 0 ; j < a[i] ; j++) 
			ans += calc(i - 1 , sum1 + j  , sum2 + j * j);
		sum1 += a[i];
		sum2 += a[i] * a[i];
	}
	ans += calc(0 , sum1 , sum2);
	return ans;
}

int main() {
	cin >> t;
	memset(f , -1 , sizeof(f));
	for(int i = 2 ; i <= 1500 ; i++) {
		bool ok = true;
		for(int j = 2 ; j <= sqrt(i) ; j++) 
			if(i % j == 0) ok = false;
		IsPrime[i] = ok;
	}
	while(t--) {
		ll l , r;
		cin >> l >> r;
		cout << solve(r) - solve(l - 1) << '\n';
	}
	return 0;
}
