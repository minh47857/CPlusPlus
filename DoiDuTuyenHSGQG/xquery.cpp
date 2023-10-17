#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<int , int>

const ll N = 5e5;

void file() {
	//freopen("xquery.inp" , "r" , stdin);
	//freopen("xquery.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

pi query[N];
int q , sum[N][20][2] , num[N] , nx[N][3] , cnt = 0 , G = 0;

int Bit(int x , int p) {
	return (x >> p) & 1;
}

void Insert(int x) {
	int cur = 0;
	for(int i = 17 ; i >= 0 ; i--) {
		if(nx[cur][Bit(x , i)] == -1) nx[cur][Bit(x , i)] = ++cnt;
		cur = nx[cur][Bit(x , i)];
		num[cur]++;
		for(int j = i ; j >= 0 ; j--) sum[cur][j][Bit(x , j)] ++;
	}
}

bool Exist(int x) {
	int cur = 0;
	for(int i = 17 ; i >= 0 ; i--) {
		if(nx[cur][Bit(x , i)] == -1) return false;
		cur = nx[cur][Bit(x , i)];
	}
	return true;
}

void Erase(int x) {
	if(!Exist(x)) return;
	int cur = 0;
	for(int i = 17 ; i >= 0 ; i--) {
		int tmp = cur;
		cur = nx[cur][Bit(x , i)];
		num[cur]--;
		if(!num[cur]) nx[tmp][Bit(x , i)] = -1;
		for(int j = i ; j >= 0 ; j--) sum[cur][j][Bit(x , j)]--;
	}
}

ll Get(int cur , int k , int id) {
	  
  ll ans = min(sum[cur][id][Bit(G , id) ^ 1] , k) * (1LL << id);
  int b = Bit(G , id - 1) , Next;
  if(id == 0)	return ans;
  
  for(int i = 0 ; i <= 1 ; i++) {
  	Next = nx[cur][i ^ b];
  	if(Next == -1) continue;
  	
  	if(k >= num[Next]) {
  		for(int j = id - 1 ; j >= 0 ; j--) ans += sum[Next][j][Bit(G , j) ^ 1] * (1LL << j);
  		k -= num[Next]; 
	  }
	   
	else if(k && k < num[Next]) {
		ans += Get(Next , k , id - 1);
		k = 0;
	}
  }
  return ans;
}

int main() {
  file();
  memset(nx , -1 , sizeof(nx));
  
  cin >> q;
  for(int i = 1 ; i <= q ; i++) cin >> query[i].fi >> query[i].se;
  
  for(int i = 1 ; i <= q ; i++) {
  	if(query[i].fi == 0) Insert(query[i].se ^ G);
  	if(query[i].fi == 1) Erase(query[i].se ^ G);
  	if(query[i].fi == 2) G ^= query[i].se;
  	if(query[i].fi == 3) cout << Get(0 , query[i].se , 18) << '\n';
  	
  }
}

