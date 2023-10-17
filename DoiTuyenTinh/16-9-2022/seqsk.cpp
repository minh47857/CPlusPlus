#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 5e6 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("seqsk.inp" , "r" , stdin);
	freopen("seqsk.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , ans = inf;
ll k , a[N] , s;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	int j = 1;
	for(int i = 1 ; i <= n ; i++) {
		s += a[i];
		while(s > k) s -= a[j] , j++;
		if(s == k) ans = min(ans , i - j + 1);
	}
	cout << ((ans == inf) ? -1 : ans);
	return 0;
}

