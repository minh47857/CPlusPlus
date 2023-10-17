#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 2005 , MOD = 1e9 + 7 , inf = 1e15;
int n ;
void file()
{
//	freopen(".inp" , "r" , stdin);
//	freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
namespace sub1
{
	int score[14] , d[14] , b[14] , w[14];
	pair<int , int> p[14];
	vector<int> res;
	void check()
	{
		for (int i = 1 ; i <= n ; i++) p[i].fi = score[i] + (1 << res[i - 1]) , p[i].se = i;
		sort(p + 1 , p + n + 1);
		int tt = 1;
		for (int i = 1 ; i <= n ; i++)
		{
			if (p[i].fi != p[i - 1].fi) tt = i;
			b[p[i].se] = max(b[p[i].se] , tt);
			w[p[i].se] = min(w[p[i].se] , tt);
		}
	}
	void gen(int t)
	{
		for (int i = 1  ; i <= n ; i++)
		{
			if (d[i] == 1) continue;
			d[i] = 1;
			res.pb(i);
			if (t == n) check();
			else gen(t + 1);
			d[i] = 0 ;
			res.pop_back();
		}
	}
	void solve()
	{
		for (int k = 1 ; k <= 2 ; k++)
		for (int i = 1 ; i <= n ; i++) 
		{
			int x;
			cin >> x ;
			score[i] += (1 << x);
			b[i] = 1 , w[i] = n;
		}
		gen(1);
		for (int i = 1 ; i <= n ; i++) cout << w[i] << ' ' << b[i] << '\n';
	}
}
namespace sub2
{
	struct Bit
	{
		int fi , se , rd , pos;
	};
	bool operator < (Bit&a , Bit&b)
	{
		if (a.fi < b.fi) return true;
		if (a.fi == b.fi)
		{
			if (a.se < b.se) return true;
			if (a.se == b.se && a.rd < b.rd) return true;
		}
		return false;
	}
	Bit x[2005];
	ll b[2005] , w[2005];
	Bit add(Bit a , int k)
	{
		 Bit nres;
	   if (k == max({k , a.fi , a.se})) nres = {k , a.fi , a.se , a.pos};
	   else
	   {
	   	if (k == min({k , a.fi , a.se})) nres = {a.fi , a.se , k , a.pos};
	   	else nres = {a.fi , k , a.se , a.pos};
	   }
	   if (nres.rd == nres.se) nres.se++ , nres.rd = 0;
	   if (nres.fi == nres.se) nres.fi++ , nres.se = 0;
	   nres = {nres.fi , max(nres.se , nres.rd) , min(nres.se , nres.rd) , nres.pos};
	   return nres;
	}
	bool com(Bit a , Bit b , int p)
	{
		if (p == 0) 
			if (a.fi == b.fi && a.se == b.se && a.rd == b.rd) return true;
		if (p == 1)
		{
			if (a.fi < b.fi) return true;
		  if (a.fi == b.fi)
		  {
			if (a.se < b.se) return true;
			if (a.se == b.se && a.rd < b.rd) return true;
		  }
		}
		if (p == 2) if (com(b , a , 1)) return true;
		return false;
	}
	void calc_worst(int v)
	{
		Bit f[2005];
		int u = v;
		for (int i = 1 ; i <= n ; i++) f[i] = x[i];
		while(f[u].fi == f[u + 1].fi && f[u].se == f[u + 1].se) u++;
		f[u] = add(f[u] , 1);
	//	cout << f[u].fi << ' ' << f[u].se << ' ' << f[u].rd << endl;
		int tt = u , num = 2;
		for (int i = u - 1 ; i >= 1 ; i--)
		{
			for ( ; num <= n ; num++)
			{
				Bit val = add(f[i] , num);
			//	cout << val.fi << ' ' << val.se << ' ' << val.rd << endl;
			   if (com(f[u] , val , 1) || com(f[u] , val , 0)) 
			   {
			   	num++ , tt--;
			   	break;
			   }
			}
		}
	//	cout << x[v].pos << ' ' << tt << endl;
		w[x[v].pos] = tt;
	}
	void calc_best(int v)
	{
		Bit f[2005];
		int u = v;
		for (int i = 1 ; i <= n ; i++) f[i] = x[i];
		while(f[u].fi == f[u + 1].fi && f[u].se == f[u + 1].se) u++;
		f[u] = add(f[u] , n);
	//	cout << f[u].fi << ' ' << f[u].se << ' ' << f[u].rd << endl;
		int tt = u , num = n - 1;
		for (int i = u + 1 ; i <= n ; i++)
		{
			for ( ; num >= 1 ; num --)
			{
				Bit val = add(f[i] , num);
			//	cout << val.fi << ' ' << val.se << ' ' << val.rd << endl;
			   if (com(f[u] , val , 2)) 
			   {
			   	num-- , tt++;
			   	break;
			   }
			}
		}
		//cout << x[v].pos << ' ' << tt << endl;
		b[x[v].pos] = tt;
	}
	void solve()
	{
		for (int i = 1 ; i <= n ; i++) cin >> x[i].fi;
		for (int i = 1 ; i <= n ; i++) cin >> x[i].se  , x[i] = {max(x[i].fi , x[i].se) , min(x[i].fi , x[i].se) , 0 , i} , x[i] = add(x[i] , 0);
	    sort(x + 1 , x + n + 1);
	  //  for (int i = 1 ; i <= n ; i++) cout << x[i].fi << ' ' << x[i].se << '\n';
	    for (int i = 1 ; i <= n ; i++)
		{
			if (x[i].fi == x[i - 1].fi && x[i].se == x[i - 1].se) b[x[i].pos] = b[x[i - 1].pos] ,  w[x[i].pos] = w[x[i - 1].pos];
			else calc_worst(i) , calc_best(i);
		}	
		for (int i = 1 ; i <= n ; i++) cout << w[i] << ' ' << b[i] << '\n';
	}
	
}
int main()
{
	file();
    cin >> n ;
    	sub2::solve();
	return 0;
}

