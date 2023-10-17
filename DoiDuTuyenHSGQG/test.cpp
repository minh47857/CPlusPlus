#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int q, c, x, ts[N], tmp;
long long ans;
set<int> s, tmps;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> q;
    while( q-- )
    {
        cin >> c >> x;
        switch(c)
        {
            case 0:
                {
                    ts[x]++;
                    if( ts[x]==1 ) s.insert(x);
                    break;
                }
            case 1:
                {
                    if( ts[x]>0 )
                    {
                        ts[x]--;
                        if( ts[x]==0 ) s.erase(x);
                    }
                    break;
                }
            case 2:
                {
                    for( auto it=s.begin(); it!=s.end(); it++ )
                    {
                        tmp = *it ^ x;
                        if( tmp > *it && ts[tmp]!=0 ) swap( ts[*it], ts[tmp] );
                        if( ts[tmp]==0 ) tmps.insert( *it ), swap( ts[*it], ts[tmp] );
                    }

                    while( tmps.size()!=0 )
                    {
                        tmp = *tmps.begin();
                        tmps.erase( tmp );
                        s.insert( tmp^x );
                        s.erase(tmp);
                    }

                    break;
                }
            case 3:
                {
                    ans = 0;
                    for( auto it=s.begin(); it!=s.end(); it++ )
                    {
                        ans += min(x, ts[*it])*(*it);
                        x -= min( x, ts[*it] );
                        if( x==0 ) break;
                    }
                    cout << ans << '\n';
                    break;
                }
        }
    }

    return 0;
}
