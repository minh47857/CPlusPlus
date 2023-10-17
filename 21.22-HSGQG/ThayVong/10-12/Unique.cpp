#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 123456790;

void file() {
    freopen("Unique.inp" , "r" , stdin);
	freopen("Unique.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int t , ans , X;
vector<int> num;

void gen(int t) {
	for(int i = 0 ; i <= 1 ; i++) {
		if(i) num.pb(t);
		if(t == 9) {
			int s = 0 , y = 0;
			for(auto x : num) {
				s += x;
				y = y * 10 + x;
			}
			if(s == X) 
				ans = min(ans , y);
		}
		else gen(t + 1);
		if(i) num.pop_back();
	}
}

int main() {
	file();
	cin >> t;
	while(t--) {
		ans = inf;
		cin >> X;
		gen(1);
		cout << ((ans == inf) ? -1 : ans) << '\n';
	}
}


