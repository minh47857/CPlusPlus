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
	freopen("DMT.inp" , "r" , stdin);
	freopen("DMT.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 ll d[N] , f[N] , t , l , r , a , b;

void sieve()
{
	d[1] = 1 , d[0] = 1;
	for (int i = 2 ; i <= sqrt(N) ; i++)
    	if(!d[i]) for (int j = i * i ; j < N ; j += i)  d[j] = 1;
    d[3] = 1;
	for (int i = 1 ; i < N ; i ++)
	{
		f[i] = f[i - 1];
	  if(!d[i] || i == 27) f[i]++;
	}
}

int main()
{
	file();
  cin >> t;
  sieve();
  while(t--)
  {
  	cin >> l >> r;
  	l--;
  	a = sqrt(l);
  	b = sqrt(r);
  	a /= 3;
  	b /= 3;
  	cout << f[b] - f[a] << '\n';
  }
  return 0;
}

