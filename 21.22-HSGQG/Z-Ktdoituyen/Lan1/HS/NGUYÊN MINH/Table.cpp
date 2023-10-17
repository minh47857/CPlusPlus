#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define pi pair<int , int>
using namespace std;

const ll inf = 1e17;

void file() {
	freopen("Table.inp" , "r" , stdin);
	freopen("Table.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
string st;

namespace sub1 {
	string res = " ";
	bool check(int i) {
		for(int j = i ; j >= i - n + 1 ; j--) 
				if(res[j] != st[n - i + j]) {
					return false;
				}
		    return true;
	}
	
	void solve() {
		for(int i = 1 ; i <= 1e7 ; i++) {
		    int x = i;
		    string str;
		    while(x) {
		    	str += (x % 10 + '0');
		    	x /= 10;
			}
			reverse(str.begin() , str.end());
			res += str;
			if(res.size() - 1 < n) continue;
			for(int j = res.size() - 1 ; j >= res.size() - n ; j--) 
				if(check(j)) {
					cout << j;
					exit(0);
				}
		}
		cout << -1;
	}
}

namespace sub3 {
	ll ans = inf;
	
	string cvS(ll x) {
		string str;
		    while(x) {
		    	str += (x % 10 + '0');
		    	x /= 10;
			}
		reverse(str.begin() , str.end());
		return str;
	}
	
	ll cvN(string s) {
		ll res = 0;
		for(int i = 0 ; i < s.size() ; i++) 
			res = res * 10 + (s[i] - '0');
		return res;
	}
	
	bool check9(string s) {
		for(int i = 0 ; i < s.size() ; i++) 
			if(s[i] != '9') return false;
			return true;
	}
	
	ll find(string s , vector<char> v) {
		ll x = cvN(s) + 1 , res = 0;
		s = cvS(x);
		for(int i = 0 ; i < v.size() ; i++)
			if(s[i] != v[i]) return -1;
	   
		ll count , Pow = 1;
		for(ll i = 1 ; i < s.size() ; i++) {
			Pow = Pow * 10;
			if(i == 1) count = 9;
			else count = count * 10;
		    res = res + count * i;
		}
		res = res + (x - Pow + 1) * (1LL * int(s.size()));
		res -= (s.size() - v.size());
		return res;
	}
	
	void calc(int len , int pos) {
	//	cout << "??" << ans << ' ' << len << ' ' << pos << '\n';
		while(pos < n) {
			string s1 , s2;	
				for(int i = pos ; i <= pos + len - 1 ; i++) s1 += st[i];
				pos += len;
				if(check9(s1)) len++;
				if(pos + len - 1 < n) {
					for(int i = pos ; i <= pos + len - 1 ; i++) s2 += st[i];
					if(cvN(s2) - cvN(s1) != 1) return;
				}
				else {
					vector<char> v;
					for(int i = pos ; i <= n ; i++) v.pb(st[i]);
					ll P = find(s1 , v); 
				//	cout << "main" << s1 << " " << len << ' ' << pos << ' ' << P << '\n';
					if(P != -1) 	ans = min(ans , P);
					return;
				}
		}
	}
	
	void solve() {
		for(int len = 1 ; len <= min(16 , n) ; len++) {
			for(int pos = 1 ; pos <= len ; pos++) {
				string s;
				if(pos + len - 1 > n) continue;
				for(int i = pos ; i <= pos + len - 1 ; i++) s += st[i];
				bool check = true;
				if(pos > 1) {
					s = cvS(cvN(s) - 1);
					s = ' ' + s;
					for(int i = 1 ; i < pos ; i++) 
						if(s[len - i + 1] != st[i]) check = false;
				}
				if(check) calc(len , pos);
			}
		}
		if(ans == inf) cout << -1;
		else cout << ans;
	}
}

int main() {
	file();
	 cin >> n >> st;
	 st = ' ' + st;
	 if(n <= 6) sub1::solve();
	 else sub3::solve();
	 return 0;
}


