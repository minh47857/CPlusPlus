#include<bits/stdc++.h>
#define ll long long
#define pi pair<int , int>
#define fi first
#define se second

using namespace std;
const int N = 1e6 + 5 , M = 1e9;

void file() {
	freopen("uocso.inp" , "r" , stdin);
	freopen("uocso.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) ; cout.tie(0);
}

int a , b , Min , Cmin , Count , d[N] , x[N];

int main() {
	file();
	cin >> a >> b;
	for(int i = a ; i <= b ; i++) x[i - a + 1] = i , d[i - a + 1] = 1;
	for(int i = 2 ; i <= sqrt(M) ; i++) {
		for(int j = (a + i - 1) / i * i ; j <= b ; j += i) {
			int dem = 0;
			while(x[j - a + 1] % i == 0) x[j - a + 1] /= i , dem++;
			d[j - a + 1] *= (dem + 1);
		}
	}	
	for(int i = a ; i <= b ; i++) {
		if(x[i - a + 1] != 1) d[i - a + 1] *= 2;
		Min = max(Min , d[i - a + 1]);
	}
	for(int i = b ; i >= a ; i--) 
		if(d[i - a + 1] == Min) Cmin = i , Count++;
	cout << Cmin << ' ' << Min << ' ' << Count;
	return 0;
}

