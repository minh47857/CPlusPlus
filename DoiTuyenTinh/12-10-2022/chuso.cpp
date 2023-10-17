#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9;

void file() {
	freopen("chuso.inp" , "r" , stdin);
	freopen("chuso.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

string s , p;
int n , m , l , res;

int main() {
	file();
	cin >> s >> n >> m;
	l = s.size();
	p = s; reverse(p.begin() , p.end());
	s = ' ' + s + p;
	for(int i = 1 ; i <= n ; i++) l *= 2;
	if(m > l) cout << -1;
	else res = m % int(s.size() - 1) ,  cout << s[((res) ? res : 1)];
	return 0;
}

