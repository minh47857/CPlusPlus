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
	freopen("lessthan.inp" , "r" , stdin);
	freopen("lessthan.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , res[N];
pi a[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].fi , a[i].se = i;
	sort(a + 1 , a + n + 1);
	for(int i = 2 ; i <= n ; i++) 
		if(a[i].fi == a[i - 1].fi) res[a[i].se] = res[a[i - 1].se];
		else res[a[i].se] = i - 1;
	for(int i = 1 ; i <= n ; i++) cout << res[i] << ' ';
	return 0;
}

