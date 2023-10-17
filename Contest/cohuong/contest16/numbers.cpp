#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair <ll , ll>
#define fi first
#define se second
using namespace std;

const ll N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("numbers.in" , "r" , stdin);
	freopen("numbers.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
}

ll a , b;

namespace sub1 {
	int res = 0;
	bool palind(string s) {
		string s2 = s;
		reverse(s2.begin() , s2.end());
		if(s2 == s) return true;
		return false;
	}
	
	bool check(ll x) {
		string s;
		int m;
		while(x) {
			s += (x % 10 + '0');
			x /= 10;
		}
		s = ' ' + s;
		m = s.size() - 1;
		for(int i = 1 ; i < m ; i++) {
			string s1; s1 += s[i];
			for(int j = i + 1 ; j <= m ; j++) {
				s1 += s[j];
				if(palind(s1)) return false;
			}
		}
	return true;	
	}
	
	void solve() {
		for(ll i = a ; i <= b ; i++) if(check(i)) res++;
		cout << res ;
	}
}

namespace sub2 {
	
	ll f[25][15][15][3][3]; 
	int u[25];
	
	ll calc(int id , int pre1 , int pre2 , int ok , int ok2) {
	
		if(id == 1) {
			if(ok2) return 1;
			return 0;
		}
		if(f[id][pre1][pre2][ok][ok2] != -1) return f[id][pre1][pre2][ok][ok2];
		ll res = 0;
		for(int i = 0 ; i <= max(u[id - 1] , ok * 9) ; i++) {
         	if(ok2 && (pre1 == i || pre2 == i)) continue;
         	if(!ok2 && i == 0) res += calc(id - 1 , -1 , pre1 , ok | (i != u[id - 1]) , ok2 | (i != 0));
			else res += calc(id - 1 , i , pre1 , ok | (i != u[id - 1]) , ok2 | (i != 0));
		}
		f[id][pre1][pre2][ok][ok2] = res;
		return res;
	}
	
	ll find(ll x) {
		memset(f , -1 , sizeof(f));
		for(int i = 1 ; i <= 19 ; i++ , x /= 10) u[i] = x % 10 ;
		return calc(20 , -1 , -1 , 0 , 0);
	}
	
	void solve() {
		cout <<find(b) - find(a - 1);
	}
}

int main() {
	file();
  cin >> a >> b;
  if(b - a <= 1e5) sub1::solve();
  else sub2::solve();
}

