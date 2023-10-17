#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 105 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("timk.inp" , "r" , stdin);
	freopen("timk.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , k;
string s , a[N];

int main() {
	file();
	cin >> n >> s;
	s = ' ' + s;
	for(int t = 1 ; t <= n ; t++) {
		bool ok = true;
		for(int i = 1 ; i <= n - t + 1 ; i++) a[i] = s.substr(i , t);
		sort(a + 1 , a + n - t + 2);
		for(int i = 1 ; i <= n - t + 1 ; i++) 
			if(a[i] == a[i - 1]) ok = false;
		if(ok) {
			k = t;
			break;
		}
	}
	cout << k;
	return 0;	
}

