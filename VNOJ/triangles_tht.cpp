#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , ans = 0;
pi a[N];

int main() {
	file();
		cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> a[i].fi >> a[i].se;
		for(int i = 1 ; i <= n ; i++) {
			map< ll , map<ll , ll> > f;
			for(int j = 1 ; j <= n ; j++) if(j != i) {
				ll nx , ny , g;
				int t;
				nx = a[i].fi - a[j].fi;
				ny = a[i].se - a[j].se;
				if((nx > 0 && ny > 0) || (nx < 0 & ny < 0)) t = 1;
				else t = -1;
				if(nx == 0 || ny == 0) t = 0;
				nx = abs(nx) , ny = abs(ny) , g = __gcd(nx , ny);
				nx = nx / g , ny = ny / g;
				if(t == 1) ans += f[-ny][nx];
				else ans += f[ny][nx];
				//cout << i << ' ' << j << ' ' << t << ' ' << nx << ' ' << ny << endl;
				if(t == -1) f[-nx][ny]++;
				else f[nx][ny]++;
			}
		}
		cout << ans;
		return 0;
}

