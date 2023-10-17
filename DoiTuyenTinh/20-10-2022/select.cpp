#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen(".inp" , "r" , stdin);
	freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , r , ans;
pi a[N];

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i].se >> a[i].fi;
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) 
		if(a[i].se >= r) r = a[i].fi , ans++;
	cout << ans;
	return 0;
}

