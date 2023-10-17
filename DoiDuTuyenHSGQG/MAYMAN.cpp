#include<bits/stdc++.h>
using namespace std;

const int N=1000001;
int n, p, ans = 0, Min[N];
pair<int, int> id, a[N];   
int binary(int l, int r, int x)
{
	int d = l, c = r, g,kq = 0;
	while( d <= c )
	{
		g = (d + c)/2;
		if(a[g].first <= x) 
		{
			kq = g;
			d = g + 1;
		}
		else c = g - 1;
	}
	return kq;
}
int main()
{
     cin>> n>> p;
     for(int i = 1; i <= n ; i++)
     {
     	cin>> a[i].first;
     	a[i].second = i;
	 }
	 
	 sort(a + 1, a + n + 1);
	 
	 for(int i = 1; i <= n; i++) Min[i] = min( Min[i - 1], a[i].second );
	 
	 for(int i = 2; i <= n; i++)
	 {
	 	int value = a[i].first - p;
	 	if( value  <= 0 ) continue;
	 	int pos = binary (1, i - 1, value); 
	 	if( pos == 0) continue;
	    int len = a[i].second - Min[pos] ;
	 	if(len == ans && pos < id.first) id.first = pos, id.second = i;
	 	if(len > ans) 
	 	{
	 		ans = len;
	 		id.first = pos;
	 		id.second = i;
		 }
	 }
	 if( ans == 0) cout<< 0;
	 else cout<<id.first<<" "<<id.second;
}

