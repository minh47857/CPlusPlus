#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

void file() {
	freopen("COCKROACH.inp" , "r" , stdin);
	freopen("COCKROACH.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , s1 = 0 , s2 = 0 , ans;
string str;

int main() {
	file();
   cin >> n >> str;
   str = ' ' + str;
   for(int i = 1 ; i <= n ; i++) {
   	if(i % 2) s1 = s1 + ((str[i] == 'r') ? 0 : 1);
   	else s2 = s2 + ((str[i] == 'b') ? 0 : 1);
   }
   ans = max(s1 , s2);
   s1 = s2 = 0;
   for(int i = 1 ; i <= n ; i++) {
   	if(i % 2 == 0) s1 = s1 + ((str[i] == 'r') ? 0 : 1);
   	else s2 = s2 + ((str[i] == 'b') ? 0 : 1);
   }
   ans = min(ans , max(s1 , s2));
   cout << ans;
   return 0;
}

