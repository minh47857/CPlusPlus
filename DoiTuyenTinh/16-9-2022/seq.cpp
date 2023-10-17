#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 2e5 + 5 , MOD = 1e9 + 7;
const ll inf = 1e18;

void file() {
	freopen("seq.inp" , "r" , stdin);
	freopen("seq.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , h , a[N] , f[N];
ll S , s[N] , ans = inf;

int main() {
	file();
	cin >> n >> h;
	S = 1LL * (h + 1) * h / 2;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , s[i] = s[i - 1] + a[i];
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] > h) {
			f[i]++;
			f[i + h]--;
		} else {
			f[min(i + h - a[i] + 1 , i + h)]++;
			f[i + h]--;
		}
		f[i] += f[i - 1];
		if(!f[i] && i >= h) ans = min(ans , S - (s[i] - s[i - h]));
	}
	cout << ((ans == inf) ? -1 : ans);
}

