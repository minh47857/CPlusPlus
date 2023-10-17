#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
    freopen("USS.inp" , "r" , stdin);
	freopen("USS.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int k[25] , s[25] , a[N][25] , n;

int main() {
//	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) cin >> k[i];
	s[n + 1] = 1;
	for(int i = n ; i >= 1 ; i--) s[i] = s[i + 1] * k[i];
	
	for(int i = n , x ; i >= 1 ; i--) {
		a[0][i] = 0;
		x = -1;
		for(int j = 1 , num ; j <= s[1] ; j++) {
			int dem = 1;
			if((j - 1) % s[i] == 0) num = a[j - 1][i] , x = -x;
			else num = a[j - 1][i] + x;
			a[j][i] = num;
			while(dem != s[i + 1]) {
				a[++j][i] = num;
				dem++;
			}
		}
	}
	
	cout << s[1] - 1 << '\n';
	
    for(int i = 2 ; i <= s[1] ; i++) {
    	for(int j = 1 ; j <= n ; j++)
    	cout << a[i][j] << ' ';
    	cout << '\n';
	}
	
	return 0;
}


