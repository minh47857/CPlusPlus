#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll t , n , s;
int main()
{
	file();
	cin >>t;
  while(t--)
  {
  	cin >> n >> s;
  	if(n % 2 == 0) cout << s / (n - n / 2 + 1) << '\n';
  	else cout << s / (n - n / 2) << '\n';
  }
}

