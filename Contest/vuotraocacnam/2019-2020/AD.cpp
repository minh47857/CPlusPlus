#include<bits/stdc++.h>
using namespace std;
const long long N=1000005;
string s1,s2;
int d1[N],d2[N],s=0;
void file()
{
	freopen("AD.inp","r",stdin);
	freopen("AD.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++) d1[s1[i]]++;
	for(int i=0;i<s2.size();i++) d2[s2[i]]++;
	for(int i='a';i<='z';i++)
     s+=abs(d1[i]-d2[i]);
     cout<<s;
}
