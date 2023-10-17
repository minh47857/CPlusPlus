#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
using namespace std;
const int N = 1e7 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("knto.inp" , "r" , stdin);
	freopen("knto.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

ll n , ans = 1 , k;

int main() {
	file();
	cin >> n;
	for(int i = 2 ; i <= sqrt(n) ; i++) if(n % i == 0) {
		k++;
		int dem = 0;
		while(n % i == 0) {
			n /= i;
			dem++;
		}
		ans *= (dem + 1);
	}
	if(n != 1) ans *= 2 , k++;
	cout << ans - k;
	return 0;
}
