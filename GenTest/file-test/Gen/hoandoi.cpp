#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("hoandoi.inp" , "r" , stdin);
	freopen("hoandoi.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , t , p , a[10] , b[10];

int main() {
	file();
	cin >> n;
	p = n;
	while(n) a[++t] = n % 10 , n /= 10;
	sort(a + 1 , a + t + 1);
	for(int i = p + 1 ; i <= 1e6 ; i++) {
		int x = i , m = 0;
		while(x) b[++m] = x % 10 , x /= 10;
		sort(b + 1 , b + m + 1);
		if(t == m) {
			bool ok = true;
			for(int j = 1 ; j <= t ; j++) ok &= (b[j] == a[j]);
			if(ok) {
				cout << i;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}

