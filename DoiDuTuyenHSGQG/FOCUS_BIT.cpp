#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N=1000001;
void file()
{
	freopen(".inp","r",stdin);
	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	ll n;
  cin>>n;
  cout<<(n&(-n));
}

