#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("RIDDLES.inp" , "r" , stdin);
	freopen("RIDDLES.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , n , k , a[N] , b[N];

bool check(int id) {
	for(int i = 1 ; i <= id ; i++) 
		b[i] = a[i];
	sort(b + 1 , b + id + 1);
	int s = 0;
	for(int i = 1 ; i <= id ; i++) {
		if(b[i] > s + 1) return false;
		else s += b[i];
	}
	return s >= k;
}

int main() {
	file();
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i++)
			cin >> a[i];
		int d = 1 , c = n , ans = -1 , g;
		while(d <= c) {
			g = (d + c) / 2;
			if(check(g)) c = g - 1 , ans = g;
			else d = g + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}


