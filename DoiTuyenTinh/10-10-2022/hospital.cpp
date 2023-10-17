#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pi pair<int , int>
#define pb push_back

using namespace std;
const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("hospital.inp" , "r" , stdin);
	freopen("hospital.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k , d = 0 , c = 1e9 , g , ans , a[N];

bool check(int x) {
	int s = 0 , res = 0;
	for(int i = 1 ; i <= n ; i++) {
		s = 0;
		while(i < n && s + a[i + 1] - a[i] <= x) s += a[i + 1] - a[i] , i++;
		s = 0;
		while(i < n && s + a[i + 1] - a[i] <= x) s += a[i + 1] - a[i] , i++;
		res++;
	}
	return res <= k;
}

int main() {
	file();
	cin >> n >> k;
	a[1] = 1;
	for(int i = 1 , x ; i < n ; i++) cin >> x , a[i + 1] = a[i] + x;
	while(d <= c) {
		g = (d + c) / 2;
		if(check(g)) ans = g , c = g - 1;
		else d = g + 1;
	}
	cout << ans;
	return 0;
}

