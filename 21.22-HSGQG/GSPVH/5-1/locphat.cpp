#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 220797 + 5,
		  num[] = {0 , 1 , 6 , 8};

void file() {
	freopen("locphat.inp" , "r" , stdin);
    freopen("locphat.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct number {
	int s , t , r;
};

int n , k , dp[N][10];
vector<int> v , f[10][10] ,  ans[10];
number trace[N][10];
string str;

void gen(int t) {
	for(int i = 0 ; i < 4 ; i++) {
		v.pb(num[i]);
		if(t == k) {
			int sum = 0;
			for(auto x : v) sum += x;
			f[sum % 10][sum / 10] = v;
		}
		else gen(t + 1);
		v.pop_back();
	}
}

int main() {
	file();
	cin >> str >> k;
	n = str.size();
	reverse(str.begin() , str.end());
	gen(1);
	dp[0][0] = 1;
	for(int i = 0 ; i < n ; i++) {
		for(int r = 0 ; r < k ; r++) {
		
			int s , bonus = 0;
			if(r > str[i] - '0') bonus++ , s = 10 + str[i] - '0' - r;
			else s = str[i] - '0' - r;
			for(int t = 0 ; t < k ; t++) {
				bool check = (f[s][t].size() && dp[i][r]);
				if(!dp[i + 1][bonus + t] && check) trace[i + 1][bonus + t] = {s , t , r};
				dp[i + 1][bonus + t] |= check;
			}
		}
	}
	int i = n , r = 0;
	while(i) {
		int t = trace[i][r].t , s = trace[i][r].s;
		for(int j = 0 ; j < k ; j++) 
			ans[j].pb(f[s][t][j]);
		r = trace[i][r].r , i--;
	}
	for(int i = 0 ; i < k ; i++) {
		bool ok = false;
		for(int j = 0 ; j < ans[i].size() ; j++) {
			if(j != ans[i].size() - 1 && ans[i][j] == 0 && !ok) continue;
			ok = true;
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}

