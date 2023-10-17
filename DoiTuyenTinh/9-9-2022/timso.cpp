#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("timso.inp" , "r" , stdin);
	freopen("timso.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , a[N];
map<int , int> d;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> a[i] , d[a[i]] = 1;
	while(k--) {
		int x;
		cin >> x;
		cout << (d[x] == 1 ? "YES\n" : "NO\n");
	}
	return 0;
}

