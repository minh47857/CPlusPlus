#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pi pair <int , int>
#define fi first
#define se second
using namespace std;

const int N = 1e5 + 5 ;

void file() {
	freopen("tripsort.in" , "r" , stdin);
	freopen("tripsort.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0);
}

int t , a[N] , n , b[N];

void sub1() {
	bool check = false , ok = true;
	int res;
	do {
		check = true;
		for(int i = 1 ; i <= n - 2 ; i++) {
			if(a[i] > a[i + 2]) check = false , swap(a[i] , a[i + 2]);
		}
	} while(check == false);
	
	for(int i = 1 ; i < n ; i++) 
	   if(a[i] > a[i + 1]) {
			ok = false;
			res = i;
			break;
		}
	if(ok) cout << "OK" << '\n';
	else cout << res << '\n';
}

void sub2() {
	vector<int> A , B;
	for(int i = 1 ; i <= n ; i += 2) A.pb(a[i]);
	for(int i = 2 ; i <= n ; i += 2) B.pb(a[i]);
	sort(A.begin() , A.end());
	sort(B.begin() , B.end());
	for(int i = 1 , d = 0; i <= n ; i += 2 , d++) b[i] = A[d];
	for(int i = 2 , d = 0; i <= n ; i += 2 , d++) b[i] = B[d];
	for(int i = 1 ; i < n ; i++) {
		if(b[i] > b[i + 1]) {
			cout << i << '\n';
			return;
		}
	}
	cout << "OK" << '\n';
}
int main() {
	file();
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1 ; i <= n ; i++) cin >> a[i];
		if(n <= 100) sub1();
		else sub2();
	}
	return 0;
}
