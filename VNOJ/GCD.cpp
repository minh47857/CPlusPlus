#include<bits/stdc++.h>
using namespace std;
const int N= 1e5 + 5 , M = 5 * 1e6 + 5;
int n , Gcd , ans = 0 , a[N] , d[M] , Max ;
void file()
{
//	freopen("GCD.inp" , "r" , stdin);
//	freopen("GCD.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main() {
	file();
	cin >> n;
	cin >> a[1];
	Gcd = a[1] , Max = a[1];
	for (int i = 2 ; i <= n ; i++) cin >> a[i] , Gcd = __gcd(Gcd , a[i]) , Max = max(Max , a[i]);
	for (int i = 1 ; i <= n ; i++) d[a[i]]++;
	for (int i = Gcd + 1 ; i <= Max ; i++)
	{
		int res = 0;
		for (int j = i ; j <= Max ; j += i) res += d[j];
		ans = max(ans , res);
	}
	if (ans == 0) cout << -1;
	else cout << n - ans;
	
}
