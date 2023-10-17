#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , type , nx[N][30] , cnt = 0;
string str;
pair<int , int> num[N];

void insert(string s)
{
	int cur = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(nx[cur][s[i] - 'a'] == -1) nx[cur][s[i] - 'a'] = ++cnt;
		cur = nx[cur][s[i] - 'a'];
	//	cout << cur << ' ' ;
		num[cur].fi++;
		if(i == s.size() - 1) num[cur].se++;
	}
//	cout << endl;
}

int get1(string s)
{
	int cur = 0 , ans = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(nx[cur][s[i] - 'a'] == -1) break;
		cur = nx[cur][s[i] - 'a'];
	//	cout << cur << ' ' << num[cur].se << ' ' << num[cur].fi << endl;
		ans += num[cur].se;
	}
	//cout << endl;
	return ans;
}

int get2(string s)
{
	int cur = 0 ;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(nx[cur][s[i] - 'a'] == -1) return 0;
		cur = nx[cur][s[i] - 'a'];
	}
	return num[cur].fi;
}

int main()
{
	file();
  cin >> n;
  memset(nx , -1 , sizeof(nx));
  for(int i = 1 ; i <= n ; i++)
  {
  	cin >> type >> str;
  	if(type == 0) insert(str);
  	if(type == 1) cout << get1(str) << '\n';
  	if(type == 2) cout << get2(str) << '\n';
  }
  return 0;
}

