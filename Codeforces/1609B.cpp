#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e5 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , q , res = 0;
char s[N];

bool Abc(int i) {
	if(i < 1 || i >= n - 1) return false;
	if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') return true;
	else return false;
}

int main() {
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++) 
		cin >> s[i];
	for(int i = 1 ; i <= n ; i++) 
		if(Abc(i)) res++;
	while(q--) {
		int pos; 
		char val;
		cin >> pos >> val;
		if(Abc(pos - (s[pos] - 'a'))) res--;
		s[pos] = val;
		res = res + Abc(pos - 2) + Abc(pos - 1) + Abc(pos);
		cout << res << '\n';
	}
	return 0;
}

