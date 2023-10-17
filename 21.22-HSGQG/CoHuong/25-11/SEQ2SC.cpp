#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e3 + 5 , inf = 1e9 + 7;

void file() {
	freopen("SEQ2SC.inp" , "r" , stdin);
	freopen("SEQ2SC.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll a[N] , b[N] , Q[N * N];
ll n , k , m , G , E , S;

ll BinaryL(ll x) {
	ll d = 1 , c = k , res = 0 , g;
	while(d <= c) {
		g = (d + c) / 2;
		if(Q[g] < x) res = g , d = g + 1;
		else c = g - 1;
	}
	return res;
}

ll BinaryR(ll x) {
	ll d = 1 , c = k , res = k + 1 , g;
	while(d <= c) {
		g = (d + c) / 2;
		if(Q[g] > x) res = g , c = g - 1;
		else d = g + 1;
	}
	return res;
}

int main() {
	file();
	cin >> m >> n;
	for(ll i = 1 , x ; i <= m ; i++) cin >> x , a[i] = a[i - 1] + x;
	for(ll i = 1 , x ; i <= n ; i++) cin >> x , b[i] = b[i - 1] + x;
    for(int i = 1 ; i <= n ; i++)
    for(int j = i ; j <= n ; j++) Q[++k] = b[j] - b[i - 1];
    sort(Q + 1 , Q + k + 1);
    for(int i = 1 ; i <= m ; i++)
    for(int j = i ; j <= m ; j++) {
    	ll s = a[j] - a[i - 1];
        int l = BinaryL(s) , r = BinaryR(s);
        S += k - r + 1 , E += r - l - 1, G += l;
	}
	cout << S << ' ' << E << ' ' << G;
	return 0;
}

