#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 1000001 , MOD = 1e9 +7 , inf = 1e15;
void file()
{
	freopen("CHUPANH.inp" , "r" , stdin);
	freopen("CHUPANH.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int n , res[N] , a[N][6];
bool cmp(int x , int y)
{
	int dem = 0;
  for (int i = 1 ; i <= 5 ; i++) if(a[x][i] < a[y][i]) dem++;
  return dem >= 3;
}
int main()
{
	file();
   cin >> n;
   for (int i = 1 ; i <= 5 ; i++)
   for (int j = 1 , x ; j <= n ; j++)
   cin >> x , a[x][i] = j;
   
   for (int i = 1 ; i <= n ; i++) res[i] = i;
    sort(res + 1 , res + n + 1 , cmp);
   for (int i = 1 ; i <= n ; i++) cout << res[i] << ' ';
    
   return 0;
}

