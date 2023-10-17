#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp>
//#include <functional> // for less
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
  tree<long long, null_type, less<long long>, rb_tree_tag,tree_order_statistics_node_update> p;
  long long n,x;
  void file()
{
	freopen("KITE.inp","r",stdin);
	freopen("KITE.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
int main()
{
	file();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		p.insert(x);
		cout<<p.size()-p.order_of_key(x)<<endl;
	}
  /*  p.insert(5);
    p.insert(2);
    p.insert(6);
    p.insert(4);
  
    // value at 3rd index in sorted array.
    cout << "The value at 3rd index ::" 
         << *p.find_by_order(3) << endl;
  
    // index of number 6
    cout << "The index of number 6::" 
         << p.order_of_key(6) << endl;
  
    // number 7 not in the set but it will show the 
    // index number if it was there in sorted array.
    cout << "The index of number seven ::"
         << p.order_of_key(7) << endl;*/
  
    return 0;
}
