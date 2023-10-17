#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("seqgame.inp" , "r" , stdin);
	freopen("seqgame.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n;
ll d , ans , a[N];

int main() {
	file();
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(ll i = 1 ; i <= n ; i++)
		a[i] = a[i] - d * (i - 1);
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) 
		ans += abs(a[(n + 1) / 2] - a[i]);
	cout << ans;
	return 0;
}

