#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define eps 1e-6
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

using namespace std;

void file() {
	freopen("Bai1.in" , "r" , stdin);
	freopen("Bai1.ans" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , m , k , a[N] , b[N];

bool check(int x) {
	int j = 1 , res = 0;
	for(int i = 1 ; i <= n ; i++) {
		while(j < m && b[j] + x < a[i]) j++;
		if(abs(a[i] - b[j]) <= x) {
			j++;
			res++;
		}
	}
	return (res >= k);
}

int main() {
	file();
	cin >> n >> m >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= m ; i++) cin >> b[i];
	sort(a + 1 , a + n + 1);
	sort(b + 1 , b + m + 1);
	int d = 0 , c = 1e9 , ans;
	while(d <= c) {
		int g = (d + c) / 2;
		if(check(g)) ans = g , c = g - 1;
		else d = g + 1;
	}
	cout << ans;
	return 0;
}


