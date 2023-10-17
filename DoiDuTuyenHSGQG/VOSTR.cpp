#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N=1000001;
void file()
{
	//freopen(".inp","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get_A(int x,int y)
{
	return  HashA[y] -HashA[x-1]*po[y-x+1] ;
}
ll get_B(int x,int y)
{
	return  HashB[y] -HashB[x-1]*po[y-x+1];
}
void solve()
{
	ll d = 0, c = min(r - l + 1, v - u + 1);
	while( d <= c)
	{
		g = (d + c)/2;
		if( get_A( l ))
	 } 
}
int main()
{
	file();
	cin>> n>> m;
     cin >>str1 >> str2;
     str1=' '+str1;
     str2=' '+str2;
     po[0] = 1;
     for(int i= 1; i <= n ; i++) po[i]=( po[i-1]*base )%MOD;
     for(int i= 1; i<= n; i++)  HashA[i]= (HashA[i-1]*base + str1[i]-'a'+1 ) 
     for(int i= 1; i<= m; i++)  HashB[i]= (HashB[i-1]*base + str2[i]-'a'+1 ) 
     cin>>q;
     while(q--)
     {
     	cin>>l>>r>>u>>v;
       solve();
	 }
		 
	 return 0;  
}

