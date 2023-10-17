#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1e5 , MOD = 1e9 +7 , inf = 1e15 , M = 55;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , m ;
ll trie[N][3] , nx[N][3] , ans = 0 , f[M][N] , cnt;
vector<int> res;
string str;

void insert(int i , int cur)
{
	if(i > m) 
	{
		res.pb(cur);
		return ;
	}
		if(str[i] == '*') 
		{
			trie[cur][0] = ++cnt;
			insert(i + 1 , cnt);
		}
		trie[cur][1] = ++cnt;
		insert(i + 1 , cnt);
}

int getnode(string s)
{
	int cur = 1;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(trie[cur][s[i] - '0'] != -1) cur = trie[cur][s[i] - '0'] ;
		else return -1;
	}
	return cur;
}

void makenext(int node , string s)
{
	for(int i = 0 ; i <= 1 ; i++)
	{
		if(s.size() == m) 
		{
			nx[node][i] = node;
			continue;
	    }
	    
		string new_str = s + char('0' + i);
		int v = getnode(new_str);
		while(v == -1)
		{
			new_str.erase(0 , 1);
			v = getnode(new_str);
		}
		nx[node][i] = v;
	}
}

void Dfs(int node , string s)
{
	makenext(node , s);
	for(int i = 0 ; i <= 1 ; i++)
	if(trie[node][i] != -1) Dfs(trie[node][i] , s + char(i + '0'));
}

int main()
{
	file();
  cin >> n ;
  cin >> str;
  m = str.size();
  str = ' ' + str;
  
  cnt = 1;
  memset(trie , -1 ,sizeof(trie));
  insert(1 , 1);
  Dfs(1 , "");
  
  f[0][1] = 1;
  for(int i = 0 ; i < n ; i++)
    for(int node = 1 ; node <= cnt ; node++)
       for(int c = 0 ; c <= 1 ; c++)
       f[i + 1][nx[node][c]] += f[i][node]; 
  for(auto x : res) ans += f[n][x];
    cout << ans;
    return 0;
}
