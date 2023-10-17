#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
const int base = 31;
const ll MOD = 1e9 + 7;

ll n, len[N], res = 0;
ll hashL[N], hashR[N], POW[N];
string ST[N];
unordered_map<ll, ll> f[3]; 

bool compare(string x, string y)
{ 
	return (x.size() < y.size());
}

void init(ll pos, string save, string rev)
{
	hashL[0] = 0; hashR[0] = 0;
	for(ll i = 1; i <= len[pos]; ++i)
	{
		hashL[i] = (hashL[i - 1] * base + save[i] - 'a' + 1) % MOD;
		hashR[i] = (hashR[i - 1] * base + rev[i] - 'a' + 1) % MOD;		
	}
}

ll gethash(ll i, ll j, int status)
{
	if(i > j) return 0;
	else if(!status) return(hashL[j] - hashL[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
	else             return(hashR[j] - hashR[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}
int main()
{
	
	cin >> n;
	for(ll i = 1; i <= n; ++i) 	cin >> len[i] >> ST[i];
	
	sort(ST + 1, ST + n + 1, compare);
	
     POW[0] = 1;
	for(ll i = 1; i <= N; ++i) POW[i] = (POW[i - 1] * base) % MOD;  
	
	for(ll i = 1; i <= n; ++i) len[i] = ST[i].size();
	
	for(ll pos = 1; pos <= n; ++pos)
	{		
		ll cnt = 0;
		string save = ST[pos], rev = ST[pos];
		reverse(rev.begin(), rev.end());
		
		rev = " " + rev; save = " " + save;
		init(pos, save, rev);
		for(ll i = 1; i <= len[pos]; ++i)
		{
			ll val  = gethash(1, i, 0),
			 	val1 = gethash(i + 1, len[pos], 0),
			 	val2 = gethash(1, len[pos] - i, 1);
			if(val1 == val2) cnt += f[1][val];
		}
		
		for(ll i = 1; i <= len[pos]; ++i)
		{
			ll val  = gethash(1, i, 1),
				val1 = gethash(i + 1, len[pos], 1),
				val2 = gethash(1, len[pos] - i, 0);
			if(val1 == val2) cnt += f[0][val];
		}
		
		int lenL = gethash(1, len[pos], 0),
			lenR = gethash(1, len[pos], 1);
		if(lenL == lenR) ++cnt;
		++f[0][lenL];
		++f[1][lenR];
		
		res += cnt;
	}
	cout << res;
	return 0;
}
