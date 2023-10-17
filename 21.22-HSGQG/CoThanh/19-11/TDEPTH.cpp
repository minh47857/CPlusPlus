#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second
#define pb push_back

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
//    freopen("TDEPTH.inp" , "r" , stdin);
//	freopen("TDEPTH.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , s = 0 , k , pos , p;

int main() {
    file();
	cin >> n;
	for(int i = 0 ; i <= 55 ; i++) {
		s += (1LL << i);
		if(s - 1 >= n) {
			k = i;
			break;
		}
	}
	cout << k << '\n';
	//cout << (1LL << (k)) - 1 << '\n';
	p = s - (1LL << (k - 1)) - 1;
	if(n <= p ) {
		pos = n - (s - (1LL << k) - 1);
		pos = 2 * pos - 1;
	}
	else {
		pos = n - p;
		pos = 2 * pos;
	}
	s--;
	cout << s + pos << ' ' << s + (1LL << k) + pos;
//	cout << s << ' ' << pos << ' ' << p ;
	return 0;
}


