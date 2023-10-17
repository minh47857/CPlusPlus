#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define Bit(x , k) ((x >> k) & 1)

using namespace std;
const int N = 1e7 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("kdele.inp" , "r" , stdin);
	freopen("kdele.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie() ; cout.tie(0);
}

ll n;
int k , c[N];

int main() {
	file();
	cin >> n >> k;
	for(int i = 2 ; i <= n; i++)
		if(!c[i]){
			k--;
			if(!k) {
				cout << i;
				return 0;
			}
			for(int j = min(n + 1 , 1LL * i * i) ; j <= n ; j += i) {
				if(c[j] == 0) k--;
				c[j] = 1;
				if(!k) {
					cout << j;
					return 0;
				}
			}
		}
}

