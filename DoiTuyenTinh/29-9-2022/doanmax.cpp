#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("doanmax.inp" , "r" , stdin);
	freopen("doanmax.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , f[N] , a[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) 
		f[i] = (a[i] >= a[i - 1] ? f[i - 1] + 1 : 1) , ans = max(ans , f[i]);
	cout << ans << '\n';
	for(int i = 1 ; i <= n ; i++) if(ans == f[i]) {
			for(int j = i - ans + 1 ; j <= i ; j++) cout << a[j] << ' ';
			return 0;
	}
	
}

