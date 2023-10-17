#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 1e9 +7 , inf = 1e15;

void file()
{
	freopen("ABC.inp" , "r" , stdin);
	freopen("ABC.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll demA = 0, demB = -1 , demC = 0, dem = 0 , n , a[N] , c[N];
string s;

int main()
{
	file();
    cin >> n >> s;
    s = ' '+s;
    a[0] = 0,c[n + 1] = 0;
   for (int i = 1 ; i <= n ; i++)
    {
        a[i] = a[i - 1];
        if(s[i] == 'A') a[i]++;
    }
    for (int i = n ; i >= 1 ; i--)
    {
        c[i] = c[i + 1];
        if(s[i] == 'C') c[i]++;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        if(s[i] == 'B') 
        {
            demA += ((a[i]+1)*c[i]);
            demC += ((c[i]+1)*a[i]);
            dem  += a[i]*c[i];    
        }
        else  demB = max(demB , a[i]*c[i]);
        
    }
    cout<< max(dem + demB ,max( demA , demC));
    return 0;
}

