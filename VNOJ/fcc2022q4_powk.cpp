#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;

int main() {
    cin >> n;
    while(n--) {
        ll x; cin >> x;
        if(x > 1 && x % 2) cout << (x + 1) / 2 << ' ' << (x - 1) / 2;
        else if(x != 4 && x % 4 == 0) cout << (x / 2 + 2) / 2 << ' ' << (x / 2 - 2) / 2;
        else cout << "impossible";
        cout << '\n';
    }
}
