#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100001;
ll n, m, q, res[N], par[N], des[N], check[N], u[N], v[N], con;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 int root(int v) {
    return par[v] < 0
            ? v
            : (par[v] = root(par[v]));
}

bool merge(int x, int y) 
{
    if ((x = root(x)) == (y = root(y)) )   return false ;
    if (par[y] < par[x])  swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
}
int main()
{
	file();
   cin >> n >> m >> q;
   memset(par , - 1 , sizeof(par)) ;
   con = n;
   for (int i = 1; i <= m ; i++)	cin >> u[i] >> v[i];
   for (int i = 1; i <= q ; i++)  
   {
   	   cin >> des[i] ;
	   check[des[i]] = 1 ;
   }
   for (int i = 1; i <= m ; i++) 
   {
   	   if ( check [i] == 1) continue;
   	   if ( merge(u[i] , v[i])) con --;
   }  
   res[q] = con;
   for(int i = q ; i >= 2 ; i--) 
   {
   	if ( merge (u[des[i]] , v[des[i]])) con-- ;
	    res[i - 1] = con;
   //	cout<< con <<" ";
	      }
   for( int i = 1; i <= q; i++) cout << res[i] << '\n';
   return 0;
}

