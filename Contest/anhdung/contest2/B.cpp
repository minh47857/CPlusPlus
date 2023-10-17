#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 2e3 + 5 , inf = 1e9 + 7;

void file() {
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , a[N] , Min = inf;
map<int , int> d;
vector<int> res;

int solve(vector<int> s) {
	vector<int> ans;
	bool check = true;
	for(int i = 0 ; i < s.size() ; i++)
	  for(int j = 0 ; j < s.size() ; j++) 
	  {
    	int G;
    	G = __gcd(s[i] , s[j]);
    	if(d[G] == 0 && G <= Min) ans.pb(G) , check = false; 
    	d[G]++;
	}
	 if(!check) return solve(ans) + ans.size();
	 else {
	 	return ans.size();
	 }  
}

int main() {
	file();
  cin >> n;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , Min = min(Min , a[i]);
  for(int i = 1 ; i <= n ; i++) 
    for(int j = 1 ; j <= n ; j++){
    	int G;
    	G = __gcd(a[i] , a[j]);
    	if(d[G] == 0 && G <= Min) res.pb(G); 
    	d[G]++;
	}
 cout << solve(res) + res.size();
 return 0;
}

