#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10000001 , MOD = 1e9 +7 , inf = 1e15;
ll n , x , d[N];
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
void sieve()
{
	d[1] = 1 , d[0] = 1;
	for (int i = 2 ; i <= sqrt(N - 1) ; i++) 
	{
		if (!d[i]) for (int j =  i * i ; j < N ; j += i) d[j] = 1;
	}
}
int main()
{
	file();
	sieve();
  cin >> n;
  while (n --) 
  {
  	cin >> x;
  	if (!d[x]) cout << "YES" << '\n';
  	else cout << "NO" << '\n';
  }
}

