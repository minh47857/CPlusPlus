#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
const long long N=1000000;
long long n,m,a[N],dp[N][3],s=0;
void file()
{
	freopen("wire.inp","r",stdin);
	freopen("wire.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
  cin>>n>>m;
  for(int i=1;i<=n;i++)	cin>>a[i];
  for(int i=m+1;i<=n;i++)
  {
  	dp[i][1]=dp[i-m][0]+a[i]+a[i-m];
  	dp[i][0]=max(dp[i-m][0],dp[i-m][1]);
  	if(i>n-m) s+=max(dp[i][0],dp[i][1]);
  }
  cout<<s;
  
}

