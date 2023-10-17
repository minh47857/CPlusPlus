#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100005 , MOD = 1e9 +7;
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
struct Node
{
    ll lazy = 0 , left_val = LLONG_MAX, ri_val = LLONG_MAX , left = 0 , ri = 0 , res = 0 , len = 0;
} ;


Node combine ( Node a ,  Node b)
{
    Node ans;
    ans.left_val = a.left_val;
    ans.ri_val = b.ri_val;
    ans.len = a.len + b.len;
    ans.left = a.left;
    ans.ri = b.ri;
    if (a.len == a.left &&  a.ri_val == b.left_val - 1) ans.left = a.left + b.left;
    if (b.len == b.ri && b.left_val == a.ri_val + 1  ) ans.ri = a. ri + b.ri;
    if (a.ri_val == b.left_val - 1) ans.res = a.ri + b.left;
    ans.res = max ({ans.res , a.res , b.res}) ;
    return ans;
}
char str;
ll la, ra , n , aa[N], bon, q;
Node st[4 * N];

void down (ll id)
{
    ll t = st[id].lazy;
    
    st[id * 2].lazy += t;
    st[id * 2].left_val += t;
    st[id * 2].ri_val += t;
    
    st[id * 2 + 1].left_val += t;
    st[id * 2 + 1].ri_val += t;
    st[id * 2 + 1].lazy += t;
    
    st[id].lazy = 0;  
}
void build(int id ,int l ,int r)
{
    if(l == r) 
    {
        st[id].len = st[id].left = st[id].ri = st[id].res = 1;
        st[id].left_val = st[id].ri_val = aa[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2 , l , mid );
    build(id * 2 + 1, mid + 1 , r);
    st[id] = combine(st[id * 2] , st[id * 2 + 1]);
}
void update(int id , int l , int r, int u , int v, int sum)
{
    if ( l > v || r < u) return;
    if ( u <= l && r <= v)
    {
        st[id].lazy += sum;
        st[id].left_val += sum;
        st[id].ri_val += sum;
        return;
    }
    down(id);
    ll mid = (l + r) / 2 ;
    update(id * 2 , l , mid , u, v , sum);
    update(id * 2 + 1, mid + 1 , r , u , v, sum);
   st[id] = combine(st[id * 2] , st[id * 2 + 1]);
}
Node get(int id ,int l , int r , int u , int v)
{
    if (l > v || r < u)
    {
        Node f;
       return f;
     }
    if (u <= l && r <= v)    return st[id];
    down(id);
    ll mid = (l + r ) / 2; 
    return combine( get(id * 2 , l , mid , u , v) , get(id * 2 + 1 , mid + 1, r , u , v));

}
int main()
{
    file();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> aa[i];
    build(1, 1 , n);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> str >> la >> ra;
        if (str == '?') cout << get(1 , 1, n , la , ra ).res << '\n';
        else 
        {
            cin >> bon;
            update(1, 1, n , la , ra , bon);
        }
    }
    return 0;
}

