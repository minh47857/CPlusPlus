#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int m;
vector<int> v[N];

int main() {
	cin >> m;
	for(int i = 1; i < N; i++) 
		for(int j = i; j < N; j += i)
			v[j].pb(i);
	for(int i = 1; i <= m; i++) {
		int u, k;
		cin >> u >> k;
		if(k > v[u].size()) cout << -1 << '\n';
		else cout << v[u][k - 1] << '\n';
	}
	return 0;
}
