#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 32005 , M = 32000 , inf = 1e9 + 7;

void file() {
	freopen("uocso.inp" , "r" , stdin);
	freopen("uocso.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , a , b , cnt[N];

void solve() {
	ll ans = 1;
	cin >> a >> b;
	for(int i = 2 ; i <= max(M , (int)sqrt(a)) ; i++) 
		while(a % i == 0) a /= i , cnt[i]++;
	for(int i = 2 ; i <= max(M , (int)sqrt(b)) ; i++)
		while(b % i == 0) b /= i , cnt[i]++;
	for(int i = 2 ; i <= M ; i++) 
		ans *= (cnt[i] + 1) , cnt[i] = 0;
	if(a != 1 && b != 1 && a == b) ans *= 3;
	if((a == 1 && b != 1) || (a != 1 && b == 1)) ans *= 2;
	cout << ans << '\n';
}

int main() {
	file();
	cin >> t;
	while(t--) solve();
	return 0;
}

