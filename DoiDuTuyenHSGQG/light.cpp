#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 3001 , M = 3501, inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll n , t , c[N][N] , f[N];
bitset<M> s[N];

int main()
{
    file();
  cin >> n >> t;
  for (int i = 1 ; i <= n ; i++)
   {
   	s[i][i] = 1;
   	int u , v;
	cin >> u >> v;
	s[u][v] = s[v][u] = 1;
   }
   for (int i = 1 ; i <= t ; i++) 
    for (int j = 1 , x; j <= n ; j++) 
     cin >> x , s[j][n + i] = 1 - x;
   for (int i = 1 ; i <= n ; i++)
    for (int j = 1 ; j <= n ; j++)
     	if(s[i][j] == 1)
   		  {
   		  	for (int k = 1 ; k <= n ; k++)
   		  	{
   		  	  if(k == i || !s[k][j] ) continue;	
   		  	  s[k] = s[k] ^ s[i];
			}
			break;
		  }
    for (int i = 1 ; i <= n ; i++)
    for (int j = 1 ; j <= n ; j++)
    if(s[i][j])
    {
      f[i] = j;
      break;
	}
   for (int i = n + 1 ; i <= n + t ; i++)
   {
   	    int ans = 0;
   	    vector<int> res;
   	    bool check = true;
   	        for (int j = 1 ; j <= n ; j++)
   	           {
   	           	int k = f[j];
   		            if (s[j][i] == 1 && s[j][k] == 0) check = false;
   		            if(s[j][i] == 1 && s[j][k] == 1) res.pb(k) , ans++;
	           }
       if (check == false) cout << -1;
       else
       {
       	 cout << ans << ' ';
       	 for (auto x : res) cout << x << ' ';
	   }
   cout << '\n';
   }
  
}
