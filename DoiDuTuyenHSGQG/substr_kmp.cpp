#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 2000001 , MOD = 1e9 +7;
string a , b;
int p[N] , k , n;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
   cin >> a >> b;
	a = ' ' + b + '+' + a;
	int n = a.size() - 1;// a = ' ' + a;
	
	p[1] = 0; k = 0;
	for(int i = 2; i <= n; ++i) {
		while(k > 0 && a[k + 1] != a[i])
			k = p[k];
		if(a[k + 1] == a[i]) k = k + 1;
		p[i] = k;
	}
   for (int i = b.size () + 2; i <= n ; i++) if(p[i] == b.size()) cout << i - 2 * b.size() << ' ';
   return 0;
}

