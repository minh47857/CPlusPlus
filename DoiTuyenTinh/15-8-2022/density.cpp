#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , M = 1e6 , inf = 1e9 + 7;

void file() {
	freopen("density.inp" , "r" , stdin);
	freopen("density.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll a , b , k , ans;

int main() {
	file();
	cin >> a >> b >> k;
	for(ll i = 1 , l , r , y ; i <= M ; i++) {
		y = i * i * i;
		if(y < a || y > b) continue;
		l = max(a , y - k) , r = min(b , y + k);
		if(sqrt(l) != (int) (sqrt(l))) l = sqrt(l) + 1;
		else l = sqrt(l);
		r = sqrt(r);
		ans += r - l + 1;
	}
	cout << ans;
	return 0;
}

