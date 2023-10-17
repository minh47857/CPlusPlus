#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("thesis.inp" , "r" , stdin);
	freopen("thesis.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , ans = 0;
string str;
vector<int> s;

int main() {
	file();
	cin >> n >> str;
	for(int i = 0 ; i <= n - 1 ; i++) if(str[i] == 'T') s.pb(i);
	for(int i = 0 , j = 0 ; i <= n - 1 ; i += 2 , j++) ans += abs(s[j] - i);
	cout << ans;
	return 0;
}


