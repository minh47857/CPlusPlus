#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 1e5 + 5 , inf = 1e18 + 5;

void file() {
    freopen(".inp" , "r" , stdin);
	freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct seg {
	ll l , r , c;
	bool operator < (const seg&s) const {
		return r < s.r;
	}
};

ll Get(ll l , ll r) {
	// th1 bao tron cac doan
	ll res = 0;
	int d = 0 , c = Q.size() - 1 , g , num = -1;
	while(d <= c) {
		g = (d + c) / 2;
		if(Q[g].l >= l) num = g , c = g - 1;
		else d = g + 1;
	}
	if(num != -1) 
		res = Q.back().c - ((num == 0) ? 0 : Q[num - 1].c);
	// th2 co 1 doan bi chua 
    d = 0 , c = Q.size() - 1 , num = -1;
	while(d <= c) {
		g = (d + c) / 2;
		if(Q[g].r >= l) num = g , c = g - 1;
		else d = g + 1;
	}
	if(num != -1 && Q[num].l < l)
		res = Q.back().c - Q[num].c + Q[num].r - l + 1;	
	return res;
}

void Update(ll w , int l , int r) {
	ll pos = r;
	if(Q.size()) {
	    pos = r - min(w , r - Q.back().r) + 1;
		w -= min(w , r - Q.back().r);
	}
	while(w && Q.size()) {
		if(Q.size() == 1) 
			pos = Q.back().l;
		else {
			int nxb = Q.size() - 2;
			pos = Q.back().l - min(w , Q.back().l - Q[nxb].r);
			w -= min(w , Q.back().l - Q[nxb].r);
		}
		Q.pop_back();
	}
	pos -= ;
	if(pos)
	Q.pb({pos , r , Q.back().c + r - pos + 1});
}

int main() {
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> x[i].l >> x[i].r >> x[i].c;
	sort(x + 1 , x + n + 1 , greater<seg>());
	for(int i = 1 ; i <= n ; i++) {
		ll cnt = Get(x[i].l , x[i].r);
		if(cnt >= x[i].c) continue;
		ans += x[i].c - cnt;
		Update(x[i].c - cnt , x[i].l , x[i].r);
	}
	cout << ans;
	return 0;
	
}

