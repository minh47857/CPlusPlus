#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("SUB.inp" , "r" , stdin);
	freopen("SUB.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct num {
	ll x , y;
	bool operator < (const num&a) const {
		if(x == a.x) return y > a.y;
		return x < a.x;
	}
};

int n , k;
ll a[N];
map<ll , int> d;
set<num> s;

int main() {
	file();
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		for(int i = 1 ; i <= k ; i++) d[a[i]]++; 
		for(int i = 1 ; i <= k ; i++) s.insert({d[a[i]] , a[i]});
		auto p = *s.begin();
			if(p.x == 1) cout << p.y << '\n';
			else cout << "Nothing" << '\n';
		for(int i = k + 1 ; i <= n ; i++) {
			d[a[i - k]]--;
			d[a[i]]++;
			s.erase({d[a[i - k]] + 1 , a[i - k]});
            if(d[a[i - k]] != 0) s.insert({d[a[i - k]] , a[i - k]});
            s.insert({d[a[i]] , a[i]});
            if(d[a[i]] != 1) s.erase({d[a[i]] - 1 , a[i]});
			auto p = *s.begin();
			if(p.x == 1) cout << p.y << '\n';
			else cout << "Nothing" << '\n';
		}
		return 0;
}


