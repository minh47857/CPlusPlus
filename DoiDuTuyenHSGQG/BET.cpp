#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 1000001 , MOD = 1e9 + 7 , inf = 1e15;
ll n ;
long double a[N] , b[N] , ans = -inf , s1 , s2 , SumA[N] , SumB[N];
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
 cin >> n ;
 for (int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i] , a[i]-- , b[i]--;
 sort(a + 1 , a + n + 1 , greater<long double>());
 sort(b + 1 , b + n + 1 , greater<long double>());
 for (int i = 1 ; i <= n ; i++)
 {
       SumA[i] = SumA[i - 1] + a[i] , SumB[i] = SumB[i - 1] + b[i];
 }
 for (int i = 0 ; i <= n ; i++)
 {
   long double    d = 0 , c = n , A = SumA[i] , B ;
     while (d <= c)
     {
     int    g = (d + c) / 2 ;
     int    j = g;
         B = SumB[j];
         ans = max(ans , min(A - j , B - i));
         if (A - j == B - i) break;
         if (A - j < B - i) c = g - 1;
         else d = g + 1;
     }
 }
 cout << fixed<<setprecision(4) << ans;
 return 0;
}


