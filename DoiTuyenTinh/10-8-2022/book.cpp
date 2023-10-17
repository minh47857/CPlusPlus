#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("book.inp" , "r" , stdin);
	freopen("book.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N];
ll s;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , s += a[i];
	n = (n + 2) / 3 * 3;
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i += 3) s -= a[i];
	cout << s;
	return 0;
}

