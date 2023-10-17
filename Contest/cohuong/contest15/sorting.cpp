#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("sorting.in" , "r" , stdin);
	freopen("sorting.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , s[N] , t = 0;
vector<int> res;

int main() {
	file();
 cin >> n;
 for(int i = 1 ; i <= n ; i++) cin >> s[i] , t = __gcd(t , abs( i - s[i] ));
 for(int i = 1 ; i <= n ; i++) if(t % i == 0) res.pb(i);
 cout << res.size() << '\n';
 for(auto x : res) cout << x << ' ';
 return 0;
}

