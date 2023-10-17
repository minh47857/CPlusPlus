#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("capdoi.inp" , "r" , stdin);
	freopen("capdoi.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , x , a[N];
ll ans;
map<int , int> d;

int main() {
	file();
	cin >> n >> x;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		ans += d[x - a[i]];
		d[a[i]]++;
	}
	cout << ans;
	return 0;
}

