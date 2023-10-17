#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5;
ll inf = 1e18;

void file() {
	freopen("sequence.inp" , "r" , stdin);
	freopen("sequence.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , k , d = 0 , c = 1e9 , g , res , s[N];

bool check(ll x) {
	ll j = 0 , val = inf;
	for(ll i = 1 ; i <= n ; i++) {
		while(j < i && s[i] - s[j] >= k) {
			val = min(val , s[j] - x * j);
			j++;
		}
		if(s[i] - x * i >= val) return true;
	}
	return false;
}

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 , x ; i <= n ; i++) 
		cin >> x , s[i] = s[i - 1] + x;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) res = g , d = g + 1;
		else c = g - 1;
	}
	cout << res;
	return 0;
}

