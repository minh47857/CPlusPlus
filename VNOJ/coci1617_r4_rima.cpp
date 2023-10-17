#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 5e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("coci1617_r4_rima.inp" , "r" , stdin);
	freopen("coci1617_r4_rima.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , ans , dp[N];
string s[N] , a[N];

int find(string x) {
	int d = 1 , c = n , g , res = 0;
	while(d <= c) {
		g = (d + c) / 2;
		if(a[g] >= x) res = g , c = g - 1;
		else d = g + 1;
	}
	if(a[res] != x) return 0;
	else return res;
}

bool cmp(string a , string b) {
	if(a.size() != b.size()) return a.size() > b.size();
	return a > b;
}

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> s[i] , reverse(s[i].begin() , s[i].end()) , a[i] = s[i];
	sort(s + 1 , s + n + 1 , cmp);
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++) {
		cout << s[i] << '\n';
		int tmp = 0;
		string s1 = s[i] , s2 = s[i];
		s2 = s2.erase(s2.size() - 1 , 1);
		for(char c = 'a' ; c <= 'z' ; c++) 
			tmp = max({tmp , dp[find(s1 + c)] + 1 , dp[find(s2 + c)] + 1});
		dp[find(s[i])] = tmp;
		cout << i << ' ' << tmp << '\n';
		ans = max(tmp , ans);
	}
	cout << ans;
	return 0;
}

