 #include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
const long long N=5e4+5;
const ll MOD=1e9+7;
ll  n, po[N], Hash2[N], Hash1[N], base = 31, n1;
string str1,str2;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
ll get1(int x,int y)
{
	return ( Hash1[y] -Hash1[x-1]*po[y-x+1] +MOD*MOD )%MOD;
}
ll get2(int x, int y)
{
	return ( Hash2[y] -Hash2[x-1]*po[y-x+1] +MOD*MOD )%MOD;
}
bool check(int k)
{
	for(int i = 1; i <= n - k + 1; i++)	if( get1(i, i + k -1) == get2( n - i - k + 2, n - i + 1) ) return true;
	return false;
}
int solve(int cl)
{
	int  d= cl , c , g, kq = 0;
	if(cl == 0) c= ( n/2 ) * 2;
    else c= n1;
    //cout<<d<<c <<endl;
     while(d <= c)
     {
     	g = (d + c)/2 ;
     	if( cl == 1 && d != c && g % 2 == 0) g= g - 1;
     	//cout<<g<<endl;
     	if(check(g)) 
		 {
		 	kq= g, d= g + 2;
		 }
     	else c= g - 2;
	 }
     return kq;
}
int main()
{
	file();
     cin>>n>>str1 ;
     str2= str1;
     reverse(str2.begin(), str2.end());
     str1=' '+str1;
     str2=' '+str2;
     po[0] = 1;
     for(int i= 1; i <= n ; i++) po[i]= ( po[i-1]*base )%MOD;
     for(int i= 1; i <= n; i++)  
	 {
	 	Hash1[i]= (Hash1[i-1]*base + str1[i]-'a'+1 ) %MOD;
	 	Hash2[i]= (Hash2[i-1]*base + str2[i]-'a'+1 ) %MOD;
	 } 
	if(n % 2 == 0) n1= n - 1;
	else n1= n;
	cout<< max( solve(1), solve(0) );
	 return 0;  
}

