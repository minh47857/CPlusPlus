#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 1000001 , MOD = 1e9 +7 , inf = 1e9;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct node
{
	int l , r , val;
};

int n , d[30];
node ans;
string str;

bool cmp(int a, int b)
{
	return a > b;
}

 node getmax(node a , int l , int r , int val)
 {
 	int len1 = a.r - a.l + 1 , len2 = r - l + 1;
 	if(a.val * len2 > val * len1) return {l , r , val};
 	return a;
 }
 
int main()
{
	file();
 cin >> n >> str;
 str = ' ' + str;
 ans = {1 , 1 , inf};
 for(int i = 1 ; i <= n ; i++)
 {
 	vector<int> apb;
 	d[str[i] - 'a'] = i;
 	for(int j = 0 ; j <= 27 ; j++) if(d[j] != 0) apb.pb(d[j]) ;
 	sort(apb.begin() , apb.end() , cmp);
 	apb.pb(0);
 	for(int j = 0 ; j < apb.size() - 1 ; j++) ans = getmax(ans , apb[j + 1] + 1, i , j + 1) ;
 }
 cout << ans.l << ' ' << ans.r;
 return 0;
}

