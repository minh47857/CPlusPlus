 #include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	freopen("absseq.inp" , "r" , stdin);
	freopen("absseq.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll p , q , n , a[N];

int main() {
	file();
   cin >> p >> q >> n;
   if(n < N) {
   	a[1] = p , a[2] = q;
   	for(int i = 3 ; i <= n ; i++) a[i] = abs(a[i - 2] - a[i - 1]);
   	cout << a[n];
   }
}

