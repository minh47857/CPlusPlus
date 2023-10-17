#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("daynt.inp" , "r" , stdin);
	freopen("daynt.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

int y , k , d[N] , c[N];

int main() {
	file();
	cin >> k;
	while(cin >> y) d[y] = 1;
	c[1] = c[0] = 1;
	
	for(int i = 2 ; i <= sqrt(1e6) ; i++) 
		if(!c[i]) for(int j = i * i ; j <= 1e6 ; j += i) c[j] = 1;
	for(int i = 2 ; i <= 1e6 ; i++) {
		if(!c[i] && d[i]) {
			cout << i << ' ';
			k--;
		}
		if(!k) break;
	}
}

