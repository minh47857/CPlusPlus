#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("high.inp" , "r" , stdin);
	freopen("high.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int n , b , sum , ans[N];
string s;

int main() {
	file();
	cin >> b >> n >> s;
	reverse(s.begin() , s.end());
	s = ' ' + s;
	for(int i = 1 ; i <= n ; i++) {
		int x = s[i] - '0';
		if(x < b - 1 && sum) {
			for(int j = i + 1 ; j <= n ; j++) ans[j] = s[j] - '0';
			ans[i] = x + 1;
			sum--;
			for(int j = 1 ; j < i ; sum -= ans[j] , j++) 
				ans[j] = ((sum < b - 1) ? sum : (b - 1));
			for(int j = n ; j >= 1 ; j--) cout << ans[j];
			return 0;
		}
		sum += x;
	}
	cout << 0;
	return 0;
}

