#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int x , ans = 0;

int main() {
		cin >> x;
		for(int i = 2 ; i <= sqrt(x) ; i++) {
			int res = 1;
			while(res <= x) 	res *= i;
			res /= i;
			if(res != i) ans = max(ans , res);
		}
		cout << ans;
		return 0;
} 

