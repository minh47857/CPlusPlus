#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e3 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("football.inp" , "r" , stdin);
	freopen("football.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k , c[N][N];

vector<int> merge(int l , int r) {
	vector<int> res;
	if(l == r) {
		res.pb(l);
		return res;
	}
	int mid = (l + r) / 2;
	vector<int> a = merge(l , mid);
	vector<int> b = merge(mid + 1 , r);
	int i = 0 , j = 0;
	while((i < a.size()) && (j < b.size())) {
		if(c[a[i]][b[j]]) res.pb(a[i++]);
		else res.pb(b[j++]);
	}
	while(i < a.size()) res.pb(a[i++]);
	while(j < b.size()) res.pb(b[j++]);
	return res;
}

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			cin >> c[i][j];
	//cin >> k;
	while(k--) {
		int l , r;
		cin >> l >> r;
		vector<int> ans = merge(l , r);
		cout << ans.size() << ' ';
		for(auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	
}


