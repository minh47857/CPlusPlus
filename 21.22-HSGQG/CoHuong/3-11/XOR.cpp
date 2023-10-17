#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e5 + 5 , MOD = 1e9 + 7 , inf = LLONG_MAX;

void file() {
	freopen("XOR.inp" , "r" , stdin);
	freopen("XOR.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll f[45][3][3] , n , A , B , c[N];

int Bit(ll x , int k) {
	return (x >> k) & 1;
}

ll cost(int id , int t) {
	ll res = 0;
	for(int i = 1 ; i <= n ; i++) {
		if(Bit(c[i] , id) != t) res += (1LL << id);
	}
	return res;
}

ll calc(int id , bool okA , bool okB) {
		if(f[id][okA][okB] != -1) return f[id][okA][okB];
		if(id == 0) return 0;
		ll res = inf;
		int s , t;
	    s = (!okA) ? Bit(A , id - 1) : 0;
	    t = (!okB) ? Bit(B , id - 1) : 1;
	    for(int i = s ; i <= t ; i++) {
	    	res = min( res , cost(id - 1 , i) + calc(id - 1 , okA | (i != Bit(A , id - 1)) , okB | (i != Bit(B , id - 1))) );
		}
		f[id][okA][okB] = res;
		return res;
}

int main() {
	file();
	    memset(f , -1 , sizeof(f));
		cin >> n >> A >> B;
		for(int i = 1 ; i <= n ; i++) cin >> c[i];
		cout << calc(40 , 0 , 0);
}

