#include <bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define pb push_back
const int MAX = 5000+3,M2=(1<<10),inf=4e18,mod=1e9+7;
void maxx(int &a,int b) {if(b>a) a=b;}
void minn(int &a,int b) {if(b<a) a=b;}
using ii = pair < int ,int > ;
using ll = long long;
string s[MAX];
int C[MAX];
int lcp(string &s1,string &s2){
    int m=min(s1.length(),s2.length());
    for(int i=0;i<m;i++)if(s1[i]!=s2[i]) return i;
    return m;
}
int cn=0;
int dp[MAX][MAX];

int dfs(int l,int r){
    if(l == r) return 0;
    int cs = l + 1;
    for(int i= l + 2 ; i <= r ; i++)
		if(C[cs] > C[i]) cs = i;
    int id1 = dfs(l , cs - 1);
    int id2 = dfs(cs , r);
    ++cn;
    for(int i = 0 ; i <= cs - l ; i++){
        for(int j = 0 ; j <= r - cs + 1 ; j++)
            maxx(dp[cn][i + j] , dp[id1][i] + dp[id2][j] + i * j * C[cs]);
    }
    //cout << l << ' ' << r << ' ' << cn << '\n';
    return cn;
}

signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("B.inp", "r", stdin);freopen("B.out", "w", stdout);
    int n,K;
    cin>>n>>K;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+1+n);
    for(int i=2;i<=n;i++){
        C[i]=lcp(s[i-1],s[i]);
    }
    dfs(1,n);
    cout<<dp[cn][K];
}
