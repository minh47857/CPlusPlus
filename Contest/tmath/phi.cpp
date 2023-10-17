#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
#define Bit(x , k) ((x >> k) & 1)
using namespace std;

const int N = 2e5 + 5 , M = 1e6 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , a[N] , f[M + 5];
ll bit[N];
set<int> pos;

void calc() {
	for(int i = 1 ; i <= 1e6 ; i++) f[i] = i;
	for(int i = 2 ; i <= 1e6 ; i++) 
		if(f[i] == i)  
			for(int j = i ; j <= 1e6 ; j += i) f[j] -= f[j] / i;	
}

ll get(int i) {
	ll res = 0;
	for( ; i >= 1 ; i -= (i & (-i)))
		 res += bit[i];
	return res;
}

void update(int i , int tmp) {
		for( ; i <= n ; i += (i & (-i))) 
		bit[i] += tmp;
}

int main() {
	file();
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) cin >> a[i];
	calc();
	for(int i = 1 ; i <= n ; i++) 
		if(a[i] != 1) pos.insert(i);
	for(int i = 1 ; i <= n ; i++)
		update(i , a[i]);
	while(m--) {
		int t , x , y;
		cin >> t >> x >> y;
		if(t == 1) {
			auto it = pos.lower_bound(x);
			while(it != pos.end() && *it <= y) {
				x = *it;
				int val = f[a[x]];
				update(x , val - a[x]);
				if(val == 1) it = pos.erase(it);
				else it++;
				a[x] = val;	
			}
		}
		else if(t == 2) {
			if(x == y) cout << a[x] << '\n';
			else cout << get(y) - get(x - 1) << '\n';
		}
		else {
			if(a[x] == 1 && y != 1) pos.insert(x);
			else if(a[x] != 1 && y == 1) pos.erase(x);
			update(x , y - a[x]);
			a[x] = y;
		}
	}
	return 0;
}
