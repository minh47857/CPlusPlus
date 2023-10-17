#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>

const int N = 4e5 + 5 ;

void file(){
    freopen("lis.inp" , "r" , stdin);
    freopen("lis.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n , m , g[N] , ans = 0 , st[3][4 * N] , x , a[N];
map<int , int> pos;
vector<int> num;

int get(int id , int l , int r , int u , int v , int x){
    if(l > v || r < u) return 0;
    if(l >= u && r <= v)    return st[x][id];
    int mid = (l + r) / 2;
    return max(get(id * 2 , l , mid , u , v , x) , get(id* 2 + 1 , mid + 1 , r , u , v , x));
}

void update(int id , int l , int r , int u , int val , int x){
    if(l > u || r < u) return ;
    if(l == r) {
        st[x][id] = max(st[x][id] , val);
        return ; 
    }
    int mid = (l + r) / 2;
    update(id * 2 , l , mid , u , val , x);
    update(id * 2 + 1 , mid + 1 , r , u , val , x);
    st[x][id] = max(st[x][id * 2] , st[x][id * 2 + 1]);
}

int main(){
    file();
  cin >> n >> x;
  
  for(int i = 1 ; i <= n ; i++){
      cin >> a[i];
      num.pb(a[i]) , num.pb(a[i] + x);
  }
  
  sort(num.begin() , num.end());
  num.erase(unique(num.begin() , num.end()) , num.end());
  m = num.size();
  for(int i = 0 ; i < m ; i++) pos[num[i]] = i + 1;
  
  for(int i = n ; i >= 1 ; i--) {
    g[i] = get(1 , 1 , m , pos[a[i]] + 1 , m , 2) + 1;
      update(1 , 1 , m , pos[a[i]] , g[i] , 2);
  }
  for(int i = 1 ; i <= n ; i++) {
      ans = max(ans , get(1 , 1 , m , 1 , pos[a[i] + x] - 1, 1) + g[i] );
      int res = get(1 , 1 , m , 1 , pos[a[i]] - 1 , 1) + 1;
      update(1 , 1 , m , pos[a[i]] , res , 1);
  }
  
  cout << ans;
  return 0;
  
}

