#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
    //Whatever
    //IMSS I am sad scam 
//add this to template 
#define pi (3.141592653589)
#define M 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define ioset ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ps(x,y) fixed<<setprecision(y)<<x
#define pii pair<int,int>
// #define int long long int
#define vi vector<int>

using namespace std;
using namespace __gnu_pbds;


#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve()
{
    int n; cin>>n;
    // vi a(n),b(n);
    vector<vi> v;
    rep(i,n){
        vi a(2); cin>>a[0]>>a[1];
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    ordered_set oset; 
    oset.insert(v[0][1]);
    ll ans = 0;
    for(int i=1; i<n; i++){
        ans += (n-i) - oset.order_of_key(v[i][1]);
        oset.insert(v[i][1]);
    }
    cout<<ans<<endl;
}


int32_t main()
{
    ioset
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}