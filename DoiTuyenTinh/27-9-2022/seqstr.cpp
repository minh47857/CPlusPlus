#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("seqstr.inp" , "r" , stdin);
	freopen("seqstr.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k , d[55];
string s[N];
ll ans;

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	for(int i = 1 ; i <= k + 1 ; i++) 
		ans += d[s[i].size()] , d[s[i].size()]++;
	for(int i = k + 2 ; i <= n ; i++)
		d[s[i - k - 1].size()]-- , ans += d[s[i].size()] , d[s[i].size()]++;
	cout << ans;
}

