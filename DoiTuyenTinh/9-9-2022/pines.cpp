#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("pines.inp" , "r" , stdin);
	freopen("pines.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , d , Min = inf , ans , a[N];

int main() {
	file();
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , Min = min(Min , a[i]);
	for(int i = 1 ; i <= n ; i++) 
		if((a[i] - Min) % d) {
			cout << -1;
			return 0;
		} else ans += (a[i] - Min) / d;
	cout << ans;
	return 0;
}

