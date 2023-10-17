 #include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const ll N=1000001;
const ll MOD = 1e9 + 7;
ll  n, po[N], Hashsum[N], base = 257, sum, charr[N], num[N] ;
string s[N];
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll get(int x, int y)
{
    return ( Hashsum[y] -Hashsum[x-1]*po[y-x+1] + MOD*MOD )%MOD;
}
int main()
{
    file();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i] , s[i] = ' ' + s[i] , num[i] = s[i].size() - 1;
    
     po[0] = 1;
     for(int i = 1; i < N ; i++) po[i]=( po[i-1]*base )%MOD;

         for (int j = 1 ; j <= num[1] ; j++ )   Hashsum[j] = (Hashsum[j - 1] * base + (s[1])[j] ) %MOD;
    sum = num [1], charr[1] = 0 ;
    
   for (int i = 2 ;i <= n ; i++)
     {
         ll kq = 0, Hash = 0;
        for( int j = 1; j <=  num[i]; j++)
        {
            Hash = (Hash * base + (s[i])[j]   ) % MOD;
            
            if(get(sum - j + 1 , sum ) == Hash) kq = j;

        }
    
        charr[i] = kq;
         for( int j = kq + 1, dem = 1; j <= num[i]; j++ , dem++)      Hashsum[sum + dem] = (Hashsum[sum + dem - 1] * base + (s[i])[j]   ) % MOD;
        sum += (num[i] - kq);
     }
     for(int i = 1; i <= n ; i++ ) 
         for (int j = charr[i] + 1 ; j <= num[i] ; j ++ ) cout << (s[i])[j];
     
     return 0;  
}

