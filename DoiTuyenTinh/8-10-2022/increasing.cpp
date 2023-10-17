#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("increasing.inp" , "r" , stdin);
	freopen("increasing.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n;
ll h , ans = 1e18 , a[N] , s[N] , f[N];

int main() {
	file();
	cin >> n >> h;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i] , s[i] = s[i - 1] + a[i];
	for(int i = 1 ; i <= n ; i++) {
		if(a[i] > h) f[i]++ , f[i + h]--;
		else f[i + h - max(1LL , a[i]) + 1]++ , f[i + h]--;
		f[i] += f[i - 1];
		if(i >= h && !f[i]) ans = min(ans , (h + 1) * h / 2 - (s[i] - s[i - h]));
	}
	cout << ((ans == 1e18) ? -1 : ans);
	return 0;
}

