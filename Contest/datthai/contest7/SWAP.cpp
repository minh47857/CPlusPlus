#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("SWAP.inp" , "r" , stdin);
	freopen("SWAP.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , q , a[N] , bit[N];

void update(int u , ll x) {
	for(int i = u ; i <= n ; i += (i & (-i))) bit[i] += x;
}

ll get(int u) {
	ll ans = 0;
	for(int i = u ; i >= 1 ; i -= (i & (-i))) ans += bit[i];
	return ans;
}

int main() {
	file();
    cin >> n >> q;
    for(int i = 1 ; i <= n ; i++) cin >> a[i] , update(i , a[i]);
    for(int i = 1 ; i <= q ; i++) {
    	int k , u , v;
    	cin >> k >> u >> v;
    	if(k == 0) {
		   update(u , a[v] - a[u]);
		 //  cout << ".";
    	   update(v , a[u] - a[v]);
    	   swap(a[u] , a[v]);
        } 
        else {
        	cout << get(v) - get(u - 1) << '\n';
		}
    	
	}
}

