#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define ld long double
#define pb push_back
#define pi pair<ld , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , pos1 , pos2;
pi a[N];
ld ans = 10;

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) {
		int x , y ; cin >> x >> y;
		a[i] = {atan2(y , x) , i};
	}
	sort(a + 1 , a + n + 1);
	a[n + 1] = a[1];
	for(int i = 1 ; i <= n ; i++) {
		ld tmp = a[i + 1].fi - a[i].fi;
		if(tmp < 0) tmp += 2 * acos(-1);
		if(tmp < ans) {
			ans = tmp;
			pos1 = a[i].se;
			pos2 = a[i + 1].se;
		}
	}
	cout << pos1 << ' ' << pos2;
	return 0;
}

