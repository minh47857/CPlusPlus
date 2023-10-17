#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("average.inp" , "r" , stdin);
	freopen("average.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , ans , s[N];
map<ll , ll> f;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 , x ; i <= n ; i++) 
		cin >> x , s[i] = s[i - 1] + x;
	f[0] = 0;
	for(ll i = 1 ; i <= n ; i++) {
		if(f.find(s[i] - k * i) != f.end()) ans = max(ans , i - f[s[i] - k * i]);
		else f[s[i] - k * i] = i;
	}
	cout << ans;
	return 0;
}

