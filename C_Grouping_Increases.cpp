#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

    //Whatever
    //IMSS I am sad scam 

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
#define vi vector<int>
#define vl vector<ll>
#define vvl vector<vl>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

void solve()
{
    int n; cin>>n; 
    vl v(n); rep(i,n) cin>>v[i];
    int ans = 0;
    ll p1 = v[0], p2 = -1;
    for(int i=1; i<n; i++){
        if(v[i]<p1 && p2==-1) p2 = v[i];
        else if(v[i]<p1 and v[i]>=p2) p1 = v[i];
        else if(v[i]>=p1 and v[i]<p2) p2 = v[i];
        else{
            if (v[i]>p1) ans++;
            if(p1<p2) p1 = v[i];
            else p2 = v[i];
        }
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