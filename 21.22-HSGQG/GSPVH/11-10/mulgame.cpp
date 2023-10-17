#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 10 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("mulgame.inp" , "r" , stdin);
	freopen("mulgame.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string A = "La premiere joueuse gagne." , B = "La deuxieme joueuse gagne.";
ll t , m , l[N] , r[N] , n;


void in() {
	l[1] = 2 , r[1] = 9 , m = 1;
	while(r[m] <= 1e9) {
		++m;
		l[m] = 2 * r[m - 1] + 1;
		r[m] = l[m] + (r[m - 1] - l[m - 1] + 1) * 18 - 1;
	}
}

void solve() {
	bool ok = false;
	for(int i = 1 ; i <= m ; i++) 
 	  	ok |= ((n >= l[i] && (n <= r[i])));
	cout << ((ok) ? A : B) << '\n';
}

int main() {
	file();
	in();
	cin >> t;
	while(t--) cin >> n , solve();
}


