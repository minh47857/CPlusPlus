#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
ll n , j , k  , a[N] , c[N] , b[N] , ans;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
  cin >> n;
  for (int i  = 1 ; i <= n ; i++) cin >> a[i];
  for (int i  = 1 ; i <= n ; i++) cin >> b[i];
  for (int i  = 1 ; i <= n ; i++) cin >> c[i];
  sort(a + 1 , a + n + 1);
  sort(b + 1 , b + n + 1);
  sort(c + 1 , c + n + 1);
  	ans  = 0;
	j = k  = 1;
  for (int i = 1;  i <= n ; i++)
  	for( ; j <= n ; j++)
  	 {
  		if(a[i] < b[j])
  		{
  			for ( ; k <= n ; k++)
  			{
  				if(b[j] < c[k]) 
				  {
				  	ans++ ;
				  	k++;
				  	break;
				  }
			}
  			j++;
  			break;
		}
  		
	  }
  cout << ans;
  return 0;
}

