#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("gun.inp" , "r" , stdin);
	freopen("gun.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int t , a , b , ans1 , ans2 , pre[15];

int main() {
	file();
	while(cin >> t >> a >> b) {
		if((a <= 5 && b <= 5) || (a > 5 && b > 5)) continue;
		if(a <= 5) ans1 += 100;
		else ans2 += 100;
		if(t - pre[a] <= 10 && pre[a]) {
			if(a <= 5) ans1 += 50;
			else ans2 += 50;
		}
		pre[a] = t;
	}
	cout << ans1 << ' ' << ans2;
	return 0;
}
