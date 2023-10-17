 #include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N=1000001;
const ll MOD=1e9+7;
ll m, n, po[N], hashson, Hash[N],base = 31;
string str1,str2;
void file()
{
	//freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get(int x,int y)
{
	return ( Hash[y] -Hash[x-1]*po[y-x+1] +MOD*MOD )%MOD;
}
int main()
{
	file();
     cin >>str1 >> str2;
     str1=' '+str1;
     str2=' '+str2;
     n=str1.size()-1;
     m=str2.size()-1;
     po[0] = 1;
     for(int i= 1; i <= n ; i++) po[i]=( po[i-1]*base )%MOD;
     for(int i= 1; i<= n; i++)   Hash[i]= (Hash[i-1]*base + str1[i]-'a'+1 ) %MOD;
     for(int i= 1; i<= m; i++)   hashson= (hashson*base + str2[i]- 'a'+1 ) %MOD;
     for(int i= 1; i<= n-m+1; i++)  	if( hashson==get(i,i+m-1) ) cout<<i<<" ";
		 
	 return 0;  
}

