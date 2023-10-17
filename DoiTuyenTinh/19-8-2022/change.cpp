#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("change.inp" , "r" , stdin);
	freopen("change.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

string s;
int n , d[15];

int main() {
	file();
	cin >> s;
	reverse(s.begin() , s.end());
	n = s.size();
	s = ' ' + s;
	d[s[1] - '0']++;
	for(int i = 2 ; i <= n ; i++) {
		bool ok = false;
		int x;
		d[s[i] - '0']++;
		for(int c = s[i] - '0' + 1 ; c <= 9 ; c++) if(d[c]) {
			x = c;
			d[c]--;
			ok = true;
			break;
		}
		if(!ok) continue;
		cout << 1 << '\n';
		for(int j = n ; j >= i + 1 ; j--) cout << s[j];
		cout << x;
		for(int c = 0 ; c <= 9 ; c++) 
			while(d[c]) cout << c , d[c]--;
		return 0;
	}
	cout << 0;
	return 0;
}

