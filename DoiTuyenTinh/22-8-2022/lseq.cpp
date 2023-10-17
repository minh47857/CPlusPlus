#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pi pair<int , int>
using namespace std;

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("lseq.inp" , "r" , stdin);
	freopen("lseq.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , p , res , a[N] , l[N] , r[N];

int main() {
	file();
	cin >> n;
	for(int i = 1 ; i <= n ; i++) 
		cin >> a[i] , p |= (a[i] == 0);
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i++)
		if(a[i] == a[i - 1] + 1) l[i] = l[i - 1] + 1 , res = max(res , l[i]);
		else l[i] = 1;	
	if(!p) {
		cout << res;
		return 0;
	} 
	for(int i = n ; i >= 1 ; i--)
		if(a[i] == a[i + 1] - 1) r[i] = r[i + 1] + 1;
		else r[i] = 1;
	for(int i = 1 ; i <= n ; i++) 
		if(l[i] != i) {
			res = max(res , l[i] + 1);
			if(a[i + 1] - a[i] == 2) res = max(res , l[i] + r[i + 1] + 1);
		}
	cout << res;
	return 0;
}

