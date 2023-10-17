#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , res = -1;
vector<int> v , sol[15];

void calc(vector<int> a , int h) {
	if(a.size() == 1) return;
	res = max(h , res);
	vector<int> l , r;
	for(int i = a.size() / 2 - 1 ; i >= 0 ; i--) 
		l.pb(a[i]) , sol[h].pb(a[i]);
	for(int i = a.size() / 2 ; i < a.size() ; i++)
		r.pb(a[i]);
	calc(l , h + 1);
	calc(r , h + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++) cin >> x;
	for(int i = 1 , x ; i <= n ; i++)
		cin >> x , v.pb(x);
	calc(v , 0);
	cout << res + 1 << '\n';
	for(int i = res ; i >= 0 ; i--) {
		cout << sol[i].size() << ' ';
		for(auto x : sol[i]) cout << x << ' ';
		cout << '\n';
	}
	
	return 0;	
}

