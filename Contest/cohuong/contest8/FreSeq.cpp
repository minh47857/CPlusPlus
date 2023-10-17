#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const int N = 100005 , inf = 1e9 + 7;

void file()
{
	freopen("FreSeq.inp" , "r" , stdin);
	freopen("FreSeq.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n , q , a[N] , Max = -inf , Min = inf;

namespace sub1
{
	void solve()
	{
		for(int i = 1 ; i <= q ; i++)
		{
			int l , r , ans = 0;
			map<int , int> d;
			cin >> l >> r;	
			for(int i = l ; i <= r ; i++) d[a[i]]++ , ans = max(d[a[i]] , ans);
			cout << ans << '\n';
		}
	}
}

namespace sub2
{
	int d[N][15];
	void solve()
	{
		for(int i = 1 ; i <= n ; i++) 
		{
			for(int j = 0 ; j <= 10 ; j++) d[i][j] = d[i - 1][j];
			d[i][a[i]]++;
		}
		for(int i = 1 ; i <= q ; i++)
		{
			int l , r , ans = 0;
			cin >> l >> r;
			for(int j = 0 ; j <= 10 ; j++) ans = max(ans , d[r][j] - d[l - 1][j]);
			cout << ans << '\n';
		}
	}
}

namespace sub3
{
	int dem , m = 0 , st[4 * N] , s[N];
	map<int , int> start , end , pos;
	
	void build(int id , int l , int r)
	{
		if(l == r)
		{
			st[id] = s[l];
			return;
		}
		
		int mid = (l + r) / 2;
		build(id *2 , l , mid);
		build(id * 2 + 1 , mid + 1 , r);
		st[id] = max(st[id * 2] , st[id * 2 + 1]);
	}
	
	int get(int id , int l , int r , int u , int v)
	{
		if(l > v || r < u) return 0;
		if(l >= u && r <= v) return st[id];
		
		int mid = (l + r) / 2;
		return max(get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1 , r , u , v));
	}
	
	void solve()
	{
		for(int i = 1 ; i <= n ; i++)
		{
			dem = 1;
			start[a[i]] = i;
			while(i < n && a[i] == a[i + 1]) i++ , dem++;
			end[a[i]] = i;
			s[++m] = dem;
			pos[a[i]] = m;
		//	cout << start[a[i]] << ' ' << end[a[i]] << ' ' << s[m] << ' ' << pos[a[i]] << '\n';
		}
        
        build(1 , 1 , m);

        for(int i = 1 ; i <= q ; i++)
        {
        	int l , r , id1 , id2 , res = 0;
        	cin >> l >> r;
        	if(a[l] == a[r])
        	{
        		cout << r - l + 1 << '\n';
        		continue;
			}
        	id1 = end[a[l]];
        	id2 = start[a[r]];
        	res = max(id1 - l + 1 , r - id2 + 1);
        	if(id1 >= id2)
        	{
        		cout << res << '\n';
        		continue;
			}
          res = max(res , get(1 , 1 , m , pos[a[id1 + 1]] , pos[a[id2 - 1]]));
		  cout << res << '\n';	
		}
	}
}

int main()
{
	file();
  cin >> n >> q;
  for(int i = 1 ; i <= n ; i++) cin >> a[i] , Max = max(a[i] , Max) , Min = min(a[i] , Min);
  if(n <= 1000 && q <= 1000) sub1::solve();
    else if(Max <= 10 && Min >= 0) sub2::solve();
       else sub3::solve();
}

