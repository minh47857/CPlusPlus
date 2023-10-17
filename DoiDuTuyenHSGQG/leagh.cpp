#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000005;
ll n , m, q, num[N], qr[N], x;
int d [10000005];
pi stmax[4*N], stmin[4*N];
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
pi cbmax(pi a, pi b)
{
	if(a.fi > b.fi)  return a;
	if(a.fi == b.fi)  return {a.fi, min(a.se , b.se)};
	return b;
}

pi cbmin(pi a, pi b)
{
	if(a.fi < b.fi)  return a;
	if(a.fi == b.fi)  return {a.fi, min(a.se , b.se)};
	return b;
}

void build(int id, int l, int r)
{
	if(l == r) 
	{
		stmax[id] = {num[l], l};
		stmin[id] = {num[l], l};
		return ;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	stmax[id] = cbmax(stmax[id * 2],stmax[id * 2 + 1]);
	stmin[id] = cbmin(stmin[id * 2],stmin[id * 2 + 1]);
}
void update(int id, int l, int r, int x)
{
	if(l > x || r < x) return ;
	if(l == r) 
	{
		stmax[id].fi++;
		stmin[id].fi++;
		return ;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, x);
	update(id * 2 + 1, mid + 1, r, x);
	stmax[id] = cbmax(stmax[id * 2], stmax[id * 2 + 1]);
	stmin[id] = cbmin(stmin[id * 2], stmin[id * 2 + 1]);
}

int main()
{
	file();
     cin >> n >> m >> q;
     for (int i = 1; i <= n ; i++)  cin >> x , num[x]++ , d[i] = x;
     for  (int i = 1; i <= q ; i++)  cin >> qr[i];
     build(1, 1 , m);
     while( stmax[1] != stmin[1] ) 
	 {
	 	n ++;
	 	d[n] = stmin[1].se;
	 	update(1, 1, m, stmin[1].se);
	 }
	 for (int i = 1; i <= q; i++)
	 {
	 	if ( qr[i] <= n) cout << d[qr[i]] << '\n';
	 	else 
		 {
		    int	res = (qr[i] - n ) % m;
		 	if (res == 0) cout << m << '\n';
		 	else cout << res << '\n';
		 }
	 }
	 
}


