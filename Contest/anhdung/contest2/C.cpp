#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const ll N = 10000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n, m , a[N] , d[N] , Mex;

int main() {
  cin >> n >> m;
  for(int i = 1 ; i <= n ; i++) cin >> a[i];
  for(int i = 1 ; i <= m ; i++) d[a[i]]++;
  for(int i = 0 ; i <= n ; i++) {
  	if(d[i] == 0) {
  		Mex = i ;
  		break;
	  }
  }
  for(int i = m + 1 ; i <= n ; i++) {
  	d[a[i]]++;
  	d[a[i - m]]--;
  	if(d[a[i - m]] == 0) Mex = min(Mex , a[i - m]);
  }
  cout << Mex;
}

