#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pi pair<ll,ll>
const ll N = 100010, inf = LLONG_MAX;
ll t1, t2, t3, w1, w2, f1, f2, dist[N][5]; 
struct data
{
    ll fi, se ,rd;
} ;
bool operator > (const data& A, const data& B) {
  return A.fi > B.fi;
}
void dijkstra(ll s)
{
    priority_queue < data, vector <data>, greater <data> > heap;
    
    dist[s][0] = 0;
    dist[s][1] = w1;
    heap.push({0 , s, 0});
    heap.push({w1, s, 1});
    if(s % 10 == 0)     dist[s][2] = w2 , heap.push({w2, s, 2});
    while( heap.size()!= 0 )
    {
        ll t = heap.top().fi;
        ll u = heap.top().se;
        ll sta =  heap.top().rd;
        heap.pop();
        if( t != dist[u][sta]) continue ;
      
            if(dist[u - 1][0] > t + t3 && u > 1) 
                   dist[u - 1][0] =  t + t3 , heap.push({dist[u - 1][0], u - 1, 0});
                   
            if(dist[u + 1][0] > t + t3 && u < N) 
                   dist[u + 1][0] =  t + t3 , heap.push({dist[u + 1][0], u + 1, 0}) ;           
    
            if(dist[u + 1][1] > t + t1 + ( (sta == 1) ? 0 : w1) && u < N )
                dist[u + 1][1] = t + t1 + ( (sta == 1) ? 0 : w1) , heap.push({dist[u + 1][1], u + 1, 1}) ;
                
            if(dist[u - 1][1] > t + t1 + ( (sta == 1) ? 0 : w1) && u > 1 )
                  dist[u - 1][1] = t + t1 + ( (sta == 1) ? 0 : w1) , heap.push({dist[u - 1][1], u - 1, 1});
                
    if (u % 10 != 0) continue;
    
            if(dist[u + 10][2] > t + t2 + ( (sta == 2) ? 0 : w2) && u <= N - 10 )
                  dist[u + 10][2] = t + t2 + ( (sta == 2) ? 0 : w2) , heap.push({dist[u + 10][2], u + 10, 2});
                  
            if(dist[u - 10][2] > t + t2 + ( (sta == 2) ? 0 : w2) && u > 10 )
                  dist[u - 10][2] = t + t2 + ( (sta == 2) ? 0 : w2) , heap.push({dist[u - 10][2], u - 10, 2});
                      
    }
    
    cout << min ({dist[f2][0] , dist[f2][1] , dist[f2][2]}) ;  
}

int main()
{
     for (int i = 1; i <= N; i++)
     {
         for( int j = 0; j <= 2; j++) dist[i][j] = inf ;
     }
   cin >> t1>> w1>> t2>> w2>> t3 >> f1>> f2;
   
   
   dijkstra(f1);
   return 0;
}

