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
    int n,k,q; cin>>n>>k>>q;
    vl v(n); rep(i,n) cin>>v[i];
    vvl dp(n, vl(k+1,0));
    rep(i,n)dp[i][0] = 1;
    rep(i,k){
        rep(j,n){
            if(j!=0) dp[j][i+1] = (dp[j][i+1]+dp[j-1][i])%M;
            if(j<n-1) dp[j][i+1] = (dp[j][i+1]+dp[j+1][i])%M;
        }  
    }
    // rep(i,n){
    //     rep(j,k+1){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    
    vl used(n,0);
    rep(i,n){
        for(int j = 0; j<=k; j++){
            used[i] = (used[i] + ((1ll * dp[i][j] * dp[i][k-j]) % M)) % M;
        }
    }

    ll ans = 0;
    rep(i,n){
        // cout<<used[i]<<" ";
        ans = (ans + ((1ll * v[i] * used[i])%M))%M;
    }
    // ll ans1 = ans;
    rep(i,q){
        ll ind, val; cin>>ind>>val;
        ind--;
        // ans = ans1;
        ans = (ans - ((1ll * v[ind] * used[ind])%M) + M)%M;
        v[ind] = val;
        ans = (ans + ((1ll * val * used[ind])%M)) % M;
        cout<<ans<<endl;
    }
}


int32_t main()
{
    ioset
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}