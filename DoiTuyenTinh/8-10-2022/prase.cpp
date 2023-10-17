#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e2 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("prase.inp" , "r" , stdin);
	freopen("prase.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , ans;
string s[N];
map<string , int> d;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	for(int i = 1 ; i <= n ; i++) {
		ans += (d[s[i]] > i - 1 - d[s[i]]);
		d[s[i]]++;
	}
	cout << ans;
	return 0;
}

