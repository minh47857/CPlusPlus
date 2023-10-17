#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005, MOD = 1e9 + 7;
ll ans = 0, HashS[N], HashT[N], po[N], base = 31, n;
string str1 , str2;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(int x,int y, ll Hash[])
{
	return ( Hash[y] -Hash[x-1]*po[y-x+1] + MOD*MOD )%MOD;
}
int tknp(int a , int b ,int x ,int y)
{
				int d = 1, c = b - a + 1, kq = 0, g;
				while( d <= c)
			    {
			    	g = ( d + c ) / 2;
			    	if (get(a , a + g - 1 , HashS) == get(x , x + g - 1 , HashT )) kq = g , d = g + 1;
			    	else c = g - 1;
				}
			if(kq == b - 1) return 1;
			if( get(a + kq + 1 , b, HashS) == get(x + kq + 1 , y, HashT) ) return 1;
			return 0;
}
int main()
{
	file();
     cin >> str1 >> str2;
     str1=' '+str1;
     str2=' '+str2;
     n = str1.size() - 1;
     po[0] = 1;
     for(int i = 1; i <= n ; i++) po[i]=( po[i - 1] * base ) % MOD;
     for(int i = 1; i <= n; i++)  
	 {
	 	 HashS[i]= (HashS[i - 1] * base + str1[i]-'A'+1 ) % MOD;
		 HashT[i]= (HashT[i - 1]* base +  str2[i]-'A'+1 )  % MOD;
	}
	for( int i = 1; i <= n ; i++)
	{
	  ll s1 = get(i , n, HashS) ;
	  ll t1 = get(1, n - i + 1, HashT);
	  ll s2 = get(1 , i - 1, HashS ) ;
	  ll t2 = get(n - i + 2 , n , HashT);
		if (s1 == t1&& s2 == t2)  
		{
			ans += n ;
		    continue;
		}
		if (s1 == t1)  ans += tknp(1, i - 1 , n - i + 2 , n);	
		if (s2 == t2)  ans += tknp(i , n , 1, n - i + 1) ;
	}
	
	cout << ans;
	return 0;  
    
}

