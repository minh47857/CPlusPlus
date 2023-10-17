#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int,int>
const int N = 1000001 ;
void file()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

 int n , a[N] , st[4 * N] , dem = 0 , m , tmp;
 unordered_map<int , int> pos;
 char type[N];
 vector<int> v;
 
 void update(int id ,int l , int r , int u , int v)
 {
 	if (l > u || r < u) return;
 	if(l == r) 
 	{
 		st[id] += v;
 		return;
	 }
	 int mid = (l + r) / 2;
	 update(id * 2 , l , mid , u , v);
	 update(id * 2 + 1 , mid + 1 , r , u , v);
	 st[id] = st[id * 2] + st[id * 2 + 1];
 }

 int get(int id , int l , int r , int val)
 {
 	if(l == r) return l;
 	int mid = (l + r) / 2;
 	if (st[id * 2] >= val) return get(id * 2 , l , mid , val);
 	else return get(id * 2 + 1 , mid + 1 , r , val - st[id * 2]);
 }
 
int main()
{
	file();
   cin >> n;
   v.pb(-1);
 for (int i = 1 ; i <= n ; i++)
 {
   cin >> type[i] >> a[i] ;
    if (type[i] == '+') v.pb(a[i]);
 }
 sort(v.begin() , v.end());
  m = v.size() - 1;
 for (int i = 1 ; i <= m ; i++)  if (v[i] != v[i - 1]) pos[v[i]] = i; else pos[v[i]] = pos[v[i - 1]];
 for (int i = 1 ; i <= n ; i++)
 {
 	if (type[i] == '-') update(1 , 1 , m , pos[a[i]] , -1) , dem--;
 	else  update(1 , 1 , m , pos[a[i]] , 1) , dem++;
    tmp = get(1 , 1 , m , (dem + 1) / 2);
    cout << v[tmp] << '\n';
 }
 return 0;
}

