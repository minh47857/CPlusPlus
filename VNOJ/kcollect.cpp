#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 10005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m , score[N] , low[N] , num[N] , a[N] , root[N] , numCpn = 0 , Time = 0 , f[N];
char str[105][105];
bool exist[N];
stack<int> st;
vector<int> adj[N] , newadj[N];

int id(int i , int j)
{
	return (i - 1) * n + j;
}

bool check(int i , int j)
{
	if(str[i][j] == '#' || i < 1 || i > m || j < 1 || j > n) return false;
	return true;
}

void Dfs(int u)
{
	st.push(u);
	num[u] = low[u] = ++Time;
	for(auto v : adj[u])
	{
		if(!exist[v]) continue;
		if(!num[v]) 
		{
			Dfs(v);
			low[u] = min(low[v] , low[u]);
		}
		else low[u] = min(low[u] , num[v]);
	}
//	cout << u << ' ' << num[u] << ' ' << low[u] << endl;
	/*if(num[u] == low[u])
	{
		cout << u << '\n';
		++numCpn;
		int v;
		score[numCpn] = a[u];
		exist[u] = false;
		while(u != (v = st.top()))
		{
			st.pop();
			root[v] = numCpn;
			exist[v] = false;
			score[numCpn] += a[v];
		}
		st.pop();
	}*/
	
	cout << u << ' ' << num[u] << ' ' << low[u] << endl;
	if (num[u] == low[u]) 
	{
        numCpn++;
        int v;
        do 
		{
            v = st.top();
            st.pop();
            exist[v] = false;
            score[numCpn] += a[v];
            root[v] = numCpn;
        } while (v != u);
    }
    cout << numCpn << endl;
}

int DP(int u)
{
//	cout << u << endl;
	if(f[u] != -1) return f[u];
	int cnt = 0;
	for(auto v : newadj[u])	cnt = max(DP(v) , cnt) ;
	f[u] = cnt + score[u];
	return f[u];
}

int main()
{
  cin >> m >> n;
  memset(f , -1 , sizeof(f));
  memset(exist , true , sizeof(exist));
  
  for(int i = 1 ; i <= m ; i++)
    for(int j = 1 ; j <= n ; j++)
      cin >> str[i][j] , a[id(i , j)] = ((str[i][j] <= '9' && str[i][j] >= '0') ? (str[i][j] - '0') : 0);
      
  for(int i = 1 ; i <= m ; i++)
    for(int j = 1 ; j <= n ; j++)
      {
      	if(!check(i , j)) continue;
      	
      	int u = id(i , j);
      	
      	if(check(i + 1 , j)) adj[u].pb(id(i + 1 , j));
      	if(check(i , j + 1)) adj[u].pb(id(i , j + 1));
      	if(str[i][j] == 'W' && check(i , j - 1)) adj[u].pb(id(i , j - 1));
      	if(str[i][j] == 'N' && check(i - 1 , j)) adj[u].pb(id(i - 1 , j));
	  }
	// cout << "?"; 
  for(int i = 1 ; i <= m ; i++)
   for(int j = 1 ; j <= n ; j++)
    	if(!num[id(i , j)] && check(i , j)) Dfs(id(i , j)) , cout << endl;
 //  cout << "?";
   for(int i = 1 ; i <= m ; i++)
     for(int j = 1 ; j <= n ; j++)
	  {
	  	int u = id(i , j);
	  	for(auto v : adj[u])  if(root[u] != root[v]) newadj[root[u]].pb(root[v]);
	  }	
	//  cout << "?";
  cout << DP(root[id(1 , 1)]);
}

