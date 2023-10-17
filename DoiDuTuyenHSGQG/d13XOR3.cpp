#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e18;
void file()
{
	//freopen(".inp" , "r" , stdin);
	//freopen(".out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
 ll a[5] , b[5] , a1[70] , b1[70] , a2[70] , b2[70] , a3[70] , b3[70] , f[70][5][5][5][5][5][5];
ll Bit(ll x , ll k)
{
	return (x >> k) & 1LL;
}
ll calcmax(int i  , int ok1a , int ok1b , int ok2a , int ok2b , int ok3a , int ok3b)
{
	if (i > 63) return 0;
	if (f[i][ok1a][ok1b][ok2a][ok2b][ok3a][ok3b] != -1) return f[i][ok1a][ok1b][ok2a][ok2b][ok3a][ok3b];
	int min1 , max1 , min2 , max2 , min3 , max3;
	if (ok1a) min1 = 0 ; else min1 = a1[63 - i];
	if (ok1b) max1 = 1 ; else max1 = b1[63 - i];
	
	if (ok2a) min2 = 0 ; else min2 = a2[63 - i];
	if (ok2b) max2 = 1 ; else max2 = b2[63 - i];
  
	if (ok3a) min3 = 0 ; else min3 = a3[63 - i];
	if (ok3b) max3 = 1 ; else max3 = b3[63 - i];
	
	 ll	best = 0;
//	 cout << min1 << ' ' << max1 << ' ' << min2 << ' ' << max2 << ' ' << min3 << ' ' << max3 << endl;
	for (int x = min1 ; x <= max1 ; x++)
	for (int y = min2 ; y <= max2 ; y++)
	for (int z = min3 ; z <= max3 ; z++)
	{
	//	cout << x << ' ' << y << ' ' << z << endl;
		ll temp = (x ^ y ^ z) * (1LL << (63 - i)) + calcmax(i + 1 , ok1a | (x > a1[63 - i]) , ok1b | (x < b1[63 - i])  , ok2a | (y > a2[63 - i]) , ok2b | (y < b2[63 - i])  , ok3a | (z > a3[63 - i]) , ok3b | (z < b3[63 - i]));
		best = max(best , temp);
	}
	//cout << i << ' ' << ok1a << ' ' << ok1b << ' ' << ok2a<< ' ' << ok2b <<' ' <<ok3a <<' ' <<ok3b <<  ' ' <<best << endl;;
	f[i][ok1a][ok1b][ok2a][ok2b][ok3a][ok3b] = best;
	return best;
}
ll calcmin(int i  , int ok1a , int ok1b , int ok2a , int ok2b , int ok3a , int ok3b)
{
	if (i > 63) return 0;
	if (f[i][ok1a][ok1b][ok2a][ok2b][ok3a][ok3b] != -1) return f[i][ok1a][ok1b][ok2a][ok2b][ok3a][ok3b];
	int min1 , max1 , min2 , max2 , min3 , max3;
	if (ok1a) min1 = 0 ; else min1 = a1[63 - i];
	if (ok1b) max1 = 1 ; else max1 = b1[63 - i];
	
	if (ok2a) min2 = 0 ; else min2 = a2[63 - i];
	if (ok2b) max2 = 1 ; else max2 = b2[63 - i];
  
	if (ok3a) min3 = 0 ; else min3 = a3[63 - i];
	if (ok3b) max3 = 1 ; else max3 = b3[63 - i];
	
	 ll	worst = inf;
//	 cout << min1 << ' ' << max1 << ' ' << min2 << ' ' << max2 << ' ' << min3 << ' ' << max3 << endl;
	for (int x = min1 ; x <= max1 ; x++)
	for (int y = min2 ; y <= max2 ; y++)
	for (int z = min3 ; z <= max3 ; z++)
	{
	//	cout << x << ' ' << y << ' ' << z << endl;
		ll temp = (x ^ y ^ z) * (1LL << (63 - i)) + calcmin(i + 1 , ok1a | (x > a1[63 - i]) , ok1b | (x < b1[63 - i])  , ok2a | (y > a2[63 - i]) , ok2b | (y < b2[63 - i])  , ok3a | (z > a3[63 - i]) , ok3b | (z < b3[63 - i]));
		worst = min(worst , temp);
	}
	//cout << i << ' ' << ok1a << ' ' << ok1b << ' ' << ok2a<< ' ' << ok2b <<' ' <<ok3a <<' ' <<ok3b <<  ' ' <<best << endl;;
	f[i][ok1a][ok1b][ok2a][ok2b][ok3a][ok3b] = worst;
	return worst;
}
int main()
{
	file();
    for (int i = 1 ; i <= 3 ; i++)  cin >> a[i] >> b[i] ;
    for (int i = 0 ; i <= 63 ; i++) 
	a1[i] = Bit(a[1] , i) , b1[i] = Bit(b[1] , i) ,
	a2[i] = Bit(a[2] , i) , b2[i] = Bit(b[2] , i) ,
	a3[i] = Bit(a[3] , i) , b3[i] = Bit(b[3] , i)  ;
	
//	cout << a[1] << ' ' << Bit(a[1] , 63) << endl;
//	for (int i = 0 ; i<= 64 ; i++) cout << a1[i];
	memset(f , -1 , sizeof(f));
	cout << calcmin(0 , 0 , 0 , 0 , 0 , 0 , 0) << '\n';
	memset(f , -1 , sizeof(f));
	cout << calcmax(0 , 0 , 0 , 0 , 0 , 0 , 0) ;
	return 0;
}

