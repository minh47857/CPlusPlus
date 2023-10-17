#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)
#define pb push_back

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("printnum.inp" , "r" , stdin);
	freopen("printnum.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int n , a[15];
vector<int> ans;

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	for(int i = 1 ; i <= n ; i++) 
		for(int j = 1 ; j <= n ; j++)
			for(int k = 1 ; k <= n ; k++)
				if(a[i] < a[j] && a[j] < a[k]) ans.pb(a[i] * 100 + a[j] * 10 + a[k]);
	sort(ans.begin() , ans.end());
	for(auto i : ans) cout << i << '\n';
}

