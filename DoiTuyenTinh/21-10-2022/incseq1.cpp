#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("incseq1.inp" , "r" , stdin);
	freopen("incseq1.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , a[N];
multiset<int> s;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	s.insert(a[1]);
	for(int i = 2 ; i <= n ; i++) {
		if(*s.rbegin() > a[i]) {
			auto it = s.upper_bound(a[i]);
			s.erase(it);
		}
		s.insert(a[i]);
	}
	cout << s.size();
	return 0;
}

