#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
#define bit(x, i)((x >> (i)) & 1)
const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , k , sum , a[N];

namespace sub1 {
	ll s[15] , d[15] , ans[15];
	bool check() {
		int res = 0;
		ll pre = 0;
		for(int i = 1 ; i <= n; i++) {
		  pre += a[s[i]];
		  ans[s[i]] = res + 1;
		  if(pre > sum) return false;
		  if(pre == sum)  pre = 0 , res++;
	    }
	    if(res == k) return true;
	    return false;
	}
	void gen(int t) {
		for(int i = 1 ; i <= n ; i++) {
			if(d[i]) continue;
			d[i] = 1;
			s[t] = i;
			if(t == n) {
			   if(check()) {
				  for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
				  exit(0);
			   }
			}
			else gen(t + 1);
			d[i] = 0;
		}
	}
	
	void solve() {
		gen(1);
		cout << -1;
		exit(0);
	}
}

namespace sub2 {
	ll id , f[1 << 23] , pre[1 << 23] , ans[23];
	void solve() {
		memset(f , -1 , sizeof(f));
		f[0] = 0;
		for(int t = 0 ; t < (1 << n) - 1 ; t++) if(f[t] != -1)
		  for(int i = 1 ; i <= n ; i++) if(!bit(t , i - 1) && a[i] + f[t] <= sum) {
		  	int new_t = t | (1 << (i - 1));
		  	f[new_t] = f[t] + a[i];
		  	pre[new_t] = i;
		  	if(f[new_t] == sum) f[new_t] = 0;
		  }
		if(f[(1 << n) - 1] != 0) {
			cout << -1;
			exit(0);
		}
			
		int t = (1 << n) - 1 ;
		ll s = 0;
		id = k;
		while(t) {
			int i = pre[t];
			ans[i] = id;
			s += a[i];
			t = t ^ (1 << (i - 1));
			if(s == sum) {
				id--;
				s = 0;
			}
		}
		for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
		exit(0);
	}
}

namespace sub3 {
	bitset<3500> f[105][3500];
	int ans[105];
	void solve() {
		f[0][0][0] = 1;
		for(int i = 1 ; i <= n ; i++)
		  for(int j = 0 ; j <= sum ; j++) {
		  	f[i][j] |= f[i - 1][j];
		  	f[i][j] |= (f[i - 1][j] << a[i]);
		    if(a[i] + j <= sum) f[i][j + a[i]] |= f[i - 1][j];
		  }
		if(f[n][sum][sum] == 0) {
			cout << -1;
			exit(0);
		}
	int	t = n , s1 = sum , s2 = sum;
		 while(t) {
		 	if(s1 >= a[t] && f[t - 1][s1 - a[t]][s2]) {
		 		ans[t] = 1;
		 		s1 -= a[t];
			 }
			 else if(s2 >= a[t] && f[t - 1][s1][s2 - a[t]]) {
			 	ans[t] = 2;
			 	s2 -= a[t];
			 }
			 else ans[t] = 3;
			 t--;
		 }
		 for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
	     exit(0);
	}	
}

namespace sub45 {
	int id = 1 , m , c[55] , ans[N] , f[55][1500];
	vector<int> pre[55][1500];
	
	void Print() {
		for(int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';
		exit(0);
	}
	
	void calc(int i) {
		if(i == 0) Print();
		if(!c[i]) {
			ans[i] = ++id;
			c[i] = sum;
		}
		
		for(auto j : pre[i][c[i] % sum]) if(!c[j]) {
			ans[j] = ans[i];
			c[j] = c[i] - a[i];
			calc(i - 1);
			c[j] = 0;
		}
		
		if(c[i] == sum) {
			--id;
			c[i] = 0;
		}
	}
	
	void solve() {
		for(int i = 1 ; i <= min(50LL , n) ; i++) if((n - i) % (2 * k) == 0) m = i;
		for(int i = m + 1 ; i <= m + (n - m) / 2 ; i++) {
			ans[i] = id++;
			if(id > k) id = 1;
		}
		for(int i = n ; i >= m + (n - m) / 2 + 1 ; i--) {
			ans[i] = id++;
			if(id > k) id = 1;
		}
		sum = 0;
		for(int i = 1 ; i <= m ; i++) sum += a[i];
		sum /= k;
		for(int i = 1 ; i <= m ; i++) if(a[i] <= sum) 
		    f[i][a[i] % sum] = 1 , pre[i][a[i] % sum].pb(0);
		for(int i = 1 ; i <= m - 1 ; i++) 
		 for(int t = 1 ; t <= sum - 1 ; t++) if(f[i][t]) 
		 	for(int j = i + 1 ; j <= m ; j++) {
		 		ll new_t = t + a[j];
		 		if(new_t <= sum) {
		 			new_t %= sum;
		 			f[j][new_t] = 1;
		 			pre[j][new_t].pb(i);
				 }
			 }
		for(int i = 1 ; i <= m ; i++) 
		 for(int j = 0 ; j < sum ; j++)
		   sort(pre[i][j].begin() , pre[i][j].end() , greater<int>() );
	id = 0;
	calc(m);	   
    cout << -1;	
    }
}

int main() {
	file();
  cin >> n >> k;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , sum += a[i];
  if(sum % k != 0) {
  	cout << -1;
  	return 0;
  }
  sum /= k;
  if(n <= 10) sub1::solve();
  if(n <= 20) sub2::solve();
  if(k == 3 && n <= 100) sub3::solve();
  sub45::solve();
}

