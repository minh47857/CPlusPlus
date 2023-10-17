#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("dautu.inp" , "r" , stdin);
	freopen("dautu.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , l = 1 , ans = inf , a[N];
ll sum , s;

int main() {
	file();
	cin >> n >> s;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) {
		sum += a[i];
		while(sum - a[l] >= s) sum -= a[l] , l++;
		if(sum >= s) ans = min(ans , i - l + 1);
	}
	cout << ans;
	return 0;
}

