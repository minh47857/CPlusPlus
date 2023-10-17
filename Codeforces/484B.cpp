#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const int N = 1e6 + 5 , MOD = 1e9 + 7 , inf = 1e9 + 7;

int n , exist[2 * N] , NumMax[2 * N] , ans = 0;
vector<int> A;

int main() {
	cin >> n;
	for(int i = 1 , x ; i <= n ; i++) 
		cin >> x , A.pb(x) , exist[x] = true;
	sort(A.begin() , A.end());
	A.erase(unique(A.begin() , A.end()) , A.end());
	for(int i = 1 ; i < 2 * N ; i++) 
		NumMax[i] = max(NumMax[i - 1] , exist[i] * i);
	for(int x : A) 
		for(int i = x ; i < N ; i += x) 
			if(NumMax[i + x - 1] > i) 
				ans = max(ans , NumMax[i + x - 1] - i);
	cout << ans;
	return 0;
}

