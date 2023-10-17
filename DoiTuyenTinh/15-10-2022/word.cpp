#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("word.inp" , "r" , stdin);
	freopen("word.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , k , sum;
string s[N];

int main() {
	file();
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++) cin >> s[i];
	for(int i = 1 ; i <= n ; i++) {
		sum += s[i].size();
		cout << s[i];
		while(i < n && sum + s[i + 1].size() <= k) i++ , cout << ' ' << s[i] , sum += s[i].size();
		sum = 0;
		cout << '\n';
	}
	return 0;
}

